/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
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
// 错误信息菜单 
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
			{	// x 正转
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 X1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_X_BACK)
			{	// x 反转
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 X-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Y_RUN)
			{	// y 正转
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 Y1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Y_BACK)
			{	// y 反转
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 Y-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Z_RUN)
			{	// z 正转
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 Z1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Z_BACK)
			{	// z 反转
				queue.enqueue_now_P(PSTR("G1 Z-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_A_RUN)
			{	// a 正转
				queue.enqueue_now_P(PSTR("M302 P1"));
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 E1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_A_BACK)
			{	// a 反转
				queue.enqueue_now_P(PSTR("M302 P1"));
				queue.enqueue_now_P(PSTR("G91"));
				queue.enqueue_now_P(PSTR("G1 E-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_4020_ON)
			{	// 4020 开
				wt_OpenExtruder0Fan();
			}
			else if (gltouchpara.value == KEY_TESTMODE_4020_OFF)
			{	// 4020 关
				wt_CloseExtruder0Fan();
			}
			else if (gltouchpara.value == KEY_TESTMODE_5015_ON)
			{	// 5015 开
				queue.enqueue_now_P(PSTR("M106"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_5015_OFF)
			{	// 5015 关
				queue.enqueue_now_P(PSTR("M107"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_POWEROFF)
			{	// 关机
				wt_PowerOff();
			}
			else if (gltouchpara.value == KEY_TESTMODE_8015_ON)
			{	// 8015 开
				queue.enqueue_now_P(PSTR("T0 S1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_8015_OFF)
			{	// 8015 关
				queue.enqueue_now_P(PSTR("T1 S1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_BACK)
			{	// 返回
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