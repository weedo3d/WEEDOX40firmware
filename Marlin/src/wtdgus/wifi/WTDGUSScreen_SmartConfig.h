/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_SMARTCONFIG_H
#define WTDUGSSCREEN_SMARTCONFIG_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 主菜单 
class DGUS_Screen_SmartConfig : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:

};

#endif
