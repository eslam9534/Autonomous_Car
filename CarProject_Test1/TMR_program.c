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

#include "TMR_interface.h"
#include "TMR_config.h"

static void (*TMR_Timer0_OVFpCallBack)(void)=NULL;

static void (*TMR_Timer0_CTCpCallBack)(void)=NULL;

volatile static u16 TMR_ICU_onPeriod,TMR_ICU_offPeriod;
volatile u16 buffer=0;
void TMR_timer0Init(void)
{
	#if   TMR_timer0_MODE == TMR_timer0_NORMAL
	
	//set timer on normal mode
	CLR(TCCR0,6);
	CLR(TCCR0,3);
	
	TCNT0=TMR_TMR0_PreloadValue;
	//enable OVF interrupt
	SET(TIMSK,0);
	#elif  TMR_timer0_MODE == TMR_timer0_CTC
	CLR(TCCR0,6);
	SET(TCCR0,3);
	
	//enable Compare Match Interrupt
	SET(TIMSK,1);
	#elif  TMR_timer0_MODE == TMR_timer0_FAST_PWM
	SET(TCCR0,6);
	SET(TCCR0,3);
	
	
	//NON INVERTING PWM
	SET(TCCR0,5);
	CLR(TCCR0,4);
	#endif 
	//set prescaler
	

}
void TMR_timer0Start(void)
{
	SET(TCCR0,0);
	CLR(TCCR0,1);
	CLR(TCCR0,2);
}
void TMR_timer0Stop(void)
{
	CLR(TCCR0,0);
	CLR(TCCR0,1);
	CLR(TCCR0,2);
}
void TMR_timer0_OVF_SetCallBack(void(*OVFptr)(void))
{
	if(OVFptr!=NULL)
	{
		TMR_Timer0_OVFpCallBack=OVFptr;
	}
}

/*void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	
	static u16 counter=0;
	++counter;
	if(TMR_TMR0_OVFcounter==counter)
	{
		TCNT0=TMR_TMR0_PreloadValue;
		
		counter=0;
		
		if(TMR_Timer0_OVFpCallBack!=NULL)
		{
			TMR_Timer0_OVFpCallBack();
		}
	}
	
}*/
void TMR_timer0_SetOCR0(u8 OCRvalue)
{
	//Init timer with compare value
	OCR0=OCRvalue;
}
//ISR Function prototype for TMR0 CTC
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static u16 counter=0;
	++counter;
	if(TMR_TMR0_CTCcounter==counter)
	{
		counter = 0;
		//Call action
		if(TMR_Timer0_CTCpCallBack!=NULL)
		{
			TMR_Timer0_CTCpCallBack();
		}
	}
}
void TMR_timer0_CTC_SetCallBack(void(*CTCptr)(void))
{
	if(CTCptr!=NULL)
	{
		TMR_Timer0_CTCpCallBack=CTCptr;
	}
}

void TMR_timer1Init(void)
{
	CLR(TCCR1A,0);
	SET(TCCR1A,1);
	
	SET(TCCR1B,3);
	SET(TCCR1B,4);//mode 14 fast pwm
	
	CLR(TCCR1A,6);
	SET(TCCR1A,7);//non inverting
	//ICR1_u16=4999;
	

}
void TMR_timer1Start(void)
{
	SET	(TCCR1B,0);
	SET	(TCCR1B,1);
	CLR	(TCCR1B,2);
}
void TMR_timer1Stop(void)
{
	
	CLR(TCCR1B,0);
	CLR(TCCR1B,1);
	CLR(TCCR1B,2);
}
void TMR_timer1_SetOCR1A(u16 OCR1Avalue)
{
	 OCR1A_u16=OCR1Avalue;
}


/* ICU */
void TMR_ICU_init(void)
{
	// Select Mode = Normal Mode
	CLR(TCCR1A,0);
	CLR(TCCR1A,1);
	CLR(TCCR1B,3);
	CLR(TCCR1B,4);
	
	//select edge source of ICP1 interrupt
	#if TMR_ICU_STARTING_EDGE == TMR_ICU_RISING_EDGE
	SET(TCCR1B,6);
	#elif TMR_ICU_STARTING_EDGE == TMR_ICU_FALLING_EDGE
	CLR(TCCR1B,6);
	#endif
	//Activate ICU interrupt
	SET(TIMSK,5);
	
	// Select Prescaler Value = 64
	SET(TCCR1B,0);
	SET(TCCR1B,1);
	CLR(TCCR1B,2);
}

void TMR_ICU_getTotalPeriod(u32* totalPeriod);
void TMR_ICU_getDutyCycle(u8* dutyCycle);

//ISR For ICU 
void __vector_6(void) __attribute__ ((signal));
void __vector_6(void)
{
	static u8  flag = TMR_ICU_STARTING_EDGE;
	static u16 oldValue;
	static u16 CounterValue;
	
	/* Read ICR1 value*/
	CounterValue = ICR1_u16;
	
	if (flag == TMR_ICU_RISING_EDGE) //calculate off period
	{
		TMR_ICU_offPeriod = (CounterValue - oldValue)*4;
		// change edge source of ICP1 interrupt to falling edge
		CLR(TCCR1B,6);
		// change flag value
		flag = TMR_ICU_FALLING_EDGE;
	}
	else if (flag == TMR_ICU_FALLING_EDGE) //calculate on period
	{
		TMR_ICU_onPeriod = (CounterValue - oldValue)*4;
		buffer=TMR_ICU_onPeriod;
		// change edge source of ICP1 interrupt to rising edge
		SET(TCCR1B,6);
		// change flag value
		flag = TMR_ICU_RISING_EDGE;
	}
	// old value
	oldValue = CounterValue;
	
	
}
void TMR_timer2Init(void)
{
	#if TMR_timer2_MODE==TMR_timer2_FAST_PWM
	SET(TCCR2,6);
	SET(TCCR2,3);
	#endif
	//CLear on compare match PWM
	CLR(TCCR2,4);
	SET(TCCR2,5);
	
}
void TMR_timer2Start(void)
{
	//prescaler 64
	CLR(TCCR2,0);
	CLR(TCCR2,1);
	SET(TCCR2,2);
}
void TMR_timer2Stop(void)
{
	//prescaler 64
	CLR(TCCR2,0);
	CLR(TCCR2,1);
	CLR(TCCR2,2);
}
void TMR_timer2_SetOCR2(u8 OCR2Avalue)
{
	OCR2=OCR2Avalue;
}