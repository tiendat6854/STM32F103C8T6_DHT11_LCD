#include "stm32f10x.h"                  // Device header
#include "timer2.h"
#include "lcd.h"
#include "dht11.h"
#include <stdio.h>

int main()
{
  char Display[17];
	uint8_t u8Buff[4];
	
	timer2_Init();
	
	DHT11_Init();
	LCD_Init();
	
	LCD_GotoXY(0, 0);
	LCD_Puts(" Hello DAT ");
	delay_ms(1000);
	LCD_Clear();
	
	while(1)
	{	
		 /* gui do am */
		
		if (DHT11_Read(u8Buff)) 
		{
			sprintf(Display, "Do am: %d ", u8Buff[0]);
			
			LCD_GotoXY(0, 0);
			LCD_Puts(Display);
			LCD_GotoXY(9, 0);
	    LCD_Puts("%");
			/* gui nhiet do */
	
			sprintf(Display, "Nhiet do: %d ", u8Buff[2]); 
			
			LCD_GotoXY(0, 1);
			LCD_Puts(Display);
			LCD_GotoXY(12, 1);
	    LCD_Puts("oC");
		} 
		else 
		{
			LCD_GotoXY(0, 0);
			LCD_Puts("STM32 - LCD1602");
			LCD_GotoXY(0, 1);
			LCD_Puts("DHT11: ERROR");
		}
	}
}
