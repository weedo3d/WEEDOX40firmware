/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Levelbed.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../WTHelpDoc.h"
#include "../../feature/bedlevel/bedlevel.h"

extern bed_mesh_t z_values;

#ifdef DGUS_LCD

void DGUS_Screen_Levelbed::Init()
{
	dserial.LoadScreen(SCREEN_LEVEL);

	dserial.SendString(ADDR_LEVEL_TITLE, MMSG_LEVEL_TITLE[wtvar_language], 30);
	dserial.SendString(ADDR_LEVEL_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString(ADDR_LEVEL_TEXT_BUTTON2, MMSG_BEGIN[wtvar_language], 20);
	dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_BEGIN);
	dserial.SendLongString(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL0_LINE1[wtvar_language], TEXTLEN_LEVEL_TEXT);

	holdontime = getcurrenttime();
	levelbedmanuelsts = LBSE_NOTHING;
}

void DGUS_Screen_Levelbed::Update()
{
	switch (levelbedmanuelsts)
	{
	case LBSE_NOTHING:
		break;

	case LBSE_WAITHOME:
	{
		if (planner.has_blocks_queued() == false)
		{
			queue.enqueue_now_P(PSTR("G1 Z10 F600"));
			queue.enqueue_now_P(PSTR("G1 X10 Y10 F4000"));
			queue.enqueue_now_P(PSTR("G1 Z0 F300"));

			levelbedmanuelsts = LBSE_WAIT1STPT;
		}
	}

	case LBSE_WAIT1STPT:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendString(ADDR_LEVEL_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS3);
			dserial.SendLongString(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL3_LINE1[wtvar_language], TEXTLEN_LEVEL_TEXT);

			levelbedmanuelsts = LBSE_WAIT_INPUT1;
		}
	}
	break;

	case LBSE_WAIT2NDPT:
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS4);
			dserial.SendLongString(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL4_LINE1[wtvar_language], TEXTLEN_LEVEL_TEXT);

			levelbedmanuelsts = LBSE_WAIT_INPUT2;
		}
		break;

	case LBSE_WAIT3RDPT:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS1);
			dserial.SendLongString(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL1_LINE1[wtvar_language], TEXTLEN_LEVEL_TEXT);

			levelbedmanuelsts = LBSE_WAIT_INPUT3;
		}
	}
	break;

	case LBSE_WAIT4THPT:
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS2);
			dserial.SendLongString(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL2_LINE1[wtvar_language], TEXTLEN_LEVEL_TEXT);

			levelbedmanuelsts = LBSE_WAIT_INPUT4;
		}
		break;

	case LBSE_WAITDETECT:
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL_DATA_ONE);
			dserial.SendString(ADDR_LDATAO_TITLE, MMSG_LEVEL_DATA_TITLE[wtvar_language], TEXTLEN_LDATAO_TITLE);
			dserial.SendString(ADDR_LDATAO_BUTTON1_TEXT, MMSG_END[wtvar_language], TEXTLEN_LDATAO_BUTTON);
			dserial.SendLongString(ADDR_LDATAO_TEXT, MMSG_LEVEL_DATA_TEXT[wtvar_language], TEXTLEN_LDATAO_TEXT);

			float f_base = z_values[1][1];
			dserial.SendFloatString(ADDR_LDATAO_ITEM1_TEXT, z_values[0][2] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM2_TEXT, z_values[1][2] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM3_TEXT, z_values[2][2] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM4_TEXT, z_values[0][1] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM5_TEXT, 0);
			dserial.SendFloatString(ADDR_LDATAO_ITEM6_TEXT, z_values[2][1] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM7_TEXT, z_values[0][0] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM8_TEXT, z_values[1][0] - f_base);
			dserial.SendFloatString(ADDR_LDATAO_ITEM9_TEXT, z_values[2][0] - f_base);

			levelbedmanuelsts = LBSE_DETECT_END;
		}
		break;

	case LBSE_WAITCOMPELTE:
	{
		if (planner.has_blocks_queued() == false)
		{
			levelbedmanuelsts = LBSE_NOTHING;
			Goback();
		}
	}
	break;

	case LBSE_WAITCANCELLED:
	{
		if (planner.has_blocks_queued() == false)
		{
			levelbedmanuelsts = LBSE_NOTHING;
			Goback();
		}
	}
	break;

	default:
		break;
	}
}

void DGUS_Screen_Levelbed::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_LEVEL_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_LEVEL_BUTTON2)
			{
				switch (levelbedmanuelsts)
				{
				case LBSE_NOTHING:
					dgus.ShowMovingMessage();
					queue.enqueue_now_P(PSTR("G28\n"));
                    queue.enqueue_now_P(PSTR("G1 Z350 F1200"));
					queue.enqueue_now_P(PSTR("G1 Z410 F600"));
					queue.enqueue_now_P(PSTR("G28 Z"));
					levelbedmanuelsts = LBSE_WAITHOME;
					break;

				case LBSE_WAIT_INPUT1:
					dgus.ShowMovingMessage();
					queue.enqueue_now_P(PSTR("G1 Z10 F600"));
					queue.enqueue_now_P(PSTR("G1 X290 Y10 F4000"));
					queue.enqueue_now_P(PSTR("G1 Z0 F300"));
					levelbedmanuelsts = LBSE_WAIT2NDPT;
					break;

				case LBSE_WAIT_INPUT2:
					dgus.ShowMovingMessage();
					queue.enqueue_now_P(PSTR("G1 Z10 F600"));
					queue.enqueue_now_P(PSTR("G1 X290 Y300 F4000"));
					queue.enqueue_now_P(PSTR("G1 Z0 F300"));
					levelbedmanuelsts = LBSE_WAIT3RDPT;
					break;

				case LBSE_WAIT_INPUT3:
					dgus.ShowMovingMessage();
					queue.enqueue_now_P(PSTR("G1 Z10 F600"));
					queue.enqueue_now_P(PSTR("G1 X10 Y300 F4000"));
					queue.enqueue_now_P(PSTR("G1 Z0 F300"));
					levelbedmanuelsts = LBSE_WAIT4THPT;
					break;

				case LBSE_WAIT_INPUT4:
					dgus.ShowMovingMessage();
					queue.enqueue_now_P(PSTR("G28"));
					queue.enqueue_now_P(PSTR("G29"));
                    queue.enqueue_now_P(PSTR("G1 Z50 F1000"));
				 	queue.enqueue_now_P(PSTR("G1 X-47 Y150 F5000"));
					queue.enqueue_now_P(PSTR("M18"));

					levelbedmanuelsts = LBSE_WAITDETECT;
					break;

				case LBSE_WAITHOME:
				case LBSE_WAIT1STPT:
				case LBSE_WAIT2NDPT:
				case LBSE_WAIT3RDPT:
				case LBSE_WAIT4THPT:
				case LBSE_WAITCOMPELTE:
				case LBSE_WAITCANCELLED:
				case LBSE_WAITDETECT:
				case LBSE_DETECT_END:
					break;
				}
			}
			else if (gltouchpara.value == KEY_LEVEL_BUTTON1)
			{
				if (levelbedmanuelsts == LBSE_NOTHING)
				{
					Goback();
				}
				else
				{
					dgus.ShowMovingMessage();
					queue.enqueue_now_P(PSTR("G1 Z50 F600"));
					queue.enqueue_now_P(PSTR("G28 X Y"));
					levelbedmanuelsts = LBSE_WAITCANCELLED;
				}
			}
		}
        else if (gltouchpara.address == ADDR_LDATAO_KEY)
		{
			gltouchpara.validflg = false;
            if (gltouchpara.value == KEY_LDATAO_BUTTON1)
                Goback();
        }
	}
}

#endif