/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_ZOFFSET_H
#define WTDUGSSCREEN_ZOFFSET_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_ZOffset : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	enum ZOFFSET_SCREEN_ENUM
	{
		ZOSE_BEGIN = 0,
		ZOSE_INPUT = 1
	};

	void ShowZOffset(void);
	void manage_manual_move(void);
	void manual_move_to_current(AxisEnum axis);

	ZOFFSET_SCREEN_ENUM zState;
	float zoffset_beginZpos;
	float zoffset_current;
	millis_t manual_move_start_time = 0;
	int8_t manual_move_axis = (int8_t)NO_AXIS;
};

#endif

