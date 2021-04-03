/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_WIFI_INFO_H
#define WTDUGSSCREEN_WIFI_INFO_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 设备信息菜单 
class DGUS_Screen_WifiInfo : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
};

#endif
