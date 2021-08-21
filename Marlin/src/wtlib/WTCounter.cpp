/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "WTCounter.h"
#include "../MarlinCore.h"
#include "../wtdgus/WTDGUSManager.h"

millis_t WTCounter::mlastDuration;
uint32_t WTCounter::mTime;
uint32_t WTCounter::mInterval;
WTCounter::State WTCounter::state;
millis_t WTCounter::accumulator;
millis_t WTCounter::startTimestamp;
millis_t WTCounter::stopTimestamp;
bool WTCounter::enabled;

millis_t WTCounter::deltaDuration()
{
	millis_t tmp = mlastDuration;
	mlastDuration = duration();
	return mlastDuration - tmp;
}

void WTCounter::tick()
{
	if (!isRunning()) return;

	mTime += deltaDuration();

	if (isRunning() && enabled && mTime > mInterval)
	{
		stop();
		#ifdef DGUS_LCD
		dgus.GotoPowerOffMenu();
		#endif
	}
}

bool WTCounter::start()
{
	if (!isRunning()) 
	{

		if (isPaused()) 
			accumulator = duration();
		else 
			reset();

		state = RUNNING;
		startTimestamp = millis();

		mlastDuration = 0;
		mTime = 0;
		return true;
	}
	else 
		return false;
}

bool WTCounter::stop()
{
	if (isRunning() || isPaused()) 
	{
		state = STOPPED;
		stopTimestamp = millis();
		mTime += deltaDuration();
		return true;
	}
	else 
		return false;
}

void WTCounter::reset()
{
	state = STOPPED;
	startTimestamp = 0;
	stopTimestamp = 0;
	accumulator = 0;

	mlastDuration = 0;
}

void WTCounter::restart()
{
	mTime = 0;
}

void WTCounter::SetInterval(uint8_t interval)
{
	if (interval <= 30 && interval > 0)
	{
		enabled = true;
		mInterval = interval * 60;
	}
	else
	{
		enabled = false;
	}
}

millis_t WTCounter::duration() 
{
	return ((isRunning() ? millis() : stopTimestamp)
		- startTimestamp) / 1000UL + accumulator;
}