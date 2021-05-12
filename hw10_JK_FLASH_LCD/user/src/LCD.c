#include "LCD.h"

unsigned char cpFontArray[] = // ASCII
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -O-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x01, 0x83, 0x00, 0x07, 0x00,
        0xC0, 0x06, 0x00, 0xC0, 0x0C, 0x00, 0x60, 0x1C, 0x00, 0x70, 0x18, 0x00, 0x30, 0x38, 0x00, 0x38,
        0x38, 0x00, 0x38, 0x30, 0x00, 0x18, 0x70, 0x00, 0x18, 0x70, 0x00, 0x1C, 0x70, 0x00, 0x1C, 0x70,
        0x00, 0x1C, 0x70, 0x00, 0x1C, 0x70, 0x00, 0x1C, 0x70, 0x00, 0x1C, 0x70, 0x00, 0x1C, 0x70, 0x00,
        0x1C, 0x70, 0x00, 0x1C, 0x70, 0x00, 0x1C, 0x30, 0x00, 0x18, 0x30, 0x00, 0x18, 0x38, 0x00, 0x38,
        0x38, 0x00, 0x38, 0x18, 0x00, 0x30, 0x1C, 0x00, 0x30, 0x0C, 0x00, 0x60, 0x06, 0x00, 0xC0, 0x03,
        0x01, 0x80, 0x01, 0x83, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -1-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x18, 0x00, 0x00, 0x38,
        0x00, 0x07, 0xF8, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00,
        0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
        0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38,
        0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00,
        0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
        0x38, 0x00, 0x00, 0x7C, 0x00, 0x07, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -2-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x03, 0x07, 0x00, 0x0C, 0x03,
        0x80, 0x18, 0x01, 0xC0, 0x18, 0x01, 0xC0, 0x38, 0x00, 0xE0, 0x38, 0x00, 0xE0, 0x38, 0x00, 0xE0,
        0x3C, 0x00, 0xE0, 0x3C, 0x00, 0xE0, 0x1C, 0x00, 0xE0, 0x00, 0x01, 0xC0, 0x00, 0x01, 0xC0, 0x00,
        0x03, 0x80, 0x00, 0x03, 0x80, 0x00, 0x07, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x38,
        0x00, 0x00, 0x70, 0x00, 0x00, 0xE0, 0x00, 0x01, 0xC0, 0x00, 0x03, 0x80, 0x00, 0x03, 0x00, 0x00,
        0x06, 0x00, 0x20, 0x0C, 0x00, 0x20, 0x18, 0x00, 0x60, 0x30, 0x00, 0x60, 0x20, 0x00, 0xC0, 0x7F,
        0xFF, 0xC0, 0x7F, 0xFF, 0xC0, 0x7F, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -3-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x03, 0x07, 0x00, 0x06, 0x03,
        0x80, 0x0C, 0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1C, 0x00, 0xE0, 0x1E, 0x00, 0xE0, 0x1E, 0x00, 0xE0,
        0x0E, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xC0, 0x00, 0x01, 0xC0, 0x00, 0x01, 0x80, 0x00,
        0x03, 0x00, 0x00, 0x0E, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00,
        0xC0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x60, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x18, 0x00, 0x70,
        0x3C, 0x00, 0x70, 0x3C, 0x00, 0x70, 0x3C, 0x00, 0x60, 0x38, 0x00, 0xE0, 0x18, 0x00, 0xC0, 0x0C,
        0x01, 0x80, 0x06, 0x07, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -4-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07,
        0x00, 0x00, 0x0F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x17, 0x00, 0x00, 0x37, 0x00, 0x00, 0x27, 0x00,
        0x00, 0x67, 0x00, 0x00, 0xC7, 0x00, 0x00, 0x87, 0x00, 0x01, 0x87, 0x00, 0x03, 0x07, 0x00, 0x02,
        0x07, 0x00, 0x06, 0x07, 0x00, 0x04, 0x07, 0x00, 0x08, 0x07, 0x00, 0x18, 0x07, 0x00, 0x10, 0x07,
        0x00, 0x30, 0x07, 0x00, 0x60, 0x07, 0x00, 0x7F, 0xFF, 0xF8, 0x7F, 0xFF, 0xF8, 0x00, 0x07, 0x00,
        0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00,
        0x07, 0x00, 0x00, 0x07, 0x80, 0x00, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -5-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xE0, 0x0F, 0xFF, 0xE0, 0x0F, 0xFF,
        0xE0, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00,
        0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0xFE, 0x00, 0x13, 0xFF, 0x00, 0x17,
        0x03, 0x80, 0x1C, 0x01, 0xC0, 0x1C, 0x00, 0xE0, 0x18, 0x00, 0xE0, 0x00, 0x00, 0xF0, 0x00, 0x00,
        0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x18, 0x00, 0x70, 0x3C, 0x00, 0x70,
        0x3C, 0x00, 0x70, 0x3C, 0x00, 0x60, 0x38, 0x00, 0xE0, 0x18, 0x00, 0xE0, 0x18, 0x01, 0xC0, 0x0C,
        0x01, 0x80, 0x07, 0x07, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -6-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x01, 0x83, 0x80, 0x03, 0x03,
        0x80, 0x06, 0x03, 0xC0, 0x0C, 0x03, 0xC0, 0x18, 0x03, 0xC0, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00,
        0x38, 0x00, 0x00, 0x30, 0x00, 0x00, 0x30, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x7E, 0x00, 0x71,
        0xFF, 0x80, 0x77, 0x83, 0xC0, 0x76, 0x01, 0xC0, 0x7C, 0x00, 0xE0, 0x78, 0x00, 0xE0, 0x70, 0x00,
        0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x30, 0x00, 0x70,
        0x38, 0x00, 0x70, 0x38, 0x00, 0x70, 0x18, 0x00, 0x60, 0x1C, 0x00, 0xE0, 0x0C, 0x00, 0xC0, 0x06,
        0x01, 0x80, 0x03, 0x83, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -7-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xF0, 0x1F, 0xFF, 0xF0, 0x1F, 0xFF,
        0xE0, 0x1C, 0x00, 0x60, 0x10, 0x00, 0xC0, 0x30, 0x00, 0x80, 0x20, 0x01, 0x80, 0x20, 0x01, 0x00,
        0x00, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0C, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x30, 0x00, 0x00, 0x30, 0x00, 0x00, 0x70,
        0x00, 0x00, 0x60, 0x00, 0x00, 0x60, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00,
        0x00, 0xE0, 0x00, 0x01, 0xE0, 0x00, 0x01, 0xE0, 0x00, 0x01, 0xE0, 0x00, 0x01, 0xE0, 0x00, 0x01,
        0xE0, 0x00, 0x01, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -8-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFE, 0x00, 0x07, 0x03, 0x80, 0x0E, 0x01,
        0xC0, 0x1C, 0x00, 0xE0, 0x18, 0x00, 0xE0, 0x38, 0x00, 0x70, 0x38, 0x00, 0x70, 0x38, 0x00, 0x70,
        0x38, 0x00, 0x70, 0x3C, 0x00, 0x70, 0x1E, 0x00, 0xE0, 0x1F, 0x00, 0xE0, 0x0F, 0x81, 0xC0, 0x07,
        0xE3, 0x80, 0x03, 0xFE, 0x00, 0x03, 0xFE, 0x00, 0x06, 0x3F, 0x00, 0x0C, 0x0F, 0x80, 0x1C, 0x07,
        0xC0, 0x38, 0x01, 0xE0, 0x38, 0x01, 0xE0, 0x70, 0x00, 0xF0, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70,
        0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x38, 0x00, 0xE0, 0x18, 0x00, 0xC0, 0x0C,
        0x01, 0xC0, 0x07, 0x03, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -9-
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x07, 0x06, 0x00, 0x0C, 0x01,
        0x00, 0x1C, 0x01, 0x80, 0x38, 0x00, 0xC0, 0x38, 0x00, 0xC0, 0x30, 0x00, 0x60, 0x70, 0x00, 0x60,
        0x70, 0x00, 0x60, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70,
        0x00, 0xF0, 0x38, 0x00, 0xF0, 0x38, 0x01, 0xF0, 0x3C, 0x03, 0x70, 0x1F, 0x0E, 0x70, 0x0F, 0xFC,
        0x70, 0x03, 0xF0, 0x70, 0x00, 0x00, 0x60, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0,
        0x00, 0x00, 0xC0, 0x00, 0x01, 0xC0, 0x0C, 0x01, 0x80, 0x1E, 0x03, 0x80, 0x1E, 0x03, 0x00, 0x1E,
        0x06, 0x00, 0x0E, 0x1C, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

};

//------------------------------------------------------
// PC8,CS; PD13,RS; PD15,RD; PB14,WR; PE,DATA;
//------------------------------------------------------
void LCDPin_Init(void)
{
}

//------------------------------------------------------
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue)
{
}

//------------------------------------------------------
void Delay(__IO uint32_t nCount)
{
    uint32_t n;
    n = 12000 * nCount;
    for (; n != 0; n--)
        ;
}

//------------------------------------------------------

void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos)
{
    LCD_WriteReg(0x0020, Xpos);       // ��
    LCD_WriteReg(0x0021, 319 - Ypos); // ��
}
//------------------------------------------------------
void LCD_WriteRAM_Prepare(void)
{
    /* Write 16-bit Index, then Write Reg */
    ClearLCDCs;
    LCD_WriteData = 0x22;
    ClearLCDRs;
    ClearLCDWr;
    SetLCDWr;
    SetLCDRs;
}
void LCD_ClearColor(uint16_t Color)
{
    uint32_t index = 0;
    LCD_SetCursor(0, 0);
    LCD_WriteRAM_Prepare();
    ClearLCDCs;
    SetLCDRs;
    LCD_WriteData = Color;
    for (index = 0; index < (320 * 240); index++)
    {
        ClearLCDWr;
        //LCD_WriteData = Color;
        SetLCDWr;
    }
    SetLCDCs;
}
//------------------------------------------------------
void STM32_LCDInit(void)
{
    LCDPin_Init(); //Initialize pin of lcd
    Delay(1);
    LCD_WriteReg(0x0000, 0x0001);
    Delay(1);
    //
    LCD_WriteReg(0x0000, 0x0001); //start internal osc
    LCD_WriteReg(0x0001, 0x0100);
    LCD_WriteReg(0x0002, 0x0700);                                     //Driving Wave Control
    LCD_WriteReg(0x0003, (1 << 12) | (0 << 5) | (1 << 4) | (1 << 3)); //65K
    LCD_WriteReg(0x0004, 0x0000);
    LCD_WriteReg(0x0007, 0x0133);
    LCD_WriteReg(0x0008, 0x0207);
    LCD_WriteReg(0x0009, 0x0000);
    LCD_WriteReg(0x000a, 0x0000); //display setting
    LCD_WriteReg(0x000c, 0x0001); //display setting
    LCD_WriteReg(0x000d, 0x0000); //0f3c
    LCD_WriteReg(0x000f, 0x0000);
    //
    //Power On sequence //
    LCD_WriteReg(0x0010, 0x0000);
    LCD_WriteReg(0x0011, 0x0007);
    LCD_WriteReg(0x0012, 0x0000);
    LCD_WriteReg(0x0013, 0x0000);
    Delay(5);
    Delay(5);
    LCD_WriteReg(0x0010, 0x1590);
    LCD_WriteReg(0x0011, 0x0227);
    Delay(5);
    Delay(5);
    LCD_WriteReg(0x0012, 0x009c);
    Delay(5);
    Delay(5);
    LCD_WriteReg(0x0013, 0x1900);
    LCD_WriteReg(0x0029, 0x0023);
    LCD_WriteReg(0x002b, 0x000e);
    Delay(5);
    Delay(5);
    LCD_WriteReg(0x0020, 0x0000);
    LCD_WriteReg(0x0021, 0x0000);
    Delay(5);
    Delay(5);
    LCD_WriteReg(0x0030, 0x0007);
    LCD_WriteReg(0x0031, 0x0707);
    LCD_WriteReg(0x0032, 0x0006);
    LCD_WriteReg(0x0035, 0x0704);
    LCD_WriteReg(0x0036, 0x1f04);
    LCD_WriteReg(0x0037, 0x0004);
    LCD_WriteReg(0x0038, 0x0000);
    LCD_WriteReg(0x0039, 0x0706);
    LCD_WriteReg(0x003c, 0x0701);
    LCD_WriteReg(0x003d, 0x000f);
    Delay(5);
    Delay(5);
    LCD_WriteReg(0x0050, 0x0000);
    LCD_WriteReg(0x0051, 0x00ef);
    LCD_WriteReg(0x0052, 0x0000);
    LCD_WriteReg(0x0053, 0x013f);
    LCD_WriteReg(0x0060, 0xa700);
    LCD_WriteReg(0x0061, 0x0001);
    LCD_WriteReg(0x006a, 0x0000);
    LCD_WriteReg(0x0080, 0x0000);
    LCD_WriteReg(0x0081, 0x0000);
    LCD_WriteReg(0x0082, 0x0000);
    LCD_WriteReg(0x0083, 0x0000);
    LCD_WriteReg(0x0084, 0x0000);
    LCD_WriteReg(0x0085, 0x0000);

    LCD_WriteReg(0x0090, 0x0010);
    LCD_WriteReg(0x0092, 0x0600);
    LCD_WriteReg(0x0093, 0x0003);
    LCD_WriteReg(0x0095, 0x0110);
    LCD_WriteReg(0x0097, 0x0000);
    LCD_WriteReg(0x0098, 0x0000);
    //display on sequence

    /*
        LCD_WriteReg(0x0020,0x0000);                                                            
        LCD_WriteReg(0x0021,0x0000);
	LCD_WriteReg(0x00e3,0x3008);
        LCD_WriteReg(0x00e7,0x0012);
        LCD_WriteReg(0x00ef,0x1231);        //Set the internal vcore voltage
        // LCD_WriteReg(0x00e7,0x0010);  
				*/
}

//--------------------------------------------------------
// num 0-9
void LCD_DrawNum(uint16_t Xpos, uint16_t Ypos, uint8_t num)
{
    uint32_t index = 0, i = 0, j = 0, k = 0, y;
    uint8_t Xaddress = 0;

    /**************** Armjishu.com Add { *************************************/
    uint32_t Width = 24;
    uint32_t Height = 48;
    //	uint32_t  BytesPreChar = 144;
    /**************** Armjishu.com Add } *************************************/
    if (num < 10)
        index = num * 144;
    else
        index = 0;
    //
    Xaddress = Xpos;

    LCD_SetCursor(Xaddress, Ypos);

    for (y = 0; y < Height; y++)
    {
        LCD_WriteRAM_Prepare();
        for (i = Width; i > 0;)
        {
            if (i >= 8)
            {
                k = 8;
            }
            else
            {
                k = i;
            }

            for (j = 0; j < k; j++)
            {
                if ((cpFontArray[index] & (0x80 >> j)) == 0x00)
                {
                    LCD_WriteData = 0xFFFF;
                    ClearLCDWr;
                    SetLCDWr;
                }
                else
                {
                    LCD_WriteData = 0x0000;
                    ClearLCDWr;
                    SetLCDWr;
                }
                i--;
                //Delay(2);//�˴����ӳٿ�������Ŀ�������ַ���һ�����ĵ���ƹ���
            }
            index++;
        }
        SetLCDCs;
        Xaddress++;
        LCD_SetCursor(Xaddress, Ypos);
    }
}