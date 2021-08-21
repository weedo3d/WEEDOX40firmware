/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTDGUSSCREEN_PREVIEW_H
#define WTDGUSSCREEN_PREVIEW_H

#include "../WTDGUSScreenBase.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_Preview : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	void enable(bool action);

private:
	bool b_enable;
    bool b_dualmode;

    void do_print(void);
};


#endif