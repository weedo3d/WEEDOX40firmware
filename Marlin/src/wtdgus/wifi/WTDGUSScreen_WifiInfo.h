/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_WIFI_INFO_H
#define WTDUGSSCREEN_WIFI_INFO_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_WifiInfo : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
};

#endif
