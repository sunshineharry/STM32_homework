#include "stm32f10x_conf.h"
#include "led.h"


/**
  * @brief  LED初始化函数
  * @retval None
  */
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 使能LED对应的GPIOD的Clock时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // 初始化引脚，设置为推挽输出
    GPIO_InitStructure.GPIO_Pin = LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_GPIO_Port, &GPIO_InitStructure);
}


/**
  * @brief  【static】点亮一盏LED灯
  * @param  led_num: 点亮LED的序号
  * @retval None
  */
static void LED_Shine(uint8_t led_num)
{
    switch (led_num)            // 根据状态变量切换LED的点亮模式
    {
        case 0:                 // LED1点亮，其他熄灭
            GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_RESET);
            GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
            break;
        case 1:                 // LED2点亮，其他熄灭
            GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_RESET);
            GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
            break;
        case 2:                 // LED3点亮，其他熄灭
            GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_RESET);
            GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
            break;
        case 3:                 // LED4点亮，其他熄灭
            GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_RESET);
            break;
        default:                 // 其余情况，LED全部熄灭
            GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
            GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);
    }

}


/**
  * @brief  【static】关闭LED
  * @param  led_num: 点亮LED的序号
  * @retval None
  */
static void LED_Close(void)
{
    GPIO_WriteBit(LED_GPIO_Port, LED1_Pin, Bit_SET);
    GPIO_WriteBit(LED_GPIO_Port, LED2_Pin, Bit_SET);
    GPIO_WriteBit(LED_GPIO_Port, LED3_Pin, Bit_SET);
    GPIO_WriteBit(LED_GPIO_Port, LED4_Pin, Bit_SET);   
}


/**
  * @brief  按照系统的工作模式，点亮LED
  * @param  mode: 系统的工作模式
  * @retval None
  */
void LED_WaterLamp(uint8_t mode)
{
    static uint16_t LEDCircleTime[4] = {1000,500,300,200};  // 定义LED点亮周期

    // 当定时器被禁用时，不启动流水灯
    if(SysTick_GetTime()==SYSTICK_DISABLE)
    {
        LED_Close();
        return;
    }

    // 根据mode按不同的频率点亮LED
    // 例：当mode=1时，LEDCircleTime[mode-1]=1000，即LED的周期为1s
    //     把系统时钟按LED周期分频计数，当计数值为0,1,2,3时点亮相应LED，其余数值关闭所有LED
    LED_Shine(SysTick_GetTime() / LEDCircleTime[mode-1]);
}
