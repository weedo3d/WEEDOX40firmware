/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_CONTROL_H
#define WTDUGSSCREEN_CONTROL_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 设置菜单 
class DGUS_Screen_Control : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	uint8_t pageid = 0;
private:
	void ShowPrePage(void);
	void ShowNextPage(void);
	void ShowPage(void);
	void ShowHelp(void);

	uint8_t clickCount;
};

#endif
