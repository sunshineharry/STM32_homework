#include "systick.h"

static uint32_t sysTickTime = 0;

/**
  * @brief  SysTick激活
  * @retval None
  */
void SysTick_Enable(void)
{
    sysTickTime = 0;
}

/**
  * @brief  SysTick关闭
  * @retval None
  */
void SysTick_Disable(void)
{
    sysTickTime = SYSTICK_DISABLE;
}

/**
  * @brief  SysTick初始化，设定系统滴答定时器1ms中断一次
  * @retval None
  */
void SysTick_Init(void)
{
    SysTick_Config(72000000/1000);  // 设定系统滴答定时器1ms中断一次
    SysTick_Disable();
}

/**
  * @brief  SysTick回调函数，每2s一个循环，当一个循环结束后，需要Reset才能继续使用
  * @retval None
  */
void SysTick_Handler(void)
{
    if (sysTickTime != SYSTICK_DISABLE)       // 把值锁定在 SYSTICK_PERIOD_END
        sysTickTime++;
}

/**
  * @brief  SysTick获取当前定时
  * @retval 系统当前时间
  */
uint32_t SysTick_GetTime(void)
{
    return sysTickTime;
}

