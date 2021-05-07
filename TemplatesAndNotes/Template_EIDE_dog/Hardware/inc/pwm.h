#ifndef __PWM_H
#define __PWM_H	 
#include "stm32f10x_conf.h"


/*
TIM3的4个通道   CH1   CH2   CH3   CH4
    对应JP口    JP7   JP8   JP9   JP10
    对应引脚    PC6   PC7   PC8   PC9
    对应狗腿    RB1   RF1   RF2   LF2 		

TIM5的4个通道   CH1   CH2   CH3   CH4
    对应JP口    JP1   JP2   JP3   JP4
    对应引脚    PA0   PA1   PA2   PA3
    对应狗腿    LF1   LB1   LB2   RB2  
		
*/


#define RF_LEG1_PIN   GPIO_Pin_7    // PC7,JP8
#define RF_LEG1       8

#define RF_LEG2_PIN   GPIO_Pin_8    // PC8,JP9
#define RF_LEG2       9

#define LF_LEG1_PIN   GPIO_Pin_0    // PA0,JP1
#define LF_LEG1       1

#define LF_LEG2_PIN   GPIO_Pin_9    // PC9,JP10
#define LF_LEG2       10

#define RB_LEG1_PIN   GPIO_Pin_6    // PC6,JP7
#define RB_LEG1       7

#define RB_LEG2_PIN   GPIO_Pin_3    // PA3,JP4
#define RB_LEG2       4

#define LB_LEG1_PIN   GPIO_Pin_1    // PA1,JP2
#define LB_LEG1       2

#define LB_LEG2_PIN   GPIO_Pin_2    // PA2,JP3
#define LB_LEG2       3

#define ARR         20000-1
#define PSC         72-1

void PWM_Init(void);
void PWM_Output(uint8_t leg, uint16_t degree);


 
#endif
