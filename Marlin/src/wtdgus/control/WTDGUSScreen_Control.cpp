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
#include "../../module/configuration_store.h"
#include "WTDGUSScreen_Control.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"
#include "../../feature/runout.h"

#ifdef DGUS_LCD
// 设置菜单 
void DGUS_Screen_Control::Init()
{
	dserial.LoadScreen(SCREEN_SETTING);
	holdontime = getcurrenttime();
	dserial.SendString(ADDR_SETTING_TEXT_TITLE, MMSG_SETTING_TITLE[wtvar_language], TEXTLEN_SETTING_TITLE);
	dserial.SendString(ADDR_SETTING_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_SETTING_BUTTON);
	dserial.SendInt16(ADDR_SETTING_ICON_HELP, ENUM_HELP_ICON_HELP);
	ShowPage();
	clickCount = 0;

	//WT_Get_ESP32Version();
	//WT_Get_IP();
}

void DGUS_Screen_Control::Update()
{
	// do nothing
}

void DGUS_Screen_Control::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		gltouchpara.validflg = false;
		if (gltouchpara.address == ADDR_SETTING_KEY)
		{
			if (gltouchpara.value == KEY_SETTING_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_SETTING_NEXT)
			{
				ShowNextPage();

                if (pageid == 2)
                {
                	clickCount++;
					if (clickCount >= 10)
					{
						clickCount = 0;
						dgus.GotoTestModeMenu();
					}
                }
			}
			else if (gltouchpara.value == KEY_SETTING_PRE)
			{
				ShowPrePage();
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM1)
			{
				if (pageid == 0)
				{	// 第1页第1项
                    // wifi设置
					dgus.GotoWifiSettingMenu();
				}
				else if (pageid == 1)
				{	// 第2页第1项
                    // 保存关机
                    if (wtvar_enablepoweroff)
					{
						wtvar_enablepoweroff = 0;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_OFF);
					}
					else
					{
						wtvar_enablepoweroff = 1;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_ON);
					}
					(void)settings.save();
				}
				else if (pageid == 2)
				{	// 第3页第1项
                    // 节能设置
                    dgus.GotoPowerSaveMenu();
				}
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM2)
			{
				if (pageid == 0)
				{	// 第1页第2项
                    // 语言设置
					dgus.GotoLanguageMenu();
				}
				else if (pageid == 1)
				{	// 第2页第2项
                    // 断丝检测 
                    if (wtvar_enablefilamentruncout)
					{
						wtvar_enablefilamentruncout = 0;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_OFF);
						runout.enabled = false;
					}
					else
					{
						wtvar_enablefilamentruncout = 1;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_ON);
						runout.enabled = true;
					}
					(void)settings.save();
				}
				else if (pageid == 2)
				{	// 第3页第2项
					// 固件升级
                    dgus.GotoIAPMenu();
				}
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM3)
			{
				if (pageid == 0)
				{	// 第1页第3项
                    // 设备信息
					dgus.GotoMachineInfoMenu();
				}
				else if (pageid == 1)
				{	// 第2页第3项
                    // 开机自检
                    if (wtvar_enableselftest)
					{
						wtvar_enableselftest = 0;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_OFF);
					}
					else
					{
						wtvar_enableselftest = 1;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_ON);
					}
					(void)settings.save();	
				}
				else if (pageid == 2)
				{	// 第3页第3项
                    // 参数设置
                    dgus.GotoRestoreSettingMenu();
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

void DGUS_Screen_Control::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_Control::ShowNextPage(void)
{
	if (pageid < 2)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_Control::ShowPage(void)
{
	if (pageid == 0)
	{
		dserial.SendEmptyString(ADDR_SETTING_TEXT_PRE, TEXTLEN_SETTING_BUTTON);
		dserial.SendString(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		// 第1页第1项
        // wifi设置
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_WIFI);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_WIFI[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第1页第2项
        // 语言设置
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_LANGUAGE);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_LANGUAGE[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第1页第3项
        // 设备信息
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_INFO);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_INFO[wtvar_language], TEXTLEN_SETTING_ITEM);

	}
	else if (pageid == 1)
	{
		dserial.SendString(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		// 第2页第1项
        // 保存关机
        if (wtvar_enablepoweroff)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_POWEROFF);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_POWEROFF[wtvar_language], TEXTLEN_SETTING_ITEM);

        // 第2页第2项
        // 断丝检测 
		if (wtvar_enablefilamentruncout)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_RUNOUT);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_RUNOUT[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第2页第3项
        // 开机自检
		if (wtvar_enableselftest)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_SELFTEST);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_SELFTEST[wtvar_language], TEXTLEN_SETTING_ITEM);

	}
	else if (pageid == 2)
	{
		dserial.SendString(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendEmptyString(ADDR_SETTING_TEXT_NEXT, TEXTLEN_SETTING_BUTTON);

		// 第3页第1项
        // 节能设置
        dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_POWERSAVING);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_POWERSAVE[wtvar_language], 32);

        // 第3页第2项
        // 固件升级
        dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_UPDATE);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_IAP[wtvar_language], TEXTLEN_SETTING_ITEM);

        // 第3页第3项
        // 参数设置
        dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_RESTORE);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_RESTORE[wtvar_language], TEXTLEN_SETTING_ITEM);
	}
}

void DGUS_Screen_Control::ShowHelp(void)
{
	if (pageid == 0)
	{
		dgus.ShowHelp(HELP_TIP11_LINE[wtvar_language]);
	}
	else if (pageid == 1)
	{
		dgus.ShowHelp(HELP_TIP12_LINE[wtvar_language]);
	}
	else if (pageid == 2)
	{
        dgus.ShowHelp(HELP_TIP13_LINE[wtvar_language]);
	}

}
#endif