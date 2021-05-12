#include "beep.h"

static uint8_t BEEP_State = CLOSE;

// 初始化蜂鸣器
void BEEP_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* 使能LED对应GPIO的Clock时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* 初始化LED的GPIO管脚，配置为推挽输出 */            
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;         //设置端口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //设置为 推挽(Push-Pull)输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //最大输出速度为50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOB, GPIO_Pin_8);
    BEEP_State = CLOSE;
}

// 关闭蜂鸣器
void BEEP_Close(void)
{
    GPIO_ResetBits(GPIOB, GPIO_Pin_8);
    BEEP_State = CLOSE;
}

// 打开蜂鸣器
void BEEP_Open(void)
{
    GPIO_SetBits(GPIOB, GPIO_Pin_8);
    BEEP_State = OPEN;
}

// 反转蜂鸣器状态
void BEEP_Toggle(void)
{
    if(BEEP_State==CLOSE)
        BEEP_Open();
    if(BEEP_State==OPEN)
        BEEP_Close();
}