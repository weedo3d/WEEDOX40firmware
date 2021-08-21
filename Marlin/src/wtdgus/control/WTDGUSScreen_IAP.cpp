/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../sd/cardreader.h"
#include "WTDGUSScreen_IAP.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTUtilty.h"
#include "../../wtlib/WTCMD.h"
#include "../../HAL/shared/persistent_store_api.h"

#define FLASH_FILE_NAME     "flash.wfm"
#define FLASH_FILE_HEAD		60
#define FLASH_FORCE_MODE    "20140506.wbs"

#ifdef DGUS_LCD

void DGUS_Screen_IAP::Init()
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString(ADDR_2BINFO_TITLE, MMSG_IAP_TITLE[wtvar_language], TEXTLEN_2BINFO_TITLE);
	dserial.SendLongString(ADDR_2BINFO_TEXT_LINE, MMSG_IAP_TIP[wtvar_language], TEXTLEN_2BINFO_ITEM);

	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON1, MMSG_BACK[wtvar_language], TEXTLEN_2BINFO_BUTTON);
	dserial.SendEmptyString(ADDR_2BINFO_TEXT_BUTTON2,  TEXTLEN_2BINFO_BUTTON);

    state = ISE_IDLE;

}

void DGUS_Screen_IAP::Update()
{
	
}

void DGUS_Screen_IAP::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_2BINFO_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2BINFO_ITEM1)
			{
				Goback();
			}
		}

	}
}

void DGUS_Screen_IAP::do_operation(void)
{
	DGUS_Screen_ScrollList::Init();
    forceMode = false;
	dserial.SendString(ADDR_HELP1_TEXT_TITLE, MMSG_IAP_TITLE[wtvar_language], TEXTLEN_HELP1_TITLE);
	dserial.SendString(ADDR_HELP1_TEXT_RETURN, MMSG_WAITING[wtvar_language], TEXTLEN_HELP1_BUTTON);
    state = ISE_CHECK_FILE;
	Clear();
    AddLine(MMSG_IAP_CHECK_FILE[wtvar_language]);
}
#endif