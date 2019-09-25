/****************************************************************************
* ATMega16(L) Microcontroller LCD  Driver   				           		*
* Author 	  Eslam Yasser AbdelHameed                                 		*
* Date        September 25, 2019                                       		*
* File name	  LCD.c															*
* Purpose:    Provide an easy way to Interface with 						*
* 			  LCD based on HD44780  (Hitachi)								*
*****************************************************************************/


#include "LCD.h"


void LCD_Init()
{
	DATA_PORT_DIR = 0xFF;
	CTRL_PORT_DIR|= 0x07;

	LCD_Send_Command(_8bit_2line);
	LCD_Send_Command(CURSOR_OFF);		// Display On and Cursor off
}


void LCD_Send_Command(uint8 address)
{
	 CLEAR_BIT(CTRL_PORT,RS);
	 CLEAR_BIT(CTRL_PORT,RW);
	 _delay_ms(1);
	 SET_BIT(CTRL_PORT,E);
	 _delay_ms(1);
	 DATA_PORT=address;
	 _delay_ms(1);
	 CLEAR_BIT(CTRL_PORT,E);
	 _delay_ms(1);

}


void LCD_Display_Character(uint8 data)
{
	 SET_BIT(CTRL_PORT,RS);
	 CLEAR_BIT(CTRL_PORT,RW);
	 _delay_ms(1);
	 SET_BIT(CTRL_PORT,E);
	 _delay_ms(1);
	 DATA_PORT=data;
	 _delay_ms(1);
	 CLEAR_BIT(CTRL_PORT,E);
	 _delay_ms(1);
}


void LCD_Display_String(const uint8 *ptr)
{
	uint8 i=0;
	while(ptr[i] != '\0')
	{
		LCD_Display_Character(ptr[i]);
		ptr++;
	}
}


void LCD_ROW_COL(uint8 row,uint8 col)
{
	uint8 address = 0;

	if(row == 0)
		address = col;

	else if(row == 1)
		address = col + 0x40;

	else if(row == 2)
			address = col + 0x10;

	else if(row == 3)
			address = col + 0x50;


	LCD_Send_Command(0x80|address);

}


void LCD_Clear_Screen()
{
	LCD_Send_Command(CLEAR);
}


void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str)
{
	LCD_ROW_COL(row,col);
	LCD_Display_String(str);
}


void LCD_Int_String(uint8 data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD_Display_String(buff);
}
