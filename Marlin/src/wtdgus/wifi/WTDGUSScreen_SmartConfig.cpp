/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "WTDGUSScreen_SmartConfig.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

extern uint8_t wifiStatus;

#ifdef DGUS_LCD

void DGUS_Screen_SmartConfig::Init()
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString(ADDR_HELP1_TEXT_TITLE, MMSG_SMARTCONFIG_TITLE[wtvar_language], TEXTLEN_HELP1_TITLE);
	dserial.SendString(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELP1_BUTTON);
	dserial.SendLongString(ADDR_HELP1_TEXT_LINE, MMSG_SMARTCONFIG_TEXT[wtvar_language], 502);

	holdontime = getcurrenttime();
}

void DGUS_Screen_SmartConfig::Update()
{

}

void DGUS_Screen_SmartConfig::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			Goback();
		}
	}
}

#endif
