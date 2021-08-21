/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../feature/powerloss.h"
#include "../../gcode/queue.h"
#include "../../gcode/gcode.h"
#include "WTDGUSScreen_ResumePrinting.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTGcodeinfo.h"
#include "../../wtlib/WTUtilty.h"
#include "../../wtlib/WTCMD.h"

#define RESUME_PREHEAT_TEMP		160

#ifdef DGUS_LCD

void DGUS_Screen_ResumePrinting::Init()
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString(ADDR_2BINFO_TITLE, MMSG_CONFIRM_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON1, MMSG_NO[wtvar_language], 20);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON2, MMSG_YES[wtvar_language], 20);
	dserial.SendLongString(ADDR_2BINFO_TEXT_LINE, MMSG_RESUME_LINE[wtvar_language], TEXTLEN_2BINFO_ITEM);

	state = DSEP_NOTHING;
	holdontime = getcurrenttime();
}

void DGUS_Screen_ResumePrinting::Update()
{
	char headgcode[MAX_CMD_SIZE + 16] = {0}, str_1[16], str_2[16];	// flchar[10] = {0};
    static uint32_t _spos;

	switch (state)
	{
	case DSEP_PREHEAT:
	{
        ShowRecoveryInfo();
        _spos = recovery.info.sdpos;
		SERIAL_ECHOLNPGM("preheat");
		HOTEND_LOOP()
		{
			thermalManager.setTargetHotend(RESUME_PREHEAT_TEMP, e);
		}

		state = DSEP_WAITPREHEAT;
	}
	break;

	case DSEP_WAITPREHEAT:
	{
		if (recovery.info.dual_mode == 0)
		{
			if ((thermalManager.degHotend(recovery.info.active_extruder) >= RESUME_PREHEAT_TEMP - 2) &&
				(thermalManager.degHotend(recovery.info.active_extruder) <= RESUME_PREHEAT_TEMP + 2))
			{
				SERIAL_ECHOLNPGM("homing");
				state = DSEP_HOMING;
			}
		}
		else
		{
			if ((thermalManager.degHotend(0) >= RESUME_PREHEAT_TEMP - 2) &&
				(thermalManager.degHotend(0) <= RESUME_PREHEAT_TEMP + 2) &&
				(thermalManager.degHotend(1) >= RESUME_PREHEAT_TEMP - 2) &&
				(thermalManager.degHotend(1) <= RESUME_PREHEAT_TEMP + 2))
			{
				SERIAL_ECHOLNPGM("homing");
				state = DSEP_HOMING;
			}
		}
	}
	break;

	case DSEP_HOMING:
	{
		queue.enqueue_now_P(PSTR("G28 R5 XY"));
		queue.enqueue_now_P(PSTR("M420 S1"));
        sprintf_P(headgcode, PSTR("T%i S"), recovery.info.active_extruder);
        queue.enqueue_one_now(headgcode);
		state = DSEP_WAITHOMING;
	}
	break;

	case DSEP_WAITHOMING:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			SERIAL_ECHOLNPGM("heating");
			state = DSEP_HEATING;
		}
	}
	break;

	case DSEP_HEATING:
	{
		HOTEND_LOOP()
		{
			thermalManager.setTargetHotend(recovery.info.target_temperature[e], e);
		}
#if HAS_HEATED_BED
		thermalManager.setTargetBed(recovery.info.target_temperature_bed);
#endif
		SERIAL_ECHOLNPGM("waitheating");
		state = DSEP_WAITHEATING;
	}
	break;

	case DSEP_WAITHEATING:
	{
		if (recovery.info.dual_mode == 0)
		{
			if ((thermalManager.degHotend(recovery.info.active_extruder) >= thermalManager.degTargetHotend(recovery.info.active_extruder) - 2) &&
				(thermalManager.degHotend(recovery.info.active_extruder) <= thermalManager.degTargetHotend(recovery.info.active_extruder) + 2) &&
				(thermalManager.degHotend(recovery.info.active_extruder) > 180))
			{
				SERIAL_ECHOLNPGM("extruding");
				state = DSEP_EXTRUDING;
			}
		}
		else
		{
			if ((thermalManager.degHotend(0) >= thermalManager.degTargetHotend(0) - 2) &&
				(thermalManager.degHotend(0) <= thermalManager.degTargetHotend(0) + 2) &&
				(thermalManager.degHotend(0) > 180) &&
				(thermalManager.degHotend(1) >= thermalManager.degTargetHotend(1) - 2) &&
				(thermalManager.degHotend(1) <= thermalManager.degTargetHotend(1) + 2) &&
				(thermalManager.degHotend(1) > 180))
			{
				SERIAL_ECHOLNPGM("extruding");
				state = DSEP_EXTRUDING;
			}
		}
	}
	break;

	case DSEP_EXTRUDING:
	{
		if (recovery.info.dual_mode == 0)
		{
			destination = current_position;
			destination.e += 20 / planner.e_factor[active_extruder];
			planner.buffer_line(destination, 3, active_extruder);
			current_position = destination;
		}
		else
		{
			destination = current_position;
			destination.e += 20 / planner.e_factor[0];
			planner.buffer_line(destination, 3, 0);
			current_position = destination;

			destination = current_position;
			destination.e += 20 / planner.e_factor[1];
			planner.buffer_line(destination, 3, 1);
			current_position = destination;
		}
		state = DSEP_WAITEXTRUDING;
	}
	break;

	case DSEP_WAITEXTRUDING:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			SERIAL_ECHOLNPGM("set dual mode");
			state = DSEP_DUALMODE;
		}
	}
	break;

	case DSEP_DUALMODE:
	{
		// Restore the dual mode
		if (recovery.info.dual_mode == 0)
		{
            queue.enqueue_now_P("M605 S1");
		}
		else if (recovery.info.dual_mode == 1)
		{
			// move_center();
            queue.enqueue_now_P("M605 S2");
            queue.enqueue_now_P("G28 X R0");
		}
		else
		{
			// move_center();
			queue.enqueue_now_P("M605 S2");
			queue.enqueue_now_P("M605 S3");
            queue.enqueue_now_P("G28 X R0");
		}
		wtvar_dual_mode = recovery.info.dual_mode;

		#if HAS_HOME_OFFSET
			home_offset = recovery.info.home_offset;
		#endif

		state = DSEP_WAITMODE;
	}
	break;

	case DSEP_WAITMODE:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			SERIAL_ECHOLNPGM("restore xy");
			state = DSEP_RESTOREPOSITION;
		}
	}
	break;

	case DSEP_RESTOREPOSITION:
	{

		// Move back to the saved XY
		sprintf_P(headgcode, PSTR("G1 X%s Y%s F3000"),
				  dtostrf(recovery.info.current_position.x, 1, 3, str_1),
				  dtostrf(recovery.info.current_position.y, 1, 3, str_2));
        queue.enqueue_one_now(headgcode);

        queue.enqueue_now_P(PSTR("G91"));
        queue.enqueue_now_P(PSTR("G1 Z-5 F500"));
        queue.enqueue_now_P(PSTR("G90"));

        sprintf_P(headgcode, PSTR("M420 S%i Z%s"), int(recovery.info.leveling), dtostrf(recovery.info.fade, 1, 1, str_1));
        queue.enqueue_one_now(headgcode);

		state = DSEP_WAITPOSITION;
	}
	break;

	case DSEP_WAITPOSITION:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			SERIAL_ECHOLNPGM("restore z");
			state = DSEP_RESTOREZ;
		}
	}
	break;
	

	case DSEP_RESTOREZ:
	{
		// Move back to the saved Z
		dtostrf(recovery.info.current_position.z, 1, 3, str_1);
#if Z_HOME_DIR > 0
		sprintf_P(headgcode, PSTR("G1 Z%s F500"), str_1);
#else
		// queue.enqueue_one_P("G1 Z0 F500");
		sprintf_P(headgcode, PSTR("G92.9 Z%s"), str_1);
#endif
		queue.enqueue_one_now(headgcode);

		// Restore the feedrate
		sprintf_P(headgcode, PSTR("G1 F%d"), recovery.info.feedrate);
		queue.enqueue_one_now(headgcode);

		// Restore E position with G92.9
		sprintf_P(headgcode, PSTR("G92.9 E%s"), dtostrf(recovery.info.current_position.e, 1, 3, str_1));
		queue.enqueue_one_now(headgcode);

		// Relative axis modes
		gcode.axis_relative = recovery.info.axis_relative;

		
		#if HAS_POSITION_SHIFT
			position_shift = recovery.info.position_shift;
		#endif
		#if HAS_HOME_OFFSET || HAS_POSITION_SHIFT
			LOOP_XYZ(i) update_workspace_offset((AxisEnum)i);
		#endif

		state = DSEP_WAITZ;
	}
	break;

	case DSEP_WAITZ:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			state = DSEP_OPENFILE;
			SERIAL_ECHOLNPGM("openfile");
		}
	}
	break;

	case DSEP_OPENFILE:
	{
        char *fn = recovery.info.sd_filename;

        // read gcode info
        dserial.JPG_Reset();
        gcodeinfo.parse(fn);

        if (gcodeinfo.info.b_image)
            gcodeinfo.load_jpg(gcodeinfo.info.filename);

		card.selectFileByName(fn);

		char filename_buffer[UNICODE_FILENAME_LENGTH];
		ZERO(filename_buffer);

		uint16_t _len = strlen(card.longFilename) * 2;
        if (_len > 0)
        {
            memcpy(filename_buffer, card.longlongFilename, _len);
        }
        else
        {
            _len = strlen(card.filename) * 2;
            ZERO(filename_buffer);
            Utf8ToUnicode(card.filename, filename_buffer);
        }
		
        if (_len > 0 && _len < UNICODE_FILENAME_LENGTH)
		    dgus.SetFileInfo(1, filename_buffer, _len);

		// Resume the SD file from the last position
		extern const char M23_STR[];
		sprintf_P(headgcode, M23_STR, fn);
        queue.enqueue_one_now(headgcode);

		sprintf_P(headgcode, PSTR("M24 S%ld T%ld"), _spos, recovery.info.print_job_elapsed);
        queue.enqueue_one_now(headgcode);

		state = DSEP_COMPLETE;
	}
	break;

	case DSEP_COMPLETE:
	{
		state = DSEP_NOTHING;
		dgus.GotoPrintingMenu();
	}
	break;

	default:
		break;
	}
}

void DGUS_Screen_ResumePrinting::KeyProcess()
{
	if (gltouchpara.address == ADDR_2BINFO_KEY)
	{
		gltouchpara.validflg = false;
		if (gltouchpara.value == KEY_2BINFO_ITEM1)
		{ // NO
			card.removeJobRecoveryFile();
			card.autostart_index = 0;
			dgus.GotoMain();
		}
		else if (gltouchpara.value == KEY_2BINFO_ITEM2)
		{ // YES
			state = DSEP_PREHEAT;
			dgus.ShowNoRetrunMessage(MMSG_RESUME_PRINTING[wtvar_language]);
		}
	}
}

void DGUS_Screen_ResumePrinting::ShowRecoveryInfo()
{
    SERIAL_ECHOLNPAIR(" Job Recovery Info...\nvalid_head:", int(recovery.info.valid_head), " valid_foot:", int(recovery.info.valid_foot));
    if (recovery.info.valid_head) {
      if (recovery.info.valid_head == recovery.info.valid_foot) {
        SERIAL_ECHOPGM("current_position: ");
        LOOP_XYZE(i) {
          if (i) SERIAL_CHAR(',');
          SERIAL_ECHO(recovery.info.current_position[i]);
        }
        SERIAL_EOL();

        #if HAS_HOME_OFFSET
          SERIAL_ECHOPGM("home_offset: ");
          LOOP_XYZ(i) {
            if (i) SERIAL_CHAR(',');
            SERIAL_ECHO(recovery.info.home_offset[i]);
          }
          SERIAL_EOL();
        #endif

        #if HAS_POSITION_SHIFT
          SERIAL_ECHOPGM("position_shift: ");
          LOOP_XYZ(i) {
            if (i) SERIAL_CHAR(',');
            SERIAL_ECHO(recovery.info.position_shift[i]);
          }
          SERIAL_EOL();
        #endif

        SERIAL_ECHOLNPAIR("feedrate: ", recovery.info.feedrate);

        #if EXTRUDERS > 1
          SERIAL_ECHOLNPAIR("active_extruder: ", int(recovery.info.active_extruder));
        #endif

        #if HOTENDS
          SERIAL_ECHOPGM("target_temperature: ");
          HOTEND_LOOP() {
            SERIAL_ECHO(recovery.info.target_temperature[e]);
            if (e < HOTENDS - 1) SERIAL_CHAR(',');
          }
          SERIAL_EOL();
        #endif

        #if HAS_HEATED_BED
          SERIAL_ECHOLNPAIR("target_temperature_bed: ", recovery.info.target_temperature_bed);
        #endif

        #if FAN_COUNT
          SERIAL_ECHOPGM("fan_speed: ");
          FANS_LOOP(i) {
            SERIAL_ECHO(int(recovery.info.fan_speed[i]));
            if (i < FAN_COUNT - 1) SERIAL_CHAR(',');
          }
          SERIAL_EOL();
        #endif

        #if HAS_LEVELING
          SERIAL_ECHOLNPAIR("leveling: ", int(recovery.info.leveling), "\n fade: ", int(recovery.info.fade));
        #endif

		if (recovery.info.dual_mode == 0)
		{
            SERIAL_ECHOLNPGM("Dual mode: normal");
		}
		else if (recovery.info.dual_mode == 1)
		{
			SERIAL_ECHOLNPGM("Dual mode: copy");
		}
		else
		{
			SERIAL_ECHOLNPGM("Dual mode: mirror");
		}

        SERIAL_ECHOLNPAIR("sd_filename: ", recovery.info.sd_filename);
        SERIAL_ECHOLNPAIR("sdpos: ", recovery.info.sdpos);
        SERIAL_ECHOLNPAIR("print_job_elapsed: ", recovery.info.print_job_elapsed);
      }
      else
        SERIAL_ECHOLNPGM("INVALID DATA");
    }
    SERIAL_ECHOLNPGM("---");
}
#endif