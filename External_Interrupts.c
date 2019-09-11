/*****************************************************************************************
* ATMega16(L) Microcontroller External Interrupts Driver               		 	 	     *
* Author 	  Eslam Yasser AbdelHameed                                 					 *
* Date        July 4, 2019                                            					 *
* Purpose:    Provide an easy way to Interface with  External Interrupts Peripheral  	 *
******************************************************************************************/

#include "External_Interrupts.h"

void EX_IT_Enable(EX_IT_Num num,EX_IT_Mode mode)
{


	*(volatile uint8 *)SREG &= ~(1<<7);			// Disable Global Interrupt



	if(num == 0)
	{

	*(volatile uint8 *)0x31  &= ~(1<<2);
	*(volatile uint8 *)MCUCR = ((*(volatile uint8 *)MCUCR) & 0xFC ) | mode ;  // Set Mode of Interrupt
	*(volatile uint8 *)GICR |= 1<<6;		// Interrupt Request 0 Enable

	}


	else if(num == 1)
	{
		*(volatile uint8 *)0x31  &= ~(1<<3);
		*(volatile uint8 *)MCUCR = ((*(volatile uint8 *)MCUCR) & 0xF3 ) | (mode<<2) ;  // Set Mode of Interrupt
		*(volatile uint8 *)GICR |= 1<<7;	// Interrupt Request 1 Enable
	}


	else if(num == 2)
	{
		*(volatile uint8 *)0x37  &= ~(1<<3);

		if(mode == Falling)
		{
			(*(volatile uint8 *)MCUCSR) &= ~(1<<6);  // Enable Mode of Interrupt
		}
		else if(mode == Rising)
		{
			(*(volatile uint8 *)MCUCSR) |= 1<<6;  // Enable Mode of Interrupt
		}

		*(volatile uint8 *)GICR |= 1<<5;		// Interrupt Request 2 Enable
	}



	*(volatile uint8 *)SREG |= 1<<7;			// Enable Global Interrupt
}




uint8 EX_IT_Polling(EX_IT_Num num)
{
	if(num == 0)
		while( !((*(volatile uint8 *)GIFR) & (1<<6)) ){}

	else if(num == 1)
		while( !((*(volatile uint8 *)GIFR) & (1<<6)) ){}

	else if(num == 2)
		while( !((*(volatile uint8 *)GIFR) & (1<<6)) ){}


	return 1;

}




void EX_IT_Disable(EX_IT_Num num)
{
	if(num == 0)
		*(volatile uint8 *)GICR &= ~(1<<6);		// Interrupt Request 0 Enable

	else if(num == 1)
		*(volatile uint8 *)GICR &= ~(1<<7);		// Interrupt Request 0 Enable

	else if(num == 2)
		*(volatile uint8 *)GICR &= ~(1<<5);		// Interrupt Request 0 Enable

}
