/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "../../MarlinCore.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "WTDGUSScreen_Preview.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTGcodeinfo.h"
#include "../../wtlib/WTCMD.h"

#ifdef DGUS_LCD

void DGUS_Screen_Preview::Init()
{
    dserial.LoadScreen(SCREEN_PREVIEW);
    b_enable = true;
    holdontime = getcurrenttime();

    dserial.SendString(ADDR_PREVIEW_TITLE, MMSG_PREVIEW_TITLE[wtvar_language], TEXTLEN_PREVIEW_TITLE);
    dserial.SendString(ADDR_PREVIEW_BUTTON1, MMSG_BACK[wtvar_language], TEXTLEN_PREVIEW_BUTTON);

    dserial.SendString(ADDR_PREVIEW_BUTTON3, MMSG_PREVIEW_PRINT[wtvar_language], TEXTLEN_PREVIEW_BUTTON);

    dserial.SendUnicodeString(ADDR_PREVIEW_ITEM1, dgus.jobinfo.fileinfo.buffer, dgus.jobinfo.fileinfo.len, TEXTLEN_PREVIEW_FILENAME);

    if (!dgus.jobinfo.remote)
    {
        dserial.JPG_Reset();

        card.selectFileByIndex(dgus.jobinfo.index);
        gcodeinfo.parse(card.filename);
    }

    if (!gcodeinfo.info.b_multi &&  (gcodeinfo.info.x_max > 0) && (gcodeinfo.info.x_max - gcodeinfo.info.x_min) < (X_BED_SIZE / 2 - 10))
    {
        dserial.SendString(ADDR_PREVIEW_BUTTON2, MMSG_PREVIEW_MODE[wtvar_language], TEXTLEN_PREVIEW_BUTTON);
        b_dualmode = true;
    }
    else
    {
        dserial.SendEmptyString(ADDR_PREVIEW_BUTTON2, TEXTLEN_PREVIEW_BUTTON);
        b_dualmode = false;
    }

    dserial.SendString(ADDR_PREVIEW_ITEM2, gcodeinfo.info.material, TEXTLEN_PREVIEW_DATA);
    dserial.SendString(ADDR_PREVIEW_ITEM3, gcodeinfo.info.filament, TEXTLEN_PREVIEW_DATA);
    dserial.SendString(ADDR_PREVIEW_ITEM4, gcodeinfo.info.layerheight, TEXTLEN_PREVIEW_TEXT);
    dserial.SendString(ADDR_PREVIEW_ITEM5, gcodeinfo.info.density, TEXTLEN_PREVIEW_TEXT);
    dserial.SendString(ADDR_PREVIEW_ITEM6, gcodeinfo.info.totaltime, TEXTLEN_PREVIEW_TEXT);

    if (!dgus.jobinfo.remote && gcodeinfo.info.b_image)
        gcodeinfo.load_jpg(gcodeinfo.info.filename);
}

void DGUS_Screen_Preview::Update()
{
    // do nothing
}

void DGUS_Screen_Preview::KeyProcess()
{
    if (gltouchpara.validflg)
    {
        if (gltouchpara.address == ADDR_PREVIEW_KEY)
        {
            gltouchpara.validflg = false;
            if (gltouchpara.value == KEY_PREVIEW_BUTTON1 && b_enable)
            {
                Goback();
            }
            else if (gltouchpara.value == KEY_PREVIEW_BUTTON2 && b_enable && b_dualmode)
            {
                dserial.LoadScreen(SCREEN_HELPMENU);

                dserial.SendString(ADDR_HELPMENU_TEXT_TITLE, MMSG_PREVIEW_MODE[wtvar_language], TEXTLEN_HELPMENU_TITLE);
                dserial.SendString(ADDR_HELPMENU_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELPMENU_BUTTON);

                dserial.SendInt16(ADDR_HELPMENU_ICON1, ENUM_SETTING_NORMAL);
                dserial.SendString(ADDR_HELPMENU_ITEM1, MMSG_DUAL_NORMAL[wtvar_language], TEXTLEN_HELPMENU_ITEM);

                dserial.SendInt16(ADDR_HELPMENU_ICON2, ENUM_SETTING_COPY);
                dserial.SendString(ADDR_HELPMENU_ITEM2, MMSG_DUAL_COPY[wtvar_language], TEXTLEN_HELPMENU_ITEM);

                dserial.SendInt16(ADDR_HELPMENU_ICON3, ENUM_SETTING_MIRROR);
                dserial.SendString(ADDR_HELPMENU_ITEM3, MMSG_DUAL_MIRROR[wtvar_language], TEXTLEN_HELPMENU_ITEM);
            }
            else if (gltouchpara.value == KEY_PREVIEW_BUTTON3 && b_enable)
            {
                do_print();
            }
        }
        else if (gltouchpara.address == ADDR_HELPMENU_KEY)
        {
            gltouchpara.validflg = false;
            if (gltouchpara.value == KEY_HELPMENU_BUTTON_RETURN)
            {
                dserial.LoadScreen(SCREEN_PREVIEW);

                if (dserial.JPG_Available())
                    dserial.JPG_Show();
            }
            else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM1)
            {
                wtvar_dual_mode = 0;
                queue.enqueue_now_P("T0 S");
                queue.enqueue_now_P("M605 S1");
                do_print();
            }
            else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM2)
            {
                wtvar_dual_mode = 1;
                move_center();
                queue.enqueue_now_P("T0 S");
                queue.enqueue_now_P("M605 S2");
                do_print();
            }
            else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM3)
            {
                wtvar_dual_mode = 2;
                move_center();
                queue.enqueue_now_P("T0 S");
                queue.enqueue_now_P("M605 S2");
                queue.enqueue_now_P("M605 S3");
                do_print();
            }
        }
    }
}

void DGUS_Screen_Preview::enable(bool action)
{
    if (action)
    {
        b_enable = true;
        dserial.SendString(ADDR_PREVIEW_BUTTON1, MMSG_BACK[wtvar_language], TEXTLEN_PREVIEW_BUTTON);
        dserial.SendString(ADDR_PREVIEW_BUTTON2, MMSG_PREVIEW_MODE[wtvar_language], TEXTLEN_PREVIEW_BUTTON);
        dserial.SendString(ADDR_PREVIEW_BUTTON3, MMSG_PREVIEW_PRINT[wtvar_language], TEXTLEN_PREVIEW_BUTTON);
    }
    else
    {
        b_enable = false;
        dserial.SendEmptyString(ADDR_PREVIEW_BUTTON1, TEXTLEN_PREVIEW_BUTTON);
        dserial.SendEmptyString(ADDR_PREVIEW_BUTTON2, TEXTLEN_PREVIEW_BUTTON);
        dserial.SendEmptyString(ADDR_PREVIEW_BUTTON3, TEXTLEN_PREVIEW_BUTTON);
    }
}

void DGUS_Screen_Preview::do_print(void)
{
    if (dgus.jobinfo.remote)
    { 
        wt_ndisk_print();
        dgus.ShowLoading();
    }
    else
    {
        card.selectFileByIndex(dgus.jobinfo.index);
        card.openAndPrintFile(card.filename);
        dgus.GotoPrintingMenu();
    }
}


#endif