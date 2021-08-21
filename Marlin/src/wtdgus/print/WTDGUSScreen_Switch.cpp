/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../gcode/queue.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Switch.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCMD.h"

#define ACTIVE_LEFT     0
#define ACTIVE_RIGHT    1

#ifdef DGUS_LCD

void DGUS_Screen_Switch::Init()
{
	dserial.LoadScreen(SCREEN_2OPTION);

	dserial.SendString(ADDR_2OPTION_TEXT_TITLE, MMSG_TITLE_MANUALSWITCH[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_2OPTION_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON1, ENUM_SETTING_FEED_IN);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON2, ENUM_SETTING_FEED_IN);
	dserial.SendString(ADDR_2OPTION_TEXT_BUTTON1, MMSG_FILAMENT_LEFT_EXTRUDER[wtvar_language], 20);
	dserial.SendString(ADDR_2OPTION_TEXT_BUTTON2, MMSG_FILAMENT_RIGHT_EXTRUDER[wtvar_language], 20);
		
	holdontime = getcurrenttime();
	old_extruder = active_extruder;
	chaning_tool = false;
}

void DGUS_Screen_Switch::Update()
{
	if (chaning_tool)
	{
		if (active_extruder != old_extruder)
			dgus.GotoPrintingMenu();
	}
}

void DGUS_Screen_Switch::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_2OPTION_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2OPTION_BUTTON_RETURN)
			{
                Goback();				
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM1)
			{
				if (active_extruder != 0)
				{
					dgus.ShowNoRetrunMessage(MMSG_WAITING[wtvar_language]);
					chaning_tool = true;
					wt_changetool();
				}
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM2)
			{
				if (active_extruder != 1)
				{
					dgus.ShowNoRetrunMessage(MMSG_WAITING[wtvar_language]);
					chaning_tool = true;
					wt_changetool();
				}
			}
		}
	}
}


#endif