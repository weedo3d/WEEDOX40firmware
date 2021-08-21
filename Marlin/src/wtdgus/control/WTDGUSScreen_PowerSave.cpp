/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/configuration_store.h"
#include "WTDGUSScreen_PowerSave.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCounter.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_PowerSave::Init()
{
	dserial.LoadScreen(SCREEN_SPEED_SETTING);
	holdontime = getcurrenttime();

	dserial.SendString(ADDR_SPEED_TEXT_TITLE, MMSG_POWER_SAVE_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_SPEED_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString(ADDR_SPEED_TEXT_BUTTON2, MMSG_OK[wtvar_language], 20);
	dserial.SendString(ADDR_SPEED_TEXT1, MMSG_POWEROFF_VALUE1[wtvar_language], 15);
	dserial.SendString(ADDR_SPEED_TEXT2, MMSG_POWEROFF_VALUE2[wtvar_language], 15);
	dserial.SendString(ADDR_SPEED_TEXT3, MMSG_POWEROFF_VALUE3[wtvar_language], 15);
	dserial.SendString(ADDR_SPEED_TEXT4, MMSG_POWEROFF_VALUE4[wtvar_language], 15);
	dserial.SendString(ADDR_SPEED_TEXT5, MMSG_POWEROFF_VALUE5[wtvar_language], 15);
	dserial.SendString(ADDR_SPEED_TEXT6, MMSG_POWEROFF_VALUE6[wtvar_language], 15);

	dserial.SendInt16(ADDR_SPEED_ICON_HELP, ENUM_HELP_ICON_HELP);

	if (wtvar_counter < 1)
		ShowButtonOn(1);
	else if (wtvar_counter < 5)
		ShowButtonOn(2);
	else if (wtvar_counter < 10)
		ShowButtonOn(3);
	else if (wtvar_counter < 15)
		ShowButtonOn(4);
	else if (wtvar_counter < 30)
		ShowButtonOn(5);
	else
		ShowButtonOn(6);

	temp_interval = wtvar_counter;
}

void DGUS_Screen_PowerSave::Update()
{
	// do nothing
}

void DGUS_Screen_PowerSave::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_SPEED_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_SPEED_BUTTON1)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON2)
			{
				wtvar_counter = temp_interval;
				wt_timer.SetInterval(wtvar_counter);
				(void)settings.save();
				Goback();
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM1)
			{
				temp_interval = 0;
				ShowButtonOn(1);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM2)
			{
				temp_interval = 1;
				ShowButtonOn(2);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM3)
			{
				temp_interval = 5;
				ShowButtonOn(3);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM4)
			{
				temp_interval = 10;
				ShowButtonOn(4);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM5)
			{
				temp_interval = 15;
				ShowButtonOn(5);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM6)
			{
				temp_interval = 30;
				ShowButtonOn(6);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_SPEED_SETTING);
			}
		}

	}
}

void DGUS_Screen_PowerSave::ShowButtonOn(uint8_t id)
{
	if (id == 1)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 2)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 3)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 4)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 5)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 6)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_ON);
	}
}

void DGUS_Screen_PowerSave::ShowHelp(void)
{
	dgus.ShowHelp(HELP_TIP14_LINE[wtvar_language]);
}

#endif