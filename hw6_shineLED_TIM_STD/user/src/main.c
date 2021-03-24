#include "main.h"

int main(void)
{
    TIM2_Init(2500,7200);
    led_init();
    while(1)
    {
        led_shine();
    }
}