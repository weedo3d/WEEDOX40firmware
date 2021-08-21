/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

#ifndef WTCOUNTER_H
#define WTCOUNTER_H

#include "../core/macros.h"
#include "../libs/stopwatch.h"

class WTCounter
{
public:
	static inline void init() 
	{
		reset();
		mTime = 0;
	}

	static void tick();

	static bool start();

	static bool stop();

	static void reset();

	static void restart();

	static void SetInterval(uint8_t interval);

	static millis_t duration();

	FORCE_INLINE static bool isRunning() { return state == RUNNING; }

	FORCE_INLINE static bool isPaused() { return state == PAUSED; }

protected:
	static millis_t deltaDuration();

private:
	enum State : char {
		STOPPED,
		RUNNING,
		PAUSED
	};

	typedef Stopwatch super;
	static const uint16_t updateInterval;
	static millis_t mlastDuration;
	static uint32_t mTime;
	static bool enabled;
	static uint32_t mInterval;
	static WTCounter::State state;
	static millis_t accumulator;
	static millis_t startTimestamp;
	static millis_t stopTimestamp;
};

extern WTCounter wt_timer;

#endif