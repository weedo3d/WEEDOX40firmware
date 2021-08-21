/**
* Copyright (C) 2021 Wiibooxtech Perron
*/
#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../wtlib/WTCMD.h"
#include "../../wtlib/WTUtilty.h"
#include "WTDGUSScreen_WifiDisk.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

extern char ipAddress[16];
extern char esp32_version[8];
extern char uploadFilename[FILENAME_LENGTH];

#ifdef DGUS_LCD

void DGUS_Screen_WifiDisk::Init()
{
	dserial.SendString(ADDR_TF_TITLE, MMSG_TF_TITLE[wtvar_language], TEXTLEN_TF_TITLE);
	dserial.SendString(ADDR_TF_BACK_TEXT, MMSG_BACK[wtvar_language], TEXTLEN_TF_BUTTON);
	dserial.SendInt16(ADDR_TF_HELP_ICON, ENUM_HELP_ICON_HELP);

	activated = true;

	dgus.ShowLoading();
	wt_ndisk_read_page();

	holdontime = getcurrenttime();

}

void DGUS_Screen_WifiDisk::Update()
{

}

void DGUS_Screen_WifiDisk::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_TF_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_TF_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_TF_PRE)
			{
				if (dgus.ndisk_pageid > 0)
				{
					dgus.ndisk_pageid--;
					dgus.ShowLoading();
					wt_ndisk_read_page();
				}
			}
			else if (gltouchpara.value == KEY_TF_NEXT)
			{
				if (dgus.ndisk_pageid < dgus.ndisk_pagecount - 1)
				{
					dgus.ndisk_pageid++;
					dgus.ShowLoading();
					wt_ndisk_read_page();
				}
			}
			else if (gltouchpara.value >= KEY_TF_FILE1 && gltouchpara.value <= KEY_TF_FILE6 )//4-7 selected file
			{
				uint16_t _len = Utf8ToUnicode(dgus.ndisk_filelist[gltouchpara.value - 4], filename_buffer);
				dgus.SetFileInfo((gltouchpara.value - 4 + dgus.ndisk_pagecount * 6), filename_buffer, _len);
				dgus.jobinfo.remote = true;
				ZERO(uploadFilename);
				strcpy(uploadFilename, dgus.ndisk_filelist[gltouchpara.value - 4]);
				wt_ndisk_read_fileinfo();
				dgus.ShowLoading();
			}
			else if (gltouchpara.value == KEY_TF_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_INFO_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_INFO_RETURN)
			{	
				Goback();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				ShowPage();
			}
		}
	}
}

void DGUS_Screen_WifiDisk::ShowPage(void)
{
	dserial.LoadScreen(SCREEN_SDCARD);

	uint8_t curIndex = 0;
	while (curIndex < dgus.ndisk_listcount)
	{
		ZERO(filename_buffer);

		uint16_t _len = Utf8ToUnicode(dgus.ndisk_filelist[curIndex], filename_buffer);
		ShowFileInfo(filename_buffer, _len, curIndex);
		curIndex++;
	}

	while (curIndex < 6)
	{
		ShowFileInfo(NULL, 0, curIndex);
		curIndex++;
	}
	
	if (dgus.ndisk_pageid == 0)
		dserial.SendEmptyString(ADDR_TF_PRE_TEXT, TEXTLEN_TF_BUTTON);
	else
		dserial.SendString(ADDR_TF_PRE_TEXT, MMSG_PRE_PAGE[wtvar_language], TEXTLEN_TF_BUTTON);

	if (dgus.ndisk_pageid >= (dgus.ndisk_pagecount - 1))
		dserial.SendEmptyString(ADDR_TF_NEXT_TEXT, TEXTLEN_TF_BUTTON);
	else
		dserial.SendString(ADDR_TF_NEXT_TEXT, MMSG_NEXT_PAGE[wtvar_language], TEXTLEN_TF_BUTTON);

}

void DGUS_Screen_WifiDisk::ShowFileInfo(char* filename, uint16_t len, uint8_t index)
{
	if (len == 0)
		dserial.SendEmptyUnicodeString(DGUS_SDMENU_FILENAME_ADDR + index * DGUS_SDMENU_FILENAME_INTERVAL, TEXTLEN_TF_ITEM);
	else
		dserial.SendUnicodeString(DGUS_SDMENU_FILENAME_ADDR + index * DGUS_SDMENU_FILENAME_INTERVAL, filename, len, TEXTLEN_TF_ITEM);
}

void DGUS_Screen_WifiDisk::ShowHelp(void)
{
	dgus.ShowHelp(HELP_TIP21_LINE[wtvar_language]);
}

#endif