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
#include "WTDGUSScreen_Prepare.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD
// 准备菜单
void DGUS_Screen_Prepare::Init()
{
	dserial.LoadScreen(SCREEN_SETTING);
	holdontime = getcurrenttime();
	dserial.SendString(ADDR_SETTING_TEXT_TITLE, MMSG_PREPARE_TITLE[wtvar_language], TEXTLEN_SETTING_TITLE);
	dserial.SendString(ADDR_SETTING_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_SETTING_BUTTON);
	dserial.SendInt16(ADDR_SETTING_ICON_HELP, ENUM_HELP_ICON_HELP);
	ShowPage();
}

void DGUS_Screen_Prepare::Update()
{
	// do nothing
}

void DGUS_Screen_Prepare::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_SETTING_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_SETTING_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_SETTING_NEXT)
			{
				ShowNextPage();
			}
			else if (gltouchpara.value == KEY_SETTING_PRE)
			{
				ShowPrePage();
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM1)
			{
				if (pageid == 0)
				{	// 第1页第1项
                    // 自动进丝
					dgus.GotoLoadFilament(this);
				}
				else if (pageid == 1)
				{	// 第2页第1项
                    // 点动模式
					dgus.GotoJobMenu();
				}
				else if (pageid == 2)
				{	// 第3页第1项
                    // 接近开关
					dgus.GotoProximityMenu();
				}
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM2)
			{
				if (pageid == 0)
				{	// 第1页第2项
                    // 自动退丝
					dgus.GotoUnloadFilament(this);
				}
				else if (pageid == 1)
				{	// 第2页第2项
                    // 平台调平
					dgus.GotoLevelMenu();
				}
				else if (pageid == 2)
				{	// 第3页第2项
					// 喷头偏置
                    dgus.GotoNozzleOffsetMenu();
				}
				
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM3)
			{
				if (pageid == 0)
				{	// 第1页第3项
                    // 手动加热
					dgus.GotoPreheatMenu();
				}
				else if (pageid == 1)
				{	// 第2页第3项
                    // Z轴偏置
					dgus.GotoZOffsetMenu();
				}
				else if (pageid == 2)
				{	// 第3页第3项
					// 关闭电机
                    dgus.ShowMessage(MMSG_MOTOROFF_LINE1[wtvar_language]);
					queue.enqueue_now_P(PSTR("M84"));
				}
			}
			else if (gltouchpara.value == KEY_SETTING_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	// 返回准备界面
				dserial.LoadScreen(SCREEN_SETTING);
			}
		}
	}
}

void DGUS_Screen_Prepare::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_Prepare::ShowNextPage(void)
{
	if (pageid < 2)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_Prepare::ShowPage(void)
{
	if (pageid == 0)
	{
		dserial.SendEmptyString(ADDR_SETTING_TEXT_PRE, TEXTLEN_SETTING_BUTTON);
		dserial.SendString(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		// 第1页第1项
        // 自动进丝
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_FEED_IN);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_FEED[wtvar_language], TEXTLEN_SETTING_ITEM);
		
		// 第1页第2项
        // 自动退丝
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_RETRACT);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_RETRACT[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第1页第3项
        // 手动加热
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_HEAT);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_HEAT[wtvar_language], TEXTLEN_SETTING_ITEM);

	}
	else if (pageid == 1)
	{
		dserial.SendString(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		// 第2页第1项
        // 点动模式
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_JOB);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_JOG[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第2页第2项
        // 平台调平
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_LEVELBED);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_LEVELBED[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第2页第3项
        // Z轴偏置
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_ZOFFSET);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_ZOFFSET[wtvar_language], TEXTLEN_SETTING_ITEM);

	}
	else if (pageid == 2)
	{
		dserial.SendString(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendEmptyString(ADDR_SETTING_TEXT_NEXT, TEXTLEN_SETTING_BUTTON);

		// 第3页第1项
        // 接近开关
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_SENSOR);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_SENSOR[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第3页第2项
        // 喷头偏置
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_NOZZLE_XY);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_NOZZLE_OFFSET[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第3页第3项
        // 关闭电机
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_MOTOROFF);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_MOTOROFF[wtvar_language], TEXTLEN_SETTING_ITEM);
	}
}

void DGUS_Screen_Prepare::ShowHelp(void)
{
	if (pageid == 0)
	{
		dgus.ShowHelp(HELP_TIP06_LINE[wtvar_language]);
	}
	else if (pageid == 1)
	{
		dgus.ShowHelp(HELP_TIP07_LINE[wtvar_language]);
	}
	else if (pageid == 2)
	{
		dgus.ShowHelp(HELP_TIP08_LINE[wtvar_language]);
	}

}

#endif