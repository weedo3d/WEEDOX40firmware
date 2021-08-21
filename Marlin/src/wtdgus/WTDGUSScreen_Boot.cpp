/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../MarlinCore.h"
#include "../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../module/planner.h"
#include "../feature/powerloss.h"
#include "../module/configuration_store.h"
#include "WTDGUSScreen_Boot.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

#define CheckCurrentScreenInterval	2000

extern uint8_t wtvar_skipTest;

#ifdef DGUS_LCD

void DGUS_Screen_Boot::Init()
{
	SERIAL_ECHOLNPGM("load screen boot");
	
	holdontime = getcurrenttime();

	checkCurrentScreen();
	//WT_Get_IP();
}

void DGUS_Screen_Boot::Update()
{
	// do nothing
	if (holdontime > lastchecktime)
		checkCurrentScreen();
}

void DGUS_Screen_Boot::checkCurrentScreen(void)
{
	dserial.payload_reset();
	dserial.payload_append_byte(DGUS_CMD_ReadVAR);
	dserial.payload_append_int(0x0084);
	dserial.payload_append_byte(0x2);
	dserial.payload_send();

	lastchecktime = getcurrenttime() + CheckCurrentScreenInterval;
}

void DGUS_Screen_Boot::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == 0x84)
		{
			if (gltouchpara.value != 0x0 && wtvar_gohome == 0)
			{
				dgus.ResetScreen();
				safe_delay(3000);
			}
            else
            {
                safe_delay(2000);
            }
            

			if (card.isMounted() && card.jobRecoverFileExists())
			{
				recovery.init();
				recovery.load();

				dgus.GotoResumePrintingMenu();
			}
			else
			{
                if (wtvar_gohome == 1)
                {
                    wtvar_gohome = 0;
                    (void)settings.save();
                    dgus.GotoMain();
                }
				else if (wtvar_showWelcome == 1)
				{
					dgus.GotoWizardMenu();
				}
				else
				{
					if (wtvar_enableselftest && wtvar_skipTest == 0)
						dgus.GotoSelfTest();
					else
						dgus.GotoMain();
				}
			}
		}
		gltouchpara.validflg = false;
	}
}
#endif