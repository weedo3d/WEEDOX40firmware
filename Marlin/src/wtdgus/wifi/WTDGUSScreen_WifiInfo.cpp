/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/printcounter.h"
#include "../../libs/duration_t.h"
#include "WTDGUSScreen_WifiInfo.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

extern char esp32_name[12];
extern char esp32_serial[16];
extern char esp32_version[8];
extern char ipAddress[16];
extern char tb_state[20];
extern char esp32_ap[32];

#ifdef DGUS_LCD
void DGUS_Screen_WifiInfo::Init()
{
	dserial.LoadScreen(SCREEN_MACHINE_INFO);
	holdontime = getcurrenttime();

	dserial.SendString(ADDR_MACHINE_TITLE, MMSG_WIFI_INFO_TITLE[wtvar_language], TEXTLEN_MACHINE_TITLE);
	dserial.SendString(ADDR_MACHINE_BUTTON2, MMSG_BACK[wtvar_language], TEXTLEN_MACHINE_BUTTON);
	dserial.SendEmptyString(ADDR_MACHINE_BUTTON1, TEXTLEN_MACHINE_BUTTON);

	dserial.SendInt16(ADDR_MACHINE_ICON_HELP, ENUM_HELP_ICON_NOHELP);

	dserial.SendString(ADDR_MACHINE_ITEM1, MMSG_MACHINE_ITEM1[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE1, esp32_name, TEXTLEN_MACHINE_ITEM);

	dserial.SendString(ADDR_MACHINE_ITEM2, MMSG_MACHINE_ITEM5[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE2, esp32_serial, TEXTLEN_MACHINE_ITEM);

	dserial.SendString(ADDR_MACHINE_ITEM3, MMSG_MACHINE_ITEM3[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE3, esp32_version, TEXTLEN_MACHINE_ITEM);

	// ip
	dserial.SendString(ADDR_MACHINE_ITEM4, MMSG_WIFI_INFO_IP[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE4, ipAddress, TEXTLEN_MACHINE_ITEM);

	// ap
	dserial.SendString(ADDR_MACHINE_ITEM5, MMSG_WIFI_INFO_AP[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE5, esp32_ap, TEXTLEN_MACHINE_ITEM);

	dserial.SendString(ADDR_MACHINE_ITEM6, MMSG_WIFI_INFO_CLOUD[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE6, tb_state, TEXTLEN_MACHINE_ITEM);

	dserial.SendEmptyString(ADDR_MACHINE_ERROR1,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR2,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR3,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR4,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR5,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR6,  TEXTLEN_MACHINE_ITEM);
}

void DGUS_Screen_WifiInfo::Update()
{
	dserial.SendString(ADDR_MACHINE_VALUE4, ipAddress, TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE5, esp32_ap, TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE6, tb_state, TEXTLEN_MACHINE_ITEM);
}

void DGUS_Screen_WifiInfo::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MACHINE_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_MACHINE_BUTTON2)
			{
				Goback();
			}
		}
		
	}
}

#endif