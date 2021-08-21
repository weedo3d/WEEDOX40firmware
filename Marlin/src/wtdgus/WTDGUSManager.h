/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDGUSMANAGER_H
#define WTDGUSMANAGER_H

#include "../MarlinCore.h"
#include "WTDGUSScreenBase.h"

#include "WTDGUSScreen_Main.h"
#include "tune/WTDGUSScreen_Prepare.h"
#include "control/WTDGUSScreen_Control.h"
#include "print/WTDGUSScreen_SDCard.h"
#include "print/WTDGUSScreen_Preview.h"
#include "print/WTDGUSScreen_Printing.h"
#include "help/WTDGUSScreen_Error.h"
#include "print/WTDGUSScreen_PrintEnd.h"
#include "control/WTDGUSScreen_PowerOff.h"
#include "print/WTDGUSScreen_PrintingSetting.h"
#include "tune/WTDGUSScreen_Levelbed.h"
#include "tune/WTDGUSScreen_Filament.h"
#include "tune/WTDGUSScreen_Preheat.h"
#include "control/WTDGUSScreen_MachineInfo.h"
#include "wifi/WTDGUSScreen_WifiSetting.h"
#include "print/WTDGUSScreen_SavePrinting.h"
#include "print/WTDGUSScreen_ResumePrinting.h"
#include "WTDGUSScreen_Boot.h"
#include "control/WTDGUSScreen_RestoreSetting.h"
#include "dialog/WTDGUSScreen_TestMode.h"
#include "wifi/WTDGUSScreen_SmartConfig.h"
#include "help/WTDGUSScreen_MESSAGE_RETURN.h"
#include "help/WTDGUSScreen_MESSAGE_NORETURN.h"
#include "wifi/WTDGUSScreen_OTA.h"
#include "tune/WTDGUSScreen_ZOffset.h"
#include "control/WTDGUSScreen_Language.h"
#include "tune/WTDGUSScreen_Job.h"
#include "tune/WTDGUSScreen_Proximity.h"
#include "tune/WTDGUSScreen_SpeedSetting.h"
#include "control/WTDGUSScreen_PowerSave.h"
#include "dialog/WTDGUSScreen_SelfTest.h"
#include "help/WTDGUSScreen_Help.h"
#include "dialog/WTDGUSScreen_Wizard.h"
#include "dialog/WTDGUSScreen_ErrorDiag.h"
#include "help/WTDGUSScreen_Log.h"
#include "wifi/WTDGUSScreen_WifiInfo.h"
#include "wifi/WTDGUSScreen_WifiDisk.h"
#include "control/WTDGUSScreen_IAP.h"
#include "print/WTDGUSScreen_Babystep.h"
#include "print/WTDGUSScreen_Switch.h"

#if ENABLED(DUAL_X_CARRIAGE)
#include "print/WTDGUSScreen_Fitness.h"
#include "tune/WTDGUSScreen_NozzleOffset.h"
#include "tune/WTDGUSScreen_NozzleX.h"
#include "tune/WTDGUSScreen_NozzleY.h"
#include "tune/WTDGUSScreen_NozzleZ.h"
#endif

#define DGUS_PAYLOAD_LENGTH		64
#define TestError
#define NDISK_MENU_PAGE_ITEMS	6
#define NDISK_FILENAME_LENGTH	30

#define PREVIEW_PARENT_SD		0
#define PREVIEW_PARENT_WIFI		1

typedef enum {
	DS_START1 = 0,
	DS_START2 = 1,
	DS_LEN = 2,
	DS_PAYLOAD = 3
} DGUSPacketStatusEnum;

typedef struct 
{
	long printTime;
	long printTimeLeft;
	double completion;
	long filepos;
	long filesize;
	wt_fileinfo_t fileinfo;
	long date;
	uint16_t index;
	bool remote;			
} wt_job_info_t;

class DGUSManager
{
public:
	DGUSManager();

	void Init(unsigned long baud, bool doreset = true);
	void Update();

	void SetFilename(const char* fname);
	void SetPrintTime(const char* time);

	void GotoScreen(DGUS_Screen_Base* screen);
	void LoadSubScreen(DGUS_Screen_Base* screen, DGUS_Screen_Base* parent);
	void ResetScreen(void);

	void GotoMain(void);
	void GotoLoadFilament(DGUS_Screen_Base* parent);
	void GotoUnloadFilament(DGUS_Screen_Base* parent);
	void GotoSDMenu(void) { GotoScreen(screenSDCard); }
	void GotoBootMenu(void) { GotoScreen(screenBoot); }
	void GotoControlMenu(void) { screenControl->pageid = 0; GotoScreen(screenControl);}
	void GotoPrepareMenu(void) { screenPrepare->pageid = 0; GotoScreen(screenPrepare);}
	void GotoErrorMenu(void) { GotoScreen(screenError); }
	void GotoLevelMenu(void) { GotoScreen(screenLevelbed); }
	void GotoPreheatMenu(void) { GotoScreen(screenPreheat); }
	void GotoMachineInfoMenu(void) { GotoScreen(screenMachineInfo); }
	void GotoWifiSettingMenu(void) { GotoScreen(screenWifiSetting); }
	void GotoPrintEndMenu(void) { GotoScreen(screenPrintEnd); }
	void GotoPowerOffMenu(void) { GotoScreen(screenPowerOff); }
	void GotoPrintingSettingMenu(void) { GotoScreen(screenPrintingSetting); }
	void GotoSavePrintingMenu(void) { GotoScreen(screenSavePrinting); }
	void GotoResumePrintingMenu(void) { GotoScreen(screenResumePrinting); }
	void GotoRestoreSettingMenu(void) { GotoScreen(screenRestoreSetting); }
	void GotoTestModeMenu(void) { GotoScreen(screenTestMode); }
	void GotoSmartConfigMenu(void) { GotoScreen(screenSmartConfig); }
	void LoadMessageReturnMenu(DGUS_Screen_Base* parent) { LoadSubScreen(screenMessageReturn, parent); }
	DGUS_Screen_Message_Return* GetScreenMessageReturn(void) { return screenMessageReturn; }
	void GotoMessageNoReturnMenu(void) { GotoScreen(screenMessageNoReturn); }
	void LoadMessageNoReturnMenu(DGUS_Screen_Base* parent) { LoadSubScreen(screenMessageNoReturn, parent); }
	DGUS_Screen_Message_NoReturn* GetScreenMessageNoReturn(void) { return screenMessageNoReturn;}
	void GotoOTAMenu(void) { GotoScreen(screenOTA);}
	void GotoZOffsetMenu(void) { GotoScreen(screenZOffset); }
	void GotoLanguageMenu(void) { GotoScreen(screenLanguage); }
	void GotoJobMenu(void) { GotoScreen(screenJob); }
	void GotoProximityMenu(void) { GotoScreen(screenProximity); }
	void GotoSpeedSettingMenu(void) { GotoScreen(screenSpeed); }
	void GotoPowerSaveMenu(void) { GotoScreen(screenPowersave); }
	void GotoSelfTest(void) { testingMode = true; GotoScreen(screenSelftest); }
	void GotoHelpMenu(void) { GotoScreen(screenHelp); }
	void GotoWizardMenu(void) { GotoScreen(screenWizard); }
	void GotoErrorDiaglogMenu(void) { testingMode = true; GotoScreen(screenErrorDiag); }
	void GotoPreviewMenu(uint8_t parentType);
	void GotoPrintingMenu() { GotoScreen(screenPrinting); }
	void GotoWifiInfo(void) { GotoScreen(screenWifiInfo); }
	void GotoWifiDisk(void) { GotoScreen(screenWifiDisk); }
	void GotoIAPMenu(void) { GotoScreen(screenIAP); }
	void GotoBabystepMenu(void) { GotoScreen(screenBabystep); }
	void GotoManualSwitchMenu(void) { GotoScreen(screenSwitch); }

    #if ENABLED(DUAL_X_CARRIAGE)
    void GotoFitnessErrorMenu(void);
    void GotoNozzleOffsetMenu(void) { GotoScreen(screenNozzleOffset); }
    void GotoNozzleXMenu(void) { GotoScreen(screenNozzleX); }
    void GotoNozzleYMenu(void) { GotoScreen(screenNozzleY); }
    void GotoNozzleZMenu(void) { GotoScreen(screenNozzleZ); }
    #endif

	void ShowMessageRetrun(const char* title, const char* button, const char* msg);
	void ShowMessage(const char* msg);
	void ShowNoRetrunMessage(const char* msg);
	void ShowErrorMessage(const char* msg);
	void ShowRunoutMessage(void);
	void ShowUploadingMenu(char* msg);
	void ShowUploadFailMenu();
	void EnableMessageNoReturnAutoGoback(void) { screenMessageNoReturn->SetAutoReturn(); }
	void ShowMovingMessage(void);
	FORCE_INLINE bool isTesting(void) { return testingMode; }
	void QuitTestingMode(void) { testingMode = false; }
	void NozzleTempError(void);
	void BedTempError(void);
	void EndStopError(void);
	void ShowHelp(const char* text);
	void ShowTip(const char* title, const char* text);
	void ShowQR(const char* title, const char* text);
	void ShowLog(const char* message);
	void ShowLogPair(const char *format, ...);
	void ShowLogMenu(DGUS_Screen_Base* parent, const char* title);
	void ShowLoading(void);

	void NDisk_Clear(void);
	void NDisk_Add(const char* filename);
	void NDisk_Show(void);

	void SetFileInfo(uint16_t index, wt_fileinfo_t* info);
	void SetFileInfo(uint16_t index, const char* fname, uint16_t len);

	void EnablePreviewAction(bool action) { screenPreview->enable(action); }

	bool busy = false;

	char ndisk_filelist[NDISK_MENU_PAGE_ITEMS][NDISK_FILENAME_LENGTH];
	uint8_t ndisk_pagecount = 0;
	uint8_t ndisk_pageid = 0;
	uint8_t ndisk_listcount = 0;
	bool ndisk_pageload = false;

	wt_job_info_t jobinfo;

private:
	void process();
	void InitMenu();
	void reset();
	void append(uint8_t data);
	void showMessageNoRetrun(const char* title, const char* line1);

	uint8_t payload[DGUS_PAYLOAD_LENGTH];
	uint8_t length;
	uint8_t expected_length;
	DGUSPacketStatusEnum state;
	uint8_t lcd_sd_status;
	bool testingMode;

	DGUS_Screen_Main* screenMain;
	DGUS_Screen_Prepare* screenPrepare;
	DGUS_Screen_Control* screenControl;
	DGUS_Screen_SDCard* screenSDCard;
	DGUS_Screen_Error* screenError;
	DGUS_Screen_PrintEnd* screenPrintEnd;
	DGUS_Screen_PowerOff* screenPowerOff;
	DGUS_Screen_PrintingSetting* screenPrintingSetting;
	DGUS_Screen_Levelbed* screenLevelbed;
	DGUS_Screen_Filament* screenFilament;
	DGUS_Screen_Preheat* screenPreheat;
	DGUS_Screen_MachineInfo* screenMachineInfo;
	DGUS_Screen_WifiSetting* screenWifiSetting;
	DGUS_Screen_SavePrinting* screenSavePrinting;
	DGUS_Screen_ResumePrinting* screenResumePrinting;
	DGUS_Screen_Boot* screenBoot;
	DGUS_Screen_RestoreSetting* screenRestoreSetting;
	DGUS_Screen_TestMode* screenTestMode;
	DGUS_Screen_SmartConfig* screenSmartConfig;
	DGUS_Screen_Message_Return* screenMessageReturn;
	DGUS_Screen_Message_NoReturn* screenMessageNoReturn;
	DGUS_Screen_OTA* screenOTA;
	DGUS_Screen_ZOffset* screenZOffset;
	DGUS_Screen_Language* screenLanguage;
	DGUS_Screen_Job* screenJob;
	DGUS_Screen_Proximity* screenProximity;
	DGUS_Screen_Speed* screenSpeed;
	DGUS_Screen_PowerSave* screenPowersave;
	DGUS_Screen_SelfTest* screenSelftest;
	DGUS_Screen_Help* screenHelp;
	DGUS_Screen_Wizard* screenWizard;
	DGUS_Screen_ErrorDiag* screenErrorDiag;
	DGUS_Screen_Preview* screenPreview;
	DGUS_Screen_Printing* screenPrinting;
	DGUS_Screen_Log* screenLog;
	DGUS_Screen_WifiInfo* screenWifiInfo;
	DGUS_Screen_WifiDisk* screenWifiDisk;
	DGUS_Screen_IAP* screenIAP;
	DGUS_Screen_Babystep* screenBabystep;
	DGUS_Screen_Switch* screenSwitch;

    #if ENABLED(DUAL_X_CARRIAGE)
    DGUS_Screen_Fitness* screenFitness;
    DGUS_Screen_Nozzle_Offset* screenNozzleOffset;
    DGUS_Screen_Nozzle_X* screenNozzleX;
    DGUS_Screen_Nozzle_Y* screenNozzleY;
    DGUS_Screen_Nozzle_Z* screenNozzleZ;
    #endif

	DGUS_Screen_Base* screenCurrent;

};

extern DGUSManager dgus;

#ifdef DGUS_LCD
extern TouchPara gltouchpara;
#endif

#endif
