#include "stm32f10x.h"
#include "log.h"
#include "ucos_ii.h"

/*---------------------------UCOSII任务设置---------------------------*/
//START 任务
//设置任务优先级
#define START_TASK_PRIO     10 //开始任务的优先级设置为最低
//设置任务堆栈大小
#define START_STK_SIZE      64
//任务堆栈
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *pdata);

//LED0任务
//设置任务优先级
#define TASK1_PRIO          7
//设置任务堆栈大小
#define TASK1_STK_SIZE      64
//任务堆栈
OS_STK TASK1_STK[TASK1_STK_SIZE];
//任务函数
void print_task(void *pdata);

/*---------------------------初始化---------------------------*/
//SysTick初始化
void SysTick_init(void) 
{
    SysTick_Config(SystemCoreClock / OS_TICKS_PER_SEC);
}



/*---------------------------MAIN函数---------------------------*/
int main(void)
{

    OSInit();
    USART1_Config();        // 串口1初始化，用于printf调试
    OSTaskCreate(start_task, (void *)0, (OS_STK *)&START_TASK_STK[START_STK_SIZE - 1], START_TASK_PRIO); //创建起始任务
    OSStart();
    while (1)
    {
    }
}

/*---------------------------任务函数---------------------------*/
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr = 0;
    SysTick_init();
    pdata = pdata;
    OS_ENTER_CRITICAL();            //进入临界区(无法被中断打断)
    OSTaskCreate(print_task, (void *)0, (OS_STK *)&TASK1_STK[TASK1_STK_SIZE], TASK1_PRIO);
    OSTaskSuspend(START_TASK_PRIO); //挂起起始任务.
    OS_EXIT_CRITICAL();             //退出临界区(可以被中断打断)
}

//LED0任务
void print_task(void *pdata)
{
    while (1)
    {
        /* USART1 config 115200 8-N-1 */
        USART1_Config();
        printf("Task 1\r\n");
        OSTimeDly(100);
    };
}
