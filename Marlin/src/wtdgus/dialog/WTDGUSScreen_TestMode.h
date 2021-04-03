/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_TESTMODE_H
#define WTDUGSSCREEN_TESTMODE_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 错误信息菜单 
class DGUS_Screen_TestMode : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	void ShowEndstop(void);
};

#endif