#include "keypad.h"

#if	(COL_NUM == 3 && ROW_NUM == 3)
static uint8 Adjust_Number_3X3(uint8 num)
{
	switch (num)
	{
	case 11 : return 0  ;
	default : return num;
	}
}
#elif (COL_NUM == 3 && ROW_NUM == 4)
static uint8 Adjust_Number_3X4(uint8 num)
{

	switch (num)
	{
	case 10 : return '*';
	case 11 : return 0  ;
	case 12 : return '#';
	default : return num;
	}
}

#elif (COL_NUM == 4 && ROW_NUM == 4)

static uint8 Adjust_Number_4X4(uint8 num)
{

	switch (num)
	{

	case 4 	: return 'A';
	case 5 	: return 4	;
	case 6 	: return 5	;
	case 7 	: return 6	;
	case 8 	: return 'B';
	case 9 	: return 7	;
	case 10 : return 8	;
	case 11 : return 9	;
	case 12 : return 'C';
	case 13 : return '*';
	case 14 : return 0	;
	case 15 : return '#';
	case 16 : return 'D';
	default : return num;

	}
}

#endif

uint8 Get_char(void)
{
	uint8 c,r;

	while(1)
	{

		for(c=0;c<COL_NUM;c++)
		{

			DIR_PORT =  (0b00010000<<c);		// First 4 pins as INPUT and one pin only be OUT
			OUT_PORT =  (~(0b00010000<<c));		// enable PULL UP Resistor

			for(r=0;r<ROW_NUM;r++)
			{
				if( !( IN_PORT & (0b00000001<<r) ) )
				{
					#if	(COL_NUM == 3 && ROW_NUM == 3)
						return Adjust_Number_3X3((r*COL_NUM)+c+1);
					#elif (COL_NUM == 3 && ROW_NUM == 4)
						return Adjust_Number_3X4((r*COL_NUM)+c+1);
					#elif (COL_NUM == 4 && ROW_NUM == 4)
						return Adjust_Number_4X4((r*COL_NUM)+c+1);
					#endif
				}

			}
		}
	}


}
