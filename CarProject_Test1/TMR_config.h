/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#ifndef TMR_CONFIG_H_
#define TMR_CONFIG_H_

#define TMR_timer0_MODE   TMR_timer0_NORMAL

#define TMR_TMR0_PreloadValue      112

#define TMR_TMR0_OVFcounter        977
#define TMR_TMR0_CTCcounter        111

/* Options FOR ICU STARTING EDGE:
1- TMR_ICU_RISING_EDGE
2- TMR_ICU_FALLING_EDGE*/
#define TMR_ICU_STARTING_EDGE           TMR_ICU_FALLING_EDGE


#define TMR_timer2_MODE   TMR_timer2_FAST_PWM
#endif /* TMR_CONFIG_H_ */