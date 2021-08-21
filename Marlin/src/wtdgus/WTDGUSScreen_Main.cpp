/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../MarlinCore.h"
#include "../module/temperature.h"
#include "../sd/cardreader.h"
#include "../module/planner.h"
#include "WTDGUSScreen_Main.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "../wtlib/WTCounter.h"
#include "../wtlib/WTCMD.h"
#include "WTHelpDoc.h"

extern uint8_t wifiStatus;
extern char ipAddress[16];
extern uint8_t esp32_signal;

#ifdef DGUS_LCD

void DGUS_Screen_Main::Init()
{
	dserial.LoadScreen(SCREEN_MAIN);

	lasttemp_nozzle0 = -100;
    lasttemp_nozzle1 = -100;
	lasttemp_bed = -100;

	dserial.SendString(ADDR_MAIN_TEXT1, MMSG_MAIN_BUTTON1[wtvar_language], 20);
	dserial.SendString(ADDR_MAIN_TEXT2, MMSG_MAIN_BUTTON2[wtvar_language], 20);
	dserial.SendString(ADDR_MAIN_TEXT3, MMSG_MAIN_BUTTON3[wtvar_language], 20);
	dserial.SendString(ADDR_MAIN_TEXT4, MMSG_MAIN_BUTTON4[wtvar_language], 20);

	WT_Get_IP();
	ShowTemperature();
	ShowIP();

	holdontime = getcurrenttime();
	chktmpcount = 3;

#ifdef POWER_SAVE
	wt_timer.start();
#endif
}

void DGUS_Screen_Main::Update()
{
	ShowTemperature();

	if (wifiStatus != lastwifiStatus)
		ShowIP();

	if (checkcount < 0)
	{
		if (wifiStatus != WIFI_OK)
			checkcount = 10;
		else
			checkcount = 60;
	}

	if (checkcount > 0)
		checkcount--;

	if (checkcount == 0)
	{
		WT_Get_IP();
		checkcount = -1;
	}

}

void DGUS_Screen_Main::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MAIN_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_MAIN_BUTTON1)
			{	
				if (wt_onlineprinting == SPARK_LOST)
					dgus.GotoSDMenu();
				else
					PrintChoice();
			}
			else if (gltouchpara.value == KEY_MAIN_BUTTON2)
			{	
				dgus.GotoPrepareMenu();
			}
			else if (gltouchpara.value == KEY_MAIN_BUTTON3)
			{	
				dgus.GotoControlMenu();
			}
			else if (gltouchpara.value == KEY_MAIN_BUTTON4)
			{	
				dgus.GotoHelpMenu();
			}
		}
		else if (gltouchpara.address == ADDR_2OPTION_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2OPTION_BUTTON_RETURN)
			{
				dserial.LoadScreen(SCREEN_MAIN);
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM1)
			{
				dgus.GotoSDMenu();
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM2)
			{
				dgus.GotoWifiDisk();
			}
            else if (gltouchpara.value == KEY_2OPTION_BUTTON_HELP)
			{
				dgus.ShowHelp(HELP_TIP22_LINE[wtvar_language]);
			}
		}
        else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_MAIN);
			}
		}
	}
}

void DGUS_Screen_Main::ShowTemperature(void)
{
	temp_nozzle0 = thermalManager.degHotend(0);
    temp_nozzle1 = thermalManager.degHotend(1);
	temp_bed = thermalManager.degBed();

	if ((lasttemp_nozzle0 != temp_nozzle0) || (lasttemp_nozzle1 != temp_nozzle1) ||(lasttemp_bed != temp_bed))
	{
		if (temp_nozzle0 >= 0)
			dserial.SendString(ADDR_MAIN_TEXT_NOZZLE1, temp_nozzle0, 3);
		else
			dserial.SendString(ADDR_MAIN_TEXT_NOZZLE1, 0, 3);

        if (temp_nozzle1 >= 0)
			dserial.SendString(ADDR_MAIN_TEXT_NOZZLE2, temp_nozzle1, 3);
		else
			dserial.SendString(ADDR_MAIN_TEXT_NOZZLE2, 0, 3);

		if (temp_bed >= 0)
			dserial.SendString(ADDR_MAIN_TEXT_BED, temp_bed, 3);
		else
			dserial.SendString(ADDR_MAIN_TEXT_BED, 0, 3);
	}

	lasttemp_nozzle0 = temp_nozzle0;
    lasttemp_nozzle1 = temp_nozzle1;
	lasttemp_bed = temp_bed;
}

void DGUS_Screen_Main::ShowIP(void)
{
	if (wifiStatus == WIFI_OK)
	{
		switch (esp32_signal)
		{
		case 1:
			dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_WIFI1);
			break;

		case 2:
			dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_WIFI2);
			break;

		case 3:
			dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_WIFI3);
			break;

		case 4:
			dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_WIFI4);
			break;
		
		default:
			dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_WIFI0);
			break;
		}
	}
	else if (wifiStatus == WIFI_OFF)
	{
		dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_WIFIOFF);
	}
	else if (wifiStatus == WIFI_UNKNOWN)
	{
		dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_NOWIFI);
		dserial.SendString(ADDR_MAIN_TEXT_IP, MSG_WIFINOTCONNECTED, 15);
	}
	dserial.SendString(ADDR_MAIN_TEXT_IP, ipAddress, 15);
	lastwifiStatus = wifiStatus;
}

void DGUS_Screen_Main::PrintChoice(void)
{
	dserial.LoadScreen(SCREEN_2OPTION);

	dserial.SendString(ADDR_2OPTION_TEXT_TITLE, MMSG_STORE_TITLE[wtvar_language], TEXTLEN_2OPTION_TITLE);
	dserial.SendInt16(ADDR_2OPTION_ICON_HELP, ENUM_HELP_ICON_HELP);
	dserial.SendString(ADDR_2OPTION_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_2OPTION_BUTTON);

	dserial.SendString(ADDR_2OPTION_TEXT_BUTTON1, MMSG_STORE_TF[wtvar_language], TEXTLEN_2OPTION_ITEM);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON1, ENUM_SETTING_TFCAED);

	dserial.SendString(ADDR_2OPTION_TEXT_BUTTON2, MMSG_STORE_WIFIDISK[wtvar_language], TEXTLEN_2OPTION_ITEM);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON2, ENUM_SETTING_WIFIDISK);

	if (!dgus.ndisk_pageload)
		wt_ndisk_read_page_count();
}
#endif
