/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus 窗口类的基类
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