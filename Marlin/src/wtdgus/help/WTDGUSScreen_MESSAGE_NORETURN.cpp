/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Message_NOReturn.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_Message_NoReturn::Init()
{
	dserial.LoadScreen(SCREEN_NOTICE);
	isAutoReturn = false;
	holdontime = getcurrenttime();
}

void DGUS_Screen_Message_NoReturn::Update()
{
	if (parent != NULL)
		parent->Update();

	if (isAutoReturn)
	{
		if (planner.has_blocks_queued() == false)
			Goback();
	}
}

void DGUS_Screen_Message_NoReturn::KeyProcess()
{
	if (parent != NULL)
		parent->KeyProcess();
}

void DGUS_Screen_Message_NoReturn::Title(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_TITLE, title, TEXTLEN_NOTICE_TITLE);
}

void DGUS_Screen_Message_NoReturn::ShowText(const char* text)
{
	dserial.SendLongString(ADDR_NOTICE_TEXT_LINE, text, TEXTLEN_NOTICE_ITEM);
}

void DGUS_Screen_Message_NoReturn::Line(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE2, title, TEXTLEN_NOTICE_LINE2);
}

#endif
