/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../gcode/queue.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Filament.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCMD.h"

#define ACTIVE_LEFT     0
#define ACTIVE_RIGHT    1

#ifdef DGUS_LCD

void DGUS_Screen_Filament::Init()
{
	dserial.LoadScreen(SCREEN_LANGUAGE_SETTING);
	dserial.SendString(ADDR_LANG_TITLE, MMSG_FILAMENT_TYPE_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_LANG_BACK_TEXT, MMSG_BACK[wtvar_language], 20);
	dserial.SendString(ADDR_LANG_PRE_TEXT, MMSG_EMPTY, 20);
	dserial.SendString(ADDR_LANG_NEXT_TEXT, MMSG_EMPTY, 20);
	dserial.SendInt16(ADDR_TF_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_LANG_ITEM1_TEXT, MMSG_FILAMENT_TYPE_NAME1, 30);
	dserial.SendString(ADDR_LANG_ITEM2_TEXT, MMSG_FILAMENT_TYPE_NAME2, 30);
	dserial.SendString(ADDR_LANG_ITEM3_TEXT, MMSG_FILAMENT_TYPE_NAME4, 30);
	dserial.SendString(ADDR_LANG_ITEM4_TEXT, MMSG_FILAMENT_TYPE_NAME3[wtvar_language], 30);
	dserial.SendString(ADDR_LANG_ITEM5_TEXT, MMSG_EMPTY, 30);
	dserial.SendString(ADDR_LANG_ITEM6_TEXT, MMSG_EMPTY, 30);

	heattime = 100;
	filamentType = FT_PLA;
	percent_last = -1;
	filaopsts = FSSE_CHOICETYPE;
	holdontime = getcurrenttime();
}

void DGUS_Screen_Filament::Update()
{
	switch (filaopsts)
	{
	case FSSE_CHOICETYPE:
	case FSSE_RETRACT:
		break;

	case FSSE_HEATTING:
		dserial.LoadScreen(SCREEN_FILAMENT_OPERATION);
		if (operation == FILAMENT_OPERATION_LOAD)
		{
			if (act_extruder == ACTIVE_LEFT)
                dserial.SendString(ADDR_FILAMENT_TEXT_TITLE, MMSG_FILAMENT_LEFT_IN_TITLE[wtvar_language], 30);
            else
				dserial.SendString(ADDR_FILAMENT_TEXT_TITLE, MMSG_FILAMENT_RIGHT_IN_TITLE[wtvar_language], 30);

			dserial.SendString(ADDR_FILAMENT_TEXT_LINE2, MMSG_FILAMENT_IN_LINE2[wtvar_language], 40);
		}
		else
		{
			if (act_extruder == ACTIVE_LEFT)
                dserial.SendString(ADDR_FILAMENT_TEXT_TITLE, MMSG_FILAMENT_LEFT_OUT_TITLE[wtvar_language], 30);
            else
				dserial.SendString(ADDR_FILAMENT_TEXT_TITLE, MMSG_FILAMENT_RIGHT_OUT_TITLE[wtvar_language], 30);

			dserial.SendString(ADDR_FILAMENT_TEXT_LINE2, MMSG_FILAMENT_OUT_LINE2[wtvar_language], 40);
		}
		dserial.SendString(ADDR_FILAMENT_TEXT_LINE1, MMSG_FILAMENT_IN_LINE1[wtvar_language], 40);
		dserial.SendString(ADDR_FILAMENT_BUTTON_RETURN, MMSG_BACK[wtvar_language], 20);

		if (filamentType == FT_PLA)
		{
			dserial.SendString(ADDR_FILAMENT_TEXT_TEMP, MMSG_FILAMENT_TYPE_TEMP1, 8);
            if (act_extruder == ACTIVE_LEFT)
			    queue.enqueue_now_P("M104 T0 S210");
            else
                queue.enqueue_now_P("M104 T1 S210");
			targetTemp = 210;
		}
		else if (filamentType == FT_ABS)
		{
			dserial.SendString(ADDR_FILAMENT_TEXT_TEMP, MMSG_FILAMENT_TYPE_TEMP2, 8);
            if (act_extruder == ACTIVE_LEFT)
			    queue.enqueue_now_P("M104 T0 S235");
            else
                queue.enqueue_now_P("M104 T1 S235");
			targetTemp = 235;
		}
		else if (filamentType == FT_TPU)
		{
			dserial.SendString(ADDR_FILAMENT_TEXT_TEMP, MMSG_FILAMENT_TYPE_TEMP4, 8);
            if (act_extruder == ACTIVE_LEFT)
			    queue.enqueue_now_P("M104 T0 S240");
            else
                queue.enqueue_now_P("M104 T1 S240");
			targetTemp = 235;
		}
		else if (filamentType == FT_OTHER)
		{
			dserial.SendString(ADDR_FILAMENT_TEXT_TEMP, MMSG_FILAMENT_TYPE_TEMP3, 8);
            if (act_extruder == ACTIVE_LEFT)
			    queue.enqueue_now_P("M104 T0 S260");
            else
                queue.enqueue_now_P("M104 T1 S260");
			targetTemp = 260;
		}
		filaopsts = FSSE_WAITTING;
		ShowProcess();

		queue.enqueue_now_P("G28 X R0");
		break;

	case FSSE_WAITTING:
        ShowProcess();

		if (temp_nozzle0 > targetTemp - 2)
		{
			queue.enqueue_now_P("G92 E0");

			if (act_extruder == ACTIVE_LEFT)
			{
				queue.enqueue_now_P("T0");
			}
			else
			{
				queue.enqueue_now_P("T1 S1");
			}

			if (operation == FILAMENT_OPERATION_LOAD)
			{
				dserial.SendString(ADDR_FILAMENT_TEXT_LINE1, MMSG_FILAMENT_IN_LINE3[wtvar_language], 40);

				if (filamentType != FT_TPU)
				{
					queue.enqueue_now_P("G1 E100 F200");
				}
				else
				{
					queue.enqueue_now_P("G1 E100 F100");
				}
			}
			else
			{
				dserial.SendString(ADDR_FILAMENT_TEXT_LINE1, MMSG_FILAMENT_OUT_LINE3[wtvar_language], 40);

				if (filamentType != FT_TPU)
				{
					queue.enqueue_now_P("G1 E5 F100");
					queue.enqueue_now_P("G1 E-40 F300");
				}
				else
				{
					queue.enqueue_now_P("G1 E-40 F100");
				}
			}
			dserial.SendString(ADDR_FILAMENT_TEXT_LINE2, MMSG_FILAMENT_OUT_LINE2[wtvar_language], 40);

			if (filamentType == FT_PLA)
			{
				queue.enqueue_now_P("M104 S210");
			}
			else if (filamentType == FT_ABS)
			{
				queue.enqueue_now_P("M104 S235");
			}
			else if (filamentType == FT_TPU)
			{
				queue.enqueue_now_P("M104 S240");
			}
			else if (filamentType == FT_OTHER)
			{
				queue.enqueue_now_P("M104 S260");
			}
			
			filaopsts = FSSE_LOADING;
		}
		
		break;

	case FSSE_LOADING:
		if (planner.has_blocks_queued() == false)
		{
			queue.enqueue_now_P("G92 E0");
			filaopsts = FSSE_COMPLETE;
		}
		break;

	case FSSE_COMPLETE:
		filaopsts = FSSE_CHOICETYPE;
        if (wt_machineStatus != WS_PAUSE)   
		    queue.enqueue_now_P("M104 S0");
        queue.enqueue_now_P("M18");
		Goback();
		break;

	case FSSE_CHOICE_EXTRUDER:
		dserial.LoadScreen(SCREEN_2OPTION);

		dserial.SendString(ADDR_2OPTION_TEXT_TITLE, MMSG_FILAMENT_CHOICE_EXTRUDER_TITLE[wtvar_language], 30);
		dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
		dserial.SendString(ADDR_2OPTION_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

		if (operation == FILAMENT_OPERATION_LOAD)
		{
			dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON1, ENUM_SETTING_FEED_IN);
			dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON2, ENUM_SETTING_FEED_IN);
		}
		else
		{
			dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON1, ENUM_SETTING_RETRACT);
			dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON2, ENUM_SETTING_RETRACT);
		}

		dserial.SendString(ADDR_2OPTION_TEXT_BUTTON1, MMSG_FILAMENT_LEFT_EXTRUDER[wtvar_language], 20);
		dserial.SendString(ADDR_2OPTION_TEXT_BUTTON2, MMSG_FILAMENT_RIGHT_EXTRUDER[wtvar_language], 20);
		
		filaopsts = FSSE_CHOICETYPE;
		break;
	}
}

void DGUS_Screen_Filament::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_LANG_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_LANG_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM1)
			{
				filamentType = FT_PLA;
				filaopsts = FSSE_CHOICE_EXTRUDER;
				Update();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM2)
			{
				filamentType = FT_ABS;
				filaopsts = FSSE_CHOICE_EXTRUDER;
				Update();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM3)
			{
				filamentType = FT_TPU;
				filaopsts = FSSE_CHOICE_EXTRUDER;
				Update();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM4)
			{
				filamentType = FT_OTHER;
				filaopsts = FSSE_CHOICE_EXTRUDER;
				Update();
			}
		}
		else if (gltouchpara.address == ADDR_FILAMENT_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_FILAMENT_BUTTON_RETURN)
			{
                if (wt_machineStatus != WS_PAUSE)
                {
                    if (filaopsts == FSSE_LOADING)
                    {
                        queue.enqueue_now_P("M410");
                        queue.enqueue_now_P("G92 E0");
                        dgus.ShowMovingMessage();
                    }
                    else
                    {
                        filaopsts = FSSE_COMPLETE;
                        queue.enqueue_now_P("M104 S0");
                        queue.enqueue_now_P("M410");
						queue.enqueue_now_P("M18");
                        Goback();
                    }
                }
                else
                {
					queue.enqueue_now_P("M18");   
                    Goback();
                }
			}
		}
		else if (gltouchpara.address == ADDR_2OPTION_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2OPTION_BUTTON_RETURN)
			{
                if (wt_machineStatus != WS_PAUSE)
                {
					filaopsts = FSSE_COMPLETE;
					queue.enqueue_now_P("M104 S0");
					queue.enqueue_now_P("M410");
                }
                queue.enqueue_now_P("M18");
                Goback();				
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM1)
			{
				act_extruder = ACTIVE_LEFT;
				filaopsts = FSSE_HEATTING;
				Update();
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM2)
			{
				act_extruder = ACTIVE_RIGHT;
				filaopsts = FSSE_HEATTING;
				Update();
			}
		}
	}
}

void DGUS_Screen_Filament::ShowProcess(void)
{
    if (act_extruder == ACTIVE_LEFT)
	{
	    temp_nozzle0 = thermalManager.degHotend(0);
	}
    else
	{
        temp_nozzle0 = thermalManager.degHotend(1);
	}

	percent_current = (temp_nozzle0 - 20) * 10 / (targetTemp - 20);
	if (percent_current > 10) percent_current = 10;
	
	if (percent_current != percent_last)
	{
		dserial.SendInt16(ADDR_FILAMENT_PROCESS, percent_current);
		percent_last = percent_current;
	}
}

#endif