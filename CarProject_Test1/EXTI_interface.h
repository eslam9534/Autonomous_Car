/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*
#define EXTI_INT0    0
#define EXTI_INT1    1
#define EXTI_INT2    2
*/

//ENUM FOR INTERRUPT SOURCE
typedef enum 
{
EXTI_INT0,//PORT_D Pin_2
EXTI_INT1,//PORT_D Pin_3
EXTI_INT2 //PORT_B PIN_2	
}EXTI_source;

//ENUM FOR INTERRUPT TRIGGER
typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_TRIGGER;


void EXTI_enable (EXTI_source interruptSource,EXTI_TRIGGER interruptTriggerEdge);
void EXTI_disable(EXTI_source interruptSource);
void EXTI_INT0SetCallBack(void(*ptr)(void));

#endif /* EXTI_INTERFACE_H_ */