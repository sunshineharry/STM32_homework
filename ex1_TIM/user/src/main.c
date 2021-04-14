#include "stm32f10x_conf.h"
#include "main.h"
#include "led.h"

int main(void)
{
    SysTick_Config(72000000/1000);     // 设定系统滴答定时器1ms中断一次
		// 初始化
		beep_init();
		led_init();
    while(1)
    {
        change_beep_state();
        change_led_state();
    }
}
