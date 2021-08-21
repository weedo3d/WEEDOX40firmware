/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#ifndef WTDUGSSCREEN_NOZZLE_Z_H
#define WTDUGSSCREEN_NOZZLE_Z_H

#include "../help/WTDGUSScreen_ScrollList.h"
#include "../WTDGUSConfig.h"


class DGUS_Screen_Nozzle_Z : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
    enum NOZZLEZ_STEP_ENUM
    {
        NSE_STEP1_INPUT     = 0,
        NSE_STEP2_MOVING    = 1,
        NSE_STEP2_INPUT     = 2,
        NSE_STEP3_MOVING    = 3,
        NSE_STEP3_INPUT     = 4,
        NSE_STEP4_MOVING    = 5,
        NSE_STEP4_INPUT     = 6,
    };

    uint8_t pageid = 0;
    NOZZLEZ_STEP_ENUM status;
    
    void ShowZOffset(void);
	void manage_manual_move(void);
	void manual_move_to_current(AxisEnum axis);
    void move_to_z(float value);
    void ShowPage(void);
    void End(void);

    float zoffset_current;
	millis_t manual_move_start_time = 0;
	int8_t manual_move_axis = (int8_t)NO_AXIS;
};

#endif

