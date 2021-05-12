
#ifndef __BEEP_H
#define __BEEP_H
#include "stm32f10x_conf.h"

#define CLOSE   0
#define OPEN    1

void BEEP_Init(void);
void BEEP_Close(void);
void BEEP_Open(void);
void BEEP_Toggle(void);

#endif
