/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_WIFI_DISK_H
#define WTDUGSSCREEN_WIFI_DISK_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_WifiDisk : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
	void ShowPage(void);

private:
	void ShowFileInfo(char* filename, uint16_t len, uint8_t index);
	void ShowHelp(void);

	char filename_buffer[UNICODE_FILENAME_LENGTH];	
};

#endif
