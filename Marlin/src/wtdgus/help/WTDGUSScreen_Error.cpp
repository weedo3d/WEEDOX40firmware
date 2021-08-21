/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Error.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_Error::Init()
{
	dserial.LoadScreen(SCREEN_ERROR);
}

void DGUS_Screen_Error::Update()
{
	// do nothing
}

void DGUS_Screen_Error::KeyProcess()
{
	// do nothing
}


void DGUS_Screen_Error::Title(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_TITLE, title, TEXTLEN_ERROR_TITLE);
}

void DGUS_Screen_Error::ShowText(const char* text)
{
	dserial.SendLongString(ADDR_ERROR_TEXT_TEXT, text, TEXTLEN_ERROR_TEXT);
}

#endif