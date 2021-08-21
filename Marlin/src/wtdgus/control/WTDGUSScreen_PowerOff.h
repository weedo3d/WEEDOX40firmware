/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_POWEROFF_H
#define WTDUGSSCREEN_POWEROFF_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_PowerOff : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	int deadtime;
};

#endif

