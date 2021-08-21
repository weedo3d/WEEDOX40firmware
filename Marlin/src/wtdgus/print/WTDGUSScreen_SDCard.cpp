/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_SDCard.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"
#include "../../wtlib/WTUtilty.h"

#ifdef DGUS_LCD

void DGUS_Screen_SDCard::Init()
{
	dserial.LoadScreen(SCREEN_SDCARD);

	dserial.SendString(ADDR_TF_TITLE, MMSG_TF_TITLE[wtvar_language], TEXTLEN_TF_TITLE);
	dserial.SendString(ADDR_TF_BACK_TEXT, MMSG_BACK[wtvar_language], TEXTLEN_TF_BUTTON);
	dserial.SendInt16(ADDR_TF_HELP_ICON, ENUM_HELP_ICON_HELP);

	if (card.flag.mounted)
	{
		if (NeedUpdate)
			UpdateFilelist();

		ShowPage(pageid);
	}
	else
	{
		filecount = 0;
		pagecount = 0;
		ClearList();
		NeedUpdate = true;
	}

	cardStatus = card.flag.mounted;

	holdontime = getcurrenttime();
}

void DGUS_Screen_SDCard::Update()
{
	if (cardStatus != card.flag.mounted)
	{
		if (card.flag.mounted)
		{
			if (NeedUpdate)
				UpdateFilelist();

			ShowPage(pageid);
		}
		else
		{
			filecount = 0;
			pagecount = 0;
			ClearList();
			NeedUpdate = true;
		}

		cardStatus = card.flag.mounted;
	}
}

void DGUS_Screen_SDCard::KeyProcess()
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
			else if (gltouchpara.value == KEY_TF_PRE)//page up
			{
				ShowPrePage();
			}
			else if (gltouchpara.value == KEY_TF_NEXT)//page down
			{
				ShowNextPage();
			}
			else if (gltouchpara.value >= KEY_TF_FILE1 && gltouchpara.value <= KEY_TF_FILE6 && filelist[gltouchpara.value - 4].len > 0)//4-7 selected file
			{
				dgus.SetFileInfo((gltouchpara.value - 4 + pageid * 6), &filelist[gltouchpara.value - 4]);
				dgus.GotoPreviewMenu(PREVIEW_PARENT_SD);
			}
			else if (gltouchpara.value == KEY_TF_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_SDCARD);
			}
		}
	}
}

void DGUS_Screen_SDCard::ShowFileInfo(char* filename, uint16_t len, uint8_t index)
{
	if (len == 0)
		dserial.SendEmptyUnicodeString(DGUS_SDMENU_FILENAME_ADDR + index * DGUS_SDMENU_FILENAME_INTERVAL, TEXTLEN_TF_ITEM);
	else
		dserial.SendUnicodeString(DGUS_SDMENU_FILENAME_ADDR + index * DGUS_SDMENU_FILENAME_INTERVAL, filename, len, TEXTLEN_TF_ITEM);
}

void DGUS_Screen_SDCard::ShowPage(uint8_t id)
{
	uint8_t beginPos, endPos, curIndex;

	beginPos = id * 6;
	if (filecount - beginPos > 6)
		endPos = beginPos + 6;
	else
		endPos = filecount - 1;

	curIndex = 0;
	while (beginPos <= endPos && curIndex < 6)
	{
		card.selectFileByIndex(beginPos);

		uint16_t _len = strlen(card.longFilename) * 2;
        if (_len > 0)
        {
            memcpy(filename_buffer, card.longlongFilename, _len);
        }
        else
        {
            _len = strlen(card.filename) * 2;
            ZERO(filename_buffer);
            Utf8ToUnicode(card.filename, filename_buffer);
        }
         
		ShowFileInfo(filename_buffer, _len, curIndex);

		memcpy(filelist[curIndex].buffer, filename_buffer, _len);
		filelist[curIndex].len = _len;

		curIndex++;
		beginPos++;
	}

	while (curIndex < 6)
	{
		ShowFileInfo(NULL, 0, curIndex);
		ZERO(filelist[curIndex].buffer);
		filelist[curIndex].len = 0;
		curIndex++;
	}

	if (pageid == 0)
	{
		dserial.SendEmptyString(ADDR_TF_PRE_TEXT, TEXTLEN_TF_BUTTON);
		if (pagecount > 1)
			dserial.SendString(ADDR_TF_NEXT_TEXT, MMSG_NEXT_PAGE[wtvar_language], TEXTLEN_TF_BUTTON);
		else
			dserial.SendEmptyString(ADDR_TF_NEXT_TEXT, TEXTLEN_TF_BUTTON);
	}
	else if (pageid == (pagecount - 1))
	{
		dserial.SendEmptyString(ADDR_TF_NEXT_TEXT, TEXTLEN_TF_BUTTON);
		dserial.SendString(ADDR_TF_PRE_TEXT, MMSG_PRE_PAGE[wtvar_language], TEXTLEN_TF_BUTTON);
	}
	else
	{
		dserial.SendString(ADDR_TF_PRE_TEXT, MMSG_PRE_PAGE[wtvar_language], TEXTLEN_TF_BUTTON);
		dserial.SendString(ADDR_TF_NEXT_TEXT, MMSG_NEXT_PAGE[wtvar_language], TEXTLEN_TF_BUTTON);
	}
}

void DGUS_Screen_SDCard::ShowPrePage(void)
{
	if (filecount > 0 && pageid > 0)
	{
		pageid--;
		ShowPage(pageid);
	}
}

void DGUS_Screen_SDCard::ShowNextPage(void)
{
	if (filecount > 0 && (pageid + 1) < pagecount)
	{
		pageid++;
		ShowPage(pageid);
	}
}

void DGUS_Screen_SDCard::ClearList(void)
{
	for (int i = 0; i < 6; i++)
		ShowFileInfo(NULL, 0, i);

	dserial.SendEmptyString(ADDR_TF_PRE_TEXT, TEXTLEN_TF_BUTTON);
	dserial.SendEmptyString(ADDR_TF_NEXT_TEXT, TEXTLEN_TF_BUTTON);
}

void DGUS_Screen_SDCard::ShowHelp(void)
{
	dgus.ShowHelp(HELP_TIP01_LINE[wtvar_language]);
}

void DGUS_Screen_SDCard::UpdateFilelist(void)
{
	filecount = card.get_num_Files();
	if (filecount % 6 > 0)
		pagecount = filecount / 6 + 1;
	else
		pagecount = filecount / 6;
	pageid = 0;

	NeedUpdate = false;
}
#endif