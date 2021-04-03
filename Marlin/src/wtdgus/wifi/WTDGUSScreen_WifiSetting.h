/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_WIFISETTING_H
#define WTDUGSSCREEN_WIFISETTING_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 网络设置菜单 
class DGUS_Screen_WifiSetting : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
};

#endif
