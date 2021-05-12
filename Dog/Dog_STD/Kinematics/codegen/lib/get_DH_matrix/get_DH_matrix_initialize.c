/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: get_DH_matrix_initialize.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 12-May-2021 12:50:57
 */

/* Include Files */
#include "get_DH_matrix_initialize.h"
#include "get_DH_matrix.h"
#include "get_DH_matrix_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void get_DH_matrix_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_get_DH_matrix = true;
}

/*
 * File trailer for get_DH_matrix_initialize.c
 *
 * [EOF]
 */
