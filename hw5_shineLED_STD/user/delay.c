#include "delay.h"

#define MAX_DELAY_VAL 0x4FFFF
#define MAX_DEALY_NUM 3

uint32_t m_nDelayNum = 0;
uint32_t m_nDelayCounter = 0;

void delay(void)
{
    m_nDelayCounter++;
    if (m_nDelayCounter < MAX_DELAY_VAL)
        m_nDelayCounter++;
    else
    {
        m_nDelayCounter = 0;
        m_nDelayNum++;
        if(m_nDelayNum > MAX_DEALY_NUM)
            m_nDelayNum = 0;
    }
}
