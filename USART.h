/****************************************************************************
* ATMega16(L) Microcontroller USART Driver   				           		*
* Author 	  Eslam Yasser AbdelHameed                                 		*
* Date        December 12, 2019                                       		*
* File name	  USART.h														*
* Purpose:    Provide an easy way to Interface with 						*
* 			  USART at ATmega16 Microcontroller 							*
*****************************************************************************/

#ifndef USART_H
#define USART_H


#include <avr/io.h>
#include "Config.h"

unsigned char NINE_BITS ;

typedef enum
{
	Normal_Speed,
	Double_Speed
}Speed;

typedef enum
{
	Asynchronous,
	Synchronous
}Mode;

typedef enum
{
	Disabled=0x00,
	Even_Parity=0x02,
	Odd_Parity=0x03
}Parity_Mode;

typedef enum
{
	bit_1,
	bit_2

}Stop_Bits;

typedef enum
{
	Five_bits	=0x00,
	Six_bits	=0x01,
	Seven_bits	=0x02,
	Eight_bits	=0x03,
	Nine_bits	=0x07
}Data_Size;

void USART_Init(Data_Size,Stop_Bits,Parity_Mode,Mode,Speed,uint16);
void USART_Transmit(uint16);
uint16 USART_Receive();

void USART_SendString(uint8 *);
void USART_RecieveString(uint8 *);

#endif
