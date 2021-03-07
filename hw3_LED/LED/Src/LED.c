/*
 * File: LED.c
 *
 * Code generated for Simulink model :LED.
 *
 * Model version      : 1.3
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Sat Mar  6 23:01:06 2021
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STM32CortexM
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#include "LED.h"
#include "LED_private.h"

/* Block signals (default storage) */
B_LED LED_B;

/* Block states (default storage) */
DW_LED LED_DW;

/* Real-time model */
RT_MODEL_LED LED_M_;
RT_MODEL_LED *const LED_M = &LED_M_;

/* Model step function */
void LED_step(void)
{
  LED_B.LED_control = ((LED_DW.clockTickCounter < 1) && (LED_DW.clockTickCounter
    >= 0));
  if (LED_DW.clockTickCounter >= 1) {
    LED_DW.clockTickCounter = 0;
  } else {
    LED_DW.clockTickCounter++;
  }

  {
    if (LED_B.LED_control == 0)
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
    else
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
  }
}

/* Model initialize function */
void LED_initialize(void)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED.c
 */
