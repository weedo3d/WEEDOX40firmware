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
 * G29.cpp - Auto Bed Leveling
 */

#include "../../../inc/MarlinConfig.h"

#if HAS_ABL_NOT_UBL

#include "../../gcode.h"
#include "../../../feature/bedlevel/bedlevel.h"
#include "../../../module/motion.h"
#include "../../../module/planner.h"
#include "../../../module/stepper.h"
#include "../../../module/probe.h"
#include "../../queue.h"
#include "../../../module/endstops.h"
#include "../../../module/printcounter.h"

#if ENABLED(POWER_LOSS_RECOVERY)
  #include "../../feature/powerloss.h"
#endif

#define DEBUG_OUT ENABLED(DEBUG_LEVELING_FEATURE)
#include "../../../core/debug_out.h"

#if HOTENDS > 1
  #include "../../../module/tool_change.h"
#endif

#if ABL_GRID
  #if ENABLED(PROBE_Y_FIRST)
    #define PR_OUTER_VAR meshCount.x
    #define PR_OUTER_END abl_grid_points.x
    #define PR_INNER_VAR meshCount.y
    #define PR_INNER_END abl_grid_points.y
  #else
    #define PR_OUTER_VAR meshCount.y
    #define PR_OUTER_END abl_grid_points.y
    #define PR_INNER_VAR meshCount.x
    #define PR_INNER_END abl_grid_points.x
  #endif
#endif

#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_RETURN(b) return b;
#else
  #define G29_RETURN(b) return;
#endif

/**
 * G29: Detailed Z probe, probes the bed at 3 or more points.
 *      Will fail if the printer has not been homed with G28.
 *
 * Enhanced G29 Auto Bed Leveling Probe Routine
 *
 *  O  Auto-level only if needed
 *
 *  D  Dry-Run mode. Just evaluate the bed Topology - Don't apply
 *     or alter the bed level data. Useful to check the topology
 *     after a first run of G29.
 *
 *  J  Jettison current bed leveling data
 *
 *  V  Set the verbose level (0-4). Example: "G29 V3"
 *
 * Parameters With LINEAR leveling only:
 *
 *  P  Set the size of the grid that will be probed (P x P points).
 *     Example: "G29 P4"
 *
 *  X  Set the X size of the grid that will be probed (X x Y points).
 *     Example: "G29 X7 Y5"
 *
 *  Y  Set the Y size of the grid that will be probed (X x Y points).
 *
 *  T  Generate a Bed Topology Report. Example: "G29 P5 T" for a detailed report.
 *     This is useful for manual bed leveling and finding flaws in the bed (to
 *     assist with part placement).
 *     Not supported by non-linear delta printer bed leveling.
 *
 * Parameters With LINEAR and BILINEAR leveling only:
 *
 *  S  Set the XY travel speed between probe points (in units/min)
 *
 *  H  Set bounds to a centered square H x H units in size
 *
 *     -or-
 *
 *  F  Set the Front limit of the probing grid
 *  B  Set the Back limit of the probing grid
 *  L  Set the Left limit of the probing grid
 *  R  Set the Right limit of the probing grid
 *
 * Parameters with DEBUG_LEVELING_FEATURE only:
 *
 *  C  Make a totally fake grid with no actual probing.
 *     For use in testing when no probing is possible.
 *
 * Parameters with BILINEAR leveling only:
 *
 *  Z  Supply an additional Z probe offset
 *
 * Extra parameters with PROBE_MANUALLY:
 *
 *  To do manual probing simply repeat G29 until the procedure is complete.
 *  The first G29 accepts parameters. 'G29 Q' for status, 'G29 A' to abort.
 *
 *  Q  Query leveling and G29 state
 *
 *  A  Abort current leveling procedure
 *
 * Extra parameters with BILINEAR only:
 *
 *  W  Write a mesh point. (If G29 is idle.)
 *  I  X index for mesh point
 *  J  Y index for mesh point
 *  X  X for mesh point, overrides I
 *  Y  Y for mesh point, overrides J
 *  Z  Z for mesh point. Otherwise, raw current Z.
 *
 * Without PROBE_MANUALLY:
 *
 *  E  By default G29 will engage the Z probe, test the bed, then disengage.
 *     Include "E" to engage/disengage the Z probe for each sample.
 *     There's no extra effect if you have a fixed Z probe.
 *
 */
G29_TYPE GcodeSuite::G29()
{

#if EITHER(DEBUG_LEVELING_FEATURE, PROBE_MANUALLY)
  const bool seenQ = parser.seen('Q');
#else
  constexpr bool seenQ = false;
#endif

  // G29 Q is also available if debugging
#if ENABLED(DEBUG_LEVELING_FEATURE)
  const uint8_t old_debug_flags = marlin_debug_flags;
  if (seenQ) marlin_debug_flags |= MARLIN_DEBUG_LEVELING;
  if (DEBUGGING(LEVELING)) {
    DEBUG_POS(">>> G29", current_position);
    log_machine_info();
  }
  marlin_debug_flags = old_debug_flags;
#if DISABLED(PROBE_MANUALLY)
  if (seenQ) G29_RETURN(false);
#endif
#endif

  constexpr bool seenA = false;

  const bool  no_action = seenA || seenQ,
              faux =
#if ENABLED(DEBUG_LEVELING_FEATURE) && DISABLED(PROBE_MANUALLY)
                parser.boolval('C')
#else
                no_action
#endif
                ;

  // Don't allow auto-leveling without homing first
  if (axis_unhomed_error()) G29_RETURN(false);

  if (!no_action && planner.leveling_active && parser.boolval('O')) { // Auto-level only if needed
    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("> Auto-level not needed, skip\n<<< G29");
    G29_RETURN(false);
  }

  // Define local vars 'static' for manual probing, 'auto' otherwise
#define ABL_VAR

  ABL_VAR int verbose_level;
  ABL_VAR xy_pos_t probePos;
  ABL_VAR float measured_z;
  ABL_VAR bool dryrun, abl_should_enable;


  ABL_VAR xy_pos_t probe_position_lf, probe_position_rb;
  ABL_VAR xy_float_t gridSpacing = { 0, 0 };

  constexpr xy_uint8_t abl_grid_points = { GRID_MAX_POINTS_X, GRID_MAX_POINTS_Y };

  ABL_VAR float zoffset;

  /**
   * On the initial G29 fetch command parameters.
   */
  if (!g29_in_progress) {

#if HOTENDS > 1
    if (active_extruder != 0) tool_change(0);
#endif

    abl_should_enable = planner.leveling_active;

    const bool seen_w = parser.seen('W');
    if (seen_w) {
      if (!leveling_is_valid()) {
        SERIAL_ERROR_MSG("No bilinear grid");
        G29_RETURN(false);
      }

      const float rz = parser.seenval('Z') ? RAW_Z_POSITION(parser.value_linear_units()) : current_position.z;
      if (!WITHIN(rz, -10, 10)) {
        SERIAL_ERROR_MSG("Bad Z value");
        G29_RETURN(false);
      }

      const float rx = RAW_X_POSITION(parser.linearval('X', NAN)),
                  ry = RAW_Y_POSITION(parser.linearval('Y', NAN));
      int8_t i = parser.byteval('I', -1), j = parser.byteval('J', -1);

      if (!isnan(rx) && !isnan(ry)) {
        // Get nearest i / j from rx / ry
        i = (rx - bilinear_start.x + 0.5 * gridSpacing.x) / gridSpacing.x;
        j = (ry - bilinear_start.y + 0.5 * gridSpacing.y) / gridSpacing.y;
        LIMIT(i, 0, GRID_MAX_POINTS_X - 1);
        LIMIT(j, 0, GRID_MAX_POINTS_Y - 1);
      }
      if (WITHIN(i, 0, GRID_MAX_POINTS_X - 1) && WITHIN(j, 0, GRID_MAX_POINTS_Y)) {
        set_bed_leveling_enabled(false);
        z_values[i][j] = rz;
#if ENABLED(ABL_BILINEAR_SUBDIVISION)
        bed_level_virt_interpolate();
#endif
        set_bed_leveling_enabled(abl_should_enable);
        if (abl_should_enable) report_current_position();
      }
      G29_RETURN(false);
    } // parser.seen('W')


    // Jettison bed leveling data
    if (!seen_w && parser.seen('J')) {
      reset_bed_level();
      G29_RETURN(false);
    }

    verbose_level = parser.intval('V');
    if (!WITHIN(verbose_level, 0, 4)) {
      SERIAL_ECHOLNPGM("?(V)erbose level implausible (0-4).");
      G29_RETURN(false);
    }

    dryrun = parser.boolval('D')
#if ENABLED(PROBE_MANUALLY)
             || no_action
#endif
             ;

    zoffset = parser.linearval('Z');


    xy_probe_feedrate_mm_s = MMM_TO_MMS(parser.linearval('S', XY_PROBE_SPEED));

    const float x_min = probe.min_x(), x_max = probe.max_x(),
                y_min = probe.min_y(), y_max = probe.max_y();

    if (parser.seen('H')) {
      const int16_t size = (int16_t)parser.value_linear_units();
      probe_position_lf.set(
        _MAX(X_CENTER - size / 2, x_min),
        _MAX(Y_CENTER - size / 2, y_min)
      );
      probe_position_rb.set(
        _MIN(probe_position_lf.x + size, x_max),
        _MIN(probe_position_lf.y + size, y_max)
      );
    } else {
      probe_position_lf.set(
        parser.seenval('L') ? RAW_X_POSITION(parser.value_linear_units()) : x_min,
        parser.seenval('F') ? RAW_Y_POSITION(parser.value_linear_units()) : y_min
      );
      probe_position_rb.set(
        parser.seenval('R') ? RAW_X_POSITION(parser.value_linear_units()) : x_max,
        parser.seenval('B') ? RAW_Y_POSITION(parser.value_linear_units()) : y_max
      );
    }

    if (!probe.good_bounds(probe_position_lf, probe_position_rb)) {
      SERIAL_ECHOLNPGM("? (L,R,F,B) out of bounds.");
      G29_RETURN(false);
    }

    // probe at the points of a lattice grid
    gridSpacing.set((probe_position_rb.x - probe_position_lf.x) / (abl_grid_points.x - 1),
                    (probe_position_rb.y - probe_position_lf.y) / (abl_grid_points.y - 1));


    if (verbose_level > 0) {
      SERIAL_ECHOPGM("G29 Auto Bed Leveling");
      if (dryrun) SERIAL_ECHOPGM(" (DRYRUN)");
      SERIAL_EOL();
    }

    planner.synchronize();

    // Disable auto bed leveling during G29.
    // Be formal so G29 can be done successively without G28.
    if (!no_action) set_bed_leveling_enabled(false);

#if HAS_BED_PROBE
    // Deploy the probe. Probe will raise if needed.
    if (probe.deploy()) {
      set_bed_leveling_enabled(abl_should_enable);
      G29_RETURN(false);
    }
#endif

    if (!faux) remember_feedrate_scaling_off();

#if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    if (gridSpacing != bilinear_grid_spacing || probe_position_lf != bilinear_start) {
      // Reset grid to 0.0 or "not probed". (Also disables ABL)
      reset_bed_level();

      // Initialize a grid with the given dimensions
      bilinear_grid_spacing = gridSpacing;
      bilinear_start = probe_position_lf;

      // Can't re-enable (on error) until the new grid is written
      abl_should_enable = false;
    }

#endif // AUTO_BED_LEVELING_BILINEAR


  } // !g29_in_progress


  const ProbePtRaise raise_after = parser.boolval('E') ? PROBE_PT_STOW : PROBE_PT_RAISE;

  measured_z = 0;

  bool zig = PR_OUTER_END & 1;  // Always end at RIGHT and BACK_PROBE_BED_POSITION

  measured_z = 0;

  xy_int8_t meshCount;

  // Outer loop is X with PROBE_Y_FIRST enabled
  // Outer loop is Y with PROBE_Y_FIRST disabled
  for (PR_OUTER_VAR = 0; PR_OUTER_VAR < PR_OUTER_END && !isnan(measured_z); PR_OUTER_VAR++) {

    int8_t inStart, inStop, inInc;

    if (zig) {                    // Zig away from origin
      inStart = 0;                // Left or front
      inStop = PR_INNER_END;      // Right or back
      inInc = 1;                  // Zig right
    } else {                      // Zag towards origin
      inStart = PR_INNER_END - 1; // Right or back
      inStop = -1;                // Left or front
      inInc = -1;                 // Zag left
    }

    zig ^= true; // zag

    // An index to print current state
    uint8_t pt_index = (PR_OUTER_VAR) * (PR_INNER_END) + 1;

    // Inner loop is Y with PROBE_Y_FIRST enabled
    // Inner loop is X with PROBE_Y_FIRST disabled
    for (PR_INNER_VAR = inStart; PR_INNER_VAR != inStop; pt_index++, PR_INNER_VAR += inInc) {

      probePos = probe_position_lf + gridSpacing * meshCount.asFloat();

      if (verbose_level) SERIAL_ECHOLNPAIR("Probing mesh point ", int(pt_index), "/", int(GRID_MAX_POINTS), ".");

      measured_z = faux ? 0.001f * random(-100, 101) : probe.probe_at_point(probePos, raise_after, verbose_level);

      if (isnan(measured_z)) {
        set_bed_leveling_enabled(abl_should_enable);
        break; // Breaks out of both loops
      }

      z_values[meshCount.x][meshCount.y] = measured_z + zoffset;


      abl_should_enable = false;
      idle();

    } // inner
  } // outer


  // Stow the probe. No raise for FIX_MOUNTED_PROBE.
  if (probe.stow()) {
    set_bed_leveling_enabled(abl_should_enable);
    measured_z = NAN;
  }


  //
  // G29 Finishing Code
  //
  // Unless this is a dry run, auto bed leveling will
  // definitely be enabled after this point.
  //
  // If code above wants to continue leveling, it should
  // return or loop before this point.
  //

  if (DEBUGGING(LEVELING)) DEBUG_POS("> probing complete", current_position);

#if ENABLED(PROBE_MANUALLY)
  g29_in_progress = false;
#if ENABLED(LCD_BED_LEVELING)
  ui.wait_for_move = false;
#endif
#endif

  // Calculate leveling, print reports, correct the position
  if (!isnan(measured_z)) {
    if (!dryrun) extrapolate_unprobed_bed_level();
    print_bilinear_leveling_grid();

    refresh_bed_level();

#if ENABLED(ABL_BILINEAR_SUBDIVISION)
    print_bilinear_leveling_grid_virt();
#endif


    if (!dryrun) {
      if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR("G29 uncorrected Z:", current_position.z);

      // Unapply the offset because it is going to be immediately applied
      // and cause compensation movement in Z
#if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
      const float fade_scaling_factor = planner.fade_scaling_factor_for_z(current_position.z);
#else
      constexpr float fade_scaling_factor = 1.0f;
#endif
      current_position.z -= fade_scaling_factor * bilinear_z_offset(current_position);

      if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR(" corrected Z:", current_position.z);
    }


    // Auto Bed Leveling is complete! Enable if possible.
    planner.leveling_active = dryrun ? abl_should_enable : true;
  } // !isnan(measured_z)

  // Restore state after probing
  if (!faux) restore_feedrate_and_scaling();

  // Sync the planner from the current_position
  if (planner.leveling_active) sync_plan_position();

#if HAS_BED_PROBE && defined(Z_AFTER_PROBING)
  probe.move_z_after_probing();
#endif

#ifdef Z_PROBE_END_SCRIPT
  if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR("Z Probe End Script: ", Z_PROBE_END_SCRIPT);
  planner.synchronize();
  process_subcommands_now_P(PSTR(Z_PROBE_END_SCRIPT));
#endif

  report_current_position();

  if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("<<< G29");

#if ENABLED(DUAL_X_CARRIAGE)
  // add by perron, 200813
  if (dxc_is_duplicating())
  {
      extruder_duplication_enabled = false;
      endstops.enable(true); 

      active_extruder = 0;
      homeaxis(X_AXIS);

      endstops.not_homing();
      
      if (card.flag.sdprinting)
      {
        bool fitness_error = false;    
        for (uint8_t _y = 0; _y <= 2; _y++)
        {
            float _ma =  max(max(z_values[0][_y], z_values[1][_y]), z_values[2][_y]);    
            float _mb =  min(min(z_values[0][_y], z_values[1][_y]), z_values[2][_y]);    
            if ((_ma - _mb) > 0.5)
            {
                fitness_error = true;
                break;
            }
        }
        if (fitness_error)
        {
            SERIAL_ECHOPGM("bed fitness error");
            SERIAL_EOL();

            card.pauseSDPrint();
	          print_job_timer.pause();
            #ifdef DGUS_LCD
            dgus.GotoFitnessErrorMenu();
            #endif
        }
      }
  }
#endif


  G29_RETURN(isnan(measured_z));
}

#endif // HAS_ABL_NOT_UBL
