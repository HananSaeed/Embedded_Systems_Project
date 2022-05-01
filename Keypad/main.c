#include "GPIO.h"
#include "LCD.h" 
#include "keypad_driver.h"
#include "Systick.h"


int main()
{
  unsigned char key;
  
	SysTick_Init();
	PORT_Init();
  keypad_init();
	LCD_Init();
 
  while(1)
  { 
    key = keypad_getchar();
    if (key != 0)
    LCD_displayCharacter(key);
    SysTick_wait10ms(2);
  } 
  
}
