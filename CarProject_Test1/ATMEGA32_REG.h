/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

                  /*DIO Registers*/
//Registers for Data Direction
#define DDRA    *((volatile u8*)0x3A)
#define DDRB    *((volatile u8*)0x37)
#define DDRC    *((volatile u8*)0x34)
#define DDRD    *((volatile u8*)0x31)


//Registers For Ports
#define PORTA    *((volatile u8*)0x3B)
#define PORTB    *((volatile u8*)0x38)
#define PORTC    *((volatile u8*)0x35)
#define PORTD    *((volatile u8*)0x32)

//Registers For Pins
#define PINA    *((volatile u8*)0x39)
#define PINB    *((volatile u8*)0x36)
#define PINC    *((volatile u8*)0x33)
#define PIND    *((volatile u8*)0x30)

                /*External Interrupt Registers*/
				
// MCU Control Register				
#define MCUCR *((volatile u8*)0x55) 

//MCU Control and Status Register 
#define MCUCSR  *((volatile u8*)0x54)

// General Interrupt Control Register
#define GICR  *((volatile u8*)0x5B) 

//General Interrupt Flag Register 
#define GIFR  *((volatile u8*)0x5A) 

//Status Registers
#define SREG  *((volatile u8*)0x5F) 

            /*ADC REGISTERS */
			
//ADC Multiplexer Selection Register – ADMUX
#define ADMUX		*((volatile u8*)0x27)	

//ADC Control and Status Register A – ADCSRA
#define ADCSRA      *((volatile u8*)0x26)	

//The ADC Data Register – ADCL and ADCH
#define ADCH        *((volatile u8*)0x25)	
#define ADCL        *((volatile u8*)0x24)	
#define ADC_u16     *((volatile u16*)0x24)
//Special FunctionIO Register –
#define SFIOR       *((volatile u8*)0x50)


 /* TIMERS REGISTERS*/
 /* TIMER0 */

 // Timer/Counter Control Register
 #define TCCR0          (*(volatile u8*)0x53)

 // Timer/Counter Register
 #define TCNT0          (*(volatile u8*)0x52)

 // Output Compare Register
 #define OCR0           (*(volatile u8*)0x5C)

 // Timer/Counter Interrupt Mask Register
 #define TIMSK          (*(volatile u8*)0x59)

 // Timer/Counter Interrupt Flag Register
 #define TIFR           (*(volatile u8*)0x58)
 
  // TIMER 1 REGISTERS
  #define TCCR1A         (*(volatile u8*)0x4F)
  #define TCCR1B         (*(volatile u8*)0x4E)
  
  
  #define TCNT1_u16			(*(volatile u16*)0x4C)
  
  
  #define OCR1A_u16			(*(volatile u16*)0x4A)
  
  #define OCR1B_u16			(*(volatile u16*)0x48)
  
  #define ICR1_u16			(*(volatile u16*)0x46)
  
  /*TIMER 2 Registers*/
  #define TCCR2             (*(volatile u8*)0x45)
  #define TCNT2             (*(volatile u8*)0x44)
  #define OCR2              (*(volatile u8*)0x43)
  
  
 
            /* TWI REGISTERS*/
//TWI Bit RATE register
#define TWBR         (*(volatile u8*)0x20)   

// TWI Control Register
#define TWCR         (*(volatile u8*)0x56)
			
// TWI Status Register
#define TWSR         (*(volatile u8*)0x21)
		
// TWI DATA Register
#define TWDR         (*(volatile u8*)0x23)
	
// TWI (SLAVE) address Register
#define TWAR         (*(volatile u8*)0x22)	
#endif /* ATMEGA32_REG_H_ */