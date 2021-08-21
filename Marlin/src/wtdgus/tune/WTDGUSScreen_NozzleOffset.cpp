/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_NozzleOffset.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_Nozzle_Offset::Init()
{
	dserial.LoadScreen(SCREEN_HELPMENU);

	dserial.SendString(ADDR_HELPMENU_TEXT_TITLE, MMSG_NOZZLE_OFFSET_TITLE[wtvar_language], TEXTLEN_SETTING_TITLE);
	dserial.SendString(ADDR_HELPMENU_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_SETTING_BUTTON);

    dserial.SendInt16(ADDR_HELPMENU_ICON1, ENUM_SETTING_NOZZLE_X);
    dserial.SendString(ADDR_HELPMENU_ITEM1, MMSG_NOZZLE_X_OFFSET[wtvar_language], TEXTLEN_SETTING_ITEM);
    
    dserial.SendInt16(ADDR_HELPMENU_ICON2, ENUM_SETTING_NOZZLE_XY);
    dserial.SendString(ADDR_HELPMENU_ITEM2, MMSG_NOZZLE_XY_OFFSET[wtvar_language], TEXTLEN_SETTING_ITEM);

    dserial.SendInt16(ADDR_HELPMENU_ICON3, ENUM_SETTING_NOZZLE_Z);
    dserial.SendString(ADDR_HELPMENU_ITEM3, MMSG_NOZZLE_Z_OFFSET[wtvar_language], TEXTLEN_SETTING_ITEM);

	holdontime = getcurrenttime();
}

void DGUS_Screen_Nozzle_Offset::Update()
{
	// do nothing
}

void DGUS_Screen_Nozzle_Offset::KeyProcess()
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
                dgus.GotoNozzleXMenu();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM2)
			{
				dgus.GotoNozzleYMenu();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM3)
			{
                dgus.GotoNozzleZMenu();
			}
		}
	}
}

#endif