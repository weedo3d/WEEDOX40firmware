/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../feature/powerloss.h"
#include "../../module/printcounter.h"
#include "WTDGUSScreen_SavePrinting.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCMD.h"

extern xyze_pos_t resume_position;

#ifdef DGUS_LCD

void DGUS_Screen_SavePrinting::Init()
{
	dgus.ShowNoRetrunMessage(MMSG_SAVE_PRINTING[wtvar_language]);
	state = DSSP_CHKSTS;
	holdontime = getcurrenttime();
}

void DGUS_Screen_SavePrinting::Update()
{
	// uint8_t indextmp, filenamelen, *pdatatmp;
	switch (state)
	{
	case DSSP_NOTHING:
		break;

	case DSSP_CHKSTS:
	{
		if (card.flag.sdprinting)
			state = DSSP_PAUSEDSD;
		else
			state = DSSP_HASPAUSED;

		// Head and foot will match if valid data was saved
		if (!++recovery.info.valid_head) ++recovery.info.valid_head; // non-zero in sequence
		recovery.info.valid_foot = recovery.info.valid_head;

	}
	break;

	case DSSP_PAUSEDSD:
	{
		card.pauseSDPrint();
		state = DSSP_WAITCLEARBUF;
	}
	break;

	case DSSP_WAITCLEARBUF:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			// Machine state
			recovery.info.current_position = current_position;
            #if HAS_HOME_OFFSET
            recovery.info.home_offset = home_offset;
            #endif
			state = DSSP_GOSETPOS;
		}
	}
	break;

	case DSSP_HASPAUSED:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			// Machine state
			recovery.info.current_position = resume_position;
			state = DSSP_GOSETPOS;
		}
	}
	break;

	case DSSP_GOSETPOS:
	{
		queue.enqueue_now_P(PSTR("G28 R0 XY"));
		state = DSSP_WAITPOS;
	}
	break;

	case DSSP_WAITPOS:
	{
		if ((planner.has_blocks_queued() == false) && (queue.length == 0))
		{
			state = DSSP_SAVEPARA;
		}
	}
	break;

	case DSSP_SAVEPARA:
	{
        // #if EXTRUDERS > 1
		// recovery.info.active_hotend = active_extruder;
        // #endif

		#if EXTRUDERS
        HOTEND_LOOP() recovery.info.target_temperature[e] = thermalManager.temp_hotend[e].target;
        #endif

		#if HAS_HEATED_BED
        recovery.info.target_temperature_bed = thermalManager.temp_bed.target;
        #endif

		// Commands in the queue
		// recovery.info.cmd_queue_index_r = 0;
		// recovery.info.queue.length = 0;

        #if FAN_COUNT
        COPY(recovery.info.fan_speed, thermalManager.fan_speed);
        #endif

		// Elapsed print job time
		recovery.info.print_job_elapsed = print_job_timer.duration();

		// dual mode
		recovery.info.dual_mode = wtvar_dual_mode;

		// SD file position
		card.getAbsFilename(recovery.info.sd_filename);
		recovery.info.sdpos = card.getIndex();

		card.openJobRecoveryFile(false);
		(void)card.saveJobRecoveryInfo();
	
		state = DSSP_SHUTNOW;

	}
	break;

	case DSSP_SHUTNOW:
	{
		wt_PowerOff();
	}
	break;

	default:
		break;
	}
}

void DGUS_Screen_SavePrinting::KeyProcess()
{
	// do nothing
}

#endif