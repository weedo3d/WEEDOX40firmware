/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_OTA_H
#define WTDUGSSCREEN_OTA_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 主菜单 
class DGUS_Screen_OTA : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:

};

#endif
