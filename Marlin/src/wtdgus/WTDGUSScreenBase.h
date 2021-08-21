/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDGUSSCREENBASE_H
#define WTDGUSSCREENBASE_H

#include "../MarlinCore.h"
#include "../../Configuration.h"

#define UNICODE_FILENAME_LENGTH	54

typedef struct
{
	char buffer[UNICODE_FILENAME_LENGTH];
    uint8_t len;
}wt_fileinfo_t;

class DGUS_Screen_Base
{
	public:
		DGUS_Screen_Base(void) { parent = NULL;}
		void SetParent(DGUS_Screen_Base* p) { parent = p; }
		void Goback(void);
		 
		virtual void Init(void) {};
		virtual void Update(void) {};
		virtual void KeyProcess(void) {};
		virtual void ShowFilename(const char* fname) {};

		uint32_t updaterate = 1000;
		uint32_t holdontime;

		bool activated = false;

	protected:
		DGUS_Screen_Base* parent;
};

#endif
