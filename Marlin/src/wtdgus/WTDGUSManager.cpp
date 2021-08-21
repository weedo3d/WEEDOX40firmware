/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include <stdarg.h>

#include "../MarlinCore.h"
#include "../sd/cardreader.h"
#include "../module/temperature.h"
#include "WTDGUSManager.h"
#include "WTDGUSConfig.h"
#include "WTDGUSSerial.h"
#include "../wtlib/WTCounter.h"
#include "../../Configuration.h"

#ifdef DGUS_LCD
DGUSManager dgus;

TouchPara gltouchpara;

DGUSManager::DGUSManager()
{

}

void DGUSManager::Init(unsigned long baud, bool doreset)
{
	dserial.Init(baud);

	lcd_sd_status = 2;

	InitMenu();

    if (doreset)
	    reset();

	memset(&jobinfo,0,sizeof(jobinfo));
	testingMode = false;
}

void DGUSManager::Update()
{
	process();

	nowtime = getcurrenttime();
	if (nowtime > screenCurrent->holdontime + screenCurrent->updaterate)
	{
		screenCurrent->holdontime = nowtime;
		screenCurrent->Update();
		// SERIAL_ECHOLNPGM("screen update");
	}

	const uint8_t sd_status = (uint8_t)IS_SD_INSERTED();
	if (sd_status != lcd_sd_status)
	{
		lcd_sd_status = sd_status;

		if (sd_status == 1) 
		{
			SERIAL_ECHOLNPGM("sd insert");
			safe_delay(1000);		
			card.mount();
			screenSDCard->NeedUpdate = true;	
		}
		else 
		{
			SERIAL_ECHOLNPGM("sd removed");
			safe_delay(1000);
			card.release();
		}
	}
}

void DGUSManager::process()
{
	uint8_t b;

	if (dserial.available() < 9)	
		return;

	while (dserial.available() > 0)
	{
		b = (uint8_t)dserial.read();
		if (state == DS_START1)
		{
			if (b == DGUS_START_BYTE_1)
				state = DS_START2;
		}
		else if (state == DS_START2)
		{
			if (b == DGUS_START_BYTE_2)
				state = DS_LEN;
			else
				reset();
		}
		else if (state == DS_LEN)
		{
			if (b < DGUS_PAYLOAD_LENGTH && b > 0)
			{
				expected_length = b;
				state = DS_PAYLOAD;
			}
			else
				reset();
		}
		else if (state == DS_PAYLOAD)
		{
			append(b);

			if (length >= expected_length)
			{
				gltouchpara.address = (payload[1] << 8) | payload[2];

				if (gltouchpara.address == 0x84)
				{
					gltouchpara.value = (payload[6] << 8) | payload[7];
					gltouchpara.validflg = true;
					SERIAL_ECHOLNPAIR("DGUS Screen ID:", gltouchpara.value);
					screenCurrent->KeyProcess();
				}
				else
				{
					gltouchpara.value = (payload[4] << 8) | payload[5];

					if (gltouchpara.address >= 0x1000 && gltouchpara.address <= 0x2FFFF)
					{
						gltouchpara.validflg = true;
						SERIAL_ECHOLNPGM("DGUS key pressed");
						SERIAL_ECHOLNPAIR("addr: ", gltouchpara.address);
						SERIAL_ECHOLNPAIR("val: ", gltouchpara.value);
						screenCurrent->KeyProcess();
						#ifdef POWER_SAVE
						wt_timer.restart();
						#endif
					}
				}
				reset();
			}
		}
	}
}

void DGUSManager::InitMenu()
{
	screenMain = new DGUS_Screen_Main();
	screenPrepare = new DGUS_Screen_Prepare();
	screenControl = new DGUS_Screen_Control();
	screenSDCard = new DGUS_Screen_SDCard();
	screenPrinting = new DGUS_Screen_Printing();
	screenError = new DGUS_Screen_Error();
	screenPrintEnd = new DGUS_Screen_PrintEnd();
	screenPowerOff = new DGUS_Screen_PowerOff();
	screenPrintingSetting = new DGUS_Screen_PrintingSetting();
	screenLevelbed = new DGUS_Screen_Levelbed();
	screenFilament = new DGUS_Screen_Filament();
	screenPreheat = new DGUS_Screen_Preheat();;
	screenMachineInfo = new DGUS_Screen_MachineInfo();
	screenWifiSetting = new DGUS_Screen_WifiSetting();
	screenSavePrinting = new DGUS_Screen_SavePrinting();
	screenResumePrinting = new DGUS_Screen_ResumePrinting();
	screenBoot = new DGUS_Screen_Boot();
	screenRestoreSetting = new DGUS_Screen_RestoreSetting();
	screenTestMode = new DGUS_Screen_TestMode();
	screenSmartConfig = new DGUS_Screen_SmartConfig();
	screenMessageReturn = new DGUS_Screen_Message_Return();
	screenMessageNoReturn = new DGUS_Screen_Message_NoReturn();
	screenOTA = new DGUS_Screen_OTA();
	screenZOffset = new DGUS_Screen_ZOffset();
	screenLanguage = new DGUS_Screen_Language();
	screenJob = new DGUS_Screen_Job();
	screenProximity = new DGUS_Screen_Proximity();
	screenSpeed = new DGUS_Screen_Speed();
	screenPowersave = new DGUS_Screen_PowerSave();
	screenSelftest = new DGUS_Screen_SelfTest();
	screenHelp = new DGUS_Screen_Help();
	screenWizard = new DGUS_Screen_Wizard();
	screenErrorDiag = new DGUS_Screen_ErrorDiag();
	screenPreview = new DGUS_Screen_Preview();
	screenLog = new DGUS_Screen_Log();
	screenWifiInfo = new DGUS_Screen_WifiInfo();
	screenWifiDisk = new DGUS_Screen_WifiDisk();
	screenIAP = new DGUS_Screen_IAP();
	screenBabystep = new DGUS_Screen_Babystep();
	screenSwitch = new DGUS_Screen_Switch();

    #if ENABLED(DUAL_X_CARRIAGE)
    screenFitness = new DGUS_Screen_Fitness();
    screenNozzleOffset = new DGUS_Screen_Nozzle_Offset();
    screenNozzleOffset->SetParent(dgus.screenPrepare);
    screenNozzleX = new DGUS_Screen_Nozzle_X();
    screenNozzleX->SetParent(dgus.screenNozzleOffset);
    screenNozzleY = new DGUS_Screen_Nozzle_Y();
    screenNozzleY->SetParent(dgus.screenNozzleOffset);
    screenNozzleZ = new DGUS_Screen_Nozzle_Z();
    screenNozzleZ->SetParent(dgus.screenNozzleOffset);
    #endif

	screenSDCard->SetParent(dgus.screenMain);
	screenPrepare->SetParent(dgus.screenMain);
	screenControl->SetParent(dgus.screenMain);
	screenPrintEnd->SetParent(dgus.screenMain);
	screenSelftest->SetParent(dgus.screenMain);
	screenHelp->SetParent(dgus.screenMain);
	screenWizard->SetParent(dgus.screenMain);
	screenWifiDisk->SetParent(dgus.screenMain);
	screenFilament->SetParent(dgus.screenPrepare);
	screenLevelbed->SetParent(dgus.screenPrepare);
	screenPreheat->SetParent(dgus.screenPrepare);
	screenJob->SetParent(dgus.screenPrepare);
	screenZOffset->SetParent(dgus.screenPrepare);
	screenProximity->SetParent(dgus.screenPrepare);
	screenWifiSetting->SetParent(dgus.screenControl);
	screenMachineInfo->SetParent(dgus.screenControl);
	screenPowersave->SetParent(dgus.screenControl);
	screenRestoreSetting->SetParent(dgus.screenControl);
	screenIAP->SetParent(dgus.screenControl);
	screenSmartConfig->SetParent(screenWifiSetting);
	screenOTA->SetParent(screenWifiSetting);
	screenWifiInfo->SetParent(screenWifiSetting);
	screenTestMode->SetParent(dgus.screenMain);
	screenMessageReturn->SetParent(dgus.screenMain);
	screenPrintingSetting->SetParent(dgus.screenPrinting);
	screenSpeed->SetParent(screenPrintingSetting);
	screenLanguage->SetParent(dgus.screenMain);
	screenErrorDiag->SetParent(screenHelp);
	screenPreview->SetParent(screenSDCard);
	screenBabystep->SetParent(screenPrintingSetting);
	screenSwitch->SetParent(screenPrintingSetting);

	screenCurrent = dgus.screenMain;
}

void DGUSManager::GotoMain(void)
{
	testingMode = false;
	screenCurrent = dgus.screenMain;
	screenCurrent->Init();
}

void DGUSManager::GotoScreen(DGUS_Screen_Base* screen)
{
	screenCurrent = screen;
	screenCurrent->Init();
}

void DGUSManager::LoadSubScreen(DGUS_Screen_Base* screen, DGUS_Screen_Base* parent)
{
	screenCurrent = screen;
	screenCurrent->SetParent(parent);
	screenCurrent->Init();
}

void DGUSManager::ResetScreen(void)
{
	dserial.ResetScreen();
}

void DGUSManager::GotoLoadFilament(DGUS_Screen_Base* parent)
{
	screenFilament->operation = FILAMENT_OPERATION_LOAD;
	screenFilament->SetParent(parent);
	GotoScreen(screenFilament);
}

void DGUSManager::GotoUnloadFilament(DGUS_Screen_Base* parent)
{
	screenFilament->operation = FILAMENT_OPERATION_UNLOAD;
	screenFilament->SetParent(parent);
	GotoScreen(screenFilament);
}

void DGUSManager::reset()
{
	memset(payload, 0 , DGUS_PAYLOAD_LENGTH);
	length = 0;
	expected_length = 0;
	state = DS_START1;
}

void DGUSManager::append(uint8_t data)
{
	if (length < DGUS_PAYLOAD_LENGTH)
	{
		payload[length] = data;
		length++;
	}
}

void DGUSManager::ShowMessageRetrun(const char* title, const char* button, const char* msg)
{
	LoadMessageReturnMenu(screenCurrent);
	screenMessageReturn->Title(title);
	screenMessageReturn->Button(button);
	screenMessageReturn->ShowText(msg);
}

void DGUSManager::showMessageNoRetrun(const char* title, const char* line1)
{
	LoadMessageNoReturnMenu(screenCurrent);
	screenMessageNoReturn->Title(title);
	screenMessageNoReturn->ShowText(line1);
}

void DGUSManager::ShowErrorMessage(const char* msg)
{
	GotoScreen(screenError);
	screenError->Title(MMSG_ERROR_TITLE[wtvar_language]);
	screenError->ShowText(msg);
}

void DGUSManager::ShowRunoutMessage(void)
{
	LoadMessageReturnMenu(screenPrinting);
	screenMessageReturn->Title(MMSG_ERROR_TITLE[wtvar_language]);
	screenMessageReturn->Button(MMSG_CONTINUE[wtvar_language]);
	screenMessageReturn->ShowText(MMSG_RUNOUT_1[wtvar_language]);
}

void DGUSManager::ShowMessage(const char* msg)
{
	LoadMessageReturnMenu(screenCurrent);
	screenMessageReturn->Title(MMSG_NOTICE_TITLE[wtvar_language]);
	screenMessageReturn->Button(MMSG_BACK[wtvar_language]);
	screenMessageReturn->ShowText(msg);
}

void DGUSManager::ShowNoRetrunMessage(const char* msg)
{
	showMessageNoRetrun(MMSG_NOTICE_TITLE[wtvar_language], msg);
}

void DGUSManager::ShowUploadingMenu(char* msg)
{

}
void DGUSManager::ShowUploadFailMenu()
{

}

void DGUSManager::SetFilename(const char* fname)
{
	// memset(filename, 0, 21);
	ZERO(jobinfo.fileinfo.buffer);
	jobinfo.fileinfo.len = strlen(fname) < (UNICODE_FILENAME_LENGTH - 1) ? strlen(fname) : (UNICODE_FILENAME_LENGTH - 1);
	strncpy(jobinfo.fileinfo.buffer, fname, jobinfo.fileinfo.len);
	
	screenPrinting->ShowFilename(jobinfo.fileinfo.buffer);
	screenPrintEnd->ShowFilename(jobinfo.fileinfo.buffer);
}

void DGUSManager::SetPrintTime(const char* time)
{

}

void DGUSManager::ShowMovingMessage(void)
{
	dserial.LoadScreen(SCREEN_NOTICE);
	dserial.SendString(ADDR_NOTICE_TEXT_TITLE, MMSG_NOTICE_TITLE[wtvar_language], TEXTLEN_NOTICE_TITLE);
	dserial.SendLongString(ADDR_NOTICE_TEXT_LINE, MMSG_NOTICE_MOVING[wtvar_language], TEXTLEN_NOTICE_ITEM);
}

void DGUSManager::NozzleTempError(void)
{
	thermalManager.disable_all_heaters();
	screenSelftest->NozzleTempError();
}

void DGUSManager::BedTempError(void)
{
	thermalManager.disable_all_heaters();
	screenSelftest->BedTempError();
}

void DGUSManager::EndStopError(void)
{
	screenSelftest->EndStopError();
}

void DGUSManager::ShowHelp(const char* text)
{
	dserial.LoadScreen(SCREEN_HELP1);
	dserial.SendString(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], TEXTLEN_HELP1_TITLE);
	dserial.SendString(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELP1_BUTTON);

    dserial.SendLongString(ADDR_HELP1_TEXT_LINE, text, TEXTLEN_HELP1_ITEM);
}

void DGUSManager::ShowTip(const char* title, const char* text)
{
	dserial.LoadScreen(SCREEN_HELP1);
	dserial.SendString(ADDR_HELP1_TEXT_TITLE, title, TEXTLEN_HELP1_TITLE);
	dserial.SendString(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELP1_BUTTON);

    dserial.SendLongString(ADDR_HELP1_TEXT_LINE, text, TEXTLEN_HELP1_ITEM);
}

void DGUSManager::ShowQR(const char* title, const char* text)
{
	dserial.LoadScreen(SCREEN_QR);
	dserial.SendString(ADDR_QR_TEXT_TILE, title, TEXTLEN_QR_TITLE);
	dserial.SendString(ADDR_QR_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_QR_BUTTON);
	dserial.SendString(ADDR_QR_CODE, text, TEXTLEN_QR_ITEM);
}

void DGUSManager::ShowLog(const char* message)
{
	if (screenLog->activated)
	{
		screenLog->AddLine(message);
	}
}

void DGUSManager::ShowLogPair(const char *format, ...)
{
	char buffer[DGUS_SCROLL_LIST_LINE_LENGTH * 2];
	va_list arg_ptr;
	va_start(arg_ptr, format); 

	ZERO(buffer);
	vsprintf(buffer, format, arg_ptr);

	va_end(arg_ptr);

	if (screenLog->activated)
	{
		screenLog->AddLine(buffer);
	}
}

void DGUSManager::ShowLogMenu(DGUS_Screen_Base* parent, const char* title)
{
	screenCurrent = screenLog;
	screenLog->SetParent(parent);
	screenLog->Init();
	screenLog->SetTitle(title);
}

void DGUSManager::NDisk_Clear(void)
{
	ndisk_listcount = 0;
	ZERO(ndisk_filelist);
}


void DGUSManager::NDisk_Add(const char* filename)
{
	if (ndisk_listcount < NDISK_MENU_PAGE_ITEMS)
	{
		ZERO(ndisk_filelist[ndisk_listcount]);

		if (strlen(filename) <= NDISK_FILENAME_LENGTH - 1)
			strcpy(ndisk_filelist[ndisk_listcount], filename);
		else
			strncpy(ndisk_filelist[ndisk_listcount], filename, NDISK_FILENAME_LENGTH - 1);

		ndisk_listcount++;
	}
}

void DGUSManager::NDisk_Show(void)
{
	screenWifiDisk->ShowPage();
}

void DGUSManager::SetFileInfo(uint16_t index, wt_fileinfo_t* info)
{
	jobinfo.index = index;
	jobinfo.fileinfo.len = info->len;
	jobinfo.remote = false;
	memcpy(jobinfo.fileinfo.buffer, info->buffer, UNICODE_FILENAME_LENGTH);
}

void DGUSManager::SetFileInfo(uint16_t index, const char* fname, uint16_t len)
{
	jobinfo.index = index;
	jobinfo.fileinfo.len = len;
	ZERO(jobinfo.fileinfo.buffer);
	memcpy(jobinfo.fileinfo.buffer, fname, len);
}

void DGUSManager::GotoPreviewMenu(uint8_t parentType)
{
	if (parentType == PREVIEW_PARENT_WIFI)
		screenPreview->SetParent(screenWifiDisk); 
	else
		screenPreview->SetParent(screenSDCard);
		
	GotoScreen(screenPreview); 
}

void DGUSManager::ShowLoading(void)
{
	dserial.LoadScreen(SCREEN_INFO);
	dserial.SendString(ADDR_INFO_TITLE, MMSG_TF_TITLE[wtvar_language], TEXTLEN_INFO_TITLE);
	dserial.SendString(ADDR_INFO_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_INFO_BUTTON);
	dserial.SendLongString(ADDR_INFO_LINE, MMSG_LOADING[wtvar_language], TEXTLEN_INFO_ITEM);
	dserial.SendEmptyString(ADDR_INFO_LINE2, TEXTLEN_INFO_LINE2);
}

#if ENABLED(DUAL_X_CARRIAGE)
void DGUSManager::GotoFitnessErrorMenu(void)
{
    LoadSubScreen(screenFitness, screenCurrent);
}
#endif

#endif