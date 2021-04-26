#include "stm32f10x_conf.h"
#include "delay.h"
#include "led.h"

int main(void)
{
    LED* led = (LED*)LED_new();
    led->init(led);
    while(1)
    {
        //led->shine(led);
        ;
    }
}
