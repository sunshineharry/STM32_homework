#include "led.h"
#include "beep.h"
#include "delay.h"
#include "key.h"
#include "pwm.h"
#include "sys.h"
#include "usart.h"
#include "includes.h"

/////////////////////////UCOSII任务堆栈设置///////////////////////////////////
//START 任务
//设置任务优先级
#define START_TASK_PRIO 10 //开始任务的优先级设置为最低
//设置任务堆栈大小
#define START_STK_SIZE 64
//创建任务堆栈空间
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数接口
void start_task(void *pdata);

int main(void)
{

    delay_init(); //延时函数初始化
    // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
    UART3_Init(9600);
    UART4_Init(9600);
    LED_Init();  //初始化与LED连接的硬件接口
    BEEP_Init(); //蜂鸣器初始化
    KEY_Init();  //按键初始化
    PWM_Init();
    TIM_SetCompare1(TIM3,20000-1500);
    TIM_SetCompare2(TIM3,20000-1500);
    TIM_SetCompare3(TIM3,20000-1500);
    TIM_SetCompare4(TIM3,20000-1500);
    TIM_SetCompare1(TIM5,20000-1500);
    TIM_SetCompare2(TIM5,20000-1500);
    TIM_SetCompare3(TIM5,20000-1500);
    TIM_SetCompare4(TIM5,20000-1500);


    delay_ms(1000);
    //PWM_Output(RF_LEG1,90);
    //PWM_Output(7,90);
    LOG_INFO("START RUN");
    OSInit();                                                                                            //初始化UCOSII
    OSTaskCreate(start_task, (void *)0, (OS_STK *)&START_TASK_STK[START_STK_SIZE - 1], START_TASK_PRIO); //创建起始任务
    OSStart();
}

//开始任务
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr = 0;
    pdata = pdata;
    OS_ENTER_CRITICAL(); //进入临界区(无法被中断打断)

    OSTaskSuspend(START_TASK_PRIO); //挂起起始任务.
    OS_EXIT_CRITICAL();             //退出临界区(可以被中断打断)
}
