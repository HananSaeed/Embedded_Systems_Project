/* Header Files */
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "SysTick.h"

/* LCD Commands */
#define Display_On  0x0F
#define Clear_Display 0x01
#define Two_Line_LCD_8bit_Mode 0x38
#define Wakeup_LCD 0x30
#define Decrement_Cursor 0x04 //From Right to left
#define Increment_Cursor 0x06 //From left to Right
#define DisplayOn_CursourOff 0x0C 
#define Set_Cursour_Location 0x80 

void LCD_Init(void);
void LCD_Command(unsigned char cmd);
void Give_Data_to_LCD(unsigned char data);
void LCD_displayCharacter(unsigned char data);
void LCD_goToRowColumn(char row,char col);
void CountDown(char *time);
void LCD_displayString(char *Str);
