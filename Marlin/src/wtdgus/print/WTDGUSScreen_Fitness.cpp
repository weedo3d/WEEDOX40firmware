/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Fitness.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"
#include "../../feature/bedlevel/bedlevel.h"
#include "../../module/printcounter.h"
#include "../../wtlib/WTCMD.h"

extern bed_mesh_t z_values;

#ifdef DGUS_LCD

void DGUS_Screen_Fitness::Init()
{
	dserial.LoadScreen(SCREEN_LEVEL_DATA_TWO);
    dserial.SendString(ADDR_LDATAT_TITLE, MMSG_FITNESS_ERROR_TITLE[wtvar_language], TEXTLEN_LDATAT_TITLE);
    dserial.SendString(ADDR_LDATAT_BUTTON1_TEXT, MMSG_CANCEL[wtvar_language], TEXTLEN_LDATAT_BUTTON);
    dserial.SendString(ADDR_LDATAT_BUTTON2_TEXT, MMSG_RESUME[wtvar_language], TEXTLEN_LDATAT_BUTTON);
    dserial.SendLongString(ADDR_LDATAT_TEXT, MMSG_FITNESS_ERROR_TEXT[wtvar_language], TEXTLEN_LDATAT_TEXT);

    float f_base = z_values[1][1];
    dserial.SendFloatString(ADDR_LDATAT_ITEM1_TEXT, z_values[0][2] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM2_TEXT, z_values[1][2] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM3_TEXT, z_values[2][2] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM4_TEXT, z_values[0][1] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM5_TEXT, 0);
    dserial.SendFloatString(ADDR_LDATAT_ITEM6_TEXT, z_values[2][1] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM7_TEXT, z_values[0][0] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM8_TEXT, z_values[1][0] - f_base);
    dserial.SendFloatString(ADDR_LDATAT_ITEM9_TEXT, z_values[2][0] - f_base);

	holdontime = getcurrenttime();
}

void DGUS_Screen_Fitness::Update()
{
	// do nothing
}

void DGUS_Screen_Fitness::KeyProcess()
{
	if (gltouchpara.validflg)
	{
        if (gltouchpara.address == ADDR_LDATAT_KEY)
		{
            gltouchpara.validflg = false;
            if (gltouchpara.value == KEY_LDATAT_BUTTON1)
            {
                wt_sdcard_stop();
            }
            else if (gltouchpara.value == KEY_LDATAT_BUTTON2)
            {
                card.startFileprint();
	            print_job_timer.start();
                Goback();
            }
        }
	}
}

#endif