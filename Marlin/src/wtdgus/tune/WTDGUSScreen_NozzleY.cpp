/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/configuration_store.h"
#include "WTDGUSScreen_NozzleY.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_Nozzle_Y::Init()
{
	dserial.LoadScreen(SCREEN_NOZZLE_OFFSET);

	dserial.SendString(ADDR_NOFFSET_TITLE, MMSG_NOZZLE_XY_TITLE[wtvar_language], TEXTLEN_NOFFSET_TITLE);
	dserial.SendString(ADDR_NOFFSET_RETURN_TEXT, MMSG_CANCEL[wtvar_language], TEXTLEN_NOFFSET_BUTTON);
 
    dserial.SendInt16(ADDR_NOFFSET_BUTTON6_ICON, 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON7_ICON, 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON8_ICON, 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON9_ICON, 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON10_ICON, 1);

    tempX = wtvar_tune_x2;
    tempY = wtvar_tune_y2;

    pageid = 0;
    ShowPage();

	holdontime = getcurrenttime();
}

void DGUS_Screen_Nozzle_Y::Update()
{
	
}

void DGUS_Screen_Nozzle_Y::KeyProcess()
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
                    wtvar_tune_x2 = tempX;
                    wtvar_tune_y2 = tempY;
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
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON6)
			{
                ShowButtonOn(6);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON7)
			{
                ShowButtonOn(7);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON8)
			{
                ShowButtonOn(8);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON9)
			{
                ShowButtonOn(9);
			}
            else if (gltouchpara.value == KEY_NOFFSET_BUTTON10)
			{
                ShowButtonOn(10);
			}
		}
	}
}

void DGUS_Screen_Nozzle_Y::ShowPage(void)
{
    if (pageid == 0)
    {
        dserial.SendString(ADDR_NOFFSET_BUTTON1_TEXT, "1(-0.4)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON2_TEXT, "2(-0.3)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON3_TEXT, "3(-0.2)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON4_TEXT, "4(-0.1)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON5_TEXT, " 5(0)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON6_TEXT, "6(+0.1)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON7_TEXT, "7(+0.2)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON8_TEXT, "8(+0.3)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON9_TEXT, "9(+0.4)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON10_TEXT, "10(+0.5)", TEXTLEN_NOFFSET_ITEM);

        dserial.SendString(ADDR_NOFFSET_NEXT_TEXT, MMSG_NEXT[wtvar_language], TEXTLEN_NOFFSET_BUTTON);
        dserial.SendLongString(ADDR_NOFFSET_TEXT, MMSG_NOZZLE_Y1_TEXT[wtvar_language], TEXTLEN_NOFFSET_TEXT);
        ShowButtonOn(wtvar_tune_x2);
    }
    else
    {
        dserial.SendString(ADDR_NOFFSET_BUTTON1_TEXT, "1(-0.4)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON2_TEXT, "2(-0.3)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON3_TEXT, "3(-0.2)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON4_TEXT, "4(-0.1)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON5_TEXT, " 5(0)", TEXTLEN_NOFFSET_ITEM);
        dserial.SendString(ADDR_NOFFSET_BUTTON6_TEXT, "6(+0.1)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON7_TEXT, "7(+0.2)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON8_TEXT, "8(+0.3)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON9_TEXT, "9(+0.4)", TEXTLEN_NOFFSET_ITEM);
	    dserial.SendString(ADDR_NOFFSET_BUTTON10_TEXT, "10(+0.5)", TEXTLEN_NOFFSET_ITEM);

        dserial.SendString(ADDR_NOFFSET_NEXT_TEXT, MMSG_SAVE[wtvar_language], TEXTLEN_NOFFSET_BUTTON);
        dserial.SendLongString(ADDR_NOFFSET_TEXT, MMSG_NOZZLE_Y2_TEXT[wtvar_language], TEXTLEN_NOFFSET_TEXT);
        ShowButtonOn(wtvar_tune_y2);
    }
}

void DGUS_Screen_Nozzle_Y::ShowButtonOn(uint8_t id)
{
    dserial.SendInt16(ADDR_NOFFSET_BUTTON1_ICON, id == 1 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON2_ICON, id == 2 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON3_ICON, id == 3 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON4_ICON, id == 4 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON5_ICON, id == 5 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON6_ICON, id == 6 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON7_ICON, id == 7 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON8_ICON, id == 8 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON9_ICON, id == 9 ? 2 : 1);
    dserial.SendInt16(ADDR_NOFFSET_BUTTON10_ICON, id == 10 ? 2 : 1);
	
    if (pageid == 0)
        tempX = id;
    else
        tempY = id;
}

#endif