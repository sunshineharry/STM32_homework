/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: get_DH_matrix.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 12-May-2021 12:50:57
 */

/* Include Files */
#include "get_DH_matrix.h"
#include "cosd.h"
#include "get_DH_matrix_data.h"
#include "get_DH_matrix_initialize.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include <math.h>

/* Function Definitions */

/*
 * 根据参数生成DH矩阵
 * Arguments    : double alpha
 *                double a
 *                double d
 *                double theta
 *                double DH_matrix[16]
 * Return Type  : void
 */
void get_DH_matrix(double alpha, double a, double d, double theta, double
                   DH_matrix[16])
{
  double DH_matrix_tmp;
  double b_DH_matrix_tmp;
  double c_DH_matrix_tmp;
  double d_DH_matrix_tmp;
  double e_DH_matrix_tmp;
  double f_DH_matrix_tmp;
  if (!isInitialized_get_DH_matrix) {
    get_DH_matrix_initialize();
  }

  DH_matrix_tmp = theta;
  b_sind(&DH_matrix_tmp);
  b_DH_matrix_tmp = theta;
  b_cosd(&b_DH_matrix_tmp);
  c_DH_matrix_tmp = alpha;
  b_cosd(&c_DH_matrix_tmp);
  d_DH_matrix_tmp = sin(alpha);
  e_DH_matrix_tmp = alpha;
  b_sind(&e_DH_matrix_tmp);
  f_DH_matrix_tmp = cos(alpha);
  DH_matrix[0] = b_DH_matrix_tmp;
  DH_matrix[4] = -DH_matrix_tmp;
  DH_matrix[8] = 0.0;
  DH_matrix[12] = a;
  DH_matrix[1] = DH_matrix_tmp * c_DH_matrix_tmp;
  DH_matrix[5] = b_DH_matrix_tmp * c_DH_matrix_tmp;
  DH_matrix[9] = -d_DH_matrix_tmp;
  DH_matrix[13] = -d_DH_matrix_tmp * d;
  DH_matrix[2] = DH_matrix_tmp * e_DH_matrix_tmp;
  DH_matrix[6] = b_DH_matrix_tmp * e_DH_matrix_tmp;
  DH_matrix[10] = f_DH_matrix_tmp;
  DH_matrix[14] = f_DH_matrix_tmp * d;
  DH_matrix[3] = 0.0;
  DH_matrix[7] = 0.0;
  DH_matrix[11] = 0.0;
  DH_matrix[15] = 1.0;
}

/*
 * File trailer for get_DH_matrix.c
 *
 * [EOF]
 */
