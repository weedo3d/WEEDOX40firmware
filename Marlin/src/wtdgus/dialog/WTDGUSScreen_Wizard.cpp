/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/configuration_store.h"
#include "WTDGUSScreen_Wizard.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

extern uint8_t wtvar_skipTest;

#ifdef DGUS_LCD

void DGUS_Screen_Wizard::Init()
{
    dserial.LoadScreen(SCREEN_OPTION_EIGHT);

	dserial.SendString(ADDR_OPTEIGHT_TITLE, MMSG_LANGUAGE_TITLE[1], TEXTLEN_OPTEIGHT_TITLE);
	
	dserial.SendString(ADDR_OPTEIGHT_ITEM1_TEXT, MMSG_LANGUAGE_ITEM2[1], TEXTLEN_OPTEIGHT_ITEM);
	dserial.SendString(ADDR_OPTEIGHT_ITEM2_TEXT, MMSG_LANGUAGE_ITEM5[4], TEXTLEN_OPTEIGHT_ITEM);
	dserial.SendString(ADDR_OPTEIGHT_ITEM3_TEXT, MMSG_LANGUAGE_ITEM6[5], TEXTLEN_OPTEIGHT_ITEM);
	dserial.SendString(ADDR_OPTEIGHT_ITEM4_TEXT, MMSG_LANGUAGE_ITEM7[6], TEXTLEN_OPTEIGHT_ITEM);
    dserial.SendString(ADDR_OPTEIGHT_ITEM5_TEXT, MMSG_LANGUAGE_ITEM4[3], TEXTLEN_OPTEIGHT_ITEM);
    dserial.SendString(ADDR_OPTEIGHT_ITEM6_TEXT, MMSG_LANGUAGE_ITEM8[7], TEXTLEN_OPTEIGHT_ITEM);
	dserial.SendString(ADDR_OPTEIGHT_ITEM7_TEXT, MMSG_LANGUAGE_ITEM1[0], TEXTLEN_OPTEIGHT_ITEM);
	dserial.SendString(ADDR_OPTEIGHT_ITEM8_TEXT, MMSG_LANGUAGE_ITEM3[2], TEXTLEN_OPTEIGHT_ITEM);

	holdontime = getcurrenttime();
}

void DGUS_Screen_Wizard::Update()
{
	// do nothing
}

void DGUS_Screen_Wizard::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_OPTEIGHT_KEY)
		{
            gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_OPTEIGHT_ITEM1)
			{
				wtvar_language = 1;
				GotoNext();
			}
			else if (gltouchpara.value == KEY_OPTEIGHT_ITEM2)
			{
				wtvar_language = 4;
				GotoNext();
			}
			else if (gltouchpara.value == KEY_OPTEIGHT_ITEM3)
			{
				wtvar_language = 5;
				GotoNext();
			}
			else if (gltouchpara.value == KEY_OPTEIGHT_ITEM4)
			{
				wtvar_language = 6;
				GotoNext();
			}
            else if (gltouchpara.value == KEY_OPTEIGHT_ITEM5)
			{
				wtvar_language = 3;
				GotoNext();
			}
            else if (gltouchpara.value == KEY_OPTEIGHT_ITEM6)
			{
				wtvar_language = 7;
				GotoNext();
			}
            else if (gltouchpara.value == KEY_OPTEIGHT_ITEM7)
			{
				wtvar_language = 0;
				GotoNext();
			}
			else if (gltouchpara.value == KEY_OPTEIGHT_ITEM8)
			{
				wtvar_language = 2;
				GotoNext();
			}
		}
		
	}
}

void DGUS_Screen_Wizard::GotoNext(void)
{
	if (wtvar_showWelcome == 1)
		wtvar_showWelcome = 0;
    
    (void)settings.save();
    dgus.GotoMain();
}
#endif