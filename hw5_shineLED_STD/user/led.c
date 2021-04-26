#include "stm32f10x_conf.h"
#include "led.h"
#include "delay.h"

static void init(void* self)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 使能LED对应的GPIOD的Clock时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);

    // 初始化引脚，设置为推挽输出
    GPIO_InitStructure.GPIO_Pin = LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(LED_GPIO_Port,&GPIO_InitStructure);
}

static void shine(void* self)
{
    delay();
    switch (m_nDelayNum)
    {
        case 0:
            GPIO_WriteBit(LED_GPIO_Port,LED1_Pin,Bit_RESET);
            GPIO_WriteBit(LED_GPIO_Port,LED2_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED3_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED4_Pin,Bit_SET);
            break;
        case 1:
            GPIO_WriteBit(LED_GPIO_Port,LED1_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED2_Pin,Bit_RESET);
            GPIO_WriteBit(LED_GPIO_Port,LED3_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED4_Pin,Bit_SET);
            break;
        case 2:
            GPIO_WriteBit(LED_GPIO_Port,LED1_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED2_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED3_Pin,Bit_RESET);
            GPIO_WriteBit(LED_GPIO_Port,LED4_Pin,Bit_SET);
            break;
        case 3:
            GPIO_WriteBit(LED_GPIO_Port,LED1_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED2_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED3_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED4_Pin,Bit_RESET);
            break;
        default:
            GPIO_WriteBit(LED_GPIO_Port,LED1_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED2_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED3_Pin,Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port,LED4_Pin,Bit_SET);
            break;

    }
}

CTOR(LED)
    FUNCTION_SETTING(init, init)
    FUNCTION_SETTING(shine, shine)
END_CTOR
