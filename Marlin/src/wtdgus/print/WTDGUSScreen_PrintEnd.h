/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_PRINTEND_H
#define WTDUGSSCREEN_PRINTEND_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 打印完成菜单 
class DGUS_Screen_PrintEnd : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
	void ShowFilename(const char* fname);
private:
	uint8_t count;
};

#endif

