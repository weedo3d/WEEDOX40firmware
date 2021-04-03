/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_BOOT_H
#define WTDUGSSCREEN_BOOT_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

// 启动菜单 
class DGUS_Screen_Boot : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	void checkCurrentScreen(void);
	
	uint32_t lastchecktime;
};

#endif

