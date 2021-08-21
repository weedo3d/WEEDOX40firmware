/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDGUSSCREEN_SCROLL_LIST_H
#define WTDGUSSCREEN_SCROLL_LIST_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

#define DGUS_SCROLL_LIST_LINE_LENGTH        48
#define DGUS_SCROLL_LIST_LINE_COUNT         9
#define DGUS_SCROLL_LIST_TOTAL_MAX          400

class DGUS_Screen_ScrollList : public DGUS_Screen_Base
{
public:
	void Init(void);

    void AddLine(const char* line);
    void Clear(void);
protected:
    void ShowAllLine(void);

    char linebuffer[DGUS_SCROLL_LIST_LINE_COUNT][DGUS_SCROLL_LIST_LINE_LENGTH];
    uint8_t current_line = 0;
};


#endif