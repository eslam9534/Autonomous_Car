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
#include "DataTypes.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/*MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_start(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_Pin4,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTA,DIO_Pin5,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTA,DIO_Pin6,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTA,DIO_Pin7,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTB,DIO_Pin1,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTB,DIO_Pin2,DIO_PinOutput);
	DIO_setPinDirection(DIO_PORTB,DIO_Pin3,DIO_PinOutput);
}
void LCD_init(void)
{
	_delay_ms(35);
	
	//set Rs pin=0 (Write command -instruction Register-)
	DIO_setPinValue(DIO_PORTB,DIO_Pin1,DIO_PIN_LOW);
	//set Rw pin=0 (Write)
	DIO_setPinValue(DIO_PORTB,DIO_Pin2,DIO_PIN_LOW);
	writeHalfPort(0b0010);
	//ENABLE PULSE H=>LOW
	DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_LOW);
	
	LCD_SendCommand(0b00101000);
	_delay_us(45);
	//Display on- Blinker on -Cursor on
	LCD_SendCommand(0b00001111);
	_delay_us(45);
	//Display Clear
	LCD_SendCommand(0b00000001);
		_delay_ms(3);
		//Auto increment 1- Shift display 
	LCD_SendCommand(0b00000110);
		
}

void LCD_SendCommand(u8 command)
{
	//set Rs pin=0 (Write command -instruction Register-)
	DIO_setPinValue(DIO_PORTB,DIO_Pin1,DIO_PIN_LOW);
	//set Rw pin=0 (Write)
	DIO_setPinValue(DIO_PORTB,DIO_Pin2,DIO_PIN_LOW);
	//write the most 4 bits of command
	writeHalfPort(command>>4);
	//ENABLE PULSE H=>LOW
	DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_LOW);
	
	//write the least 4 bits of command
	writeHalfPort(command);
	//ENABLE PULSE H=>LOW
	DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_LOW);
		
}
void LCD_SendChar(u8 dataChar)
{
		//set Rs pin=1 (Write data -instruction Register-)
		DIO_setPinValue(DIO_PORTB,DIO_Pin1,DIO_PIN_HIGH);
		//set Rw pin=0 (Write)
		DIO_setPinValue(DIO_PORTB,DIO_Pin2,DIO_PIN_LOW);
		//write the most 4 bits of dataChar
		writeHalfPort(dataChar>>4);
		//ENABLE PULSE H=>LOW
		DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_LOW);
		
		//write the least 4 bits of dataChar
		writeHalfPort(dataChar);
		//ENABLE PULSE H=>LOW
		DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_setPinValue(DIO_PORTB,DIO_Pin3,DIO_PIN_LOW);
}
 void LCD_writeString(u8* String)
 {
	 if(String!=NULL)
	 {
		 u8 stringLength=0;
		 
		 while(String[stringLength]!='\0')
		 {
			 LCD_SendChar(String[stringLength]);
			 ++stringLength;
		 } 
	 }
	  
 }
 static void writeHalfPort(u8 Value)
 {
	 
	 if(1==GET(Value,0))
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin4,DIO_PIN_HIGH);
	 }
	 else 
	 {
		 		 DIO_setPinValue(DIO_PORTA,DIO_Pin4,DIO_PIN_LOW);

	 }
	 if(1==GET(Value,1))
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin5,DIO_PIN_HIGH);
	 }
	 else
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin5,DIO_PIN_LOW);

	 }
	 if(1==GET(Value,2))
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin6,DIO_PIN_HIGH);
	 }
	 else
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin6,DIO_PIN_LOW);

	 }
	 if(1==GET(Value,3))
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin7,DIO_PIN_HIGH);
	 }
	 else
	 {
		 DIO_setPinValue(DIO_PORTA,DIO_Pin7,DIO_PIN_LOW);

	 }
 }
 void LCD_Clear(void)
 {
	 LCD_SendCommand(0b00000001);
	 _delay_ms(3);
 }
 void LCD_shift(u8 shiftdirection)
 {
	 if (shiftdirection==LCD_SHIFT_LEFT)
	 {
		LCD_SendCommand(0b00011000);
		_delay_ms(10); 
	 }
	 if (shiftdirection==LCD_SHIFT_RIGHT)
	 {
		 LCD_SendCommand(0b00011100);
		 _delay_ms(10);
	 }
 }