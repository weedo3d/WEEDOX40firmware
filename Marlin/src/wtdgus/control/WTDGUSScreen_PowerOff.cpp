/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../wtlib/WTCMD.h"
#include "WTDGUSScreen_PowerOff.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_PowerOff::Init()
{
	dserial.LoadScreen(SCREEN_POWER_OFF);

	dserial.SendString(ADDR_POWEROFF_TEXT_TITLE, MMSG_POWEROFF_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_POWEROFF_TEXT_CANCEL, MMSG_EXIT[wtvar_language], 20);
	dserial.SendString(ADDR_POWEROFF_TEXT_LINE1, MMSG_POWEROFF_LINE1[wtvar_language], 60);
	dserial.SendString(ADDR_POWEROFF_TEXT_LINE2, MMSG_POWEROFF_LINE2[wtvar_language], 30);
	

	deadtime = 30;
	Update();
	holdontime = getcurrenttime();
}

void DGUS_Screen_PowerOff::Update()
{
	deadtime--;
	if (deadtime < 0)
	{
		wt_PowerOff();
	}
	else
	{
		dserial.SendString(ADDR_POWEROFF_TEXT_TIME, deadtime, 2);
	}
}

void DGUS_Screen_PowerOff::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_POWEROFF_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_POWEROFF_BUTTON_CANCEL)//cancel poweroff
			{
				dgus.GotoMain();
			}
		}
	}
}
#endif