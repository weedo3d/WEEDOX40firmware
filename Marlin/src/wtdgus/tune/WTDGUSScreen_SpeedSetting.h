/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_SPEED_SETTING_H
#define WTDUGSSCREEN_SPEED_SETTING_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 设置菜单 
class DGUS_Screen_Speed : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	void ShowButtonOn(uint8_t id);
	void ShowHelp(void);

	int16_t temp_feedrate;
};

#endif
