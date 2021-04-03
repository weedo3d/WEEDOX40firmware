/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/configuration_store.h"
#include "../../module/probe.h"
#include "WTDGUSScreen_ZOffset.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD
void DGUS_Screen_ZOffset::manual_move_to_current(AxisEnum axis)
{
	manual_move_start_time = millis();
	manual_move_axis = (int8_t)axis;
}

void DGUS_Screen_ZOffset::manage_manual_move() 
{

	if (manual_move_axis != (int8_t)NO_AXIS && ELAPSED(millis(), manual_move_start_time) && !planner.is_full()) 
	{
		planner.buffer_line(current_position, planner.settings.max_feedrate_mm_s[Z_AXIS], active_extruder);
		manual_move_axis = (int8_t)NO_AXIS;
	}
}

// 自动调平菜单 
void DGUS_Screen_ZOffset::Init()
{
	dgus.ShowMovingMessage();
	queue.enqueue_one_now("G28");
	queue.enqueue_one_now("G29");
	queue.enqueue_one_now("G1 X150 Y150 F3000");
	queue.enqueue_one_now("G1 Z0 F200");

	dserial.SendString(ADDR_ZOFFSET_TEXT_TITLE, MMSG_ZOFFSET_TITLE[wtvar_language], TEXTLEN_ZOFFSET_TITLE);
	dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
	dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON2, MMSG_SAVE[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
	dserial.SendLongString_P(ADDR_ZOFFSET_TEXT_LINE, MMSG_ZOFFSET_LINE[wtvar_language], TEXTLEN_ZOFFSET_LINE);

	holdontime = getcurrenttime();
	updaterate = 200;
	zState = ZOSE_BEGIN;
	zoffset_current = probe.offset.z;
	manual_move_start_time = 0;
	manual_move_axis = (int8_t)NO_AXIS;
	ShowZOffset();
}

void DGUS_Screen_ZOffset::Update()
{
	switch (zState)
	{
	case ZOSE_BEGIN:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_ZOFFSET);
			zState = ZOSE_INPUT;
			zoffset_beginZpos = current_position[Z_AXIS];
		}
	}
	break;

	case ZOSE_INPUT:
		manage_manual_move();
		break;

	default:
		break;
	}
}

void DGUS_Screen_ZOffset::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_ZOFFSET_KEY)
		{
			if (gltouchpara.value == KEY_ZOFFSET_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_SAVE)
			{
				probe.offset.z = zoffset_current;
				(void)settings.save();
				// queue.enqueue_one_now(PSTR("G28"));
				queue.enqueue_one_now("G1 Z200 F2000");
				Goback();

			}
			else if (gltouchpara.value == KEY_ZOFFSET_DEC)
			{
				zoffset_current -= 0.1;
				if (zoffset_current >= -9.9) 
					current_position[Z_AXIS] -= 0.1;
				else
					zoffset_current = -9.9;
				manual_move_to_current(Z_AXIS);
				ShowZOffset();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_ADD)
			{
				zoffset_current += 0.1;
				if (zoffset_current <= 9.9)
					current_position[Z_AXIS] += 0.1;
				else
					zoffset_current = 9.9;
				manual_move_to_current(Z_AXIS);
				ShowZOffset();
			}
			
		}
		gltouchpara.validflg = false;
	}
}

void DGUS_Screen_ZOffset::ShowZOffset(void)
{
	dserial.SendFloatString(ADDR_ZOFFSET_TEXT_VALUE, zoffset_current);
}

#endif