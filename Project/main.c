#include "stdint.h"
#include "io.h"
#include "LCD.h"
#include "GPIO.h"
#include "keypad.h"
#include "Systick.h"
#include "Function.h"
#define IDLE  1
#define POPCORN 'A'
#define BEEF 'B'
#define CHICKEN 'C'
#define CookingTime 'D'

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
if (Key_Input == POPCORN){
		A();
 blink();	
			
	}
else if (Key_Input == BEEF) {
   B();
 blink();

}
else if (Key_Input == CHICKEN) {
C();
 blink();
	
  }
else if (Key_Input == CookingTime){
D();
 blink();

} 
 
}
	return 1;
	}
