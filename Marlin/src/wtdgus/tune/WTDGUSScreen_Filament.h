/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_FILAMENT_H
#define WTDUGSSCREEN_FILAMENT_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_Filament : public DGUS_Screen_Base
{
public:
	DGUS_Screen_Filament(void) { operation = FILAMENT_OPERATION_LOAD; }
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	FILAMENT_OPERATION_ENUM operation;

private:
	enum FILAMENT_SCREEN_STATUS_ENUM
	{
		FSSE_CHOICETYPE = 0,
		FSSE_HEATTING = 1,
		FSSE_WAITTING = 2,
		FSSE_LOADING = 3,
		FSSE_COMPLETE = 4,
		FSSE_CHOICE_EXTRUDER = 5,
		FSSE_RETRACT = 6
	};

	enum FILAMENT_TYPE
	{
		FT_PLA = 0,
		FT_ABS = 1,
		FT_TPU = 2,
		FT_OTHER = 3
	};

	void ShowProcess(void);

	int heattime;
	FILAMENT_TYPE filamentType;
	int targetTemp;
	int16_t temp_nozzle0;
	int percent_current;
	int percent_last;
	uint8_t act_extruder;
	enum FILAMENT_SCREEN_STATUS_ENUM filaopsts;
};

#endif

