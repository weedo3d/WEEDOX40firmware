/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_IAP_H
#define WTDUGSSCREEN_IAP_H

#include "../help/WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_IAP : public DGUS_Screen_ScrollList
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	void do_operation(void);

    enum IAP_STEP_ENUM
	{
		ISE_IDLE = 0,
        ISE_CHECK_FILE = 1,
        ISE_CHECK_VERSION = 2,
        ISE_CHECK_UPDATE_WAIT = 3,
        ISE_ERROR = 4
	};

    IAP_STEP_ENUM state;
	char wfmversion[8];
	uint8_t filelength[6];
	char machinename[22];
	char fwversion[12];
	uint8_t rebootcount;
    bool forceMode;
};

#endif

