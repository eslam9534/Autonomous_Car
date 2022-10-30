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
#include "EXTI_interface.h"
#include "TMR_config.h"
#include "TMR_interface.h"

#include "US_interface.h"

u16 counter=0;
u8 object=0;
u8 sensor_status=0;
u8 rising_edge=0;
u32 timer_counter=0;
u32 distance;
void US_init(void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_Pin0,DIO_PinOutput);//TRIGGER PIN
	DIO_setPinDirection(DIO_PORTD,DIO_Pin3,DIO_PinInput);//ECHO PIN
	  

	TMR_timer0Init();
	TMR_timer0Start();//no_prescaler
	EXTI_enable(EXTI_INT1,EXTI_ANY_LOGICAL_CHANGE);
	
}
void US_trigger(void)
{
	if(sensor_status==0){
		//Set Trigger High For 15 us then off
		
		DIO_setPinValue(DIO_PORTD,DIO_Pin0,DIO_PIN_HIGH);
		_delay_us(15);
		DIO_setPinValue(DIO_PORTD,DIO_Pin0,DIO_PIN_LOW);
		sensor_status=1;
	}
	

}

void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{
	
	if(sensor_status==1)
	{
		if(rising_edge==0)
		{
			TCNT0=0x00;
			rising_edge=1;
			timer_counter=0;
		}
		else
		{
			distance =(timer_counter*256+TCNT0)/928;
			if(distance<20)
			{
				object=1;
				
			}
			else
			{
				object=0;
				
			}
			_delay_ms(40);
			timer_counter=0;
			rising_edge=0;
			
		}
	}
}
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	
	
	timer_counter++;
	if(timer_counter >730){
		TCNT0=0x00;
		sensor_status=0;
		rising_edge=0;
		timer_counter=0;
	}
	
}