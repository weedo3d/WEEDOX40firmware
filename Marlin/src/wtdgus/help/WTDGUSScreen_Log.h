/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_LOG_H
#define WTDUGSSCREEN_LOG_H

#include "WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"


// 自动调平菜单 
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

