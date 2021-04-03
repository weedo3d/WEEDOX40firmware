/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_MAIN_H
#define WTDUGSSCREEN_MAIN_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

// 主菜单 
class DGUS_Screen_Main : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	void ShowTemperature(void);
	void ShowIP(void);
	void PrintChoice(void);

	int chktmpcount;
	int lasttemp_nozzle0;
    int lasttemp_nozzle1;
	int lasttemp_bed;
	int16_t temp_nozzle0;
    int16_t temp_nozzle1;
	int16_t temp_bed;
	bool lastwifiStatus;
	int checkcount;
};

#endif
