/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../module/motion.h"
#include "../../gcode/queue.h"
#include "WTDGUSScreen_SelfTest.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#define NOZZLE_HEATING_WAITING		30000
#define BED_HEATING_WAITING			50000
#define NOOZLE_LOW_HEATING_TEMP		10
#define NOZZLE_HIGH_HEATING_TEMP	5
#define BED_LOW_HEATING_TEMP		3
#define BED_HIGH_HEATING_TEMP		1
#define NOZZLE_THRESHOLD			150
#define BED_THRESHOLD				50
#define XY_WAITING					25000
#define Z_WAITING					50000

#ifdef DGUS_LCD

void DGUS_Screen_SelfTest::Init()
{
	dserial.LoadScreen(SCREEN_MACHINE_INFO);
	holdontime = getcurrenttime();
	beginTime = getcurrenttime();
	axisTime = getcurrenttime();

	dserial.SendString(ADDR_MACHINE_TITLE, MMSG_SELF_TEST_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_MACHINE_BUTTON1, MMSG_SKIP[wtvar_language], 20);
	dserial.SendString(ADDR_MACHINE_BUTTON2, MMSG_MAINMENU[wtvar_language], 20);
	dserial.SendString(ADDR_MACHINE_ITEM1, MMSG_SELF_TEST_ITEM1[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_ITEM2, MMSG_SELF_TEST_ITEM2[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_ITEM3, MMSG_SELF_TEST_ITEM3[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_ITEM4, MMSG_SELF_TEST_ITEM4[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_ITEM5, MMSG_SELF_TEST_ITEM5[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_ITEM6, MMSG_SELF_TEST_ITEM6[wtvar_language], 32);

	dserial.SendInt16(ADDR_MACHINE_ICON_HELP, ENUM_HELP_ICON_HELP);

	nozzleState0 = SNE_READING;
	temp_nozzle0 = thermalManager.degHotend(0);
	if (temp_nozzle0 < -10)
	{
		dserial.SendString(ADDR_MACHINE_ERROR1, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_VALUE1,  30);
		nozzleState0 = SNE_ERROR;
	}
	else
	{
		if (temp_nozzle0 < NOZZLE_THRESHOLD)
			target_nozzle0 = temp_nozzle0 + NOOZLE_LOW_HEATING_TEMP;
		else
			target_nozzle0 = temp_nozzle0 + NOZZLE_HIGH_HEATING_TEMP;

		thermalManager.setTargetHotend(target_nozzle0, 0);

		dserial.SendString(ADDR_MACHINE_VALUE1, MMSG_SELF_TEST_HEATING[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_ERROR1,  30);
		nozzleState0 = SNE_HEATING;
	}

	nozzleState1 = SNE_READING;
	temp_nozzle1 = thermalManager.degHotend(1);
	if (temp_nozzle1 < -10)
	{
		dserial.SendString(ADDR_MACHINE_ERROR2, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_VALUE2,  30);
		nozzleState1 = SNE_ERROR;
	}
	else
	{
		if (temp_nozzle1 < NOZZLE_THRESHOLD)
			target_nozzle1 = temp_nozzle1 + NOOZLE_LOW_HEATING_TEMP;
		else
			target_nozzle1 = temp_nozzle1 + NOZZLE_HIGH_HEATING_TEMP;

		thermalManager.setTargetHotend(target_nozzle1, 1);

		dserial.SendString(ADDR_MACHINE_VALUE2, MMSG_SELF_TEST_HEATING[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_ERROR2,  30);
		nozzleState1 = SNE_HEATING;
	}

	bedState = SBE_READING;
	temp_bed = thermalManager.degBed();
	if (temp_bed < -10)
	{
		dserial.SendString(ADDR_MACHINE_ERROR3, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_VALUE3,  30);
		bedState = SBE_ERROR;
	}
	else
	{
		target_bed = temp_bed + BED_HIGH_HEATING_TEMP;

		thermalManager.setTargetBed(target_bed);

		dserial.SendString(ADDR_MACHINE_VALUE3, MMSG_SELF_TEST_HEATING[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_ERROR3, 30);
		bedState = SBE_HEATING;
	}

	doxhome();	

	dserial.SendEmptyString(ADDR_MACHINE_ERROR4, 30);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR5, 30);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR6, 30);
}

void DGUS_Screen_SelfTest::Update()
{
	temp_nozzle0 = thermalManager.degHotend(0);
	temp_nozzle1 = thermalManager.degHotend(1);
	temp_bed = thermalManager.degBed();

	if (nozzleState0 == SNE_HEATING)
	{
		if ((beginTime + NOZZLE_HEATING_WAITING) > getcurrenttime())
		{
			if (temp_nozzle0 >= target_nozzle0)
			{
				dserial.SendString(ADDR_MACHINE_VALUE1, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				nozzleState0 = SNE_END;
				thermalManager.setTargetHotend(0, 0);
			}
		}
		else
		{	
			dserial.SendString(ADDR_MACHINE_ERROR1, MMSG_SELF_TEST_NOHEAT[wtvar_language], 32);
			dserial.SendEmptyString(ADDR_MACHINE_VALUE1, 30);
			nozzleState0 = SNE_ERROR;
			thermalManager.setTargetHotend(0, 0);
		}
	}

	if (nozzleState1 == SNE_HEATING)
	{
		if ((beginTime + NOZZLE_HEATING_WAITING) > getcurrenttime())
		{
			if (temp_nozzle1 >= target_nozzle1)
			{
				dserial.SendString(ADDR_MACHINE_VALUE2, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				nozzleState1 = SNE_END;
				thermalManager.setTargetHotend(0, 1);
			}
		}
		else
		{	
			dserial.SendString(ADDR_MACHINE_ERROR2, MMSG_SELF_TEST_NOHEAT[wtvar_language], 32);
			dserial.SendEmptyString(ADDR_MACHINE_VALUE2, 30);
			nozzleState1 = SNE_ERROR;
			thermalManager.setTargetHotend(0, 1);
		}
	}

	if (bedState == SBE_HEATING)
	{
		if ((beginTime + BED_HEATING_WAITING) > getcurrenttime())
		{
			if (temp_bed >= target_bed)
			{
				dserial.SendString(ADDR_MACHINE_VALUE3, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				bedState = SBE_END;
				thermalManager.setTargetBed(0);
			}
		}
		else
		{	
			dserial.SendString(ADDR_MACHINE_ERROR3, MMSG_SELF_TEST_NOHEAT[wtvar_language], 32);
			dserial.SendEmptyString(ADDR_MACHINE_VALUE3, 30);
			bedState = SBE_ERROR;
			thermalManager.setTargetBed(0);
		}
	}

	if (axisState == SAE_XMOVING)
	{
		if ((axisTime + XY_WAITING) > getcurrenttime())
		{
			if (TEST(axis_homed, X_AXIS))
			{
				dserial.SendString(ADDR_MACHINE_VALUE4, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				doyhome();
			}
		}
		else
		{	
			dserial.SendString(ADDR_MACHINE_ERROR4, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
			dserial.SendEmptyString(ADDR_MACHINE_VALUE4, 30);
			axisState = SAE_ERROR;
		}
	}
	else if (axisState == SAE_YMOVING)
	{
		if ((axisTime + XY_WAITING) > getcurrenttime())
		{
			if (TEST(axis_homed, Y_AXIS))
			{
				dserial.SendString(ADDR_MACHINE_VALUE5, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				dozhome();
			}
		}
		else
		{	
			dserial.SendString(ADDR_MACHINE_ERROR5, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
			dserial.SendEmptyString(ADDR_MACHINE_VALUE5, 30);
			axisState = SAE_ERROR;
		}
	}
	else if (axisState == SAE_ZMOVING)
	{
		if ((axisTime + Z_WAITING) > getcurrenttime())
		{
			if (TEST(axis_homed, Z_AXIS))
			{
				dserial.SendString(ADDR_MACHINE_VALUE6, MMSG_SELF_TEST_PASS[wtvar_language], 32);
                queue.enqueue_now_P(PSTR("G1 Z50 F1500"));
				axisState = SAE_END;
			}
		}
		else
		{	
			dserial.SendString(ADDR_MACHINE_ERROR6, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
			dserial.SendEmptyString(ADDR_MACHINE_VALUE6, 30);
			axisState = SAE_ERROR;
		}
	}

	if (nozzleState0 == SNE_END && nozzleState1 == SNE_END && bedState == SBE_END && axisState == SAE_END)
	{	
		queue.enqueue_now_P(PSTR("M18"));
		dgus.QuitTestingMode();
		Goback();
	}
}

void DGUS_Screen_SelfTest::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MACHINE_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_MACHINE_BUTTON1 || gltouchpara.value == KEY_MACHINE_BUTTON2)
			{
				thermalManager.setTargetHotend(0, 0);
				thermalManager.setTargetBed(0);
				queue.enqueue_now_P(PSTR("M18"));
				dgus.QuitTestingMode();
				Goback();
			}
			else if (gltouchpara.value == KEY_MACHINE_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_MACHINE_INFO);
			}
		}
	}
}

void DGUS_Screen_SelfTest::NozzleTempError(void)
{
	dserial.SendString(ADDR_MACHINE_ERROR1, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
	dserial.SendEmptyString(ADDR_MACHINE_VALUE1, 30);
	nozzleState0 = SNE_ERROR;
    nozzleState1 = SNE_ERROR;
}

void DGUS_Screen_SelfTest::BedTempError(void)
{
	dserial.SendString(ADDR_MACHINE_ERROR2, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
	dserial.SendEmptyString(ADDR_MACHINE_VALUE2, 30);
	bedState = SBE_ERROR;
}

void DGUS_Screen_SelfTest::EndStopError(void)
{
	if (axisState == SAE_XMOVING)
	{
		dserial.SendString(ADDR_MACHINE_ERROR4, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_VALUE4, 30);
	}
	else if (axisState == SAE_YMOVING)
	{
		dserial.SendString(ADDR_MACHINE_ERROR5, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_VALUE5, 30);
	}
	else if (axisState == SAE_ZMOVING)
	{
		dserial.SendString(ADDR_MACHINE_ERROR6, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
		dserial.SendEmptyString(ADDR_MACHINE_VALUE6, 30);
	}
	axisState = SAE_ERROR;
}

void DGUS_Screen_SelfTest::ShowHelp(void)
{
    dgus.ShowHelp(HELP_TIP05_LINE[wtvar_language]);
}


void DGUS_Screen_SelfTest::doxhome(void)
{
	if (TEST(axis_homed, X_AXIS))
	{
		dserial.SendString(ADDR_MACHINE_VALUE4, MMSG_SELF_TEST_PASS[wtvar_language], 32);
		doyhome();
	}
	else
	{
		dserial.SendString(ADDR_MACHINE_VALUE4, MMSG_SELF_TEST_MOVING[wtvar_language], 32);
		queue.enqueue_now_P(PSTR("G28 X F2000"));
		axisState = SAE_XMOVING;
	}
}


void DGUS_Screen_SelfTest::doyhome(void)
{
	if (TEST(axis_homed, Y_AXIS))
	{
		dserial.SendString(ADDR_MACHINE_VALUE5, MMSG_SELF_TEST_PASS[wtvar_language], 32);
		dozhome();
	}
	else
	{
		dserial.SendString(ADDR_MACHINE_VALUE5, MMSG_SELF_TEST_MOVING[wtvar_language], 32);

		queue.enqueue_now_P(PSTR("G28 Y F2000"));
		axisState = SAE_YMOVING;
		axisTime = getcurrenttime();
	}
}


void DGUS_Screen_SelfTest::dozhome(void)
{
	if (TEST(axis_homed, Z_AXIS))
	{
		dserial.SendString(ADDR_MACHINE_VALUE6, MMSG_SELF_TEST_PASS[wtvar_language], 32);
        queue.enqueue_now_P(PSTR("G1 Z50 F1500"));
		axisState = SAE_END;
	}
	else
	{
		dserial.SendString(ADDR_MACHINE_VALUE6, MMSG_SELF_TEST_MOVING[wtvar_language], 32);

		queue.enqueue_now_P(PSTR("G28 Z F500"));
		axisState = SAE_ZMOVING;
		axisTime = getcurrenttime();
	}
}
#endif