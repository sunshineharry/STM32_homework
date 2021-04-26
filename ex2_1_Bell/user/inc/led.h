#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x_conf.h"
#include "systick.h"

// 定义引脚
#define LED1_Pin GPIO_Pin_2
#define LED2_Pin GPIO_Pin_3
#define LED3_Pin GPIO_Pin_4
#define LED4_Pin GPIO_Pin_7
#define LED_GPIO_Port GPIOD

void LED_Init(void);
void LED_WaterLamp(uint8_t mode);


#endif
