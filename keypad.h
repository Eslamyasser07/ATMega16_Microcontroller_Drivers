/***********************************************************************
* ATMega16(L) Microcontroller KeyPad  Driver   				           *
* Author 	  Eslam Yasser AbdelHameed                                 *
* Date        September 22, 2019                                       *
* Purpose:    Provide an easy way to Interface with  Keypad			   *
***********************************************************************/

#ifndef KP_H
#define KP_H


#include <avr/io.h>
#include "Config.h"

#define COL_NUM		4		// Number of Columns
#define ROW_NUM		4		// Number of Rows

#define OUT_PORT	PORTA	// Output Port
#define IN_PORT		PINA	// Input  Port
#define DIR_PORT	DDRA	// Direction Port


// Function responsible for getting the pressed keypad key

uint8 Get_char(void);



#endif
