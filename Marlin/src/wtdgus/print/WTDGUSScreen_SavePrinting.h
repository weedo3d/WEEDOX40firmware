/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_SAVEPRINTING_H
#define WTDUGSSCREEN_SAVEPRINTING_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_SavePrinting : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	enum DSSP_ENUM
	{
		DSSP_NOTHING = 0,
		DSSP_CHKSTS = 1,
		DSSP_PAUSEDSD = 2,
		DSSP_WAITCLEARBUF = 3,
		DSSP_GOSETPOS = 4,
		DSSP_WAITPOS = 5,
		DSSP_SAVEPARA = 6,
		DSSP_SHUTNOW = 7,
		DSSP_HASPAUSED = 8
	};

	DSSP_ENUM state;
	//float pausedprint_position[4];
	//int temp_nozzle0;
	//int temp_bed;
	//uint32_t sdpos;
	//char sdsavedname[20];
};

#endif

