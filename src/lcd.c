#include "lcd.h"
#include "timer2.h"
#include <ctype.h>

static GPIO_InitTypeDef gpioInit = {0};

static void GPIO_Pin_To_Output(GPIO_TypeDef *gpioPort, uint32_t gpioPin)
{
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioInit.GPIO_Pin = gpioPin;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(gpioPort, &gpioInit);
}

void LCD_Enable(void) {
    GPIO_WriteBit(LCD_EN_PORT, LCD_EN, Bit_SET);
	  delay_us(3);
	  GPIO_WriteBit(LCD_EN_PORT, LCD_EN, Bit_RESET);
	  delay_us(50);
}

// ham gui 4 bit du lieu ra LCD
void LCD_Send4bit(uint8_t Data) {
	
    GPIO_WriteBit(LCD_D4_PORT, LCD_D4, (Data & 0x01) ? Bit_SET : Bit_RESET);
	  GPIO_WriteBit(LCD_D5_PORT, LCD_D5, ((Data >> 1) & 0x01) ? Bit_SET : Bit_RESET);
	  GPIO_WriteBit(LCD_D6_PORT, LCD_D6, ((Data >> 2) & 0x01) ? Bit_SET : Bit_RESET);
	  GPIO_WriteBit(LCD_D7_PORT, LCD_D7, ((Data >> 3) & 0x01) ? Bit_SET : Bit_RESET);
}

// ham gui 1 lenh cho LCD
void LCD_SendCommand(uint8_t command) {
	
    LCD_Send4bit(command >> 4); // gui 4 bit cao
	  LCD_Enable();
	  LCD_Send4bit(command); // gui 4 bit thap
	  LCD_Enable();
}

void LCD_Clear(void){  // ham xoa man hinh LCD
	
    LCD_SendCommand(0x01);
	  delay_ms(1);
}

// ham khoi tao LCD
void LCD_Init(void){
	
		LCD_RCC_RS_EN;
	  LCD_RCC_RW_EN;
	  LCD_RCC_EN_EN;
	  LCD_RCC_D4_EN;
	  LCD_RCC_D5_EN;
	  LCD_RCC_D6_EN;
	  LCD_RCC_D7_EN;
	
	  GPIO_WriteBit(LCD_RS_PORT, LCD_RS, Bit_RESET);
  	GPIO_WriteBit(LCD_RW_PORT, LCD_RW, Bit_RESET);
	  GPIO_WriteBit(LCD_EN_PORT, LCD_EN, Bit_RESET);
	  GPIO_WriteBit(LCD_D4_PORT, LCD_D4, Bit_RESET);
	  GPIO_WriteBit(LCD_D5_PORT, LCD_D5, Bit_RESET);
	  GPIO_WriteBit(LCD_D6_PORT, LCD_D6, Bit_RESET);
	  GPIO_WriteBit(LCD_D7_PORT, LCD_D7, Bit_RESET);
	
	  GPIO_Pin_To_Output(LCD_RS_PORT, LCD_RS);
	  GPIO_Pin_To_Output(LCD_RW_PORT, LCD_RW);
	  GPIO_Pin_To_Output(LCD_EN_PORT, LCD_EN);
	  GPIO_Pin_To_Output(LCD_D4_PORT, LCD_D4);
	  GPIO_Pin_To_Output(LCD_D5_PORT, LCD_D5);
	  GPIO_Pin_To_Output(LCD_D6_PORT, LCD_D6);
	  GPIO_Pin_To_Output(LCD_D7_PORT, LCD_D7);
	
    LCD_Send4bit(0x00);    // turn on LCD
	  delay_ms(20);
	  GPIO_WriteBit(LCD_RS_PORT, LCD_RS, Bit_RESET);
	  GPIO_WriteBit(LCD_RW_PORT, LCD_RW, Bit_RESET);
	  LCD_Send4bit(0x03);   // function setting
	  LCD_Enable();
	  delay_ms(5);
	  LCD_Enable();
	  delay_us(100);
	  LCD_Enable();
	  LCD_Send4bit(0x02);   // di chuyen con tro ve dau man hinh
	  LCD_Enable();
	  LCD_SendCommand(0x28);   // lua chon che do 4 bit
    LCD_SendCommand(0x0c);   // bat hien thi va tat con tro di
	  LCD_SendCommand(0x06);
	  LCD_SendCommand(0x01);
		
		delay_ms(10);
}

void LCD_GotoXY(uint8_t x, uint8_t y)
{
    uint8_t address;
	  if(!y) address= (0x80+x);
	  else address= (0xc0+x);
	  delay_us(1000);
	  LCD_SendCommand(address);
	  delay_us(50);
}

void LCD_PutC(uint8_t u8Data){
	
    GPIO_WriteBit(LCD_RS_PORT, LCD_RS, Bit_SET);
	  LCD_SendCommand(u8Data);
	  GPIO_WriteBit(LCD_RS_PORT, LCD_RS, Bit_RESET);
}

void LCD_Puts(char *s)
{
      while (*s)
			{
	       LCD_PutC(*s);
			   s++;
	    }
			
			  delay_ms(1000);
}
