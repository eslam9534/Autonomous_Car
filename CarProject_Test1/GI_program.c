/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#include "ATMEGA32_REG.h"
#include "DataTypes.h"
#include "BIT_MATH.h"
#include "GI_interface.h"


void GI_enable(void)
{
	//global interrupt enable
SET(SREG,7);
}
void GI_disable(void)
{
	//global interrupt enable
	CLR(SREG,7);
}