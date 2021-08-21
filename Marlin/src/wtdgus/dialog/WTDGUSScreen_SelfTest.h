/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_SELF_TEST_H
#define WTDUGSSCREEN_SELF_TEST_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_SelfTest : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	void NozzleTempError(void);
	void BedTempError(void);
	void EndStopError(void);

private:
	void ShowHelp(void);

	enum SELFTEST_NOZZLE_ENUM
	{
		SNE_READING = 0,
		SNE_HEATING = 1,
		SNE_END = 2,
		SNE_ERROR = 3
	};

	enum SELFTEST_BED_ENUM
	{
		SBE_READING = 0,
		SBE_HEATING = 1,
		SBE_END = 2,
		SBE_ERROR = 3
	};

	enum SELFTEST_AXIS_ENUM
	{
		SAE_XMOVING = 0,
		SAE_YMOVING = 1,
		SAE_ZMOVING = 2,
		SAE_END = 3,
		SAE_ERROR = 4
	};

	void doxhome(void);
	void doyhome(void);
	void dozhome(void);

	SELFTEST_NOZZLE_ENUM nozzleState0;
	SELFTEST_NOZZLE_ENUM nozzleState1;
	SELFTEST_BED_ENUM bedState;
	SELFTEST_AXIS_ENUM axisState;

	uint32_t beginTime;
	uint32_t axisTime;
	int16_t temp_nozzle0;
	int16_t temp_nozzle1;
	int16_t temp_bed;
	int16_t target_nozzle0;
	int16_t target_nozzle1;
	int16_t target_bed;

};

#endif
