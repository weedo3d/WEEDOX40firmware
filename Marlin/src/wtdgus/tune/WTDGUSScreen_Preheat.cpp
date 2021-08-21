/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Preheat.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#define PREHEAT_TARGET_NOZZLE	200
#define PREHEAT_TARGET_BED		80

#ifdef DGUS_LCD

void DGUS_Screen_Preheat::Init()
{
	dserial.LoadScreen(SCREEN_TEMP_SETTING);

	lasttemp_nozzle0 = -100;
	lasttemp_nozzle1 = -100;
	lasttemp_bed = -100;

	dserial.SendString(ADDR_TEMP_TEXT_TITLE, MMSG_PREHEAT_TITLE[wtvar_language], TEXTLEN_TEMP_TITLE);
	dserial.SendInt16(ADDR_TEMP_ICON_HELP, ENUM_HELP_ICON_HELP);
	dserial.SendString(ADDR_TEMP_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], TEXTLEN_TEMP_BUTTON);
	dserial.SendString(ADDR_TEMP_TEXT_BUTTON2, MMSG_OK[wtvar_language], TEXTLEN_TEMP_BUTTON);
	dserial.SendString(ADDR_TEMP_TEXT_ITEM1, MMSG_STATUS_LABEL_NOZZLE1[wtvar_language], TEXTLEN_TEMP_ITEM);
	dserial.SendString(ADDR_TEMP_TEXT_ITEM3, MMSG_STATUS_LABEL_NOZZLE2[wtvar_language], TEXTLEN_TEMP_ITEM);
	dserial.SendString(ADDR_TEMP_TEXT_ITEM2, MMSG_STATUS_LABEL_BED[wtvar_language], TEXTLEN_TEMP_ITEM);

	dserial.SendInt16(ADDR_TEMP_VALUE1, PREHEAT_TARGET_NOZZLE);
	dserial.SendInt16(ADDR_TEMP_VALUE3, PREHEAT_TARGET_NOZZLE);
	dserial.SendInt16(ADDR_TEMP_VALUE2, PREHEAT_TARGET_BED);
	target_nozzle0 = PREHEAT_TARGET_NOZZLE;
	target_nozzle1 = PREHEAT_TARGET_NOZZLE;
	target_bed = PREHEAT_TARGET_BED;
    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE1, target_nozzle0);
	dserial.SendTemp(ADDR_TEMP_TEXT_VALUE3, target_nozzle1);
    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE2, target_bed);

	isHeating = false;

	holdontime = getcurrenttime();
}

void DGUS_Screen_Preheat::Update()
{
	if (isHeating)
	{
		ShowTemperature();
	}
}

void DGUS_Screen_Preheat::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_TEMP_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_TEMP_BUTTON2)
			{
				thermalManager.setTargetHotend(target_nozzle0, 0);
				thermalManager.setTargetHotend(target_nozzle1, 1);
				thermalManager.setTargetBed(target_bed);
				dserial.LoadScreen(SCREEN_PREHEAT_HEATING);
				dserial.SendString(ADDR_HEAT_TEXT_TITLE, MMSG_HEATING_TITLE[wtvar_language], 30);
				dserial.SendString(ADDR_HEAT_TEXT_BUTTON1, MMSG_SETTING[wtvar_language], 20);
				dserial.SendString(ADDR_HEAT_TEXT_BUTTON2, MMSG_CANCEL[wtvar_language], 20);
				dserial.SendString(ADDR_HEAT_TEXT_ITEM1, MMSG_STATUS_LABEL_NOZZLE1[wtvar_language], 16);
				dserial.SendString(ADDR_HEAT_TEXT_ITEM3, MMSG_STATUS_LABEL_NOZZLE2[wtvar_language], 16);
				dserial.SendString(ADDR_HEAT_TEXT_ITEM2, MMSG_STATUS_LABEL_BED[wtvar_language], 16);

				begin_nozzle0 = thermalManager.degHotend(0);
				begin_nozzle1 = thermalManager.degHotend(1);
				begin_bed = thermalManager.degBed();

				ShowTemperature();

				isHeating = true;
			}
			else if (gltouchpara.value == KEY_TEMP_BUTTON1)
			{
				thermalManager.disable_all_heaters();
				Goback();
			}
            else if (gltouchpara.value == KEY_TEMP_RESET1)
			{
				target_nozzle0 = 0;
                dserial.SendTemp(ADDR_TEMP_TEXT_VALUE1, target_nozzle0);
			}
            else if (gltouchpara.value == KEY_TEMP_RESET3)
			{
				target_nozzle1 = 0;
			    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE3, target_nozzle1);
			}
            else if (gltouchpara.value == KEY_TEMP_RESET2)
			{
				target_bed = 0;
			    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE2, target_bed);
			}
			else if (gltouchpara.value == KEY_TEMP_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HEAT_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HEAT_BUTTON2)
			{
				thermalManager.disable_all_heaters();
				Goback();
			}
			else if (gltouchpara.value == KEY_HEAT_BUTTON1)
			{
				isHeating = false;
				dserial.LoadScreen(SCREEN_TEMP_SETTING);
			}
		}
		else if (gltouchpara.address == ADDR_TEMP_VALUE1)
		{
			gltouchpara.validflg = false;
			target_nozzle0 = gltouchpara.value;
			dserial.SendTemp(ADDR_TEMP_TEXT_VALUE1, target_nozzle0);
		}
		else if (gltouchpara.address == ADDR_TEMP_VALUE2)
		{
			gltouchpara.validflg = false;
			target_bed = gltouchpara.value;
			dserial.SendTemp(ADDR_TEMP_TEXT_VALUE2, target_bed);
		}
        else if (gltouchpara.address == ADDR_TEMP_VALUE3)
		{
			gltouchpara.validflg = false;
			target_nozzle1 = gltouchpara.value;
			dserial.SendTemp(ADDR_TEMP_TEXT_VALUE3, target_nozzle1);
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_TEMP_SETTING);
			}
		}
	}
}

void DGUS_Screen_Preheat::ShowTemperature(void)
{
	temp_nozzle0 = thermalManager.degHotend(0);
	temp_nozzle1 = thermalManager.degHotend(1);
	temp_bed = thermalManager.degBed();

	if ((lasttemp_nozzle0 != temp_nozzle0) || (lasttemp_nozzle1 != temp_nozzle1) ||(lasttemp_bed != temp_bed))
	{
        dserial.SendTemp(ADDR_HEAT_TEXT_TEMP1, temp_nozzle0);
        dserial.SendTemp(ADDR_HEAT_TEXT_TEMP3, temp_nozzle1);
        dserial.SendTemp(ADDR_HEAT_TEXT_TEMP2, temp_bed);

        // temp0 bar
		if (temp_nozzle0 < target_nozzle0 && begin_nozzle0 < target_nozzle0)
		{
			if (temp_nozzle0 > begin_nozzle0)
			{
				percent_nozzle0 = (temp_nozzle0 - begin_nozzle0) * 10 / (target_nozzle0 - begin_nozzle0);
				percent_nozzle0++;
				if (percent_nozzle0 > 10) percent_nozzle0 = 10;
			}
			else
				percent_nozzle0 = 0;
		}
		else
		{
			percent_nozzle0 = 10;
		}

		dserial.SendInt16(ADDR_HEAT_BAR_ITEM1, percent_nozzle0);

        // temp1 bar
        if (temp_nozzle1 < target_nozzle1 && begin_nozzle1 < target_nozzle1)
		{
			if (temp_nozzle1 > begin_nozzle1)
			{
				percent_nozzle1 = (temp_nozzle1 - begin_nozzle1) * 10 / (target_nozzle1 - begin_nozzle1);
				percent_nozzle1++;
				if (percent_nozzle1 > 10) percent_nozzle1 = 10;
			}
			else
				percent_nozzle1 = 0;
		}
		else
		{
			percent_nozzle1 = 10;
		}

		dserial.SendInt16(ADDR_HEAT_BAR_ITEM3, percent_nozzle1);

        // bed bar
		if (temp_bed < target_bed && begin_bed < target_bed)
		{
			if (temp_bed > begin_bed)
			{
				percent_bed = (temp_bed - begin_bed) * 10 / (target_bed - begin_bed);
				percent_bed++;
				if (percent_bed > 10) percent_bed = 10;
			}
			else
				percent_bed = 0;
		}
		else
		{
			percent_bed = 10;
		}

		dserial.SendInt16(ADDR_HEAT_BAR_ITEM2, percent_bed);

	}

	lasttemp_nozzle0 = temp_nozzle0;
	lasttemp_nozzle1 = temp_nozzle1;
	lasttemp_bed = temp_bed;
}

void DGUS_Screen_Preheat::ShowHelp(void)
{
	dgus.ShowHelp(HELP_TIP09_LINE[wtvar_language]);
}

#endif