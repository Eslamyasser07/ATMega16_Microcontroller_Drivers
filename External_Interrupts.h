/*****************************************************************************************
* ATMega16(L) Microcontroller External Interrupts Driver               		 	 	     *
* Author 	  Eslam Yasser AbdelHameed                                 					 *
* Date        July 4, 2019                                            					 *
* Purpose:    Provide an easy way to Interface with  External Interrupts Peripheral  	 *
******************************************************************************************/

#ifndef External_Interrupts_H
#define External_Interrupts_H


#include "..\Configurations\Config.h"


#define SREG	0x5F
#define MCUCR	0x55
#define MCUCSR	0x54
#define GICR	0x5B
#define GIFR	0x5A


typedef enum EX_IT_Num
{
	INT_0,
	INT_1,
	INT_2
}EX_IT_Num;

typedef enum EX_IT_Mode
{
	low,
	Any_Change,
	Falling,
	Rising

}EX_IT_Mode;

//void Ex_IT_Init();
void EX_IT_Enable(EX_IT_Num num,EX_IT_Mode mode);
uint8 EX_IT_Polling(EX_IT_Num num);
void EX_IT_Disable(EX_IT_Num num);

#endif
