#include "stm32f10x_conf.h"
#include "led.h"

// led下一盏灯亮
void _next_led(unsigned char _led_number)
{
    switch (_led_number)
    {
    case 1:
        GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_RESET);
        GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
        break;
    case 2:
        GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_RESET);
        GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
        break;
    case 3:
        GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_RESET);
        GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
        break;
    case 4:
        GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
        GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_RESET);
        break;
    }
}

void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 使能LED对应的GPIOD的Clock时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // 初始化引脚，设置为推挽输出
    GPIO_InitStructure.GPIO_Pin = LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_GPIO_Port, &GPIO_InitStructure);
}

void change_led_state(void)
{
    switch (systemTime)
    {
    /*周期100ms切换一次*/
    case 1:
        _next_led(1);
        break;
    case 100:
        _next_led(2);
        break;
    case 200:
        _next_led(3);
        break;
    case 300:
        _next_led(4);
        break;
    case 400:
        _next_led(1);
        break;
    case 500:
        _next_led(2);
        break;
    case 600:
        _next_led(3);
        break;
    case 700:
        _next_led(4);
        break;
    case 800:
        _next_led(1);
        break;
    case 900:
        _next_led(2);
        break;
    case 1000:
        _next_led(3);
        break;
    case 1100:
        _next_led(4);
        break;
    case 1200:
        _next_led(1);
        break;
    case 1300:
        _next_led(2);
        break;
    case 1400:
        _next_led(3);
        break;
    case 1500:
        _next_led(4);
        break;
    case 1600:
        _next_led(1);
        break;
    case 1700:
        _next_led(2);
        break;
    case 1800:
        _next_led(3);
        break;
    case 1900:
        _next_led(4);
        break;
    /*周期200ms切换一次*/
    case 2000:
        _next_led(1);
        break;
    case 2200:
        _next_led(2);
        break;
    case 2400:
        _next_led(3);
        break;
    case 2600:
        _next_led(4);
        break;
    case 2800:
        _next_led(1);
        break;
    case 3000:
        _next_led(2);
        break;
    case 3200:
        _next_led(3);
        break;
    case 3400:
        _next_led(4);
        break;
    case 3600:
        _next_led(1);
        break;
    case 3800:
        _next_led(2);
        break;
    /*周期400ms切换一次*/
    case 4000:
        _next_led(3);
        break;
    case 4400:
        _next_led(4);
        break;
    case 4800:
        _next_led(1);
        break;
    case 5200:
        _next_led(2);
        break;
    case 5600:
        _next_led(3);
        break;
    /*周期500ms切换一次*/
    case 6000:
        _next_led(4);
        break;
    case 6500:
        _next_led(1);
        break;
    case 7000:
        _next_led(2);
        break;
    case 7500:
        _next_led(3);
        break;
    }
}
