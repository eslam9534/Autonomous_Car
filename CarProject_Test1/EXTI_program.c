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
#include "EXTI_interface.h"

static void (*pCallBack)(void)=NULL;

void EXTI_enable (EXTI_source interruptSource,EXTI_TRIGGER interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		if(interruptTriggerEdge==EXTI_RISING_EDGE)
		{
			SET(MCUCR,0);
			SET(MCUCR,1);
		}
		else if(interruptTriggerEdge==EXTI_FALLING_EDGE)
		{
			CLR(MCUCR,0);
			SET(MCUCR,1);
		}
		else if(interruptTriggerEdge==EXTI_LOW_LEVEL)
		{
			CLR(MCUCR,0);
			CLR(MCUCR,1);
		}
		else if(interruptTriggerEdge==EXTI_ANY_LOGICAL_CHANGE)
		{
			SET(MCUCR,0);
			CLR(MCUCR,1);
		}
		
		SET(GICR,6);     //bit number 6 logical 1 (enable INT0)
		break;
		
		case EXTI_INT1:
		if(interruptTriggerEdge==EXTI_RISING_EDGE)
		{
			SET(MCUCR,2);
			SET(MCUCR,3);
		}
		else if(interruptTriggerEdge==EXTI_FALLING_EDGE)
		{
			CLR(MCUCR,2);
			SET(MCUCR,3);
		}
		else if(interruptTriggerEdge==EXTI_LOW_LEVEL)
		{
			CLR(MCUCR,2);
			CLR(MCUCR,3);
		}
		else if(interruptTriggerEdge==EXTI_ANY_LOGICAL_CHANGE)
		{
			SET(MCUCR,2);
			CLR(MCUCR,3);
		}
		
		SET(GICR,7);     //bit number 7 logical 1 (enable INT1)
		break;
		
		case EXTI_INT2:
		if(interruptTriggerEdge==EXTI_RISING_EDGE)
		{
			SET(MCUCSR,6);
		}
		else if(interruptTriggerEdge==EXTI_FALLING_EDGE)
		{
			CLR(MCUCSR,6);
		}
		
		SET(GICR,5);
		break;
	}
}



void EXTI_disable(EXTI_source interruptSource)
{
switch (interruptSource)
{
	case EXTI_INT0:
	CLR(GICR,6);
	break;
	case EXTI_INT1:
	CLR(GICR,7);
	break;
	case EXTI_INT2:
	CLR(GICR,5);
	break;
}

}

void EXTI_INT0SetCallBack(void(*ptr)(void))
{
	if(ptr!=NULL)
	{
		pCallBack=ptr;
	}
}
//ISR FUNCTION PROTOTYPE FOR EXTI0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{ 
	 if(pCallBack!=NULL)
	 {
		 pCallBack();
	 }
	
}