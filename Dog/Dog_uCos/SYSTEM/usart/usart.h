#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#define LOG (1)



void UART3_Init(uint32_t bound);
void UART4_Init(uint32_t bound);
int fputc(int ch, FILE *f);

#if LOG
    // ��ӡINFO������־��ʹ�ô���3��
    #define LOG_INFO(format, ...)  printf("[" __FILE__ "]\t INFO:"  format "\r\n", ##__VA_ARGS__)

    // ��ӡDEBUG������־��ʹ�ô���3��
    #define LOG_DEBUG(format, ...) printf("[" __FILE__ "]\t DEBUG:" format "\r\n", ##__VA_ARGS__)

    // ��ӡERROR������־��ʹ�ô���3��
    #define LOG_ERROR(format, ...) printf("[" __FILE__ "]\t ERROR:" format "\r\n", ##__VA_ARGS__)
#else
    // �ѹر���־��ӡ����
    #define LOG_INFO(format, ...)

    // �ѹر���־��ӡ����
    #define LOG_DEBUG(format, ...)
    
    // �ѹر���־��ӡ����
    #define LOG_ERROR(format, ...)
#endif


#endif


