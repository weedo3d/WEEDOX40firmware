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
#include "WTDGUSScreen_NozzleZ.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD
// 自动调平菜单 
void DGUS_Screen_Nozzle_Z::Init()
{
    pageid = 1;
    ShowPage();

    updaterate = 200;
	holdontime = getcurrenttime();
    status = NSE_STEP1_INPUT;
    zoffset_current = 0;
    ShowZOffset();
}

void DGUS_Screen_Nozzle_Z::manual_move_to_current(AxisEnum axis)
{
	manual_move_start_time = millis();
	manual_move_axis = (int8_t)axis;
}

void DGUS_Screen_Nozzle_Z::manage_manual_move() 
{
	if (manual_move_axis != (int8_t)NO_AXIS && ELAPSED(millis(), manual_move_start_time) && !planner.is_full()) 
	{
		planner.buffer_line(current_position, planner.settings.max_feedrate_mm_s[Z_AXIS], active_extruder);
		manual_move_axis = (int8_t)NO_AXIS;
	}
}

void DGUS_Screen_Nozzle_Z::Update()
{
    if (status == NSE_STEP2_MOVING)
    {
        if (planner.has_blocks_queued() == false)
        {
            status = NSE_STEP2_INPUT;
            ShowPage();
        }
    }
    else if (status == NSE_STEP2_INPUT)
    {
        manage_manual_move();
    }
    else if (status == NSE_STEP3_MOVING)
    {
        if (planner.has_blocks_queued() == false)
        {
            status = NSE_STEP3_INPUT;
            ShowPage();
        }
    }
    else if (status == NSE_STEP4_MOVING)
    {
        if (planner.has_blocks_queued() == false)
        {
            status = NSE_STEP4_INPUT;
            ShowPage();
        }
    }
}

void DGUS_Screen_Nozzle_Z::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_PICHELP_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_PICHELP_BUTTON1)
			{
				End();
			}
			else if (gltouchpara.value == KEY_PICHELP_BUTTON2)
			{
				if (pageid == 1)
				{
					pageid = 2;
                    status = NSE_STEP2_MOVING;
					dgus.ShowMovingMessage();
                    queue.enqueue_one_now("G28");
                    queue.enqueue_one_now("G29");
                    queue.enqueue_one_now("G1 X125 Y150 F3000");
                    queue.enqueue_one_now("M605 S0");
                    queue.enqueue_one_now("T1");
                    queue.enqueue_one_now("G1 X175 F3000");
                    queue.enqueue_one_now("G1 Z0 F200");
				}
				else if (pageid == 3)
				{
                    pageid = 4;
                    dgus.ShowMovingMessage();
                    move_to_z(zoffset_current + 5.0);
                    queue.enqueue_one_now("G28 X R0");
                    queue.enqueue_one_now("T0");
                    queue.enqueue_one_now("G1 X120 F3000");
                    move_to_z(zoffset_current + 0.3);
                    status = NSE_STEP4_MOVING;
				}
				else if (pageid == 4)
				{
					End();
				}
			}
		}
		else if (gltouchpara.address == ADDR_ZOFFSET_KEY)
		{
            gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_ZOFFSET_RETURN)
			{
				End();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_SAVE)
			{
                pageid = 3;
				dgus.ShowMovingMessage();
                move_to_z(zoffset_current + 5.0);
                queue.enqueue_one_now("G28 X R0");
                queue.enqueue_one_now("T1");
                queue.enqueue_one_now("G1 X120 F3000");
                move_to_z(zoffset_current + 0.3);
                status = NSE_STEP3_MOVING;
			}
			else if (gltouchpara.value == KEY_ZOFFSET_DEC)
			{
				zoffset_current -= 0.1;
				current_position[Z_AXIS] -= 0.1;
				manual_move_to_current(Z_AXIS);
				ShowZOffset();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_ADD)
			{
				zoffset_current += 0.1;
				current_position[Z_AXIS] += 0.1;
				manual_move_to_current(Z_AXIS);
				ShowZOffset();
			}
			
		}

	}
}

void DGUS_Screen_Nozzle_Z::ShowPage(void)
{
    if (pageid == 1)
	{
		dserial.LoadScreen(SCREEN_PICHELP);
		dserial.SendString(ADDR_PICHELP_TEXT_TITLE, MMSG_NOZZLE_Z_TITLE[wtvar_language], TEXTLEN_PICHELP_TITLE);
		dserial.SendString(ADDR_PICHELP_TEXT_BUTTON1, MMSG_EXIT[wtvar_language], TEXTLEN_PICHELP_BUTTON);
		dserial.SendString(ADDR_PICHELP_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], TEXTLEN_PICHELP_BUTTON);
		dserial.SendLongString(ADDR_PICHELP_TEXT_LINE1, MMSG_NOZZLE_Z_TEXT1[wtvar_language], TEXTLEN_PICHELP_ITEM);

		dserial.SendInt16(ADDR_PICHELP_ICON, 1);
	}
    else if (pageid == 2)
    {
        dserial.LoadScreen(SCREEN_ZOFFSET);
        dserial.SendString(ADDR_ZOFFSET_TEXT_TITLE, MMSG_NOZZLE_Z_TITLE[wtvar_language], TEXTLEN_ZOFFSET_TITLE);
        dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON1, MMSG_EXIT[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
        dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
        dserial.SendLongString_P(ADDR_ZOFFSET_TEXT_LINE, MMSG_NOZZLE_Z_TEXT2[wtvar_language], TEXTLEN_ZOFFSET_LINE);

    }
	else if (pageid == 3)
	{
		dserial.LoadScreen(SCREEN_PICHELP);
		dserial.SendString(ADDR_PICHELP_TEXT_TITLE, MMSG_NOZZLE_Z_TITLE[wtvar_language], TEXTLEN_PICHELP_TITLE);
		dserial.SendString(ADDR_PICHELP_TEXT_BUTTON1, MMSG_EXIT[wtvar_language], TEXTLEN_PICHELP_BUTTON);
		dserial.SendString(ADDR_PICHELP_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], TEXTLEN_PICHELP_BUTTON);
		dserial.SendLongString(ADDR_PICHELP_TEXT_LINE1, MMSG_NOZZLE_Z_TEXT3[wtvar_language], TEXTLEN_PICHELP_ITEM);

		dserial.SendInt16(ADDR_PICHELP_ICON, 2);
	}
	else if (pageid == 4)
	{
        dserial.LoadScreen(SCREEN_PICHELP);
		dserial.SendString(ADDR_PICHELP_TEXT_BUTTON2, MMSG_END[wtvar_language], TEXTLEN_PICHELP_BUTTON);
		dserial.SendLongString(ADDR_PICHELP_TEXT_LINE1, MMSG_NOZZLE_Z_TEXT4[wtvar_language], TEXTLEN_PICHELP_ITEM);

		dserial.SendInt16(ADDR_PICHELP_ICON, 3);
        
	}
}

void DGUS_Screen_Nozzle_Z::ShowZOffset(void)
{
	dserial.SendFloatString(ADDR_ZOFFSET_TEXT_VALUE, zoffset_current);
}

void DGUS_Screen_Nozzle_Z::move_to_z(float value)
{
    char buffer[50];
    ZERO(buffer);
    sprintf(buffer, "G1 Z%.2f F300", value);
    queue.enqueue_one_now(buffer);
}

void DGUS_Screen_Nozzle_Z::End(void)
{
    queue.enqueue_one_now("G28 X R20");
    queue.enqueue_one_now("M605 S1");
    queue.enqueue_one_now("M18");
    Goback();
}

#endif