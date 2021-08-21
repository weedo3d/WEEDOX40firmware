/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../gcode/queue.h"
#include "WTDGUSScreen_Job.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"

#ifdef DGUS_LCD

void DGUS_Screen_Job::Init()
{
	dserial.LoadScreen(SCREEN_JOB);
	holdontime = getcurrenttime();
	
	dserial.SendString(ADDR_JOB_TEXT_TITLE, MMSG_JOB_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_JOB_TEXT_BUTTON1, MMSG_RETURN_HOME[wtvar_language], 20);
	dserial.SendString(ADDR_JOB_TEXT_BUTTON2, MMSG_BACK[wtvar_language], 20);

    queue.enqueue_one_P(PSTR("M120"));
}

void DGUS_Screen_Job::Update()
{
	// do nothing
}

void DGUS_Screen_Job::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		gltouchpara.validflg = false;
		if (gltouchpara.address == ADDR_JOB_XADD1)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 X-1 F500"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_XADD2)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 X-10 F1000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_XADD3)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 X-50 F2000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_XDEC1)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 X1 F500"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_XDEC2)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 X10 F1000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_XDEC3)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 X50 F2000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_YADD1)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Y1 F500"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_YADD2)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Y10 F1000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_YADD3)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Y50 F2000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_YDEC1)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Y-1 F500"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_YDEC2)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Y-10 F1000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_YDEC3)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Y-50 F2000"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_ZADD1)
		{	
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Z0.1 F100"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_ZADD2)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Z1 F300"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_ZADD3)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Z10 F500"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_ZDEC1)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Z-0.1 F100"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_ZDEC2)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Z-1 F300"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_ZDEC3)
		{
            if (queue.length < BUFSIZE - 4)
            {
                queue.enqueue_one_P(PSTR("M211 S0"));
                queue.enqueue_one_P(PSTR("G91"));
                queue.enqueue_one_P(PSTR("G1 Z-10 F500"));
                queue.enqueue_one_P(PSTR("M211 S1"));
            }
		}
		else if (gltouchpara.address == ADDR_JOB_KEY)
		{
			if (gltouchpara.value == KEY_JOB_BUTTON2)
			{
				queue.enqueue_one_P(PSTR("G90"));
				Goback();
			}
			else if (gltouchpara.value == KEY_JOB_BUTTON1)
			{
				queue.enqueue_one_P(PSTR("G28"));
			}
			else if (gltouchpara.value == KEY_JOB_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_JOB);
			}
		}
	}
}

void DGUS_Screen_Job::ShowHelp(void)
{
	dgus.ShowHelp(HELP_TIP10_LINE[wtvar_language]);
}

#endif