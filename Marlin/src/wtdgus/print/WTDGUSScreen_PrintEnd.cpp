/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../module/printcounter.h"
#include "../../libs/duration_t.h"
#include "WTDGUSScreen_PrintEnd.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTGcodeinfo.h"
#include "../../wtlib/WTCMD.h"

#define JUMP_TO_POWEROFF_MENU	10

#ifdef DGUS_LCD
// 打印完成菜单 
void DGUS_Screen_PrintEnd::Init()
{
	dserial.LoadScreen(SCREEN_PRINTING_END);

	dserial.SendString(ADDR_PRINTEND_TEXT_TITLE, MMSG_PRINTEND_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_PRINTEND_TEXT_BACK, MMSG_EXIT[wtvar_language], 20);
	dserial.SendString(ADDR_PRINTEND_TEXT_AGAIN, MMSG_PRINTEND_AGAIN[wtvar_language], 20);
	dserial.SendString(ADDR_PRINTEND_TEXT_FILENAME, MMSG_PRINTEND_FILE[wtvar_language], 30);
	dserial.SendString(ADDR_PRINTEND_TEXT_TIME, MMSG_PRINTEND_TIME[wtvar_language], 30);
	dserial.SendString(ADDR_PRINTEND_TEXT_FILAMENT, MMSG_PRINTEND_FILAMENT[wtvar_language], 30);

	dserial.SendUnicodeString(ADDR_PRINT_VALUE_FILENAME, dgus.jobinfo.fileinfo.buffer, dgus.jobinfo.fileinfo.len, 32);

	// 打印时间
	char b[14];
	memset(b, 0, 14);
	duration_t elapsed = print_job_timer.duration();
	bool has_days = (elapsed.value >= 60 * 60 * 24L);
	elapsed.toDigital(b, has_days);
	dserial.SendString(ADDR_PRINTEND_VALUE_TIME, b, 16);

	dserial.SendString(ADDR_PRINTEND_VALUE_FILAMENT, gcodeinfo.info.filament, 16);

	count = JUMP_TO_POWEROFF_MENU;
	holdontime = getcurrenttime();
}

void DGUS_Screen_PrintEnd::Update()
{
#ifdef POWER_SAVE
	if (count > 0)
	{
		count--;
	}
	else
	{
		if (wtvar_enablepoweroff == 1)
		{
			dgus.GotoPowerOffMenu();
		}
	}
#endif
}

void DGUS_Screen_PrintEnd::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_PRINTEND_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_PRINTEND_BUTTON_BACK)
			{
                queue.enqueue_now_P("M605 S1");
				Goback();
			}
			else if (gltouchpara.value == KEY_PRINTEND_BUTTON_AGAIN)
			{
				if (dgus.jobinfo.remote)
                {   // 打印WIFI盘文件
                    wt_ndisk_print();
                    dgus.ShowLoading();
                }
				else
				{
					// 打印本地文件	
					card.selectFileByIndex(dgus.jobinfo.index);
					card.openAndPrintFile(card.filename);

					dgus.GotoPrintingMenu();
				}
			}
			
		}
	}
}

void DGUS_Screen_PrintEnd::ShowFilename(const char* fname)
{
	// dserial.SendString(ADDR_PRINT_VALUE_FILENAME, fname, 16);
}

#endif