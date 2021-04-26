#include "bell_state.h"

static uint8_t bellMode = 0;

// TODO：用定时器重写
static void delay_ms(uint16_t delayTime)
{    
   uint16_t i = 0;  
   while(delayTime--)
   {
      i = 12000;
      while(i--) ;    
   }
}

void STATE_Set_State(uint8_t bellNewState)
{
    bellMode = bellNewState;
}

void STATE_Get_State(void)
{
    return bellMode;
}

// 使系统按照设定的工作模式开始工作
void STATE_Enable_Work(void)
{
    // 每种模式下最长的循环周期
    static maxCircleTime[4] = {4000,2000,1200,800};

    // 循环次数
    static flipTime = 3;

    while(flipTime)
    {
        SysTick_Enable();                                   // 打开滴答计时器，开始工作
        BEEP_Water_Beep(bellMode);                          // 控制蜂鸣器
        LED_WaterLamp(bellMode);                            // 控制流水灯
        if (SysTick_GetTime==maxCircleTime[bellMode-1])     // 当到达最长循环周期时
        {
            SysTick_Disbale();                              // 关闭滴答计时器
            BEEP_Water_Beep(bellMode);                      // 关闭流水灯与蜂鸣器
            LED_WaterLamp(bellMode);
            delay_ms(2000);
            flipTime--;
        }
    }

    SysTick_Disbale();                                      // 当循环三次后，关闭
}