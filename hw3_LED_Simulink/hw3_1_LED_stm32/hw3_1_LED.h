/*
 * File: hw3_1_LED.h
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

#ifndef RTW_HEADER_hw3_1_LED_h_
#define RTW_HEADER_hw3_1_LED_h_
#include "STM32_Config.h"
#include "hw3_1_LED_External_Functions.h"
#ifndef hw3_1_LED_COMMON_INCLUDES_
# define hw3_1_LED_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hw3_1_LED_COMMON_INCLUDES_ */

#include "hw3_1_LED_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
} B_hw3_1_LED;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_hw3_1_LED;

/* Real-time Model Data Structure */
struct tag_RTM_hw3_1_LED {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_hw3_1_LED hw3_1_LED_B;

/* Block states (default storage) */
extern DW_hw3_1_LED hw3_1_LED_DW;

/* Model entry point functions */
extern void hw3_1_LED_initialize(void);
extern void hw3_1_LED_step(void);

/* Real-time Model object */
extern RT_MODEL_hw3_1_LED *const hw3_1_LED_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hw3_1_LED'
 */
#endif                                 /* RTW_HEADER_hw3_1_LED_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] hw3_1_LED.h
 */
