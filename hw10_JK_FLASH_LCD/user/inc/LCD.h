
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_H
#define __LCD_H

#include "stm32f10x_conf.h"
//PC8,CS; PD13,RS; PD15,RD; PB14,WR; PE,DATA; 
#define SetLCDCs    (GPIOC->BSRR |= GPIO_Pin_8)
#define ClearLCDCs  (GPIOC->BRR |= GPIO_Pin_8)
#define SetLCDRs    (GPIOC->BSRR |= GPIO_Pin_13)
#define ClearLCDRs  (GPIOC->BRR |= GPIO_Pin_13)
#define SetLCDRd    (GPIOC->BSRR |= GPIO_Pin_15)
#define ClearLCDRd  (GPIOC->BRR |= GPIO_Pin_15)
#define SetLCDWr    (GPIOC->BSRR |= GPIO_Pin_14)
#define ClearLCDWr  (GPIOC->BRR |= GPIO_Pin_14)

#define LCD_PORT_DAT    GPIOE
#define LCD_WriteData   LCD_PORT_DAT->ODR
#define LCD_ReadData    LCD_PORT_DAT->IDR

#define LCD_COLOR_WHITE          0xFFFF
#define LCD_COLOR_BLACK          0x0000
#define LCD_COLOR_GREY           0xE79C
#define LCD_COLOR_BLUE           0x001F
#define LCD_COLOR_BLUE2          0x051F
#define LCD_COLOR_RED            0xF800
#define LCD_COLOR_MAGENTA        0xF81F
#define LCD_COLOR_GREEN          0x07E0
#define LCD_COLOR_CYAN           0x7FFF
#define LCD_COLOR_YELLOW         0xFFE0
//--------------------------------------------------------------


void LCDPin_Init(void); 

void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);

void Delay(__IO uint32_t nCount);
void LCD_ClearColor(uint16_t Color);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_WriteRAM_Prepare(void);
void STM32_LCDInit(void);

void LCD_DrawNum(uint16_t Xpos, uint16_t Ypos, uint8_t num);
#endif /* __LCD_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
