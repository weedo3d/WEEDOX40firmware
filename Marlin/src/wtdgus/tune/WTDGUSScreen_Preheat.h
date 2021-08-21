/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_PREHEAT_H
#define WTDUGSSCREEN_PREHEAT_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_Preheat : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	int lasttemp_nozzle0;
	int lasttemp_nozzle1;
	int lasttemp_bed;
	int16_t temp_nozzle0;
	int16_t temp_nozzle1;
	int16_t temp_bed;
	int target_nozzle0;
	int target_nozzle1;
	int target_bed;
	bool isHeating;
	int percent_nozzle0;
	int percent_nozzle1;
	int percent_bed;
	int begin_nozzle0;
	int begin_nozzle1;
	int begin_bed;

	void ShowTemperature(void);
	void ShowHelp(void);
};

#endif
