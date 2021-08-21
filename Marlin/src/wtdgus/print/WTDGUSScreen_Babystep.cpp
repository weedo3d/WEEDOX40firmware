/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "WTDGUSScreen_Babystep.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSManager.h"
#include "../../feature/babystep.h"

#define BABYSTEP_Z_DRIFT    0.05

void DGUS_Screen_Babystep::Init()
{
    dserial.LoadScreen(SCREEN_ZOFFSET);

    dserial.SendString(ADDR_ZOFFSET_TEXT_TITLE, MMSG_BABYSTEP_TITLE[wtvar_language], TEXTLEN_ZOFFSET_TITLE);
	dserial.SendEmptyString(ADDR_ZOFFSET_TEXT_BUTTON1, TEXTLEN_ZOFFSET_BUTTON);
	dserial.SendString(ADDR_ZOFFSET_TEXT_BUTTON2, MMSG_OK[wtvar_language], TEXTLEN_ZOFFSET_BUTTON);
	dserial.SendLongString_P(ADDR_ZOFFSET_TEXT_LINE, MMSG_BABYSTEP_TIP[wtvar_language], TEXTLEN_ZOFFSET_LINE);

	holdontime = getcurrenttime();
	updaterate = 200;

    babystep_current = 0;
    ShowZOffset();
}

void DGUS_Screen_Babystep::Update()
{

}

void DGUS_Screen_Babystep::KeyProcess()
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
				Goback();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_DEC)
			{
				if (babystep_current > -2) babystep_current -= BABYSTEP_Z_DRIFT;
                babystep.add_mm(Z_AXIS, -BABYSTEP_Z_DRIFT);
                ShowZOffset();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_ADD)
			{
				if (babystep_current < 2) babystep_current += BABYSTEP_Z_DRIFT;
                babystep.add_mm(Z_AXIS, BABYSTEP_Z_DRIFT);
                ShowZOffset();
			}
			
		}
		gltouchpara.validflg = false;
	}
}

void DGUS_Screen_Babystep::ShowZOffset(void)
{
	dserial.SendFloatString(ADDR_ZOFFSET_TEXT_VALUE, babystep_current);
}
