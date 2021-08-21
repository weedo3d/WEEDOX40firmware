/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_ErrorDiag.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_ErrorDiag::Init()
{
	dserial.LoadScreen(SCREEN_HELP2);
	holdontime = getcurrenttime();
	updaterate = 500;

	pageid = 1;

	ShowPage();
}

void DGUS_Screen_ErrorDiag::Update()
{
	switch (pageid)
	{
    case 1:    
    case 4: 
    case 7:
    case 14:
    case 17:
        break;
	case 2:    
	case 5:     
    case 8:     
    case 10:   
    case 12:    
    case 15:    
		if (planner.has_blocks_queued() == false && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

	case 3:    
		if (!READ(X_MIN_PIN) && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

    case 6:    
		if (!READ(X_MAX_PIN) && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

	case 9:    
		if (!READ(Y_MIN_PIN) && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

    case 11:    
        if (planner.has_blocks_queued() == false && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}

		if (READ(Z_MIN_PIN))
			dserial.SendString(ADDR_HELP2_TEXT_LINE2, MMSG_SWITCH_OFF[wtvar_language], 20);
		else
			dserial.SendString(ADDR_HELP2_TEXT_LINE2, MMSG_SWITCH_ON[wtvar_language], 20);

		break;

	case 13:   
		if (thermalManager.degHotend(0) > 58 && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);

			queue.enqueue_now_P(PSTR("M104 T0 S0"));
		}
		else if (moving)
		{
			temp_nozzle0 = thermalManager.degHotend(0);
            dserial.SendTemp(ADDR_HELP2_TEXT_LINE2, temp_nozzle0);
		}

		break;

    case 16:    
		if (thermalManager.degHotend(1) > 58 && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);

			queue.enqueue_now_P(PSTR("M104 T1 S0"));
		}
		else if (moving)
		{
			temp_nozzle0 = thermalManager.degHotend(1);
            dserial.SendTemp(ADDR_HELP2_TEXT_LINE2, temp_nozzle0);
		}

		break;

    case 18:    
		if (thermalManager.degBed() > 38 && moving)
		{
			moving = 0;
			dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_END[wtvar_language], 20);

			queue.enqueue_now_P(PSTR("M140 S0"));
		}
		else if (moving)
		{
			temp_nozzle0 = thermalManager.degBed();
            dserial.SendTemp(ADDR_HELP2_TEXT_LINE2, temp_nozzle0);
		}

		break;

	default:
		break;
	}
	
}

void DGUS_Screen_ErrorDiag::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_HELP2_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP2_BUTTON1)
			{
				Finish();
			}
			else if (gltouchpara.value == KEY_HELP2_BUTTON2)
			{
				if (pageid == 1)
				{
					pageid = 2;
					ShowPage();
				}
				else if (pageid > 1 && pageid < 18 && moving == 0)
				{
					pageid++;
					ShowPage();
				}
				else if (pageid == 18 && moving == 0)
				{
					Finish();
				}
			}
		}
	}
}

void DGUS_Screen_ErrorDiag::ShowPage(void)
{
	if (pageid == 1)
	{	
        queue.enqueue_now_P(PSTR("T0 S1"));
	    queue.enqueue_now_P(PSTR("M605 S0"));
        queue.enqueue_now_P(PSTR("T0"));
		queue.enqueue_now_P(PSTR("M84"));
		dserial.SendString(ADDR_HELP2_TEXT_BUTTON1, MMSG_EXIT[wtvar_language], 20);
		dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_BEGIN[wtvar_language], 20);

		ShowDialog(DIAG_PAGE1_TITLE[wtvar_language], DIAG_PAGE1_LINE[wtvar_language]);

	}
	else if (pageid == 2)
	{	
		queue.enqueue_now_P(PSTR("M211 S0"));
		queue.enqueue_now_P(PSTR("M121"));
        queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 X-50 F3000"));
		queue.enqueue_now_P(PSTR("G1 X50"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE1_TITLE[wtvar_language], DIAG_PAGE2_LINE[wtvar_language]);

	}
	else if (pageid == 3)
	{	
		queue.enqueue_now_P(PSTR("M120"));
        queue.enqueue_now_P(PSTR("G91"));
        queue.enqueue_now_P(PSTR("G1 X-300 F3000"));
		moving = 1;

		dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY, 20);

		ShowDialog(DIAG_PAGE3_TITLE[wtvar_language], DIAG_PAGE3_LINE[wtvar_language]);
	}
    else if (pageid == 4)
    {   
        queue.enqueue_now_P(PSTR("T1 S1"));
		queue.enqueue_now_P(PSTR("M84"));

		dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);

		ShowDialog(DIAG_PAGE4_TITLE[wtvar_language], DIAG_PAGE4_LINE[wtvar_language]);
    }
    else if (pageid == 5)
    {   
		queue.enqueue_now_P(PSTR("M211 S0"));
		queue.enqueue_now_P(PSTR("M121"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 X-50 F3000"));
		queue.enqueue_now_P(PSTR("G1 X50"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE4_TITLE[wtvar_language], DIAG_PAGE5_LINE[wtvar_language]);
    }
    else if (pageid == 6)
    {  
		queue.enqueue_now_P(PSTR("M120"));
        queue.enqueue_now_P(PSTR("G91"));
        queue.enqueue_now_P(PSTR("G1 X300 F3000"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE6_TITLE[wtvar_language], DIAG_PAGE6_LINE[wtvar_language]);
    }
    else if (pageid == 7)
    {   
		queue.enqueue_now_P(PSTR("M84"));

		dserial.SendString(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);

		ShowDialog(DIAG_PAGE7_TITLE[wtvar_language], DIAG_PAGE7_LINE[wtvar_language]);
    }
	else if (pageid == 8)
	{	
    	queue.enqueue_now_P(PSTR("M211 S0"));
		queue.enqueue_now_P(PSTR("M121"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 Y50 F3000"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 Y-50"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE7_TITLE[wtvar_language], DIAG_PAGE8_LINE[wtvar_language]);
	}
	else if (pageid == 9)
	{
		queue.enqueue_now_P(PSTR("M120"));
		queue.enqueue_now_P(PSTR("G91"));
        queue.enqueue_now_P(PSTR("G1 Y-300 F3000"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE9_TITLE[wtvar_language], DIAG_PAGE9_LINE[wtvar_language]);
	}
	else if (pageid == 10)
	{	
		queue.enqueue_now_P(PSTR("M211 S0"));
		queue.enqueue_now_P(PSTR("M121"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 Z100 F500"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 Z-50"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE10_TITLE[wtvar_language], DIAG_PAGE10_LINE[wtvar_language]);
	}
	else if (pageid == 11)
	{	
		ShowDialog(DIAG_PAGE11_TITLE[wtvar_language], DIAG_PAGE11_LINE[wtvar_language]);
	}
	else if (pageid == 12)
	{	
		queue.enqueue_now_P(PSTR("T0 S1"));
		queue.enqueue_now_P(PSTR("M302 P1"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 E-60 F500"));
		queue.enqueue_now_P(PSTR("G1 E60 F500"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_LINE2, 20);
		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE12_TITLE[wtvar_language], DIAG_PAGE12_LINE[wtvar_language]);
	}
	else if (pageid == 13)
	{	
		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		temp_nozzle0 = thermalManager.degHotend(0);
		if (temp_nozzle0 < -10)
		{
			ShowDialog(DIAG_PAGE13_TITLE[wtvar_language], DIAG_PAGE13_LINE2[wtvar_language]);
		}
		else
		{
			queue.enqueue_now_P(PSTR("M104 T0 S60"));
			moving = 1;

			ShowDialog(DIAG_PAGE13_TITLE[wtvar_language], DIAG_PAGE13_LINE[wtvar_language]);
		}
	}
	else if (pageid == 14)
	{	
        queue.enqueue_now_P(PSTR("M104 T0 S0"));
		queue.enqueue_now_P(PSTR("M106 P0 S255"));
		dserial.SendEmptyString(ADDR_HELP2_TEXT_LINE2, 20);

        ShowDialog(DIAG_PAGE14_TITLE[wtvar_language], DIAG_PAGE14_LINE[wtvar_language]);
	}
	else if (pageid == 15)
	{	
        queue.enqueue_now_P(PSTR("M107 P0"));
        queue.enqueue_now_P(PSTR("T1 S1"));
		queue.enqueue_now_P(PSTR("M302 P1"));
		queue.enqueue_now_P(PSTR("G91"));
		queue.enqueue_now_P(PSTR("G1 E-60 F500"));
		queue.enqueue_now_P(PSTR("G1 E60 F500"));
		moving = 1;

		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		ShowDialog(DIAG_PAGE15_TITLE[wtvar_language], DIAG_PAGE15_LINE[wtvar_language]);
	}
	else if (pageid == 16)
	{	
		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

		temp_nozzle0 = thermalManager.degHotend(1);
		if (temp_nozzle0 < -10)
		{
			ShowDialog(DIAG_PAGE16_TITLE[wtvar_language], DIAG_PAGE13_LINE2[wtvar_language]);
		}
		else
		{
			queue.enqueue_now_P(PSTR("M104 T1 S60"));
			moving = 1;

			ShowDialog(DIAG_PAGE16_TITLE[wtvar_language], DIAG_PAGE16_LINE[wtvar_language]);
		}
	}
	else if (pageid == 17)
	{	
        queue.enqueue_now_P(PSTR("M104 T1 S0"));
		queue.enqueue_now_P(PSTR("M106 P1 S255"));
		dserial.SendEmptyString(ADDR_HELP2_TEXT_LINE2, 20);

        ShowDialog(DIAG_PAGE17_TITLE[wtvar_language], DIAG_PAGE17_LINE[wtvar_language]);
	}
    else if (pageid == 18)
	{	
        queue.enqueue_now_P(PSTR("M107 P1"));
		dserial.SendEmptyString(ADDR_HELP2_TEXT_BUTTON2, 20);

        temp_nozzle0 = thermalManager.degBed();
		if (temp_nozzle0 < -10)
		{
			ShowDialog(DIAG_PAGE18_TITLE[wtvar_language], DIAG_PAGE18_LINE2[wtvar_language]);
		}
		else
		{
			queue.enqueue_now_P(PSTR("M140 S40"));
			moving = 1;

			ShowDialog(DIAG_PAGE18_TITLE[wtvar_language], DIAG_PAGE18_LINE[wtvar_language]);
		}
	}
}

void DGUS_Screen_ErrorDiag::ShowDialog(const char* title, const char* line)
{
	dserial.SendString(ADDR_HELP2_TEXT_TITLE, title, 40);
	dserial.SendLongString(ADDR_HELP2_TEXT_LINE1, line, TEXTLEN_HELP2_ITEM);
}


void DGUS_Screen_ErrorDiag::NozzleTempError(void)
{
	dserial.SendString(ADDR_HELP2_TEXT_LINE2, MMSG_SELF_TEST_NOTEMP[wtvar_language], 64);
}

void DGUS_Screen_ErrorDiag::BedTempError(void)
{

}

void DGUS_Screen_ErrorDiag::EndStopError(void)
{
	switch (pageid)
	{
	case 3:
	case 5:
	case 7:
		dserial.SendString(ADDR_HELP2_TEXT_LINE2, MMSG_SELF_TEST_NOHOMING[wtvar_language], 64);
		break;

	default:
		break;
	}
}

void DGUS_Screen_ErrorDiag::Finish(void)
{
	thermalManager.setTargetHotend(0, 0);
	thermalManager.setTargetBed(0);
	queue.enqueue_now_P(PSTR("M84"));
	queue.enqueue_now_P(PSTR("M211 S1"));
	queue.enqueue_now_P(PSTR("M605 S1"));
	queue.enqueue_now_P(PSTR("M302 P0"));
	dgus.QuitTestingMode();
	Goback();
}
#endif