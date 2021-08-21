/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#include "WTDGUSScreenBase.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Base::Goback()
{
	if (parent != NULL)
	{
		activated = false;
		dgus.GotoScreen(parent);
	}
}