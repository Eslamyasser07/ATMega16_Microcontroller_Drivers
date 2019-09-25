/****************************************************************************
* ATMega16(L) Microcontroller LCD  Driver   				           		*
* Author 	  Eslam Yasser AbdelHameed                                 		*
* Date        September 25, 2019                                       		*
* File name	  LCD.h															*
* Purpose:    Provide an easy way to Interface with 						*
* 			  LCD based on HD44780  (Hitachi)								*
*****************************************************************************/


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include "Config.h"



/* ---------------- Define Ports we use -------------------*/

#define	RS	PD0
#define RW	PD1
#define E	PD2

#define CTRL_PORT 		PORTD
#define CTRL_PORT_DIR 	DDRD

#define DATA_PORT 		PORTC
#define DATA_PORT_DIR 	DDRC


/* ---------------- Define Instructions  -------------------*/

#define _8bit_1line		0x30
#define _8bit_2line		0x38
#define _4bit_1line		0x20
#define _4bit_2line		0x28

#define ENTRY_MODE		0x06
#define CLEAR			0x01
#define CURSOR_ON		0x0E
#define CURSOR_OFF		0x0C
#define CURSOR_BLINK	0x0F
#define SHIFT_L			0x18
#define SHIFT_R			0x1C
#define CURSOR_L		0x10
#define CURSOR_R		0x14


/* ---------------- Function Prototype -------------------*/

void LCD_Init();
void LCD_Send_Command(uint8);
void LCD_Display_Character(uint8);
void LCD_Display_String(const uint8 *);
void LCD_ROW_COL(uint8,uint8);
void LCD_Clear_Screen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str);
void LCD_Int_String(uint8);

#endif
