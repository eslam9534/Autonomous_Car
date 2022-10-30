/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_
//CHOOSE MODE AND TYPE IN MACRO
#define TMR_timer0_NORMAL   1
#define TMR_timer0_CTC      2
#define TMR_timer0_FAST_PWM 3

#define TMR_timer2_NORMAL   0
#define TMR_timer2_CTC		1
#define TMR_timer2_FAST_PWM	2

#define TMR_ICU_FALLING_EDGE         0
#define TMR_ICU_RISING_EDGE          1

void TMR_timer0Init(void);
void TMR_timer0Start(void);
void TMR_timer0Stop(void);

void TMR_timer0_OVF_SetCallBack(void(*OVFptr)(void));

void TMR_timer0_SetOCR0(u8 OCRvalue);
void TMR_timer0_CTC_SetCallBack(void(*CTCptr)(void));

void TMR_delay(u16 DelayTime);

//TIMER1//

void TMR_timer1Init(void);
void TMR_timer1Start(void);
void TMR_timer1Stop(void);
void TMR_timer1_SetOCR1A(u16 OCR1Avalue);

/* ICU */
void TMR_ICU_init(void);
void TMR_ICU_getTotalPeriod(u32* totalPeriod);
void TMR_ICU_getDutyCycle(u8* dutyCycle);

void TMR_timer2Init(void);
void TMR_timer2Start(void);
void TMR_timer2Stop(void);
void TMR_timer2_SetOCR2(u8 OCR2Avalue);
#endif /* TMR_INTERFACE_H_ */