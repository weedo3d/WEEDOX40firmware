/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../libs/duration_t.h"
#include "../../module/printcounter.h"
#include "WTDGUSScreen_Printing.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTCounter.h"
#include "../WTHelpDoc.h"
#include "../../wtlib/WTCMD.h"
#include "../../wtlib/WTGcodeinfo.h"

#ifdef DGUS_LCD

/// <summary>
/// Initializes this instance.
/// </summary>
void DGUS_Screen_Printing::Init()
{
	dserial.LoadScreen(SCREEN_PRINTING);

	lasttemp_nozzle0 = -100;
	lasttemp_nozzle1 = -100;
	lasttemp_bed = -100;
	percent_last = -1;

	Update();

	if (card.flag.sdprinting || wt_onlineprinting == SPARK_PRINTING)
	{
		dserial.SendString(ADDR_PRINTING_TITLE, MMSG_STATUS_TITLE_PRINTING[wtvar_language], TEXTLEN_PRINTING_TITLE);
		dserial.SendString(ADDR_PRINTING_BUTTON2, MMSG_PAUSE[wtvar_language], TEXTLEN_PRINTING_BUTTON);
		lastSDPrinting = true;
	}
	else
	{
		dserial.SendString(ADDR_PRINTING_TITLE, MMSG_STATUS_TITLE_PAUSE[wtvar_language], TEXTLEN_PRINTING_TITLE);
		dserial.SendString(ADDR_PRINTING_BUTTON2, MMSG_RESUME[wtvar_language], TEXTLEN_PRINTING_BUTTON);
		lastSDPrinting = false;
	}
	   	  	
	dserial.SendString(ADDR_PRINTING_BUTTON1, MMSG_EXIT[wtvar_language], TEXTLEN_PRINTING_BUTTON);
	dserial.SendString(ADDR_PRINTING_BUTTON3, MMSG_SETTING[wtvar_language], TEXTLEN_PRINTING_BUTTON);

	dserial.SendUnicodeString(ADDR_PRINTING_ITEM1, dgus.jobinfo.fileinfo.buffer, dgus.jobinfo.fileinfo.len, TEXTLEN_PRINTING_FILENAME);

	holdontime = getcurrenttime();

	if (dserial.JPG_Available())
		dserial.JPG_Show();

#ifdef POWER_SAVE
	wt_timer.stop();
#endif
}

void DGUS_Screen_Printing::Update()
{
	temp_nozzle0 = thermalManager.degHotend(0);
	temp_nozzle1 = thermalManager.degHotend(1);
	temp_bed =  thermalManager.degBed();

	if ((lasttemp_nozzle0 != temp_nozzle0) || (lasttemp_nozzle1 != temp_nozzle1) || (lasttemp_bed != temp_bed))
	{
		if (temp_nozzle0 >= 0)
			dserial.SendTemp(ADDR_PRINTING_ITEM2, temp_nozzle0);
		else
			dserial.SendTemp(ADDR_PRINTING_ITEM2, 0);

        if (temp_nozzle1 >= 0)
			dserial.SendTemp(ADDR_PRINTING_ITEM7, temp_nozzle1);
		else
			dserial.SendTemp(ADDR_PRINTING_ITEM7, 0);

		if (temp_bed >= 0)
			dserial.SendTemp(ADDR_PRINTING_ITEM3, temp_bed);
		else
			dserial.SendTemp(ADDR_PRINTING_ITEM3, 0);
	}

	lasttemp_nozzle0 = temp_nozzle0;
	lasttemp_nozzle1 = temp_nozzle1;
	lasttemp_bed = temp_bed;

	if (wt_onlineprinting == SPARK_IDLE || wt_onlineprinting == SPARK_LOST)
		percent_current = card.percentDone();
	else
		percent_current = progress_bar_percent;

	if (percent_current != percent_last)
	{
		ZERO(b);
		sprintf_P(b, PSTR("%3d%%"), percent_current);
		dserial.SendString(ADDR_PRINTING_ITEM6, b, 6);

		percent_progress = percent_current / 10;
		if (percent_progress > 10) percent_progress = 10;

		dserial.SendInt16(ADDR_PRINTING_PERCENT, percent_progress);

		percent_last = percent_current;
	}

	ZERO(b);
	duration_t elapsed = print_job_timer.duration();
	bool has_days = (elapsed.value >= 60 * 60 * 24L);
	elapsed.toDigital(b, has_days);
	dserial.SendString(ADDR_PRINTING_ITEM4, b, TEXTLEN_PRINTING_TEXT);

	if (percent_current == 0)
	{
		dserial.SendString(ADDR_PRINTING_ITEM5, gcodeinfo.info.totaltime, TEXTLEN_PRINTING_TEXT);
	}
	else
	{
		calc_local_printing_time();
		ZERO(b);
		duration_t remained = dgus.jobinfo.printTimeLeft;
		if (remained.value < 60)	
			remained.value = 60;
		has_days = (remained.value >= 60 * 60 * 24L);
		remained.toDigital(b, has_days);
		dserial.SendString(ADDR_PRINTING_ITEM5, b, 10);
	}

	if ((card.flag.sdprinting || wt_onlineprinting == SPARK_PRINTING) != lastSDPrinting)
	{
		if (card.flag.sdprinting || wt_onlineprinting == SPARK_PRINTING)
		{
			dserial.SendString(ADDR_PRINTING_TITLE, MMSG_STATUS_TITLE_PRINTING[wtvar_language], TEXTLEN_PRINTING_TITLE);
			dserial.SendString(ADDR_PRINTING_BUTTON2, MMSG_PAUSE[wtvar_language], TEXTLEN_PRINTING_BUTTON);
			lastSDPrinting = true;
		}
		else
		{
			dserial.SendString(ADDR_PRINTING_TITLE, MMSG_STATUS_TITLE_PAUSE[wtvar_language], TEXTLEN_PRINTING_TITLE);
			dserial.SendString(ADDR_PRINTING_BUTTON2, MMSG_RESUME[wtvar_language], TEXTLEN_PRINTING_BUTTON);
			lastSDPrinting = false;
		}
	}
}

void DGUS_Screen_Printing::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_PRINTING_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_PRINTING_BUTTON1)
			{
				ShowDialog();
			}
			else if (gltouchpara.value == KEY_PRINTING_BUTTON2)
			{
				if (wt_onlineprinting == SPARK_IDLE || wt_onlineprinting == SPARK_LOST)
				{
					if (card.flag.sdprinting)
						wt_sdcard_pause();
					else
						wt_sdcard_resume();
				}
				else if (wt_onlineprinting == SPARK_PRINTING)
				{
					wt_online_pause();
				}
				else
				{
					wt_online_resume();
				}
			}
			else if (gltouchpara.value == KEY_PRINTING_BUTTON3)
			{
				if (wt_onlineprinting == SPARK_IDLE || wt_onlineprinting == SPARK_LOST)			
					dgus.GotoPrintingSettingMenu();
				else
					dgus.ShowHelp(HELP_TIP23_LINE[wtvar_language]);
			}
			else if (gltouchpara.value == KEY_PRINTING_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_2BINFO_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2BINFO_ITEM1)
			{	// cancel
				dserial.LoadScreen(SCREEN_PRINTING);

                if (dserial.JPG_Available())
		            dserial.JPG_Show();
			}
			else if (gltouchpara.value == KEY_2BINFO_ITEM2)
			{	// quit
				if (wt_onlineprinting == SPARK_IDLE || wt_onlineprinting == SPARK_LOST)
					wt_sdcard_stop();
				else
					wt_online_cancel();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_PRINTING);

                if (dserial.JPG_Available())
		            dserial.JPG_Show();
			}
		}
	}
}

void DGUS_Screen_Printing::ShowFilename(const char* fname)
{
	dserial.SendString(ADDR_STATUS_TEXT_VALUE1, fname);
}

void DGUS_Screen_Printing::ShowDialog(void)
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString(ADDR_2BINFO_TITLE, MMSG_CONFIRM_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON1, MMSG_NO[wtvar_language], 20);
	dserial.SendString(ADDR_2BINFO_TEXT_BUTTON2, MMSG_YES[wtvar_language], 20);

    dserial.SendLongString(ADDR_2BINFO_TEXT_LINE, 
                            MMSG_QUIT_PRINT_CONFIRM_TEXT[wtvar_language], 
                            TEXTLEN_2BINFO_ITEM);
}

void DGUS_Screen_Printing::ShowHelp(void)
{
	dgus.ShowHelp(HELP_TIP02_LINE[wtvar_language]);
}

void DGUS_Screen_Printing::calc_local_printing_time(void)
{
	dgus.jobinfo.printTime = print_job_timer.duration();

	float p = (float) dgus.jobinfo.filepos;
	p /= dgus.jobinfo.filesize;
	if (p < 0) p = 0;
	if (p > 1) p = 1;
	dgus.jobinfo.completion = p;

	long est_total;
	if (gcodeinfo.info.i_totaltime > 0)
	{
		if (p > 0)
			est_total = (long)((float) dgus.jobinfo.printTime / p);
		else
			est_total = gcodeinfo.info.i_totaltime;

		long est_last = est_total - dgus.jobinfo.printTime;
		long slicing_last = gcodeinfo.info.i_totaltime - dgus.jobinfo.printTime;
		if (slicing_last < 0) slicing_last = 0;

		dgus.jobinfo.printTimeLeft = (long)((float)est_last * p + (float)slicing_last * (1 - p));
	}
	else
	{
		if (p > 0)
			est_total = (long)((float)dgus.jobinfo.printTime / p);
		else
			est_total = 0;

		dgus.jobinfo.printTimeLeft = est_total - dgus.jobinfo.printTime;
		if (dgus.jobinfo.printTimeLeft < 0) dgus.jobinfo.printTimeLeft = 0;
	}
}

#endif