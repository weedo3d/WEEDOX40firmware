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
#include "WTDGUSScreen_PrintingSetting.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"
#include "../../feature/runout.h"

#ifdef DGUS_LCD
// 打印中参数设置菜单 
void DGUS_Screen_PrintingSetting::Init()
{
	dserial.LoadScreen(SCREEN_SETTING);
	holdontime = getcurrenttime();
	pageid = 0;
	dserial.SendString(ADDR_SETTING_TEXT_TITLE, MMSG_PRINTINT_SETTING_TITLE[wtvar_language], TEXTLEN_SETTING_TITLE);
	dserial.SendString(ADDR_SETTING_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_SETTING_BUTTON);
	dserial.SendInt16(ADDR_SETTING_ICON_HELP, ENUM_HELP_ICON_HELP);
	ShowPage();
}

void DGUS_Screen_PrintingSetting::Update()
{
	// do nothing
}

void DGUS_Screen_PrintingSetting::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_SETTING_KEY)
		{	// 打印设置菜单
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
					if (card.flag.sdprinting)
					{
						dgus.ShowMessageRetrun(MMSG_NOTICE_TITLE[wtvar_language],
						MMSG_BACK[wtvar_language],
						MMSG_PRINTING_NOTICE[wtvar_language]);
					}
					else
						ShowFilamentOption();
				}
				else if (pageid == 1)
				{	// 第2页第1项
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
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM2)
			{
				if (pageid == 0)
				{	// 第1页第2项
					ShowTempSetting();
				}
				else if (pageid == 1)
				{	// 第2页第2项
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

			}
			else if (gltouchpara.value == KEY_SETTING_ITEM3)
			{
				if (pageid == 0)
				{	// 第1页第3项
					dgus.GotoSpeedSettingMenu();
				}
				else if (pageid == 1)
				{	// 第2页第3项
					dgus.GotoSavePrintingMenu();
				}
			}
			else if (gltouchpara.value == KEY_SETTING_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_2OPTION_KEY)
		{	// 料丝菜单
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2OPTION_BUTTON_RETURN)
			{
				dserial.LoadScreen(SCREEN_SETTING);
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM1)
			{
				dgus.GotoLoadFilament(this);
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM2)
			{
				dgus.GotoUnloadFilament(this);
			}
		}
		else if (gltouchpara.address == ADDR_TEMP_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_TEMP_BUTTON2)
			{
				thermalManager.setTargetHotend(target_nozzle0, 0);
				thermalManager.setTargetHotend(target_nozzle1, 1);
				thermalManager.setTargetBed(target_bed);

				dserial.LoadScreen(SCREEN_SETTING);
			}
			else if (gltouchpara.value == KEY_TEMP_BUTTON1)
			{
				dserial.LoadScreen(SCREEN_SETTING);
			}
            else if (gltouchpara.value == KEY_TEMP_RESET1)
			{
				target_nozzle0 = 0;
                dserial.SendTemp(ADDR_TEMP_TEXT_VALUE1, target_nozzle0);
			}
            else if (gltouchpara.value == KEY_TEMP_RESET3)
			{
				target_nozzle1 = 0;
			    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE3, target_nozzle1);
			}
            else if (gltouchpara.value == KEY_TEMP_RESET2)
			{
				target_bed = 0;
			    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE2, target_bed);
			}
		}
		else if (gltouchpara.address == ADDR_TEMP_VALUE1)
		{	// 温度设置菜单
			gltouchpara.validflg = false;
			target_nozzle0 = gltouchpara.value;
			dserial.SendTemp(ADDR_TEMP_TEXT_VALUE1, target_nozzle0);
		}
		else if (gltouchpara.address == ADDR_TEMP_VALUE2)
		{	// 温度设置菜单
			gltouchpara.validflg = false;
			target_bed = gltouchpara.value;
			dserial.SendTemp(ADDR_TEMP_TEXT_VALUE2, target_bed);
		}
        else if (gltouchpara.address == ADDR_TEMP_VALUE3)
		{
			gltouchpara.validflg = false;
			target_nozzle1 = gltouchpara.value;
			dserial.SendTemp(ADDR_TEMP_TEXT_VALUE3, target_nozzle1);
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	// 返回设置界面
				dserial.LoadScreen(SCREEN_SETTING);
			}
		}
	}
}


void DGUS_Screen_PrintingSetting::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_PrintingSetting::ShowNextPage(void)
{
	if (pageid < 1)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_PrintingSetting::ShowPage(void)
{
	if (pageid == 0)
	{
		dserial.SendEmptyString(ADDR_SETTING_TEXT_PRE, TEXTLEN_SETTING_BUTTON);
		dserial.SendString(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		// 第1页第1项
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_FILAMENT);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_FILAMENT[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第1页第2项
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_TEMP);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_TEMP[wtvar_language], TEXTLEN_SETTING_ITEM);
		
		// 第1页第3项
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_SPEED);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_SPEED[wtvar_language], TEXTLEN_SETTING_ITEM);

	}
	else if (pageid == 1)
	{
		dserial.SendString(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendEmptyString(ADDR_SETTING_TEXT_NEXT, TEXTLEN_SETTING_BUTTON);

		// 第2页第1项
		if (wtvar_enablepoweroff)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_POWEROFF);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_POWEROFF[wtvar_language], 32);

        // 第2页第2项
		if (wtvar_enablefilamentruncout)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_RUNOUT);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_RUNOUT[wtvar_language], TEXTLEN_SETTING_ITEM);

		// 第2页第3项
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_SAVE);
		dserial.SendString(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_SAVE[wtvar_language], TEXTLEN_SETTING_ITEM);

	}
}

void DGUS_Screen_PrintingSetting::ShowFilamentOption(void)
{
	dserial.LoadScreen(SCREEN_2OPTION);

	dserial.SendString(ADDR_2OPTION_TEXT_TITLE, MMSG_FILAMENT_OPERATION_TITLE[wtvar_language], TEXTLEN_2OPTION_TITLE);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_2OPTION_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_2OPTION_BUTTON);

	dserial.SendString(ADDR_2OPTION_TEXT_BUTTON1, MMSG_SETTING_FEED[wtvar_language], TEXTLEN_2OPTION_ITEM);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON1, ENUM_SETTING_FEED_IN);

	dserial.SendString(ADDR_2OPTION_TEXT_BUTTON2, MMSG_SETTING_RETRACT[wtvar_language], TEXTLEN_2OPTION_ITEM);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON2, ENUM_SETTING_RETRACT);

}

void DGUS_Screen_PrintingSetting::ShowTempSetting(void)
{
	dserial.LoadScreen(SCREEN_TEMP_SETTING);

	dserial.SendString(ADDR_TEMP_TEXT_TITLE, MMSG_PREHEAT_TITLE[wtvar_language], TEXTLEN_TEMP_TITLE);
	dserial.SendInt16(ADDR_TEMP_ICON_HELP, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_TEMP_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], TEXTLEN_TEMP_BUTTON);
	dserial.SendString(ADDR_TEMP_TEXT_BUTTON2, MMSG_OK[wtvar_language], TEXTLEN_TEMP_BUTTON);
	dserial.SendString(ADDR_TEMP_TEXT_ITEM1, MMSG_STATUS_LABEL_NOZZLE1[wtvar_language], TEXTLEN_TEMP_ITEM);
	dserial.SendString(ADDR_TEMP_TEXT_ITEM3, MMSG_STATUS_LABEL_NOZZLE2[wtvar_language], TEXTLEN_TEMP_ITEM);
	dserial.SendString(ADDR_TEMP_TEXT_ITEM2, MMSG_STATUS_LABEL_BED[wtvar_language], TEXTLEN_TEMP_ITEM);

	target_nozzle0 = thermalManager.degTargetHotend(0);
	target_nozzle1 = thermalManager.degTargetHotend(1);
	target_bed = thermalManager.degBed();

    // 修改显示屏中寄存器数值
	dserial.SendInt16(ADDR_TEMP_VALUE1, target_nozzle0);
	dserial.SendInt16(ADDR_TEMP_VALUE3, target_nozzle1);
	dserial.SendInt16(ADDR_TEMP_VALUE2, target_bed);
	
	ShowTarget();
}

// 显示温度数据字符串
void DGUS_Screen_PrintingSetting::ShowTarget(void)
{
    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE1, target_nozzle0);
    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE3, target_nozzle1);
    dserial.SendTemp(ADDR_TEMP_TEXT_VALUE2, target_bed);
}

void DGUS_Screen_PrintingSetting::ShowHelp(void)
{
	if (pageid == 0)
	{
		dgus.ShowHelp(HELP_TIP03_LINE1[wtvar_language]);
	}
	else if (pageid == 1)
	{
		dgus.ShowHelp(HELP_TIP03_LINE2[wtvar_language]);
	}
}
#endif