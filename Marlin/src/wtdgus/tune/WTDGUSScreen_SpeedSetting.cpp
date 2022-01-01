/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../module/motion.h"
#include "WTDGUSScreen_SpeedSetting.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_Speed::Init()
{
	dserial.LoadScreen(SCREEN_ZOFFSET);

	dserial.SendString(ADDR_ZOFFSET_TEXT_TITLE, MMSG_SPEED_SETTING_TITLE[wtvar_language], TEXTLEN_ZOFFSET_TITLE);
	dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
	dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON2, MMSG_SAVE[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
	dserial.SendLongString_P(ADDR_ZOFFSET_TEXT_LINE, HELP_TIP04_LINE[wtvar_language], TEXTLEN_ZOFFSET_LINE);
	dserial.SendString(ADDR_ZOFFSET_TEXT2_VALUE, PSTR(" %"), 4);

	holdontime = getcurrenttime();
	updaterate = 200;

	temp_feedrate = feedrate_percentage;

	ShowFeedrate();
}

void DGUS_Screen_Speed::Update()
{
	// do nothing
}

void DGUS_Screen_Speed::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_ZOFFSET_KEY)
		{
			if (gltouchpara.value == KEY_ZOFFSET_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_SAVE)
			{
				feedrate_percentage = temp_feedrate;
				Goback();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_DEC)
			{
				if (temp_feedrate > 50)
					temp_feedrate -= 5;
				ShowFeedrate();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_ADD)
			{
				if (temp_feedrate < 400)
					temp_feedrate += 5;
				ShowFeedrate();
			}
			
		}
		gltouchpara.validflg = false;
	}
}


void DGUS_Screen_Speed::ShowFeedrate(void)
{
	dserial.SendPercentString(ADDR_ZOFFSET_TEXT_VALUE, temp_feedrate);
}

#endif