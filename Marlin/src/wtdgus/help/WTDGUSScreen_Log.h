/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_LOG_H
#define WTDUGSSCREEN_LOG_H

#include "WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_Log : public DGUS_Screen_ScrollList
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
    void SetTitle(const char* title);

private:

};

#endif

