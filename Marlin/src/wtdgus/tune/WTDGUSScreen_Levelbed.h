/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_LEVELBED_H
#define WTDUGSSCREEN_LEVELBED_H

#include "../help/WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_Levelbed : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	enum LEVELBED_SCREEN_ENUM
	{
		LBSE_NOTHING = 0,
		LBSE_WAITHOME = 1,
		LBSE_WAIT1STPT = 2,
		LBSE_WAIT2NDPT = 3,
		LBSE_WAIT3RDPT = 4,
		LBSE_WAIT4THPT = 5,
		LBSE_WAITCOMPELTE = 6,
		LBSE_WAITCANCELLED = 7,
		LBSE_WAIT_INPUT1 = 8,
		LBSE_WAIT_INPUT2 = 9,
		LBSE_WAIT_INPUT3 = 10,
		LBSE_WAIT_INPUT4 = 11,
		LBSE_WAITDETECT = 12,
		LBSE_DETECT_END = 13,
	};

	LEVELBED_SCREEN_ENUM levelbedmanuelsts;
};

#endif

