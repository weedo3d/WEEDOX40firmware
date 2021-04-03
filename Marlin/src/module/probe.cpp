/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * module/probe.cpp
 */

#include "../inc/MarlinConfig.h"

#if HAS_BED_PROBE

#include "probe.h"

// #include "../libs/buzzer.h"
#include "motion.h"
#include "../module/temperature.h"
#include "endstops.h"

#include "../gcode/gcode.h"
// #include "../lcd/ultralcd.h"

#include "../MarlinCore.h" // for stop(), disable_e_steppers, wait_for_user

#if HAS_LEVELING
  #include "../feature/bedlevel/bedlevel.h"
#endif

#if ENABLED(DELTA)
  #include "delta.h"
#endif

#if ENABLED(BABYSTEP_ZPROBE_OFFSET)
  #include "../module/planner.h"
#endif

#if ENABLED(HOST_PROMPT_SUPPORT)
  #include "../feature/host_actions.h" // for PROMPT_USER_CONTINUE
#endif


#define DEBUG_OUT ENABLED(DEBUG_LEVELING_FEATURE)
#include "../core/debug_out.h"

Probe probe;

xyz_pos_t Probe::offset; // Initialized by settings.load()

#if HAS_PROBE_XY_OFFSET
  const xyz_pos_t &Probe::offset_xy = Probe::offset;
#endif

/**
 * Raise Z to a minimum height to make room for a probe to move
 */
void Probe::do_z_raise(const float z_raise) {
  if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR("Probe::move_z(", z_raise, ")");

  float z_dest = z_raise;
  if (offset.z < 0) z_dest -= offset.z;

  NOMORE(z_dest, Z_MAX_POS);

  if (z_dest > current_position.z)
    do_blocking_move_to_z(z_dest);
}

FORCE_INLINE void probe_specific_action(const bool deploy) {
 
    UNUSED(deploy);

}

/**
 * Attempt to deploy or stow the probe
 *
 * Return TRUE if the probe could not be deployed/stowed
 */
bool Probe::set_deployed(const bool deploy) {

  if (DEBUGGING(LEVELING)) {
    DEBUG_POS("Probe::set_deployed", current_position);
    DEBUG_ECHOLNPAIR("deploy: ", deploy);
  }

  if (endstops.z_probe_enabled == deploy) return false;

  // Make room for probe to deploy (or stow)
  // Fix-mounted probe should only raise for deploy
  // unless PAUSE_BEFORE_DEPLOY_STOW is enabled
  #if EITHER(FIX_MOUNTED_PROBE, NOZZLE_AS_PROBE) && DISABLED(PAUSE_BEFORE_DEPLOY_STOW)
    const bool deploy_stow_condition = deploy;
  #else
    constexpr bool deploy_stow_condition = true;
  #endif

  // For beds that fall when Z is powered off only raise for trusted Z
  #if ENABLED(UNKNOWN_Z_NO_RAISE)
    const bool unknown_condition = TEST(axis_known_position, Z_AXIS);
  #else
    constexpr float unknown_condition = true;
  #endif

  if (deploy_stow_condition && unknown_condition)
    do_z_raise(_MAX(Z_CLEARANCE_BETWEEN_PROBES, Z_CLEARANCE_DEPLOY_PROBE));

  const xy_pos_t old_xy = current_position;

  probe_specific_action(deploy);


  do_blocking_move_to(old_xy);
  endstops.enable_z_probe(deploy);
  return false;
}

#ifdef Z_AFTER_PROBING
  // After probing move to a preferred Z position
  void Probe::move_z_after_probing() {
    if (current_position.z != Z_AFTER_PROBING) {
      do_blocking_move_to_z(Z_AFTER_PROBING);
      current_position.z = Z_AFTER_PROBING;
    }
  }
#endif

/**
 * @brief Used by run_z_probe to do a single Z probe move.
 *
 * @param  z        Z destination
 * @param  fr_mm_s  Feedrate in mm/s
 * @return true to indicate an error
 */

/**
 * @brief Move down until the probe triggers or the low limit is reached
 *
 * @details Used by run_z_probe to get each bed Z height measurement.
 *          Sets current_position.z to the height where the probe triggered
 *          (according to the Z stepper count). The float Z is propagated
 *          back to the planner.position to preempt any rounding error.
 *
 * @return TRUE if the probe failed to trigger.
 */
bool Probe::probe_down_to_z(const float z, const feedRate_t fr_mm_s) {
  if (DEBUGGING(LEVELING)) DEBUG_POS(">>> Probe::probe_down_to_z", current_position);

  #if HAS_HEATED_BED && ENABLED(WAIT_FOR_BED_HEATER)
    thermalManager.wait_for_bed_heating();
  #endif

  // Move down until the probe is triggered
  do_blocking_move_to_z(z, fr_mm_s);

  // Check to see if the probe was triggered
  const bool probe_triggered =
    #if BOTH(DELTA, SENSORLESS_PROBING)
      endstops.trigger_state() & (_BV(X_MIN) | _BV(Y_MIN) | _BV(Z_MIN))
    #else
      TEST(endstops.trigger_state(),
        #if ENABLED(Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN)
          Z_MIN
        #else
          Z_MIN_PROBE
        #endif
      )
    #endif
  ;

  // Clear endstop flags
  endstops.hit_on_purpose();

  // Get Z where the steppers were interrupted
  set_current_from_steppers_for_axis(Z_AXIS);

  // Tell the planner where we actually are
  sync_plan_position();

  if (DEBUGGING(LEVELING)) DEBUG_POS("<<< Probe::probe_down_to_z", current_position);

  return !probe_triggered;
}

/**
 * @brief Probe at the current XY (possibly more than once) to find the bed Z.
 *
 * @details Used by probe_at_point to get the bed Z height at the current XY.
 *          Leaves current_position.z at the height where the probe triggered.
 *
 * @return The Z position of the bed at the current XY or NAN on error.
 */
float Probe::run_z_probe(const bool sanity_check/*=true*/) {

  if (DEBUGGING(LEVELING)) DEBUG_POS(">>> Probe::run_z_probe", current_position);

  // Stop the probe before it goes too low to prevent damage.
  // If Z isn't known then probe to -10mm.
  const float z_probe_low_point = TEST(axis_known_position, Z_AXIS) ? -offset.z + Z_PROBE_LOW_POINT : -10.0;

  // Double-probing does a fast probe followed by a slow probe
  #if TOTAL_PROBING == 2

    // Do a first probe at the fast speed
    if (probe_down_to_z(z_probe_low_point, MMM_TO_MMS(Z_PROBE_SPEED_FAST))         // No probe trigger?
      || (sanity_check && current_position.z > -offset.z + _MAX(Z_CLEARANCE_BETWEEN_PROBES, 4) / 2)  // Probe triggered too high?
    ) {
      if (DEBUGGING(LEVELING)) {
        DEBUG_ECHOLNPGM("FAST Probe fail!");
        DEBUG_POS("<<< run_z_probe", current_position);
      }
      return NAN;
    }

    const float first_probe_z = current_position.z;

    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR("1st Probe Z:", first_probe_z);

    // Raise to give the probe clearance
    do_blocking_move_to_z(current_position.z + Z_CLEARANCE_MULTI_PROBE, MMM_TO_MMS(Z_PROBE_SPEED_FAST));

  #elif Z_PROBE_SPEED_FAST != Z_PROBE_SPEED_SLOW

    // If the nozzle is well over the travel height then
    // move down quickly before doing the slow probe
    const float z = Z_CLEARANCE_DEPLOY_PROBE + 5.0 + (offset.z < 0 ? -offset.z : 0);
    if (current_position.z > z) {
      // Probe down fast. If the probe never triggered, raise for probe clearance
      if (!probe_down_to_z(z, MMM_TO_MMS(Z_PROBE_SPEED_FAST)))
        do_blocking_move_to_z(current_position.z + Z_CLEARANCE_BETWEEN_PROBES, MMM_TO_MMS(Z_PROBE_SPEED_FAST));
    }
  #endif

  #ifdef EXTRA_PROBING
    float probes[TOTAL_PROBING];
  #endif

  #if TOTAL_PROBING > 2
    float probes_z_sum = 0;
    for (
      #if EXTRA_PROBING
        uint8_t p = 0; p < TOTAL_PROBING; p++
      #else
        uint8_t p = TOTAL_PROBING; p--;
      #endif
    )
  #endif
    {
      // Probe downward slowly to find the bed
      if (probe_down_to_z(z_probe_low_point, MMM_TO_MMS(Z_PROBE_SPEED_SLOW))      // No probe trigger?
        || (sanity_check && current_position.z > -offset.z + _MAX(Z_CLEARANCE_MULTI_PROBE, 4) / 2)  // Probe triggered too high?
      ) {
        if (DEBUGGING(LEVELING)) {
          DEBUG_ECHOLNPGM("SLOW Probe fail!");
          DEBUG_POS("<<< run_z_probe", current_position);
        }
        return NAN;
      }

      #if ENABLED(MEASURE_BACKLASH_WHEN_PROBING)
        backlash.measure_with_probe();
      #endif

      const float z = current_position.z;

      #if EXTRA_PROBING
        // Insert Z measurement into probes[]. Keep it sorted ascending.
        LOOP_LE_N(i, p) {                            // Iterate the saved Zs to insert the new Z
          if (i == p || probes[i] > z) {                              // Last index or new Z is smaller than this Z
            for (int8_t m = p; --m >= i;) probes[m + 1] = probes[m];  // Shift items down after the insertion point
            probes[i] = z;                                            // Insert the new Z measurement
            break;                                                    // Only one to insert. Done!
          }
        }
      #elif TOTAL_PROBING > 2
        probes_z_sum += z;
      #else
        UNUSED(z);
      #endif

      #if TOTAL_PROBING > 2
        // Small Z raise after all but the last probe
        if (p
          #if EXTRA_PROBING
            < TOTAL_PROBING - 1
          #endif
        ) do_blocking_move_to_z(z + Z_CLEARANCE_MULTI_PROBE, MMM_TO_MMS(Z_PROBE_SPEED_FAST));
      #endif
    }

  #if TOTAL_PROBING > 2

    #if EXTRA_PROBING
      // Take the center value (or average the two middle values) as the median
      static constexpr int PHALF = (TOTAL_PROBING - 1) / 2;
      const float middle = probes[PHALF],
                  median = ((TOTAL_PROBING) & 1) ? middle : (middle + probes[PHALF + 1]) * 0.5f;

      // Remove values farthest from the median
      uint8_t min_avg_idx = 0, max_avg_idx = TOTAL_PROBING - 1;
      for (uint8_t i = EXTRA_PROBING; i--;)
        if (ABS(probes[max_avg_idx] - median) > ABS(probes[min_avg_idx] - median))
          max_avg_idx--; else min_avg_idx++;

      // Return the average value of all remaining probes.
      LOOP_S_LE_N(i, min_avg_idx, max_avg_idx)
        probes_z_sum += probes[i];

    #endif

    const float measured_z = probes_z_sum * RECIPROCAL(MULTIPLE_PROBING);

  #elif TOTAL_PROBING == 2

    const float z2 = current_position.z;

    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR("2nd Probe Z:", z2, " Discrepancy:", first_probe_z - z2);

    // Return a weighted average of the fast and slow probes
    const float measured_z = (z2 * 3.0 + first_probe_z * 2.0) * 0.2;

  #else

    // Return the single probe result
    const float measured_z = current_position.z;

  #endif

  if (DEBUGGING(LEVELING)) DEBUG_POS("<<< run_z_probe", current_position);

  return measured_z;
}

/**
 * - Move to the given XY
 * - Deploy the probe, if not already deployed
 * - Probe the bed, get the Z position
 * - Depending on the 'stow' flag
 *   - Stow the probe, or
 *   - Raise to the BETWEEN height
 * - Return the probed Z position
 */
float Probe::probe_at_point(const float &rx, const float &ry, const ProbePtRaise raise_after/*=PROBE_PT_NONE*/, const uint8_t verbose_level/*=0*/, const bool probe_relative/*=true*/, const bool sanity_check/*=true*/) {
  if (DEBUGGING(LEVELING)) {
    DEBUG_ECHOLNPAIR(
      ">>> Probe::probe_at_point(", LOGICAL_X_POSITION(rx), ", ", LOGICAL_Y_POSITION(ry),
      ", ", raise_after == PROBE_PT_RAISE ? "raise" : raise_after == PROBE_PT_STOW ? "stow" : "none",
      ", ", int(verbose_level),
      ", ", probe_relative ? "probe" : "nozzle", "_relative)"
    );
    DEBUG_POS("", current_position);
  }

  // TODO: Adapt for SCARA, where the offset rotates
  xyz_pos_t npos = { rx, ry };
  if (probe_relative) {                                     // The given position is in terms of the probe
    if (!can_reach(npos)) {
      if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("Position Not Reachable");
      return NAN;
    }
    npos -= offset_xy;                                      // Get the nozzle position
  }
  else if (!position_is_reachable(npos)) return NAN;        // The given position is in terms of the nozzle

  npos.z =
    #if ENABLED(DELTA)
      // Move below clip height or xy move will be aborted by do_blocking_move_to
      _MIN(current_position.z, delta_clip_start_height)
    #else
      current_position.z
    #endif
  ;

  const float old_feedrate_mm_s = feedrate_mm_s;
  feedrate_mm_s = XY_PROBE_FEEDRATE_MM_S;

  // Move the probe to the starting XYZ
  do_blocking_move_to(npos);

  float measured_z = NAN;
  if (!deploy()) measured_z = run_z_probe(sanity_check) + offset.z;
  if (!isnan(measured_z)) {
    const bool big_raise = raise_after == PROBE_PT_BIG_RAISE;
    if (big_raise || raise_after == PROBE_PT_RAISE)
      do_blocking_move_to_z(current_position.z + (big_raise ? 25 : Z_CLEARANCE_BETWEEN_PROBES), MMM_TO_MMS(Z_PROBE_SPEED_FAST));
    else if (raise_after == PROBE_PT_STOW)
      if (stow()) measured_z = NAN;   // Error on stow?

    if (verbose_level > 2) {
      SERIAL_ECHOPAIR_F("Bed X: ", LOGICAL_X_POSITION(rx), 3);
      SERIAL_ECHOPAIR_F(   " Y: ", LOGICAL_Y_POSITION(ry), 3);
      SERIAL_ECHOLNPAIR_F( " Z: ", measured_z, 3);
    }
  }

  feedrate_mm_s = old_feedrate_mm_s;

  if (isnan(measured_z)) {
    stow();
    // LCD_MESSAGEPGM(MSG_LCD_PROBING_FAILED);
    SERIAL_ERROR_MSG(STR_ERR_PROBING_FAILED);
  }

  if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("<<< Probe::probe_at_point");

  return measured_z;
}

#endif // HAS_BED_PROBE
