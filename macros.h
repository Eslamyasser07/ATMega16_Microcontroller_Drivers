
/*
 * macros.h
 *
 * Created: 1/7/2019 1:38:46 PM
 *  Author: Eslam Yasser
 */

#ifndef MACRO_H
#define	MACRO_H


#define SET_BIT(REG,BIT)	(REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)	(REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)	(REG^=(1<<BIT))
#define IS_SET(REG,BIT)	    (REG & (1<<BIT))
#define IS_CLEAR(REG,BIT)	( !(REG & (1<<BIT)) )

#endif
