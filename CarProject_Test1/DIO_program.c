/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
//Utils library
#include "DataTypes.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

// MCAL (micro-controller abstraction library)
#include "DIO_interface.h"

void DIO_setPinDirection  (u8 PortID,u8 PinID,u8 PinDirection)
{
	if((PortID<=3)&& (PinID<=7)&&((PinDirection==0)||(PinDirection==1)))
	{
		switch (PortID)
		{
			case DIO_PORTA:
			if(DIO_PinOutput==PinDirection)
			{
				SET(DDRA,PinID);
			}
			else
			{
				CLR(DDRA,PinID);
				
			}
			break;
			case DIO_PORTB:
			if(DIO_PinOutput==PinDirection)
			{
				SET(DDRB,PinID);
			}
			else
			{
				CLR(DDRB,PinID);
				
			}
			break;
			case DIO_PORTC:
			if(DIO_PinOutput==PinDirection)
			{
				SET(DDRC,PinID);
			}
			else
			{
				CLR(DDRC,PinID);
				
			}
			break;
			case DIO_PORTD:
			if(DIO_PinOutput==PinDirection)
			{
				SET(DDRD,PinID);
			}
			else
			{
				CLR(DDRD,PinID);
				
			}
			break;
		}
	}
	
}
void DIO_setPinValue      (u8 PortID,u8 PinID,u8 PinValue )
{
	if((PortID<=3)&&(PinID<=7)&&((DIO_PIN_HIGH==PinValue)||(DIO_PIN_LOW==PinValue)))
	{
		switch(PortID)
		{
			case 0:
			if(PinValue==DIO_PIN_HIGH)
			{
				SET(PORTA,PinID);
			}
			else
			{
				CLR(PORTA,PinID);
			}
			break;
			case 1:
			if(PinValue==DIO_PIN_HIGH)
			{
				SET(PORTB,PinID);
			}
			else
			{
				CLR(PORTB,PinID);
			}
			break;
			case 2:
			if(PinValue==DIO_PIN_HIGH)
			{
				SET(PORTC,PinID);
			}
			else
			{
				CLR(PORTC,PinID);
			}
			break;
			case 3:
			if(PinValue==DIO_PIN_HIGH)
			{
				SET(PORTD,PinID);
			}
			else
			{
				CLR(PORTD,PinID);
			}
			break;
		}
	}
}


void DIO_GetPinValue      (u8 PortID,u8 PinID,u8* PinValue)
{
	if((PortID<=3)&&(PinID<=7)&&(PinValue!=NULL))
	{
		switch(PortID)
		{
			case 0:
			if(DIO_PIN_HIGH==GET(PINA,PinID))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
			case 1:
			if(DIO_PIN_HIGH==GET(PINB,PinID))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
			case 2:
			if(DIO_PIN_HIGH==GET(PINC,PinID))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
			case 3:
			if(DIO_PIN_HIGH==GET(PIND,PinID))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
		}
	}
}
void DIO_togglePinValue   (u8 PortID,u8 PinID)
{
	if((PortID<=3)&&(PinID<=7))
	{
		
		switch (PortID)
		{
			case 0:
			TOGGLE_BIT(PORTA,PinID);
			break;
			case 1:
			TOGGLE_BIT(PORTB,PinID);
			break;
			case 2:
			TOGGLE_BIT(PORTC,PinID);
			break;
			case 3:
			TOGGLE_BIT(PORTD,PinID);
			break;
		}
	}
}
void DIO_SetInputPinResistance(u8 PortID,u8 PinID)
{
	if((PortID<=3)&&(PinID<=7))
	{
		switch(PortID)
		{
			case 0:
			SET(PORTA,PinID);
			break;
			case 1:
			SET(PORTB,PinID);
			break;
			case 2:
			SET(PORTC,PinID);
			break;
			case 3:
			SET(PORTD,PinID);
			break;
		}
	}
}




void DIO_setPortDirection  (u8 PortID,u8 PortDirection)
{
	if((PortID<=3)&&((DIO_PinOutput==PortDirection)||(DIO_PinInput==PortDirection )))
	{
		switch (PortID)
		{
			case 0: //port A
			if (PortDirection==DIO_PinOutput){
			DDRA=0xff;
			}
			else
			{
				DDRA=0x00;
			}
			break;
			case 1: //port B
			if (PortDirection==DIO_PinOutput){
				DDRB=0xff;
			}
			else
			{
				DDRB=0x00;
			}
			break;
			case 2: //port C
			if (PortDirection==DIO_PinOutput){
				DDRC=0xff;
			}
			else
			{
				DDRC=0x00;
			}
			break;
			case 3: //port D
			if (PortDirection==DIO_PinOutput){
				DDRD=0xff;
			}
			else
			{
				DDRD=0x00;
			}
			break;
		}
	}
	
}

void DIO_setPortValue      (u8 PortID,u8 PortValue )
{
	if(PortID<=3)
	{
		switch(PortID)
		{
			case 0:
			PORTA= PortValue;
			
			break;
			case 1:
			PORTB= PortValue;
			
			break;
			case 2:
			PORTC= PortValue;
			
			break;
			case 3:
			PORTD= PortValue;
			
			break;
		}
	}
}
void DIO_GetPortValue      (u8 PortID,u8* PortValue)
{
	if((PortID<=3 )&&(PortValue!=NULL))
	{
		switch(PortID)
		{
			case 0:
			*PortValue=PINA;
			break;
			case 1:
			*PortValue=PINB;
			break;
			case 2:
			*PortValue=PINC;
			break;
			case 3:
			*PortValue=PIND;
			break;
		}
	}
}
void DIO_togglePortValue   (u8 PortID)
{
	if(PortID<=3)
	{
		switch (PortID)
		{
			case 0:
			PORTA=~PORTA;
			
			break;
			case 1:
			PORTB=~PORTB;
			
			break;
			case 2:
			PORTC=~PORTC;
			
			break;
			case 3:
			PORTD=~PORTD;
			
			break;
		}
	}
}
void DIO_SetInputPortResistance(u8 PortID)
{
	if(PortID<=3)
	{
		switch (PortID)
		{
			case 0:
			PORTA=0xff;
			break;
			case 1:
			PORTB=0xff;
			break;
			case 2:
			PORTC=0xff;
			break;
			case 3:
			PORTD=0xff;
			break;
			
		}
	}
}

