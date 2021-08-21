/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_SDCARD_H
#define WTDUGSSCREEN_SDCARD_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_SDCard : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	bool NeedUpdate = true;
private:
	void ShowFileInfo(char* filename, uint16_t len, uint8_t index);
	void ShowPage(uint8_t id);
	void ShowPrePage(void);
	void ShowNextPage(void);
	void ClearList(void);
	void ShowHelp(void);
	void UpdateFilelist(void);

	uint16_t filecount;
	uint8_t pageid;
	uint8_t pagecount;
	bool cardStatus;

	char filename_buffer[UNICODE_FILENAME_LENGTH];
	wt_fileinfo_t filelist[6];
};

#endif