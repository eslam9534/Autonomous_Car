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

u8 i;
void Servo_init(void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_Pin7,DIO_PinOutput);
	
	Servo_Zero();
}
void Servo_RotateRight(void)
{
	for(i=0;i<50;i++)
	{
		DIO_setPinValue(DIO_PORTD,DIO_Pin7,DIO_PIN_HIGH);
		_delay_ms(4);
		DIO_setPinValue(DIO_PORTD,DIO_Pin7,DIO_PIN_LOW);
		_delay_ms(20);
	}
}
void Servo_RotateLeft(void)
{
	for(i=0;i<50;i++)
	{
		DIO_setPinValue(DIO_PORTD,DIO_Pin7,DIO_PIN_HIGH);
		_delay_ms(0.5);
		DIO_setPinValue(DIO_PORTD,DIO_Pin7,DIO_PIN_LOW);
		_delay_ms(19.5);
	}
}
void Servo_Zero(void)
{
	for(i=0;i<50;i++)
	{
		DIO_setPinValue(DIO_PORTD,DIO_Pin7,DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_setPinValue(DIO_PORTD,DIO_Pin7,DIO_PIN_LOW);
		_delay_ms(19);
	}
}