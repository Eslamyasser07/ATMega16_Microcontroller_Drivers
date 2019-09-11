/****************************************************************************************
* ATMega16(L) Microcontroller Seven Segment Driver   				           					*
* Author 	  Eslam Yasser AbdelHameed                                              	*
* Date        July 4, 2019                                             					*
* Purpose:    Provide an easy way to Interface with 7 Segment using IC7447 Decoder    	*
*****************************************************************************************/



#ifndef SEG_H
#define SEG_H


#include "..\Configurations\Config.h"
#include "..\GPIO_Driver\GPIO.h"


#define Direction_PORT	DDRC
#define OUTPUT_PORT	    PORTC

#define First_Four	1


void  Seven_Segment_Init	  	();
void  Seven_Segment_Display		(uint8 num);
uint8 Seven_Segment_Get			();

#endif
