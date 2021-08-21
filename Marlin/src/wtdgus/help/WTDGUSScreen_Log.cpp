/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Log.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD
void DGUS_Screen_Log::Init()
{
	DGUS_Screen_ScrollList::Init();

	Clear();
}

void DGUS_Screen_Log::SetTitle(const char* title)
{
    dserial.SendString(ADDR_HELP1_TEXT_TITLE, title, TEXTLEN_HELP1_TITLE);
}

void DGUS_Screen_Log::Update()
{

}

void DGUS_Screen_Log::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{
				Goback();
			}
		}
	}
}
#endif
