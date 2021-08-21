/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Message_Return.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_Message_Return::Init()
{
	dserial.LoadScreen(SCREEN_INFO);

	holdontime = getcurrenttime();
}

void DGUS_Screen_Message_Return::Update()
{
	if (parent != NULL)
		parent->Update();
}

void DGUS_Screen_Message_Return::KeyProcess()
{
	if (parent != NULL)
		parent->KeyProcess();

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

void DGUS_Screen_Message_Return::Title(const char* title)
{
	dserial.SendString(ADDR_INFO_TITLE, title, TEXTLEN_INFO_TITLE);
}

void DGUS_Screen_Message_Return::Button(const char* title)
{
	dserial.SendString(ADDR_INFO_RETURN, title, TEXTLEN_INFO_BUTTON);
}

void DGUS_Screen_Message_Return::ShowText(const char* str)
{
	dserial.SendLongString(ADDR_INFO_LINE, str, TEXTLEN_INFO_ITEM);
}

void DGUS_Screen_Message_Return::Line(const char* title)
{
	dserial.SendString(ADDR_INFO_LINE2, title, TEXTLEN_INFO_LINE2);
}
#endif