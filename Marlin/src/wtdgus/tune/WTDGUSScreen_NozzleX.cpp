/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/configuration_store.h"
#include "WTDGUSScreen_NozzleX.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_Nozzle_X::Init()
{
	dserial.LoadScreen(SCREEN_NOZZLE_OFFSET);

	dserial.SendString(ADDR_NOFFSET_TITLE, MMSG_NOZZLE_X_TITLE[wtvar_language], TEXTLEN_NOFFSET_TITLE);
	dserial.SendString(ADDR_NOFFSET_RETURN_TEXT, MMSG_CANCEL[wtvar_language], TEXTLEN_NOFFSET_BUTTON);
	
    tempX = wtvar_tune_x1;
	tempY = wtvar_tune_y1;

	holdontime = getcurrenttime();

	pageid = 0;
    ShowPage();
}

void DGUS_Screen_Nozzle_X::Update()
{
	
}

void DGUS_Screen_Nozzle_X::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_NOFFSET_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_NOFFSET_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_NOFFSET_NEXT)
			{
				if (pageid == 0)
                {
                    pageid = 1;
                    ShowPage();
                }
                else
                {
					wtvar_tune_x1 = tempX;
					wtvar_tune_y1 = tempY;
					hotend_offset[1].x = T1_OFFSET_X + (wtvar_tune_x1 - 3) + ((float)wtvar_tune_x2 - 5) / 10;
					hotend_offset[1].y = (wtvar_tune_y1 - 3) + ((float)wtvar_tune_y2 - 5) / 10;
					(void)settings.save();
					Goback();
				}
			}
			else if (gltouchpara.value == KEY_NOFFSET_BUTTON1)
			{
                ShowButtonOn(1);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON2)
			{
                ShowButtonOn(2);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON3)
			{
                ShowButtonOn(3);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON4)
			{
                ShowButtonOn(4);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON5)
			{
                ShowButtonOn(5);
			}
		}
	}
}

void DGUS_Screen_Nozzle_X::ShowButtonOn(uint8_t id)
{
    dserial.SendInt16(ADDR_NOFFSET_BUTTON1_ICON, id == 1 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON2_ICON, id == 2 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON3_ICON, id == 3 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON4_ICON, id == 4 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON5_ICON, id == 5 ? 2 : 1);
	
    if (pageid == 0)
        tempX = id;
    else
        tempY = id;
}

void DGUS_Screen_Nozzle_X::ShowPage(void)
{
    if (pageid == 0)
    {
        dserial.SendString(ADDR_NOFFSET_BUTTON1_TEXT, "1(351)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON2_TEXT, "2(352)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON3_TEXT, "3(353)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON4_TEXT, "4(354)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON5_TEXT, "5(355)", TEXTLEN_NOFFSET_ITEM);

		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON6_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON7_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON8_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON9_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON10_TEXT, TEXTLEN_NOFFSET_ITEM);
	
		dserial.SendInt16(ADDR_NOFFSET_BUTTON6_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON7_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON8_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON9_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON10_ICON, 0);

		dserial.SendString(ADDR_NOFFSET_NEXT_TEXT, MMSG_NEXT[wtvar_language], TEXTLEN_NOFFSET_BUTTON);
        dserial.SendLongString(ADDR_NOFFSET_TEXT, MMSG_NOZZLE_X_TEXT[wtvar_language], TEXTLEN_NOFFSET_TEXT);
		ShowButtonOn(wtvar_tune_x1);
    }
    else
    {
        dserial.SendString(ADDR_NOFFSET_BUTTON1_TEXT, "1(-2)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON2_TEXT, "2(-1)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON3_TEXT, "3(0)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON4_TEXT, "4(1)", TEXTLEN_NOFFSET_ITEM);
		dserial.SendString(ADDR_NOFFSET_BUTTON5_TEXT, "5(2)", TEXTLEN_NOFFSET_ITEM);

		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON6_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON7_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON8_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON9_TEXT, TEXTLEN_NOFFSET_ITEM);
		dserial.SendEmptyString(ADDR_NOFFSET_BUTTON10_TEXT, TEXTLEN_NOFFSET_ITEM);

		dserial.SendInt16(ADDR_NOFFSET_BUTTON6_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON7_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON8_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON9_ICON, 0);
		dserial.SendInt16(ADDR_NOFFSET_BUTTON10_ICON, 0);

		dserial.SendString(ADDR_NOFFSET_NEXT_TEXT, MMSG_SAVE[wtvar_language], TEXTLEN_NOFFSET_BUTTON);
        dserial.SendLongString(ADDR_NOFFSET_TEXT, MMSG_NOZZLE_Y2_TEXT[wtvar_language], TEXTLEN_NOFFSET_TEXT);
        ShowButtonOn(wtvar_tune_y1);
    }
}

#endif