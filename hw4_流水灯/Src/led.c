#include "led.h"

void _led_reset(void)
{
    HAL_GPIO_WritePin(GPIOD,LED1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD,LED2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD,LED3_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD,LED4_Pin,GPIO_PIN_RESET);
}

void led_shine(uint32_t delayTime)
{
    _led_reset();
    HAL_GPIO_TogglePin(GPIOD,LED1_Pin);
    HAL_Delay(delayTime);

    _led_reset();
    HAL_GPIO_TogglePin(GPIOD,LED2_Pin);
    HAL_Delay(delayTime);

    _led_reset();
    HAL_GPIO_TogglePin(GPIOD,LED3_Pin);
    HAL_Delay(delayTime);

    _led_reset();
    HAL_GPIO_TogglePin(GPIOD,LED4_Pin);
    HAL_Delay(delayTime);   
}