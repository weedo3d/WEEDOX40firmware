/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_MACHINEINFO_H
#define WTDUGSSCREEN_MACHINEINFO_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 设备信息菜单 
class DGUS_Screen_MachineInfo : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
};

#endif
