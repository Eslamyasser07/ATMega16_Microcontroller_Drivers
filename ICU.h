

#ifndef ICU_H_
#define ICU_H_

#include "Config.h"
#include "Data_Types.h"
#include "macros.h"


typedef enum
{
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024

}Icu_Clock;

typedef enum
{
	FALLING,
	RISING

}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;

}Icu_ConfigType;



void Icu_init(const Icu_ConfigType * Config_Ptr);
void Icu_setEdge(const Icu_EdgeType edgeType);
uint16 Icu_getValue(void);
void Icu_clearValue(void);
void Icu_DeInit(void);

#endif /* ICU_H_ */
