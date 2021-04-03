/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的定义
*/

#ifndef WTDUGSSCREEN_RESUMEPRINTING_H
#define WTDUGSSCREEN_RESUMEPRINTING_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

// 恢复打印菜单 
class DGUS_Screen_ResumePrinting : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
    void ShowRecoveryInfo();

	enum DSEP_ENUM
	{
		DSEP_NOTHING = 0,
		DSEP_FOUNDFILE = 1,
		DSEP_WAITUSER = 2,
		DSEP_START = 3,
		DSEP_HEATING = 4,
		DSEP_WAITHEATING = 5,
		DSEP_GOHOME = 6,
		DSEP_WAITGOHOME = 7,
		DSEP_SETPOS = 8,
		DSEP_WAITSETPOS = 9,
		DSEP_WAITBUFFER = 10,
		DSEP_OPENFILE = 11,
		DSEP_COMPLETE = 12,
		DSEP_PREHEAT = 13,
		DSEP_WAITPREHEAT = 14
	};

	DSEP_ENUM state;
	//float pausedprint_position[4];
	//int temp_nozzle0;
	//int temp_bed;
	//uint32_t sdpos;
	//char sdsavedname[20];

	uint8_t r, c;
};

#endif

