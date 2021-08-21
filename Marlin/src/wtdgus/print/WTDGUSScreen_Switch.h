/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_SWITCH_H
#define WTDUGSSCREEN_SWITCH_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_Switch : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	FILAMENT_OPERATION_ENUM operation;

private:
	uint8_t old_extruder;
	bool chaning_tool;
};

#endif

