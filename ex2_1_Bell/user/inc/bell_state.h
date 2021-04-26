#ifndef __BELL_STATE_H__
#define __BELL_STATE_H__

#include "stm32f10x_conf.h"
#include "beep.h"
#include "led.h"
#include "systick.h"
void STATE_Set_State(uint8_t bellNewState);
void STATE_Get_State(void);
void STATE_Enable_Work(void);

#endif