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
#pragma once

/**
 * feature/runout.h - Runout sensor support
 */

#include "../sd/cardreader.h"
#include "../module/printcounter.h"
#include "../module/planner.h"
#include "../module/stepper.h" // for block_t
#include "../gcode/queue.h"

#include "../inc/MarlinConfig.h"

#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #include "pause.h"
#endif

#define FILAMENT_RUNOUT_SENSOR_DEBUG
#ifndef FILAMENT_RUNOUT_THRESHOLD
  #define FILAMENT_RUNOUT_THRESHOLD 500
#endif

void event_filament_runout();

class RunoutResponseDebounced 
{
    private:
        static constexpr int16_t runout_threshold = FILAMENT_RUNOUT_THRESHOLD;
        static int16_t runout_count;
    public:
        static inline void reset()                                  { runout_count = runout_threshold; }
        static inline void run()                                    { if (runout_count >= 0) runout_count--; }
        static inline bool has_run_out()                            { return runout_count < 0; }
        static inline void block_completed(const block_t* const)    { }
        static inline void filament_present(const uint8_t)          { runout_count = runout_threshold; }
};

/**
 * This is a simple endstop switch in the path of the filament.
 * It can detect filament runout, but not stripouts or jams.
 */
class FilamentSensorSwitch  
{
private:
    static inline bool poll_runout_state(const uint8_t extruder) {
    const uint8_t runout_states = poll_runout_states();

    if (dual_x_carriage_mode == DXC_DUPLICATION_MODE || dual_x_carriage_mode == DXC_MIRRORED_MODE)
        return runout_states;               // Any extruder

    return TEST(runout_states, extruder); // Specific extruder
    }

public:
    static inline void setup() {
      #define _INIT_RUNOUT(N) SET_INPUT_PULLUP(FIL_RUNOUT##N##_PIN);
      REPEAT_S(1, INCREMENT(NUM_RUNOUT_SENSORS), _INIT_RUNOUT)
      #undef _INIT_RUNOUT
    }

    // Return a bitmask of runout pin states
    static inline uint8_t poll_runout_pins() {
      #define _OR_RUNOUT(N) | (READ(FIL_RUNOUT##N##_PIN) ? _BV((N) - 1) : 0)
      return (0 REPEAT_S(1, INCREMENT(NUM_RUNOUT_SENSORS), _OR_RUNOUT));
      #undef _OR_RUNOUT
    }

    // Return a bitmask of runout flag states (1 bits always indicates runout)
    static inline uint8_t poll_runout_states() {
      return (poll_runout_pins());
    }

    static void filament_present(const uint8_t extruder);

    static inline void block_completed(const block_t* const) {}

    static inline void run() {
    const bool out = poll_runout_state(active_extruder);
    if (!out) filament_present(active_extruder);
    #ifdef FILAMENT_RUNOUT_SENSOR_DEBUG
        static bool was_out = false;
        if (out != was_out) {
        was_out = out;
        PORT_REDIRECT(0);
        SERIAL_ECHOPGM("Filament ");
        serialprintPGM(out ? PSTR("OUT\n") : PSTR("IN\n"));
        PORT_RESTORE();
        }
    #endif
    }
};

class FilamentMonitor    
{
  private:
    static  RunoutResponseDebounced response;
    static  FilamentSensorSwitch sensor;
    
  public:
    static bool enabled, filament_ran_out;
    static  uint8_t last_active_extruder;

    #if ENABLED(HOST_ACTION_COMMANDS)
      static bool host_handling;
    #else
      static constexpr bool host_handling = false;
    #endif

    static inline void setup() 
    {
      sensor.setup();
      reset();
      last_active_extruder = active_extruder;
    }

    static inline void reset() 
    {
      filament_ran_out = false;
      response.reset();
    }

    // Call this method when filament is present,
    // so the response can reset its counter.
    static inline void filament_present(const uint8_t extruder) 
    {
      response.filament_present(extruder);
    }

    // Handle a block completion. RunoutResponseDelayed uses this to
    // add up the length of filament moved while the filament is out.
    static inline void block_completed(const block_t* const b) 
    {
      if (enabled) 
      {
        response.block_completed(b);
        sensor.block_completed(b);
      }
    }

    // Give the response a chance to update its counter.
    static inline void run() 
    {
      if (last_active_extruder != active_extruder)
        response.reset();

      if (enabled && !filament_ran_out && (printingIsActive() || did_pause_print)) 
      {
        response.run();
        sensor.run();
        const bool ran_out = response.has_run_out();
        if (ran_out) {
          filament_ran_out = true;
          event_filament_runout();
          planner.synchronize();
        }
      }
    }
};


extern FilamentMonitor runout;
