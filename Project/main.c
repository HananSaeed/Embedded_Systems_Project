#include "stdint.h"
#include "io.h"
#include "LCD.h"
#include "GPIO.h"
#include "keypad.h"
#include "Systick.h"


int main()
{

  
	SysTick_Init();
	PORT_Init();
  keypad_init();
	LCD_Init();
 
 
while(1)
  { 
		unsigned char Key_Input;
		//Part A
		Key_Input = keypad_getkey();

		if (Key_Input == 'A'){
			char Seconds[] = "0059";
			LCD_displayCharacter('A');
			time(2);
			LCD_Command(Clear_Display);
			
			LCD_displayString("Popcorn");
			time(2);
			LCD_Command(Clear_Display);
			
			CountDown(Seconds);
			LCD_Command(Clear_Display);
			
			
	}
		else if (Key_Input == 'D')
	{
		int n = 0;
	  char arr1[4] = {'0','0' ,'0' ,'0' };
    int index = 4;
		int sec;
		int i;
		char x;
	  char arr[4] = { '0','0','0','0' };

		LCD_displayCharacter('D');
		time(2);
		LCD_Command(Clear_Display);
			
		LCD_displayString("Cooking Time?");
		time(2);
		LCD_Command(Clear_Display);

	
	while (n<4) {
   	x = keypad_getkey();
		if(x != 0){
		arr[n]=x;
		LCD_displayCharacter(arr[n]);
		n++;
			if(n==2){
				LCD_displayCharacter(':');
				time(1);
			}
		}
    }
		time(3);
		LCD_Command(Clear_Display);
//		for ( i = 4 - n; i > 0;i--) { //this part should be added to SW2 code
//		char temp = arr[3];
//		for (i = 3; i > 0; i--){
//			arr[i] = arr[i - 1];
//	}
//		arr[0] = temp;
//	}
	 sec = ((arr[0]-'0') * 10 +(arr[1]-'0')) * 60 + ((arr[2]-'0') * 10 + (arr[3]-'0'));
	

	while (sec) {
        arr1[--index] = sec  % 10 + '0';
        sec /= 10;
    }
	CountDown(arr1);
    
	}
  } 
  
}