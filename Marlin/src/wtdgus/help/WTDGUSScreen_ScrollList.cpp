/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#include "../../MarlinCore.h"
#include "../../sd/cardreader.h"
#include "WTDGUSScreen_ScrollList.h"
#include "../WTDGUSSerial.h"
#include "../WTDGUSConfig.h"
#include "../WTDGUSManager.h"
#include "../../wtlib/WTGcodeinfo.h"

#ifdef DGUS_LCD
// 文本滚动界面
void DGUS_Screen_ScrollList::Init()
{
	dserial.LoadScreen(SCREEN_HELP1);

    activated = true;
	holdontime = getcurrenttime();

	dserial.SendString(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], TEXTLEN_HELP1_BUTTON);
 
    current_line = 0;
    ZERO(linebuffer);
}

void DGUS_Screen_ScrollList::AddLine(const char* line)
{
    uint16_t _len = strlen(line);

    if (_len == 0) return;

    uint8_t _current = 0;
    if (current_line < DGUS_SCROLL_LIST_LINE_COUNT)
    {
        _current = current_line++;
    }
    else
    {
        for(uint8_t i = 0; i < DGUS_SCROLL_LIST_LINE_COUNT - 1; i++)
        {
            ZERO(linebuffer[i]);
            strcpy(linebuffer[i], linebuffer[i + 1]);
        }
        _current = DGUS_SCROLL_LIST_LINE_COUNT - 1;
    }

    ZERO(linebuffer[_current]);
    strncpy(linebuffer[_current], line, _len < DGUS_SCROLL_LIST_LINE_LENGTH - 3 ? _len : DGUS_SCROLL_LIST_LINE_LENGTH - 3);

    ShowAllLine();
}

void DGUS_Screen_ScrollList::Clear(void)
{
    dserial.SendLongString(ADDR_HELP1_TEXT_LINE, MMSG_EMPTY, TEXTLEN_HELP1_ITEM);
    current_line = 0;
    ZERO(linebuffer);
}

void DGUS_Screen_ScrollList::ShowAllLine(void)
{
    uint16_t buffer_len = 0;

    // 获取缓冲行所有字节长度
    for(uint8_t i = 0; i < current_line; i++)
    {
        buffer_len += strlen(linebuffer[i]) + 2;
    }

    if (buffer_len == 0) return;

    buffer_len++;       // 增加空字符结尾

    char* _buffer = (char*)malloc(buffer_len);
    memset(_buffer, 0, buffer_len);

    // 所有行复制至缓冲区
    for(uint8_t i = 0; i < current_line; i++)
    {
        strcat(_buffer, linebuffer[i]);                    
        strcat(_buffer, "\r\n");    
    }

    // 发送缓冲区
    dserial.SendLongString(ADDR_HELP1_TEXT_LINE, _buffer, TEXTLEN_HELP1_ITEM);

    free(_buffer);
}

#endif