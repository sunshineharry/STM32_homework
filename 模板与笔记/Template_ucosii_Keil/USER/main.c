#include "stm32f10x.h"
#include "usart1.h"
#include "ucos_ii.h"

/////////////////////////UCOSII��������///////////////////////////////////
//START ����
//�����������ȼ�
#define START_TASK_PRIO      			10 //��ʼ��������ȼ�����Ϊ���
//���������ջ��С
#define START_STK_SIZE  				64
//�����ջ	
OS_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *pdata);	
 			   
//LED0����
//�����������ȼ�
#define TASK1_PRIO       			7 
//���������ջ��С
#define TASK1_STK_SIZE  		    		64
//�����ջ	
OS_STK TASK1_STK[TASK1_STK_SIZE];
//������
void print_task(void *pdata);

void SysTick_init(void)	       /*  SysTick_init   ����SysTick��ʱ��  */
{
    SysTick_Config(SystemCoreClock/OS_TICKS_PER_SEC);   //��ʼ����ʹ��SysTick��ʱ��
}

int main(void)
{	
	
		OSInit();
		OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//������ʼ����
		OSStart();
	
		while(1)
		{
			
		}
}

//��ʼ����
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr=0;
		
		SysTick_init();
		pdata = pdata; 
  	OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��)    
		OSTaskCreate(print_task,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE],TASK1_PRIO);						   				   
		OSTaskSuspend(START_TASK_PRIO);	//������ʼ����.
		OS_EXIT_CRITICAL();				//�˳��ٽ���(���Ա��жϴ��)
}

//LED0����
void print_task(void *pdata)
{	 	
	while(1)
	{
		/* USART1 config 115200 8-N-1 */
				USART1_Config();
	
				printf("Task 1\r\n");
			
				OSTimeDly(100);
	};
}
