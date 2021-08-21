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

#include "../../inc/MarlinConfig.h"

#if HAS_HOTEND_OFFSET

#include "../gcode.h"
#include "../../module/motion.h"

#if ENABLED(DELTA)
  #include "../../module/planner.h"
#endif

extern uint8_t wtvar_tune_x1;
extern uint8_t wtvar_tune_x2;
extern uint8_t wtvar_tune_y1;
extern uint8_t wtvar_tune_y2;

/**
 * M218 - set hotend offset (in linear units)
 *
 *   T<tool>
 *   X<xoffset>
 *   Y<yoffset>
 *   Z<zoffset>
 */
void GcodeSuite::M218() {

  const int8_t target_extruder = get_target_extruder_from_command();
  if (target_extruder < 0) return;

  if (parser.seenval('X')) 
  {
      hotend_offset[target_extruder].x = parser.value_linear_units();

      // perron 200824
      if (target_extruder == 1)
      {
        wtvar_tune_x1 = (uint8_t)((int)(hotend_offset[1].x + 0.5) - T1_OFFSET_X) + 3;
        if (wtvar_tune_x1 > 5) wtvar_tune_x1 = 5;
        if (wtvar_tune_x1 <1) wtvar_tune_x1 = 1;

        wtvar_tune_x2 = (uint8_t)(((float)((float)hotend_offset[1].x - (int)(hotend_offset[1].x + 0.5))) * 10 + 5.5);
        if (wtvar_tune_x2 > 10) wtvar_tune_x2 -= 10;
        if (wtvar_tune_x2 > 10) wtvar_tune_x2 = 10;
        if (wtvar_tune_x2 < 1) wtvar_tune_x2 = 1;

        hotend_offset[1].x = T1_OFFSET_X + (wtvar_tune_x1 - 3) + ((float)wtvar_tune_x2 - 5) / 10;
      }
  }

  if (parser.seenval('Y'))
  {
      hotend_offset[target_extruder].y = parser.value_linear_units();

      // perron 200824
      if (target_extruder == 1)
      {
        wtvar_tune_y1 = (uint8_t)(hotend_offset[1].y + 3.4);

        if (wtvar_tune_y1 > 5) wtvar_tune_y1 = 5;
        if (wtvar_tune_y1 <1) wtvar_tune_y1 = 1;

        wtvar_tune_y2 = (uint8_t)(((float)((float)hotend_offset[1].y - (int)(hotend_offset[1].y + 0.5))) * 10 + 5.5);
        if (wtvar_tune_y2 > 10) wtvar_tune_y2 -= 10;
        if (wtvar_tune_y2 > 10) wtvar_tune_y2 = 10;
        if (wtvar_tune_y2 < 1) wtvar_tune_y2 = 1;

        hotend_offset[1].y = (wtvar_tune_y1 - 3) + ((float)wtvar_tune_y2 - 5) / 10;
      }
  }

  if (parser.seenval('Z')) hotend_offset[target_extruder].z = parser.value_linear_units();

  if (!parser.seen("XYZ")) {
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM(STR_HOTEND_OFFSET);
    HOTEND_LOOP() {
      SERIAL_CHAR(' ');
      SERIAL_ECHO(hotend_offset[e].x);
      SERIAL_CHAR(',');
      SERIAL_ECHO(hotend_offset[e].y);
      SERIAL_CHAR(',');
      SERIAL_ECHO_F(hotend_offset[e].z, 3);
    }
    SERIAL_EOL();
  }

  #if ENABLED(DELTA)
    if (target_extruder == active_extruder)
      do_blocking_move_to_xy(current_position, planner.settings.max_feedrate_mm_s[X_AXIS]);
  #endif
}

#endif // HAS_HOTEND_OFFSET
