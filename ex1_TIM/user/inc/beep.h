#ifndef __BEE_H__
#define __BEE_H__
#include "stm32f10x_it.h"
#include "stm32f10x.h"
#define GPIO_BEEP_PORT GPIOA
#define GPIO_BEEP_PIN GPIO_Pin_3

void beep_init(void);
void change_beep_state(void);

#endif

