/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../wtlib/WTCMD.h"
#include "WTDGUSScreen_TestMode.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#define STRING_ON	"on "
#define STRING_OFF	"off"

#ifdef DGUS_LCD

void DGUS_Screen_TestMode::Init()
{
	dserial.LoadScreen(SCREEN_TEST_MODE);

	ShowEndstop();
	holdontime = getcurrenttime();
	updaterate = 500;
}

void DGUS_Screen_TestMode::Update()
{
	ShowEndstop();
}

void DGUS_Screen_TestMode::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_TESTMODE_KEY)
		{
			if (gltouchpara.value == KEY_TESTMODE_X_RUN)
			{
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 X1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_X_BACK)
			{	
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 X-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Y_RUN)
			{	
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 Y1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Y_BACK)
			{	
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 Y-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Z_RUN)
			{	
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 Z1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Z_BACK)
			{	
				queue.enqueue_now_P(PSTR("G1 Z-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_A_RUN)
			{	
				queue.enqueue_now_P(PSTR("M302 P1"));
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 E1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_A_BACK)
			{	
				queue.enqueue_now_P(PSTR("M302 P1"));
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 E-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_4020_ON)
			{	
				wt_OpenExtruder0Fan();
			}
			else if (gltouchpara.value == KEY_TESTMODE_4020_OFF)
			{	
				wt_CloseExtruder0Fan();
			}
			else if (gltouchpara.value == KEY_TESTMODE_5015_ON)
			{	
				queue.enqueue_now_P(PSTR("M106"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_5015_OFF)
			{	
				queue.enqueue_now_P(PSTR("M107"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_POWEROFF)
			{	
				wt_PowerOff();
			}
			else if (gltouchpara.value == KEY_TESTMODE_8015_ON)
			{	
				queue.enqueue_now_P(PSTR("T0 S1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_8015_OFF)
			{	
				queue.enqueue_now_P(PSTR("T1 S1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_BACK)
			{	
				Goback();
			}
		}
		gltouchpara.validflg = false;
	}
}

void DGUS_Screen_TestMode::ShowEndstop(void)
{
	if (READ(X_MAX_PIN))
		dserial.SendString(ADDR_TESTMODE_ENDSTOP_X, PSTR(STRING_ON));
	else
		dserial.SendString(ADDR_TESTMODE_ENDSTOP_X, PSTR(STRING_OFF));

	if (READ(Y_MAX_PIN))
		dserial.SendString(ADDR_TESTMODE_ENDSTOP_Y, PSTR(STRING_ON));
	else
		dserial.SendString(ADDR_TESTMODE_ENDSTOP_Y, PSTR(STRING_OFF));

	if (READ(Z_MAX_PIN))
		dserial.SendString(ADDR_TESTMODE_ENDSTOP_Z, PSTR(STRING_ON));
	else
		dserial.SendString(ADDR_TESTMODE_ENDSTOP_Z, PSTR(STRING_OFF));

	if (READ(Z_MIN_PIN))
		dserial.SendString(ADDR_TESTMODE_HALL, PSTR(STRING_OFF));
	else
		dserial.SendString(ADDR_TESTMODE_HALL, PSTR(STRING_ON));

	if (READ(FIL_RUNOUT_PIN))
		dserial.SendString(ADDR_TESTMODE_BREAK, PSTR(STRING_OFF));
	else
		dserial.SendString(ADDR_TESTMODE_BREAK, PSTR(STRING_ON));
}

#endif