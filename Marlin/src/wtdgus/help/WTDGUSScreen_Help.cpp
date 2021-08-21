/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "WTDGUSScreen_Help.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_Help::Init()
{
	dserial.LoadScreen(SCREEN_HELPMENU);

	holdontime = getcurrenttime();

	dserial.SendString(ADDR_HELPMENU_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], TEXTLEN_HELPMENU_TITLE);
	dserial.SendString(ADDR_HELPMENU_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELPMENU_BUTTON);

	dserial.SendInt16(ADDR_HELPMENU_ICON1, ENUM_SETTING_DIAG);
	dserial.SendString(ADDR_HELPMENU_ITEM1, MMSG_HELP_DIAG[wtvar_language], TEXTLEN_HELPMENU_ITEM);

	dserial.SendInt16(ADDR_HELPMENU_ICON2, ENUM_SETTING_WIKI);
	dserial.SendString(ADDR_HELPMENU_ITEM2, MMSG_HELP_WIKI[wtvar_language], TEXTLEN_HELPMENU_ITEM);

	dserial.SendInt16(ADDR_HELPMENU_ICON3, ENUM_SETTING_CONTACT);
	dserial.SendString(ADDR_HELPMENU_ITEM3, MMSG_HELP_CONTACT[wtvar_language], TEXTLEN_HELPMENU_ITEM);

}

void DGUS_Screen_Help::Update()
{
	// do nothing
}

void DGUS_Screen_Help::KeyProcess()
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
				dgus.GotoErrorDiaglogMenu();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM2)
			{
                dserial.SendString(ADDR_QR_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_QR_BUTTON);
				dgus.ShowQR(MMSG_WIKI_TITLE[wtvar_language], MMSG_WIKI_URL);
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM3)
			{
				dserial.LoadScreen(SCREEN_INFO);

                dserial.SendString(ADDR_INFO_TITLE, MMSG_CONTACT_TITLE[wtvar_language], TEXTLEN_HELP1_TITLE);
                dserial.SendString(ADDR_INFO_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELP1_BUTTON);
                dserial.SendLongString(ADDR_INFO_LINE, MMSG_CONTACT_TEXT[wtvar_language], 510);

			}
		}
		else if (gltouchpara.address == ADDR_QR_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_QR_BUTTON_RETURN)
			{	
				dgus.GotoHelpMenu();
			}
		}
        else if (gltouchpara.address == ADDR_INFO_KEY)
		{
			gltouchpara.validflg = false;
			dserial.LoadScreen(SCREEN_HELPMENU);
		}
	}
}

#endif