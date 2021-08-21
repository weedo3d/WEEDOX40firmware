/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/configuration_store.h"
#include "../../wtlib/WTCMD.h"
#include "../../gcode/parser.h"
#include "../../module/probe.h"
#include "../../module/stepper.h"
#include "WTDGUSScreen_RestoreSetting.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_RestoreSetting::Init()
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString(ADDR_2BINFO_TITLE, MMSG_FIRMWARE_PARAM_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON1, MMSG_FIRMWARE_PARAM_OPERATION[wtvar_language], 20);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON2, MMSG_BACK[wtvar_language], 20);

	restoreConfirm = false;

	ShowReport();

	holdontime = getcurrenttime();
}

void DGUS_Screen_RestoreSetting::Update()
{


}

void DGUS_Screen_RestoreSetting::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_2BINFO_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2BINFO_ITEM2)
			{
				if (restoreConfirm)
				{
					settings.reset();
					settings.save();				
					wt_restart();
				}
				else
				{
					Goback();
				}
			}
			else if (gltouchpara.value == KEY_2BINFO_ITEM1)
			{
				if (restoreConfirm)
				{
					Goback();
				}
				else
				{
					LoadOperationMenu();
				}
			}
		}
		else if (gltouchpara.address == ADDR_HELPMENU_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELPMENU_BUTTON_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM1)
			{
				dgus.ShowLogMenu(this, MMSG_FIRMWARE_PARAM_SAVE[wtvar_language]);
				queue.enqueue_one_now("W216");
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM2)
			{
				dgus.ShowLogMenu(this, MMSG_FIRMWARE_PARAM_SAVE[wtvar_language]);
				queue.enqueue_one_now("W217");
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM3)
			{
				ShowConfirm();
			}
		}
		
	}
}

void DGUS_Screen_RestoreSetting::ShowReport(void)
{
	char* buffer = (char*)malloc(TEXTLEN_2BINFO_ITEM);

	memset(buffer, 0, TEXTLEN_2BINFO_ITEM);
	sprintf(buffer, "Home offset:\r\n M218 T1 X%.2f Y%.2f Z%.2f\r\nZ-Probe Offset:\r\n M851 X%.2f Y%.2f Z%.2f\r\nStepper motor currents:\r\n M907 X%ld Y%ld Z%ld E%ld",
					 LINEAR_UNIT(hotend_offset[1].x),
					 LINEAR_UNIT(hotend_offset[1].y),
					 LINEAR_UNIT(hotend_offset[1].z),
                     LINEAR_UNIT(probe.offset_xy.x),
					 LINEAR_UNIT(probe.offset_xy.y),
					 probe.offset.z,
					 stepper.motor_current_setting[0],
					 stepper.motor_current_setting[1],
					 stepper.motor_current_setting[2],
					 stepper.motor_current_setting[3]);

	dserial.SendLongString(ADDR_2BINFO_TEXT_LINE, buffer, TEXTLEN_2BINFO_ITEM);

	free(buffer);
}

void DGUS_Screen_RestoreSetting::ShowConfirm(void)
{
	restoreConfirm = true;
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendLongString(ADDR_2BINFO_TEXT_LINE, MMSG_RESTORE_SETTING_LINE[wtvar_language], TEXTLEN_2BINFO_ITEM);

	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON1, MMSG_NO[wtvar_language], TEXTLEN_2BINFO_BUTTON);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON2, MMSG_YES[wtvar_language], TEXTLEN_2BINFO_BUTTON);
}

void DGUS_Screen_RestoreSetting::LoadOperationMenu(void)
{
	dserial.LoadScreen(SCREEN_HELPMENU);

	dserial.SendString(ADDR_HELPMENU_TEXT_TITLE, MMSG_FIRMWARE_PARAM_OPERATION[wtvar_language], TEXTLEN_HELPMENU_TITLE);
	dserial.SendString(ADDR_HELPMENU_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELPMENU_BUTTON);

	dserial.SendInt16(ADDR_HELPMENU_ICON1, ENUM_SETTING_TF_SAVE);
	dserial.SendString(ADDR_HELPMENU_ITEM1, MMSG_FIRMWARE_PARAM_SAVE[wtvar_language], TEXTLEN_HELPMENU_ITEM);

	dserial.SendInt16(ADDR_HELPMENU_ICON2, ENUM_SETTING_TF_LOAD);
	dserial.SendString(ADDR_HELPMENU_ITEM2, MMSG_FIRMWARE_PARAM_LOAD[wtvar_language], TEXTLEN_HELPMENU_ITEM);

	dserial.SendInt16(ADDR_HELPMENU_ICON3, ENUM_SETTING_RESTORE);
	dserial.SendString(ADDR_HELPMENU_ITEM3, MMSG_FIRMWARE_PARAM_RESTORE[wtvar_language], TEXTLEN_HELPMENU_ITEM);
}
#endif