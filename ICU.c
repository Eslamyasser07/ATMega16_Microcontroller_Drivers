#include "ICU.h"


void Icu_init(const Icu_ConfigType * Config_Ptr)
{
	DDRD &= ~(1<<PD6);
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->clock);
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge)<<6);
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK |= (1<<TICIE1);
}

void Icu_setEdge(const Icu_EdgeType a_edgeType)
{
	TCCR1B = (TCCR1B & 0xBF) | (a_edgeType<<6);
}

uint16 Icu_getValue(void)
{
	return ICR1;
}
void Icu_clearValue(void)
{
	TCNT1 = 0;
}
void Icu_DeInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK &= ~(1<<TICIE1);
}
