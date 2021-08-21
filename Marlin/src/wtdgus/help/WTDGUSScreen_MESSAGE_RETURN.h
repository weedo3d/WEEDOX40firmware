/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDUGSSCREEN_MESSAGE_RETURN_H
#define WTDUGSSCREEN_MESSAGE_RETURN_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"

class DGUS_Screen_Message_Return : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	void Title(const char* title);
	void Button(const char* title);
	void ShowText(const char* title);
	void Line(const char* title);

};

#endif
