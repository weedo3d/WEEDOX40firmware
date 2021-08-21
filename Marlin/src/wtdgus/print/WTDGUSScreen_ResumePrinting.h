/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_RESUMEPRINTING_H
#define WTDUGSSCREEN_RESUMEPRINTING_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

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
		DSEP_PREHEAT,
		DSEP_WAITPREHEAT,
		DSEP_HOMING,
		DSEP_WAITHOMING,
		DSEP_HEATING,
		DSEP_WAITHEATING,
		DSEP_EXTRUDING,
		DSEP_WAITEXTRUDING,
		DSEP_DUALMODE,
		DSEP_WAITMODE,
		DSEP_RESTOREPOSITION,
		DSEP_WAITPOSITION,
		DSEP_RESTOREZ,
		DSEP_WAITZ,
		DSEP_OPENFILE,
		DSEP_COMPLETE
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

