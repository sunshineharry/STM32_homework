#include "beep.h"

// 打开蜂鸣器
void beep_turn_on(void)
{
    GPIO_ResetBits(GPIO_BEEP_PORT, GPIO_BEEP_PIN);
}

// 蜂鸣器关闭
void beep_turn_off(void)
{
    GPIO_SetBits(GPIO_BEEP_PORT, GPIO_BEEP_PIN);
}

void beep_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 使能LED对应的GPIOD的Clock时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    // 初始化引脚，设置为推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_BEEP_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIO_BEEP_PORT,&GPIO_InitStructure);
}


void change_beep_state(void)
{
    switch (systemTime)
    {
        /*第一次，响一下，持续500ms*/
        case 1:
            beep_turn_on();
            break;            
        case 500:
            beep_turn_off();
            break;

        /*第二次，响两下，持续250ms，间隔250ms*/
        // 第一次
        case 2000:
            beep_turn_on();
            break;
        case 2250:
            beep_turn_off();
            break;  
        // 第二次
        case 2500:
            beep_turn_on();
            break;
        case 2570:
            beep_turn_off();
            break; 

        /*第三次，响三下，持续200ms，间隔200ms*/
        // 第一次
        case 4000:
            beep_turn_on();
            break;
        case 4200:
            beep_turn_off();
            break;  
        // 第二次
        case 4400:
            beep_turn_on();
            break;
        case 4600:
            beep_turn_off();
            break;  
        // 第三次
        case 4800:
            beep_turn_on();
            break;
        case 5000:
            beep_turn_off();
            break;  

        /*第四次，响四下，持续150ms，间隔150ms*/
        // 第一次
        case 6000:
            beep_turn_on();
            break;
        case 6150:
            beep_turn_off();
            break;  
        // 第二次
        case 6300:
            beep_turn_on();
            break;
        case 6450:
            beep_turn_off();
            break;  
        // 第三次
        case 6600:
            beep_turn_on();
            break;
        case 6750:
            beep_turn_off();
            break;  
        // 第四次
        case 6900:
            beep_turn_on();
            break;
        case 7050:
            beep_turn_off();
            break;               
    }
}
