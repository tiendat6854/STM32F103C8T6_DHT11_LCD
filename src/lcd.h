#ifndef LCD_H_
#define LCD_H_

#include "stm32f10x.h"

/* cau hinh GPIO */
/* LCD PIN */
#define LCD_RS GPIO_Pin_9
#define LCD_RW GPIO_Pin_10
#define LCD_EN GPIO_Pin_11
#define LCD_D4 GPIO_Pin_12
#define LCD_D5 GPIO_Pin_13
#define LCD_D6 GPIO_Pin_14
#define LCD_D7 GPIO_Pin_15

/* LCD RCC */
#define LCD_RCC_RS_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LCD_RCC_RW_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LCD_RCC_EN_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LCD_RCC_D4_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LCD_RCC_D5_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LCD_RCC_D6_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LCD_RCC_D7_EN RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)

/* PORT */
#define LCD_RS_PORT GPIOB
#define LCD_RW_PORT GPIOB
#define LCD_EN_PORT GPIOB
#define LCD_D4_PORT GPIOB
#define LCD_D5_PORT GPIOB
#define LCD_D6_PORT GPIOB
#define LCD_D7_PORT GPIOB

void LCD_Enable(void);
void LCD_Send4bit(uint8_t Data);
void LCD_SendCommand(uint8_t command);
void LCD_Clear(void);
void LCD_Init(void);
void LCD_GotoXY(uint8_t x, uint8_t y);
void LCD_PutC(uint8_t u8Data);
void LCD_Puts(char *s);

#endif
