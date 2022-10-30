/************************************************************************
*														   				*
*************************  DATE		:	25/10/2022   ********************
*********************  PROJECT		:	AUTONOMOUS CAR   ****************
*************************  VERSION	:	1.0          ********************
*																		*
************************************************************************/
#ifndef LCD_interface_H_
#define LCD_interface_H_
#define LCD_SHIFT_LEFT 0
#define LCD_SHIFT_RIGHT 1

void LCD_init(void);
void LCD_SendCommand(u8 command);
void LCD_SendChar(u8 dataChar);
void LCD_writeString(u8* String);
void LCD_Clear(void);
void LCD_shift(u8 shiftdirection);
static void writeHalfPort(u8 Value);
void LCD_start(void);
 



#endif /* INCFILE1_H_ */