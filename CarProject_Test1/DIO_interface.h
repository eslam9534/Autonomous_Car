/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_Pin0 0
#define DIO_Pin1 1
#define DIO_Pin2 2
#define DIO_Pin3 3
#define DIO_Pin4 4
#define DIO_Pin5 5
#define DIO_Pin6 6
#define DIO_Pin7 7

// PIN DIRECTION
#define DIO_PinOutput 1
#define DIO_PinInput 0

// PIN STATE
#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

void DIO_setPinDirection  (u8 PortID,u8 PinID,u8 PinDirection);
void DIO_setPinValue      (u8 PortID,u8 PinID,u8 PinValue );
void DIO_GetPinValue      (u8 PortID,u8 PinID,u8* PinValue);
void DIO_togglePinValue   (u8 PortID,u8 PinID);



void DIO_setPortDirection  (u8 PortID,u8 PortDirection);
void DIO_setPortValue      (u8 PortID,u8 PortValue );
void DIO_GetPortValue      (u8 PortID,u8* PortValue);
void DIO_togglePortValue   (u8 PortID);

#endif /* DIO_INTERFACE_H_ */