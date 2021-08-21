/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDGUSScreen_BABYSTEP_H
#define WTDGUSScreen_BABYSTEP_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_Babystep : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess();

private:
	float babystep_current;

	void ShowZOffset(void);
};

#endif

