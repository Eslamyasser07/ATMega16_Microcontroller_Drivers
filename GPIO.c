/***********************************************************************
* ATMega16(L) Microcontroller GPIO Driver   				           *
* Author 	  Eslam Yasser AbdelHameed                                 *
* Date        July 3, 2019                                             *
* Purpose:    Provide an easy way to Interface with  I/O Peripheral    *
***********************************************************************/

#include "GPIO.h"


void GPIO_Pin_Init				(uint8 base_addr, uint8 pin_num,gpio_dir dir)
{
	if(dir == OUTPUT)
	{
		*(volatile uint8 *)base_addr |= 1<<pin_num;		// OUTPUT
		*(volatile uint8 *)SFIOR 	 |= 1<<PUD;			// PULLUP Disable
	}
	else
	{
		*(volatile uint8 *)base_addr &= ~(1<<pin_num);	// INPUT

		if(dir == PULLUP)
		{
			*(volatile uint8 *)SFIOR &= ~(1<<PUD);					// PULLUP Enable
			*(volatile uint8 *)(base_addr + 0x01) |= 1<<pin_num;	// PORTx = High for PULLUP
		}
	}

}



void GPIO_Port_Init				(uint8 base_addr, gpio_dir dir)
{
	if(dir == OUTPUT)
	{
		*(volatile uint8 *)base_addr = 0xFF;			// OUTPUT
		*(volatile uint8 *)SFIOR 	 |= 1<<PUD;			// PULLUP Disable
	}
	else
	{
		*(volatile uint8 *)base_addr = 0x00;			// INPUT

		if(dir == PULLUP)
		{
			*(volatile uint8 *)SFIOR &= ~(1<<PUD);					// PULLUP Enable
			*(volatile uint8 *)(base_addr + 0x01) |= 0xFF;			// PORTx = High for PULLUP
		}
	}
}



void GPIO_Pin_Write				(uint8 base_addr, uint8 pin_num,gpio_state state)
{
	if(state == LOW)
	{
		*(volatile uint8 *)base_addr &= ~(1<<pin_num);
	}
	else
	{
		*(volatile uint8 *)base_addr |=   1<<pin_num;
	}
}



gpio_state GPIO_Pin_Read		(uint8 base_addr, uint8 pin_num)
{
	if( *(volatile uint8 *)base_addr & (1<<pin_num) )
		return HIGH;
	else
		return LOW;
}



void GPIO_Port_Write			(uint8 base_addr, uint8 val)
{
	*(volatile uint8 *)base_addr = val;
}



uint8 GPIO_Port_Read			(uint8_t base_addr)
{
	return *(volatile uint8 *)base_addr ;
}
