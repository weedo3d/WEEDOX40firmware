/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../wtlib/WTCMD.h"
#include "WTDGUSScreen_WifiSetting.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

extern char ipAddress[16];
extern char esp32_version[8];

#ifdef DGUS_LCD

void DGUS_Screen_WifiSetting::Init()
{
	dserial.LoadScreen(SCREEN_HELPMENU);
	holdontime = getcurrenttime();
	WT_Get_ESP32Version();
	WT_Get_IP();
	WT_TB_STATE();
	WT_AP_NAME();

	dserial.SendString(ADDR_HELPMENU_TEXT_TITLE, MMSG_WIFISETTING_TITLE[wtvar_language], TEXTLEN_HELPMENU_TITLE);
	dserial.SendString(ADDR_HELPMENU_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELPMENU_BUTTON);

	dserial.SendInt16(ADDR_HELPMENU_ICON1, ENUM_SETTING_WIFICONFIG);
	dserial.SendString(ADDR_HELPMENU_ITEM1, MMSG_WIFISETTING_CONNECT[wtvar_language], TEXTLEN_HELPMENU_ITEM);

	dserial.SendInt16(ADDR_HELPMENU_ICON2, ENUM_SETTING_INFO);
	dserial.SendString(ADDR_HELPMENU_ITEM2, MMSG_SETTING_INFO[wtvar_language], TEXTLEN_HELPMENU_ITEM);

	dserial.SendInt16(ADDR_HELPMENU_ICON3, ENUM_SETTING_UPDATE);
	dserial.SendString(ADDR_HELPMENU_ITEM3, MMSG_SETTING_IAP[wtvar_language], TEXTLEN_HELPMENU_ITEM);

}

void DGUS_Screen_WifiSetting::Update()
{
	// dserial.SendString(ADDR_MACHINE_VALUE1, esp32_version, 16);
	// dserial.SendString(ADDR_MACHINE_VALUE2, ipAddress, 16);
}

void DGUS_Screen_WifiSetting::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_HELPMENU_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELPMENU_BUTTON_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM1)
			{
				dgus.GotoSmartConfigMenu();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM2)
			{
				dgus.GotoWifiInfo();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM3)
			{
				dgus.GotoOTAMenu();
			}
		}
		
	}
}
#endif