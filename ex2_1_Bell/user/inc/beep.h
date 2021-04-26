#ifndef __BEEP_H__
#define __BEEP_H__

#include "stm32f10x.h"
#include "systick.h"
#define GPIO_BEEP_PORT GPIOA
#define GPIO_BEEP_PIN GPIO_Pin_3
void BEEP_Init(void);
void BEEP_Water_Beep(uint8_t mode);


#endif

