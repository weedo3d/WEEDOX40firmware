/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_JOB_H
#define WTDUGSSCREEN_JOB_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 设置菜单 
class DGUS_Screen_Job : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	void ShowHelp(void);
};

#endif
