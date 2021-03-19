#include "stm32f10x_conf.h"
#include "delay.h"
#include "led.h"

int main(void)
{
    LED_Init();
    while(1)
    {
        LED_Shine();
    }
}