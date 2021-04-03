/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_POWER_SAVE_H
#define WTDUGSSCREEN_POWER_SAVE_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 设置菜单 
class DGUS_Screen_PowerSave : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	void ShowButtonOn(uint8_t id);
	void ShowHelp(void);

	int8_t temp_interval;
};

#endif
