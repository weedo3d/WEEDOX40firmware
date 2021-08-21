/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Proximity.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_Proximity::Init()
{
	dserial.SendString(ADDR_INFO_TITLE, MMSG_POXIMITY_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_INFO_RETURN, MMSG_BACK[wtvar_language], 20);
	dserial.SendLongString(ADDR_INFO_LINE, MMSG_POXIMITY_LINE[wtvar_language], TEXTLEN_INFO_ITEM);

	dgus.ShowMovingMessage();
	queue.enqueue_now_P(PSTR("G28"));
	queue.enqueue_now_P(PSTR("G1 X150 Y150 F3000"));
	queue.enqueue_now_P(PSTR("G1 Z10 F500"));
	queue.enqueue_now_P(PSTR("G1 Z0 F100"));

	holdontime = getcurrenttime();
	updaterate = 1000;
	zState = PSE_BEGIN;
}

void DGUS_Screen_Proximity::Update()
{
	switch (zState)
	{
	case PSE_BEGIN:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_INFO);
			zState = PSE_INPUT;
		}
	}
	break;

	case PSE_INPUT:
		if (READ(Z_MIN_PIN))
			dserial.SendString(ADDR_INFO_LINE2, MMSG_SWITCH_OFF[wtvar_language], 60);
		else
			dserial.SendString(ADDR_INFO_LINE2, MMSG_SWITCH_ON[wtvar_language], 60);
		break;

	case PSE_END:
		if (planner.has_blocks_queued() == false)
		{
			Goback();
		}
        break;

	default:
		break;
	}
}

void DGUS_Screen_Proximity::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_INFO_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_INFO_RETURN)
			{
				dgus.ShowMovingMessage();
				queue.enqueue_now_P(PSTR("G28"));
				queue.enqueue_now_P(PSTR("M18"));
				zState = PSE_END;
			}
		}
		
	}
}

#endif