/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "DataTypes.h"
#include "DIO_interface.h"
#include "Hbridge_interface.h"

void Hbridge_init(void)
{
	//EN1 and EN2
	DIO_setPinDirection(DIO_PORTD,DIO_Pin4,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTD,DIO_Pin5,DIO_PinOutput);
	
	//MOTOR 1 H-A1 and H-A2
	DIO_setPinDirection(DIO_PORTC,DIO_Pin3,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTC,DIO_Pin4,DIO_PinOutput);
								
	//MOTOR 2 H-A3 and H-A4		
	DIO_setPinDirection(DIO_PORTC,DIO_Pin5,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTC,DIO_Pin6,DIO_PinOutput);
	
}
void Hbridge_forward(void)
{
	DIO_setPinValue(DIO_PORTD,DIO_Pin4,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTD,DIO_Pin5,DIO_PIN_HIGH);
	
	DIO_setPinValue(DIO_PORTC,DIO_Pin3,DIO_PIN_HIGH);//forward m1
	DIO_setPinValue(DIO_PORTC,DIO_Pin4,DIO_PIN_LOW);
	
	DIO_setPinValue(DIO_PORTC,DIO_Pin5,DIO_PIN_LOW);//forward m2
	DIO_setPinValue(DIO_PORTC,DIO_Pin6,DIO_PIN_HIGH);
	
}
void Hbridge_Right(void)
{
	DIO_setPinValue(DIO_PORTD,DIO_Pin4,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTD,DIO_Pin5,DIO_PIN_HIGH);
	// motor 1 forward
	DIO_setPinValue(DIO_PORTC,DIO_Pin3,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTC,DIO_Pin4,DIO_PIN_LOW);
	//motor 2 reverse
	DIO_setPinValue(DIO_PORTC,DIO_Pin5,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTC,DIO_Pin6,DIO_PIN_LOW);
	
}
void Hbridge_Left(void)
{
	DIO_setPinValue(DIO_PORTD,DIO_Pin4,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTD,DIO_Pin5,DIO_PIN_HIGH);
	// motor 1 reverse
	DIO_setPinValue(DIO_PORTC,DIO_Pin3,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_Pin4,DIO_PIN_HIGH);
	//motor 2 forward
	DIO_setPinValue(DIO_PORTC,DIO_Pin5,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_Pin6,DIO_PIN_HIGH);
}
void Hbridge_Stop(void)
{
	DIO_setPinValue(DIO_PORTD,DIO_Pin4,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTD,DIO_Pin5,DIO_PIN_LOW);
					//motor1 off						   
	DIO_setPinValue(DIO_PORTC,DIO_Pin3,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_Pin4,DIO_PIN_LOW);
					//motor2 off						  
	DIO_setPinValue(DIO_PORTC,DIO_Pin5,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_Pin6,DIO_PIN_LOW);
}
