/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/




#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET(REG,BIT) REG|=(1<<BIT)
#define GET(REG,BIT) ((REG>>BIT)&1)
#define CLR(REG,BIT) REG&=~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)

#define NULL 0




#endif