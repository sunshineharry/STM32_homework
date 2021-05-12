#ifndef __PWM_H
#define __PWM_H	 
#include "stm32f10x_conf.h"


/*
TIM3��4��ͨ��   CH1   CH2   CH3   CH4
    ��ӦJP��    JP7   JP8   JP9   JP10
    ��Ӧ����    PC6   PC7   PC8   PC9
    ��Ӧ����    ZH1   YH1   YH2   LF2 		

TIM5��4��ͨ��   CH1   CH2   CH3   CH4  
    ��ӦJP��    JP1   JP2   JP3   JP4
    ��Ӧ����    PA0   PA1   PA2   PA3
    ��Ӧ����    LF1   LB1   LB2   ZH2  
		
*/



#define YH_LEG1       8
#define YH_LEG2       9
#define YQ_LEG1       1
#define YQ_LEG2       10
#define ZH_LEG1       7
#define ZH_LEG2       4
#define ZQ_LEG1       2
#define ZQ_LEG2       3

#define ARR         20000-1
#define PSC         72-1

void PWM_Init(void);
void PWM_Output(uint8_t leg, uint16_t degree);


 
#endif
