#include "stm32f10x_conf.h"
#include "pwm.h"
#include "beep.h"
#include "usart.h"

// MALTAB includes
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "get_DH_matrix_types.h"
#include "get_DH_matrix.h"
#include "get_DH_matrix_terminate.h"
#include "rt_nonfinite.h"



static void Init(void)
{
    UART3_Init(115200);
    LOG_DEBUG("System satrt up!");
    BEEP_Init();
    PWM_Init();
    LOG_DEBUG("System init finished!");
    
}


// static void delay_us(uint16_t time)
// {    
//    u16 i=0;  
//    while(time--)
//    {
//       i=10;
//       while(i--);    
//    }
// }


int main(void)
{
    Init();
    double DH_matrix[16];
    get_DH_matrix(50, 50, 50, 50, DH_matrix);
    LOG_DEBUG("DH_matrix[0]=%lf",DH_matrix[0]);
    LOG_DEBUG("DH_matrix[1]=%lf",DH_matrix[1]);
    LOG_DEBUG("DH_matrix[2]=%lf",DH_matrix[2]);
    LOG_DEBUG("DH_matrix[3]=%lf",DH_matrix[3]);
    LOG_DEBUG("DH_matrix[4]=%lf",DH_matrix[4]);
    LOG_DEBUG("DH_matrix[5]=%lf",DH_matrix[5]);
    LOG_DEBUG("DH_matrix[6]=%lf",DH_matrix[6]);
    LOG_DEBUG("DH_matrix[7]=%lf",DH_matrix[7]);
    LOG_DEBUG("DH_matrix[8]=%lf",DH_matrix[8]);
    LOG_DEBUG("DH_matrix[9]=%lf",DH_matrix[9]);
    LOG_DEBUG("DH_matrix[10]=%lf",DH_matrix[10]);
    LOG_DEBUG("DH_matrix[11]=%lf",DH_matrix[11]);
    LOG_DEBUG("DH_matrix[12]=%lf",DH_matrix[12]);
    LOG_DEBUG("DH_matrix[13]=%lf",DH_matrix[13]);
    LOG_DEBUG("DH_matrix[14]=%lf",DH_matrix[14]);
    LOG_DEBUG("DH_matrix[15]=%lf",DH_matrix[15]);
    while (1)
    {
        PWM_Output(YH_LEG1,90);
        PWM_Output(YH_LEG2,90);
        PWM_Output(ZH_LEG1,90);
        PWM_Output(ZH_LEG2,90);
        PWM_Output(YQ_LEG1,90);
        PWM_Output(YQ_LEG2,90);
        PWM_Output(ZQ_LEG1,90);
        PWM_Output(ZQ_LEG2,90);
    }
}
