#include "stm32f10x.h"
#include "pwm.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"

// 对输出PWM的GPIO口初始化
static void PWM_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure_A;
    GPIO_InitTypeDef GPIO_InitStructure_C;


    /*------------------------打开时钟------------------------*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);     // 复用功能需要的时钟 AFIO 

    /*------------------------配置引脚------------------------*/
    GPIO_InitStructure_A.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
    GPIO_InitStructure_A.GPIO_Mode = GPIO_Mode_AF_PP;       // 复用推挽输出
    GPIO_InitStructure_A.GPIO_Speed = GPIO_Speed_50MHz;     // 输出50MHz

    GPIO_Init(GPIOA,&GPIO_InitStructure_A);

    GPIO_InitStructure_C.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure_C.GPIO_Mode = GPIO_Mode_AF_PP;       // 复用推挽输出
    GPIO_InitStructure_C.GPIO_Speed = GPIO_Speed_50MHz;     // 输出50MHz
    GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);
    GPIO_Init(GPIOC,&GPIO_InitStructure_C);
}

// 对生成PWM的定时器初始化
// 使用TIM2和TIM3进行输出，由于PWM的周期为2ms，选择ARR=20000-1，PSC=72-1
// 周期公式：Tout=((arr+1)*(pscv+1))/Tclk，其中，Tclk=1/72M
static void PWM_TIM_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruture;       // 定时器初始化结构体
    TIM_OCInitTypeDef TIM_OCInitStruture;                   // 定时器通道初始化结构体
    
    /*------------------------打开时钟------------------------*/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);

    /*------------------------初始化定时器------------------------*/
    TIM_DeInit(TIM3);
    TIM_DeInit(TIM5);
    TIM_TimeBaseInitStruture.TIM_Period = ARR;                      // 自动重装载计数器的值
    TIM_TimeBaseInitStruture.TIM_Prescaler = PSC;                   // 时钟预分频数
    TIM_TimeBaseInitStruture.TIM_CounterMode=TIM_CounterMode_Up;    // 计数模式采用向上计数    
    TIM_TimeBaseInitStruture.TIM_ClockDivision=TIM_CKD_DIV1;        // 分频因子采用采样分频
    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruture);
    TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitStruture);


    /*------------------------初始化定时器通道------------------------*/
    TIM_OCInitStruture.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStruture.TIM_OCPolarity=TIM_OCPolarity_High; 
    TIM_OCInitStruture.TIM_OutputState=TIM_OutputState_Enable;
    TIM_OC1Init(TIM5,&TIM_OCInitStruture);
    TIM_OC1PreloadConfig(TIM5,TIM_OCPreload_Enable);
    TIM_OC2Init(TIM5,&TIM_OCInitStruture);
    TIM_OC2PreloadConfig(TIM5,TIM_OCPreload_Enable);
    TIM_OC3Init(TIM5,&TIM_OCInitStruture);
    TIM_OC3PreloadConfig(TIM5,TIM_OCPreload_Enable);
    TIM_OC4Init(TIM5,&TIM_OCInitStruture);
    TIM_OC4PreloadConfig(TIM5,TIM_OCPreload_Enable);
    TIM_OC1Init(TIM3,&TIM_OCInitStruture);
    TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
    TIM_OC2Init(TIM3,&TIM_OCInitStruture);
    TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
    TIM_OC3Init(TIM3,&TIM_OCInitStruture);
    TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
    TIM_OC4Init(TIM3,&TIM_OCInitStruture);
    TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);

    /*------------------------使能定时器------------------------*/
    TIM_Cmd(TIM3,ENABLE);
    TIM_Cmd(TIM5,ENABLE);
}

// 初始化PWM信号
void PWM_Init(void)
{
    PWM_GPIO_Init();
    PWM_TIM_Init();
}


/**
  * @brief  输出PWM信号
  * @param  leg: 机器狗控制腿的舵机
  *   该参数可以有以下选择
  *     @arg RF_LEG1, RF_LEG2, LF_LEG1, LF_LEG2
  *          RB_LEG1, RB_LEG2, LB_LEG1, LB_LEG2
  * @param  degree: 电机旋转角度
  * @retval None
  */
void PWM_Output(uint8_t leg, uint16_t degree)
{
    uint16_t compareTime = degree/180*1000+1000;
    switch (leg)
    {
        case RF_LEG1:
        {
            TIM_SetCompare2(TIM3,compareTime);
            break;
        }
        case RF_LEG2:
        {
            TIM_SetCompare3(TIM3,compareTime);
            break;
        }
        case LF_LEG1:
        {
            TIM_SetCompare1(TIM5,compareTime);
            break;
        }
        case LF_LEG2:
        {
            TIM_SetCompare4(TIM3,compareTime);
            break;
        }
        case RB_LEG1:
        {
            TIM_SetCompare1(TIM3,compareTime);
            break;
        }
        case RB_LEG2:
        {
            TIM_SetCompare4(TIM5,compareTime);
            break;
        }
        case LB_LEG1:
        {
            TIM_SetCompare2(TIM5,compareTime);
            break;
        }
        case LB_LEG2:
        {
            TIM_SetCompare3(TIM5,compareTime);
            break;
        }
    }
}
