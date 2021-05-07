#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#define LOG (1)



void UART3_Init(uint32_t bound);
void UART4_Init(uint32_t bound);
int fputc(int ch, FILE *f);

#if LOG
    // 打印INFO级别日志（使用串口3）
    #define LOG_INFO(format, ...)  printf("[" __FILE__ "]\t INFO:"  format "\r\n", ##__VA_ARGS__)

    // 打印DEBUG级别日志（使用串口3）
    #define LOG_DEBUG(format, ...) printf("[" __FILE__ "]\t DEBUG:" format "\r\n", ##__VA_ARGS__)

    // 打印ERROR级别日志（使用串口3）
    #define LOG_ERROR(format, ...) printf("[" __FILE__ "]\t ERROR:" format "\r\n", ##__VA_ARGS__)
#else
    // 已关闭日志打印功能
    #define LOG_INFO(format, ...)

    // 已关闭日志打印功能
    #define LOG_DEBUG(format, ...)
    
    // 已关闭日志打印功能
    #define LOG_ERROR(format, ...)
#endif


#endif


