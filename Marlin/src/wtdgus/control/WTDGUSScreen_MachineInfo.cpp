/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

/*
* DGus 
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/printcounter.h"
#include "../../libs/duration_t.h"
#include "WTDGUSScreen_MachineInfo.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCMD.h"

extern char esp32_name[12];
extern char esp32_serial[16];

#ifdef DGUS_LCD
void DGUS_Screen_MachineInfo::Init()
{
	dserial.LoadScreen(SCREEN_MACHINE_INFO);
	holdontime = getcurrenttime();
	WT_Get_ESP32Version();

	dserial.SendString(ADDR_MACHINE_TITLE, MMSG_MACHINE_TITLE[wtvar_language], TEXTLEN_MACHINE_TITLE);
	dserial.SendString(ADDR_MACHINE_BUTTON1, MMSG_BUTTON_QR[wtvar_language], TEXTLEN_MACHINE_BUTTON);
	dserial.SendString(ADDR_MACHINE_BUTTON2, MMSG_BACK[wtvar_language], TEXTLEN_MACHINE_BUTTON);

	dserial.SendInt16(ADDR_MACHINE_ICON_HELP, ENUM_HELP_ICON_NOHELP);

	// name
	dserial.SendString(ADDR_MACHINE_ITEM1, MMSG_MACHINE_ITEM1[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE1, PSTR(MACHINE_NAME), TEXTLEN_MACHINE_ITEM);

	// ¥Ú”° ±º‰
	dserial.SendString(ADDR_MACHINE_ITEM2, MMSG_MACHINE_ITEM2[wtvar_language], TEXTLEN_MACHINE_ITEM);

	printStatistics now = print_job_timer.getStats();
	duration_t elapsed = now.printTime;
	char buffer[21];
	memset(buffer, 0, 21);
	elapsed.toShortTimeString(buffer);
	dserial.SendString(ADDR_MACHINE_VALUE2, buffer, TEXTLEN_MACHINE_ITEM);

	// firmware
	dserial.SendString(ADDR_MACHINE_ITEM3, MMSG_MACHINE_ITEM3[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE3, PSTR(SHORT_BUILD_VERSION), TEXTLEN_MACHINE_ITEM);

	// ui version
	dserial.SendString(ADDR_MACHINE_ITEM4, MMSG_MACHINE_ITEM4[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE4, PSTR(UI_VERSION), TEXTLEN_MACHINE_ITEM);

	// ip
	dserial.SendString(ADDR_MACHINE_ITEM5, MMSG_MACHINE_ITEM5[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE5, esp32_serial, TEXTLEN_MACHINE_ITEM);

	// wifi
	dserial.SendString(ADDR_MACHINE_ITEM6, MMSG_MACHINE_ITEM6[wtvar_language], TEXTLEN_MACHINE_ITEM);
	dserial.SendString(ADDR_MACHINE_VALUE6, esp32_name, TEXTLEN_MACHINE_ITEM);

	dserial.SendEmptyString(ADDR_MACHINE_ERROR1,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR2,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR3,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR4,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR5,  TEXTLEN_MACHINE_ITEM);
	dserial.SendEmptyString(ADDR_MACHINE_ERROR6,  TEXTLEN_MACHINE_ITEM);
}

void DGUS_Screen_MachineInfo::Update()
{
	dserial.SendString(ADDR_MACHINE_VALUE5, esp32_serial, 16);
	dserial.SendString(ADDR_MACHINE_VALUE6, esp32_name, 16);
}

void DGUS_Screen_MachineInfo::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MACHINE_KEY)
		{	
			gltouchpara.validflg = false;
            if (gltouchpara.value == KEY_MACHINE_BUTTON1)
			{
				dgus.ShowQR(MMSG_QR_TITLE[wtvar_language], esp32_serial);
			}
			else if (gltouchpara.value == KEY_MACHINE_BUTTON2)
			{
				Goback();
			}
		}
		else if (gltouchpara.address == ADDR_QR_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_QR_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_MACHINE_INFO);
			}
		}
        
	}
}
#endif