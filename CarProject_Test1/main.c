/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#define F_CPU 16000000UL
#include <util/delay.h>
//UTILS
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "DataTypes.h"
//MCAL
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "TMR_config.h"
#include "TMR_interface.h"
#include "GI_interface.h"
//HAL
#include "US_interface.h"
#include "Servo_interface.h"
#include "Hbridge_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"



int main(void)
{
	GI_enable();
	LCD_start();
	LCD_init();
   US_init();
   Servo_init();
   Hbridge_init();
    while (1) 
    {
		US_trigger();
		while(object==0){
			US_trigger();
			
			LCD_writeString((u8*)"Moving Forward");
			
			Hbridge_forward();
			
			
		}
		if(object==1)
		{
			Hbridge_Stop();
			_delay_ms(500);
			Servo_RotateLeft();
		
		_delay_ms(500);
			US_trigger();
		
		
		_delay_ms(500);
			if (object==0)
			{
				LCD_Clear();
				LCD_writeString((u8*)"Moving Right");
				Hbridge_Right();
				_delay_ms(900);
				Hbridge_Stop();
				_delay_ms(500);
			Servo_Zero();
			}
			else if(object==1)
			{
				Servo_RotateRight();

				_delay_ms(1000);
				US_trigger();
				_delay_ms(500);
				if(object==0)
				{
					LCD_Clear();
					LCD_writeString((u8*)"Moving Left");
					Hbridge_Left();
					_delay_ms(900);
					Hbridge_Stop();
					Servo_Zero();
				}
			
					
				
			}
			
			
		
		}
		
    }
}

