#include "timer.h"

/*------------------------ 配置通用定时器 TIM2 ------------------------*/

uint8_t LED_switch = 0;

/**
  * @brief  中断优先级NVIC设置
  * @param  None
  * @retval None
  */
void _NVIC_TIM2_configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;                      // 定义NVIC寄存器初始化结构体变量
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);           // 用途？？？
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;           // TIM2中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; // 先占优先级0级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;        // 从优先级3级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);                           // 初始化NVIC寄存器
}

/**
  * @brief  定时器2初始化，中断周期 Tout=(arrv*pscv)/Tclk 。
  *         其中Tclk为定时器输入时钟频率，通常，Tclk=72MHz
  * @param  pscv TIM_Prescaler，预分频寄存器
  * @param  arrv TIM_Period寄存器    
  * @retval None
  */
void TIM2_Init(u32 pscv, u32 arrv)
{
    _NVIC_TIM2_configuration();
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);        // 初始化TIM2的时钟

    TIM_TimeBaseStructure.TIM_Period = arrv - 1;                // 设置自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler = pscv - 1;             // 设置时钟频率除数的预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // 设置时钟分割
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // TIM向上计数

    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);             // 初始化TIM2
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);                 // 清除溢出中断标志
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);                  // 溢出中断使能
    TIM_Cmd(TIM2,ENABLE);                                       // 计数器使能
}

/**
  * @brief  定时器2的中断回调函数，发生中断后自动进入
  * @param  None
  * @retval None
  */
void TIM2_IQRHandler(void)
{
    if (TIM_GetITStatus(TIM2,TIM_IT_Update) != RESET)           // 判断是否进入中断
    {
        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);              // 清除中断标志位
        LED_switch++;                                           // 每中断一次，LED_switch加一，这个量控制是哪个LED灯点亮
        if (LED_switch==4)
            LED_switch = 0;
    }
}