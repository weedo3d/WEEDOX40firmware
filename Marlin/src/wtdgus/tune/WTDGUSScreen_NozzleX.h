/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_NOZZLE_X_H
#define WTDUGSSCREEN_NOZZLE_X_H

#include "../help/WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"


// 自动调平菜单 
class DGUS_Screen_Nozzle_X : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
    uint8_t tempX;
    
	void ShowButtonOn(uint8_t id);
};

#endif

