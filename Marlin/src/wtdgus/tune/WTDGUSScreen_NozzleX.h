/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_NOZZLE_X_H
#define WTDUGSSCREEN_NOZZLE_X_H

#include "../help/WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_Nozzle_X : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
    uint8_t tempX;
	uint8_t tempY;
    uint8_t pageid = 0;
    
	void ShowButtonOn(uint8_t id);
	void ShowPage(void);
};

#endif

