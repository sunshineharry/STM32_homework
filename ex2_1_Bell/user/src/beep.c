#include "beep.h"

// 打开蜂鸣器
static void BEEP_Turn_Off(void)
{
    GPIO_ResetBits(GPIO_BEEP_PORT, GPIO_BEEP_PIN);
}

// 蜂鸣器关闭
static void BEEP_Turn_On(void)
{
    GPIO_SetBits(GPIO_BEEP_PORT, GPIO_BEEP_PIN);
}

// 更改蜂鸣器状态
static void BEEP_Change_State(void)
{
    if(GPIO_ReadOutputDataBit(GPIO_BEEP_PORT, GPIO_BEEP_PIN))
        BEEP_Turn_Off();
    else
        BEEP_Turn_On();
}


// 蜂鸣器初始化
void BEEP_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 使能LED对应的GPIOD的Clock时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    // 初始化引脚，设置为推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_BEEP_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIO_BEEP_PORT,&GPIO_InitStructure);
    BEEP_Turn_Off();
}


/**
  * @brief  按照系统的工作模式，控制蜂鸣器
  * @param  mode: 系统的工作模式
  * @retval None
  */
void BEEP_Water_Beep(uint8_t mode)
{
    // 定义蜂鸣器需要翻转的次数
    // 例：如果蜂鸣器响3次，则需要翻转6次
    uint8_t remainBeepFlipTime = 2*mode;

    // 定义蜂鸣器的周期
    // 例：当mode=1时，beepCircleTime[mode-1]=500，表示蜂鸣器鸣响或熄灭的周期是500ms
    uint16_t beepCircleTime[4] = {500,250,100,63};

    // 如果系统滴答计时器被禁用，则关闭蜂鸣器
    if(SysTick_GetTime()==SYSTICK_DISABLE)
    {
        BEEP_Turn_Off();
        return;
    }

    // 正常工作模式
    // 定义beepFlipTime为已经翻转的次数
    for (uint8_t beepFlipTime=0;beepFlipTime<=remainBeepFlipTime;beepFlipTime++)
    {
        if(SysTick_GetTime()==beepFlipTime*beepCircleTime[mode-1] || beepFlipTime==0)
            BEEP_Change_State();
    }
}

