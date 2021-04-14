#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f10x.h"

#define SYSTICK_DISABLE 0xFFFFFFFF
void SysTick_Handler(void);
void SysTick_Init(void);
uint32_t SysTick_GetTime(void);
void SysTick_Enable(void);
void SysTick_Disbale(void);

#endif