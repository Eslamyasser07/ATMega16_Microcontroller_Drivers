/***********************************************************************
* ATMega16(L) Microcontroller GPIO Driver   				           *
* Author 	  Eslam Yasser AbdelHameed                                 *
* Date        July 3, 2019                                             *
* Purpose:    Provide an easy way to Interface with  I/O Peripheral    *
***********************************************************************/

#ifndef IO_H
#define IO_H

#include "..\Configurations\Config.h"

/*
 * ---- Register Definitions -------
 */

#define SFIOR	0x50

#define PORTA	0x3B
#define DDRA	0x3A
#define PINA	0x39

#define PORTB	0x38
#define DDRB	0x37
#define PINB	0x36

#define PORTC	0x35
#define DDRC	0x34
#define PINC	0x33

#define PORTD	0x32
#define DDRD	0x31
#define PIND	0x30


/*
 * ---- PINs Definitions -------
 */

#define PUD	2

#define PA0	0
#define PA1	1
#define PA2	2
#define PA3	3
#define PA4	4
#define PA5	5
#define PA6	6
#define PA7	7

#define PB0	0
#define PB1	1
#define PB2	2
#define PB3	3
#define PB4	4
#define PB5	5
#define PB6	6
#define PB7	7

#define PC0	0
#define PC1	1
#define PC2	2
#define PC3	3
#define PC4	4
#define PC5	5
#define PC6	6
#define PC7	7

#define PD0	0
#define PD1	1
#define PD2	2
#define PD3	3
#define PD4	4
#define PD5	5
#define PD6	6
#define PD7	7


typedef enum gpio_dir
{
	INPUT,
	OUTPUT,
	PULLUP
}gpio_dir;

typedef enum gpio_state
{
	LOW,
	HIGH
}gpio_state;

void GPIO_Pin_Init				(uint8 base_addr, uint8 pin_num,gpio_dir dir);
void GPIO_Port_Init				(uint8 base_addr, gpio_dir dir);
void GPIO_Pin_Write				(uint8 base_addr, uint8 pin_num,gpio_state state);
gpio_state GPIO_Pin_Read		(uint8 base_addr, uint8 pin_num);
void GPIO_Port_Write			(uint8 base_addr, uint8 val);
uint8 GPIO_Port_Read			(uint8_t base_addr);



#endif
