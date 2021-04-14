#include "main.h"

void init(void)
{
    SysTick_Init();
    LED_Init();
    BEEP_Init();
}

int main(void)
{
    init();
    while(1)
    {
        LED_WaterLamp(0);
    }
}