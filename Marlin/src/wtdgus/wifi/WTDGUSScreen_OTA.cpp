/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "WTDGUSScreen_OTA.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCMD.h"

extern char esp32_message[22];

#ifdef DGUS_LCD

void DGUS_Screen_OTA::Init()
{
	dgus.LoadMessageReturnMenu(this);
	dgus.GetScreenMessageReturn()->Title(MMSG_OTA_TITLE[wtvar_language]);
	dgus.GetScreenMessageReturn()->Button(MMSG_BACK[wtvar_language]);
	dgus.GetScreenMessageReturn()->ShowText(MMSG_OTA_LINE[wtvar_language]);

	WT_OTA_Default();

	holdontime = getcurrenttime();
}

void DGUS_Screen_OTA::Update()
{
	dgus.GetScreenMessageReturn()->Line(esp32_message);
}

void DGUS_Screen_OTA::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_INFO_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_INFO_RETURN)
			{
				Goback();
			}
		}
	}
}
#endif