/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_PROXIMITY_H
#define WTDUGSSCREEN_PROXIMITY_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"


// 自动调平菜单 
class DGUS_Screen_Proximity : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	enum PROXIMITY_SCREEN_ENUM
	{
		PSE_BEGIN = 0,
		PSE_INPUT = 1,
		PSE_END = 2
	};

	PROXIMITY_SCREEN_ENUM zState;
};

#endif

