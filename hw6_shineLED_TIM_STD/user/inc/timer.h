#ifndef __TIMER_H__
#define __TIMER_H__

#include "stm32f10x_conf.h"
void TIM2_Init(u32 pscv, u32 arrv);
extern uint8_t LED_switch;

#endif