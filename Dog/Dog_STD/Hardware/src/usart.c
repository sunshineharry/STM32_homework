#include "usart.h"

/**
  * @brief  串口3初始化函数，串口3被用作printf重定向，用作日志打印
  *         字长为8位数据格式，一个停止位，无奇偶校验位，收发模式
  * @param  uint32_t: 波特率，推荐9600
  * @retval None
  */
void UART3_Init(uint32_t bound)
{
    /*------------------------GPIO端口设置------------------------*/
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);  //使能USART3，GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    //USART1_TX   GPIOA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;              //PA.9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //复用推挽输出
    GPIO_Init(GPIOB, &GPIO_InitStructure);                  //初始化GPIOA.9

    //USART1_RX	  GPIOA.10初始化
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;              //PA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   //浮空输入
    GPIO_Init(GPIOB, &GPIO_InitStructure);                  //初始化GPIOA.10

    
    /*------------------------Usart1 NVIC 配置------------------------*/
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //抢占优先级2
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;        //子优先级2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                           //根据指定的参数初始化VIC寄存器


    /*------------------------初始化设置------------------------*/
    USART_InitStructure.USART_BaudRate = bound;                                     //串口波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     //字长为8位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                          //一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;                             //无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                 //收发模式

    USART_Init(USART3, &USART_InitStructure);      //初始化串口1
    USART_Cmd(USART3, ENABLE);                     //使能串口1
}


/**
  * @brief  重定向c库函数printf到USART3【由printf调用】
  * @retval None
  */
int fputc(int ch, FILE *f)
{
	USART_SendData(USART3, (unsigned char) ch);
	while( USART_GetFlagStatus(USART3,USART_FLAG_TC)!= SET);	
	return (ch);
}


/**
  * @brief  串口4初始化函数
  *         字长为8位数据格式，一个停止位，无奇偶校验位，收发模式
  * @param  uint32_t: 波特率，推荐9600
  * @retval None
  */
void UART4_Init(u32 bound)
{
    /*------------------------GPIO端口设置------------------------*/
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    //USART1_TX   GPIOA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PA.9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //复用推挽输出
    GPIO_Init(GPIOC, &GPIO_InitStructure);                  //初始化GPIOA.9

    //USART1_RX	  GPIOA.10初始化
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;              //PA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   //浮空输入
    GPIO_Init(GPIOC, &GPIO_InitStructure);                  //初始化GPIOA.10


    /*------------------------Usart1 NVIC 配置------------------------*/
    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //抢占优先级2
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //子优先级2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                           //根据指定的参数初始化VIC寄存器


    /*------------------------初始化设置------------------------*/
    USART_InitStructure.USART_BaudRate = bound;                                     //串口波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     //字长为8位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                          //一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;                             //无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                 //收发模式

    USART_Init(UART4, &USART_InitStructure);      //初始化串口4
    USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); //开启串口接受中断
    USART_Cmd(UART4, ENABLE);                     //使能串口4
}


/**
  * @brief  串口4中断服务程序，将收到的数据在发出去
  * @retval None
  */
void UART4_IRQHandler(void)
{
    uint8_t Res;
    if (USART_GetITStatus(UART4, USART_IT_RXNE) != RESET) //接收中断(接收到的数据必须是0x0d 0x0a结尾)
    {
        Res = USART_ReceiveData(UART4); //读取接收到的数据
        USART_SendData(UART4, Res);
    }
}

