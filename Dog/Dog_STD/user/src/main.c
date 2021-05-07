#include "stm32f10x_conf.h"
#include "pwm.h"
#include "beep.h"
#include "usart.h"


static void Init(void)
{
    #if LOG
    UART3_Init(115200);
    LOG_DEBUG("System satrt up!");
    #endif
    BEEP_Init();
    PWM_Init();
    LOG_DEBUG("System init finished!");
}

int main(void)
{
    Init();
    PWM_Output(RF_LEG1,90);
    PWM_Output(RF_LEG2,90);
    PWM_Output(RB_LEG1,90);
    PWM_Output(RB_LEG2,90);
    PWM_Output(LF_LEG1,90);
    PWM_Output(LF_LEG2,90);
    PWM_Output(LB_LEG1,90);
    PWM_Output(LB_LEG2,90);

    while (1)
    {
    }
}
