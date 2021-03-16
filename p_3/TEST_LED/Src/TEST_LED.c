/*
 * File: TEST_LED.c
 *
 * Code generated for Simulink model :TEST_LED.
 *
 * Model version      : 1.3
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Fri Mar 12 19:27:21 2021
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

#include "TEST_LED.h"
#include "TEST_LED_private.h"

/* Block states (default storage) */
DW_TEST_LED TEST_LED_DW;

/* Real-time model */
RT_MODEL_TEST_LED TEST_LED_M_;
RT_MODEL_TEST_LED *const TEST_LED_M = &TEST_LED_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
real_T LED_control;                    /* '<Root>/Pulse Generator' */

/* Model step function */
void TEST_LED_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  LED_control = (real_T)((TEST_LED_DW.clockTickCounter < 1000) &&
    (TEST_LED_DW.clockTickCounter >= 0));
  if (TEST_LED_DW.clockTickCounter >= 1999) {
    TEST_LED_DW.clockTickCounter = 0;
  } else {
    TEST_LED_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */
  /* S-Function (GPIO_Write): '<Root>/GPIO_Write' */
  {
    if (LED_control == 0)
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    else
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
  }
}

/* Model initialize function */
void TEST_LED_initialize(void)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] TEST_LED.c
 */
