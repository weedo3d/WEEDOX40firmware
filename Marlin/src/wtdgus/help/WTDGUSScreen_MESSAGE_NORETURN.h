/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_MESSAGE_NORETURN_H
#define WTDUGSSCREEN_MESSAGE_NORETURN_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 提示信息菜单 
class DGUS_Screen_Message_NoReturn : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	void Title(const char* title);
	void ShowText(const char* title);
	void Line(const char* title);

	// void Title_P(const char* title);
	// void ShowText_P(const char* title);
	// void Line_P(const char* title);

	void SetAutoReturn(void) { isAutoReturn = true; }

private:
	bool isAutoReturn;

};

#endif
