#include "stdint.h"
#include "io.h"
#include "LCD.h"
#include "GPIO.h"
#include "keypad.h"
#include "Systick.h"
#include "Function.h"
#define IDLE  1


int main()
{
    EdgeCounter_Init1(); 
	EdgeCounter_Init2(); 
  RGBLED_Init();
	SysTick_Init();
	PORT_Init();
	LCD_Init();
  keypad_init();
	SW3_init();
	Buzzer_init();

	time(2);
while(IDLE)
  { 
				unsigned char Key_Input;


		Key_Input = keypad_getkey();
	
		if (Key_Input == 'A'){
		A();
 blink();	
			
	}
		else if (Key_Input == 'B') {
   B();
			 blink();

}
	else if (Key_Input == 'C') {
		C();
		 blink();
	
  }
		else if (Key_Input == 'D')
	{
		D();
	 blink();

		
} 
 
}
	
	}
