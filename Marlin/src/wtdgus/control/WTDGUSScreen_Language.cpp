/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/configuration_store.h"
#include "WTDGUSScreen_Language.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"

#ifdef DGUS_LCD

void DGUS_Screen_Language::Init()
{
	dserial.LoadScreen(SCREEN_LANGUAGE_SETTING);

	dserial.SendString(ADDR_LANG_TITLE, MMSG_LANGUAGE_TITLE[wtvar_language], TEXTLEN_LANGUAGE_TITLE);
	dserial.SendString(ADDR_LANG_BACK_TEXT, MMSG_BACK[wtvar_language], TEXTLEN_LANGUAGE_BUTTON);

    pageid = 0;
    ShowPage();

	holdontime = getcurrenttime();
}

void DGUS_Screen_Language::Update()
{

}

void DGUS_Screen_Language::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_LANG_KEY)
		{
			if (gltouchpara.value == KEY_LANG_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_LANG_PRE)
			{
                ShowPrePage();
			}
			else if (gltouchpara.value == KEY_LANG_NEXT)
			{
                ShowNextPage();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM1)
			{
                if (pageid == 0)
                {
                    SetLanguage(1);
                }
                else if (pageid == 1)
                {
                    SetLanguage(2);
                }
			}
			else if (gltouchpara.value == KEY_LANG_ITEM2)
			{
                if (pageid == 0)
                {
                    SetLanguage(4);
                }
                else if (pageid == 1)
                {
                    SetLanguage(7);
                }
			}
			else if (gltouchpara.value == KEY_LANG_ITEM3)
			{
                if (pageid == 0)
                {
                    SetLanguage(5);
                }
			}
			else if (gltouchpara.value == KEY_LANG_ITEM4)
			{
                if (pageid == 0)
                {
                    SetLanguage(6);
                }
			}
            else if (gltouchpara.value == KEY_LANG_ITEM5)
			{
                if (pageid == 0)
                {
                    SetLanguage(3);
                }
			}
            else if (gltouchpara.value == KEY_LANG_ITEM6)
			{
                if (pageid == 0)
                {
                    SetLanguage(0);
                }
			}
		}
		gltouchpara.validflg = false;
	}
}


void DGUS_Screen_Language::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_Language::ShowNextPage(void)
{
	if (pageid < 1)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_Language::ShowPage(void)
{
	if (pageid == 0)
	{
        dserial.SendEmptyString(ADDR_LANG_PRE_TEXT, TEXTLEN_LANGUAGE_BUTTON);
        dserial.SendString(ADDR_LANG_NEXT_TEXT, MMSG_NEXT_PAGE[wtvar_language]);

        dserial.SendString(ADDR_LANG_ITEM1_TEXT, MMSG_LANGUAGE_ITEM2[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendString(ADDR_LANG_ITEM2_TEXT, MMSG_LANGUAGE_ITEM5[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendString(ADDR_LANG_ITEM3_TEXT, MMSG_LANGUAGE_ITEM6[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendString(ADDR_LANG_ITEM4_TEXT, MMSG_LANGUAGE_ITEM7[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendString(ADDR_LANG_ITEM5_TEXT, MMSG_LANGUAGE_ITEM4[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendString(ADDR_LANG_ITEM6_TEXT, MMSG_LANGUAGE_ITEM1[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
	}
	else if (pageid == 1)
	{
        dserial.SendString(ADDR_LANG_PRE_TEXT, MMSG_PRE_PAGE[wtvar_language]);
        dserial.SendEmptyString(ADDR_LANG_NEXT_TEXT, TEXTLEN_LANGUAGE_BUTTON);

        dserial.SendString(ADDR_LANG_ITEM1_TEXT, MMSG_LANGUAGE_ITEM3[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendString(ADDR_LANG_ITEM2_TEXT, MMSG_LANGUAGE_ITEM8[wtvar_language], TEXTLEN_LANGUAGE_ITEM);
        dserial.SendEmptyString(ADDR_LANG_ITEM3_TEXT, TEXTLEN_LANGUAGE_ITEM);
        dserial.SendEmptyString(ADDR_LANG_ITEM4_TEXT, TEXTLEN_LANGUAGE_ITEM);
        dserial.SendEmptyString(ADDR_LANG_ITEM5_TEXT, TEXTLEN_LANGUAGE_ITEM);
        dserial.SendEmptyString(ADDR_LANG_ITEM6_TEXT, TEXTLEN_LANGUAGE_ITEM);
	}
	
}

void DGUS_Screen_Language::SetLanguage(uint8_t langid)
{
    wtvar_language = langid;
    dgus.GotoMain();
    (void)settings.save();
}
#endif