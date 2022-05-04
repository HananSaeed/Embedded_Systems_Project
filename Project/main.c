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
	//Part D
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
				time(1);
				LCD_displayCharacter(':');
				time(1);
			}
		}
    }
		time(3);
		LCD_Command(Clear_Display);

//If the user added 123 we know that arr[0]=1,arr[1]=2,arr[2]=3 so this will be a problem as we will want arr[0] to be min while arr[1],arr[2] as seconds but if the user entered 12 we want them as seconds only (arr[0]=1,arr[1]=2)
//we will make a general case where the frist two chars represent the minutes and the other two seconds 
 //This function represent shifting the array to assign every point to the right place
//If the user added 123 we know that arr[0]=1,arr[1]=2,arr[2]=3	 arr={1,2,3,0}   n=3
//		for ( i = 4 - n; i > 0;i--) {  //i=1 represent the number of shifts needed
//		char temp = arr[3];      
  			
//		for (i = 3; i > 0; i--){        //this part shift one time to the right to get arr={0,1,2,3}
//			arr[i] = arr[i - 1];
//	}
//		arr[0] = temp;
//	}
	 sec = ((arr[0]-'0') * 10 +(arr[1]-'0')) * 60 + ((arr[2]-'0') * 10 + (arr[3]-'0'));// to convert the time to only seconds

//To return the value to char
	while (sec) {
        arr1[--index] = sec  % 10 + '0';
        sec /= 10;
    }
	CountDown(arr1);
    
	}
  } 
  
}
