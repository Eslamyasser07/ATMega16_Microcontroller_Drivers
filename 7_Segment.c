/****************************************************************************************
* ATMega16(L) Microcontroller Seven Segment Driver   				           					*
* Author 	  Eslam Yasser AbdelHameed                                              	*
* Date        July 4, 2019                                             					*
* Purpose:    Provide an easy way to Interface with 7 Segment using IC7447 Decoder    	*
*****************************************************************************************/


#include "7_Segment.h"


void Seven_Segment_Init ()
{

#if   (First_Four == 1)

	*(volatile uint8 *)Direction_PORT |= 0x0F;

#elif (First_Four == 0)

	*(volatile uint8 *)Direction_PORT |= 0xF0;

#endif

}
void Seven_Segment_Display	 (uint8 num)

{

#if   (First_Four == 1)

	*(volatile uint8 *)OUTPUT_PORT = ( OUTPUT_PORT & 0xF0 ) | ( num & 0x0F ) ;

#elif (First_Four == 0)

	*(volatile uint8 *)OUTPUT_PORT = ( OUTPUT_PORT & 0x0F ) | (( num & 0x0F )<<4) ;

#endif

}


uint8 Seven_Segment_Get	()
{
	uint8 num = 0 ;

#if   (First_Four == 1)

	num = 0x0F & (*(volatile uint8 *)OUTPUT_PORT);

#elif (First_Four == 0)

	num = ( 0xF0 & (*(volatile uint8 *)OUTPUT_PORT) ) >> 4;

#endif

	return num;
}
