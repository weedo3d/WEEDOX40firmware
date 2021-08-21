/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDGUSSCREEN_PRINTING_H
#define WTDGUSSCREEN_PRINTING_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_Printing : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
    void ShowFilename(const char* fname);

private:
    void ShowDialog(void);
	void ShowHelp(void);
	void calc_local_printing_time(void);

	int lasttemp_nozzle0;
	int lasttemp_nozzle1;
	int lasttemp_bed;
	int16_t temp_nozzle0;
	int16_t temp_nozzle1;
	int16_t temp_bed;
	uint8_t percent_current;
	int percent_last;
	uint8_t percent_progress;
	bool lastSDPrinting;

    char b[14];
};


#endif