/****************************************************************************
* ATMega16(L) Microcontroller USART Driver   				           		*
* Author 	  Eslam Yasser AbdelHameed                                 		*
* Date        December 12, 2019                                       		*
* File name	  USART.c														*
* Purpose:    Provide an easy way to Interface with 						*
* 			  USART at ATmega16 Microcontroller 							*
*****************************************************************************/

#include "USART.h"

static uint16 Calculate_BR(uint16 BR,Mode m,Speed s)
{
	if(m == Asynchronous)
	{
		if (s == Normal_Speed )
		{
			return ( (F_CPU/(16*BR))-1 );
		}
		else
		{
			return ( (F_CPU/(8*BR))-1 );
		}
	}
	else
	{
		return ( (F_CPU/(2*BR))-1 );
	}

}
void USART_Init(Data_Size D_S,Stop_Bits S_B,Parity_Mode P_M,Mode m,Speed s,uint16 BR)
{
//-------------- 1- Calculate Baud Rate ----------

	BR = Calculate_BR(BR,m,s);
	UBRRH = BR>>8;
	UBRRL = BR;

//-------------- 2-Mode & Stop Bits & Parity Bit & speed ----------

	UCSRC |= (1<<URSEL);
	UCSRC |= (m<<UMSEL) | (S_B<<USBS);

	if(P_M == Even_Parity )
	{
		UCSRC |= (Even_Parity<<UPM0) ;
	}
	else if(P_M == Odd_Parity)
	{
		UCSRC |= (Odd_Parity<<UPM0) ;
	}
	else
	{
		UCSRC &= ~(Disabled<<UPM0);
	}
	UCSRA = (s<<U2X);

//--------------3-Data Size ---------------------------------------

	if(D_S == Nine_bits)
	{
		NINE_BITS = 1;

		UCSRC |= (D_S & 0x03);
		UCSRB |= (1<<UCSZ2);
	}

	else
	{
		NINE_BITS = 0;
		UCSRC |= (D_S << UCSZ0);
	}


}

void USART_Transmit( uint16 data )
{
	/* Wait for empty transmit buffer */
		while ( !( UCSRA & (1<<UDRE)) );

	/* Put data into buffer, sends the data */

		if(NINE_BITS == 1)
		{
			UCSRB &= ~(0x01);
			data = UCSRB | (data >> 8);
			data &= 0x01FF;
		}

		UDR = data;
		
		UCSRB |= 1<<TXEN ;
		
}

uint16 USART_Receive( )
{
	UCSRB |= 1<<RXEN ;
	
	/* Wait for data to be received */
		while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */

		uint16 data=0x00;

		if(NINE_BITS == 1)
		{
			UCSRB &= ~(0x01);
			data |= (UCSRB<<7) & (data | 0x0100);
		}
		else
		{
			data |= UDR;
		}

		return data;
}

void USART_SendString(uint8 *data)
{
	uint8 i=0;
	while(data[i] != '\0' )
	{
		USART_Transmit(data[i]);
		i++;
	}
		USART_Transmit('@');

}

void USART_RecieveString(uint8 * Str)
{
	uint8 i = 0;
	Str[i] = USART_Receive();

	while(Str[i] != '@')
	{
		i++;
		Str[i] = USART_Receive();
	}
		Str[i] = '\0';
}

