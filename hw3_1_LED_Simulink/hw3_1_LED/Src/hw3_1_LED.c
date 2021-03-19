/*
 * File: hw3_1_LED.c
 *
 * Code generated for Simulink model :hw3_1_LED.
 *
 * Model version      : 1.1
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Wed Mar 10 11:41:21 2021
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

#include "hw3_1_LED.h"
#include "hw3_1_LED_private.h"

/* Block signals (default storage) */
B_hw3_1_LED hw3_1_LED_B;

/* Block states (default storage) */
DW_hw3_1_LED hw3_1_LED_DW;

/* Real-time model */
RT_MODEL_hw3_1_LED hw3_1_LED_M_;
RT_MODEL_hw3_1_LED *const hw3_1_LED_M = &hw3_1_LED_M_;

/* Model step function */
void hw3_1_LED_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  hw3_1_LED_B.PulseGenerator = ((hw3_1_LED_DW.clockTickCounter < 1000) &&
    (hw3_1_LED_DW.clockTickCounter >= 0));
  if (hw3_1_LED_DW.clockTickCounter >= 1999) {
    hw3_1_LED_DW.clockTickCounter = 0;
  } else {
    hw3_1_LED_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */
  /* S-Function (GPIO_Write): '<Root>/GPIO_Write' */
  {
    if (hw3_1_LED_B.PulseGenerator == 0)
      HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
    else
      HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
  }
}

/* Model initialize function */
void hw3_1_LED_initialize(void)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] hw3_1_LED.c
 */
