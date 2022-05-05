#include "stdint.h"
#include "io.h"
#include "LCD.h"
#include "GPIO.h"
#include "keypad.h"
#include "Systick.h"
#include "switch.h"


int main()
{
  int index = 4;
  EdgeCounter_Init2(); 
  EdgeCounter_Init1(); 
  RGBLED_Init();
	SysTick_Init();
	PORT_Init();
	LCD_Init();
  keypad_init();
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
/**************************************************************************************************************************************************/	
	//Part B
	else if (Key_Input == 'B') {
			int w =0;
  	  int i=0;
			int x=0;
		  char arr[2]; 
			char arr1[4] = { '0','0' ,'0' ,'0' };
				LCD_displayCharacter('B');
			  time(2);
			  LCD_Command(Clear_Display);
			

	 do{
  		LCD_displayString("Beef weight");
			  time(2);

			  LCD_Command(Clear_Display);

    
   	while (i<2) {
		
   	x = keypad_getkey();

		if(x != 0){
		arr[i]=x;
		LCD_displayCharacter(arr[i]);
		i++;
		}
	}
	time(2);
	i=0;
w = (arr[0]-'0') * 10 +(arr[1]-'0');
	if ( w>=1 && w <=9)
		{
			LCD_Command(Clear_Display);//clear LCD
			break;
       }

		else {
    LCD_Command(Clear_Display);
		LCD_displayString("Err");
		time(2);
		LCD_Command(Clear_Display);		
		}


	}	 while(1);

    w = w*30;    
	while (w) {
        arr1[--index] = w  % 10 + '0';
        w /= 10;
    }

	CountDown(arr1);

}
	/**************************************************************************************************************************************************/		
           //Part C
	else if (Key_Input == 'C') {
			int w =0;
  	  int i=0;
			int x=0;
		  char arr[2]; 
			char arr1[4] = { '0','0' ,'0' ,'0' };

				LCD_displayCharacter('C');
			  time(2);
			  LCD_Command(Clear_Display);
	 do{
  	  	LCD_displayString("Chicken weight");
			  time(2);
			  LCD_Command(Clear_Display); 
   	while (i<2) {
   	x = keypad_getkey();
		if(x != 0){
		arr[i]=x;
		LCD_displayCharacter(arr[i]);
		i++;
		}
	}
	time(2);
	 i=0;
   w = (arr[0]-'0') * 10 +(arr[1]-'0');
	if ( w>=1 && w <=9)
		{
			LCD_Command(Clear_Display);//clear LCD
			break;
       }

		else {
    LCD_Command(Clear_Display);
		LCD_displayString("Err");
		time(2);
		LCD_Command(Clear_Display);		
		}


	}	 while(1);

    w = w*12;    
	while (w) {
        arr1[--index] = w  % 10 + '0';
        w /= 10;
    }

	CountDown(arr1);

}
/**************************************************************************************************************************************************/		
//Part D
else if (Key_Input == 'D')
	{
		int n = 0;
	  char arr1[4] = {'0','0' ,'0' ,'0' };

		int sec;
		int i=0;
		char x=0;
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
		}
			if (GPIO_PORTF_DATA_R == 0x10)
			break;	
    }
		time(3);
		LCD_Command(Clear_Display);
		for ( n = 4 - n; n > 0;n--) { 
		char temp = arr[3];
		for (i = 3; i > 0; i--){
			arr[i] = arr[i - 1];
	}
		arr[0] = temp;
	}
	 sec = ((arr[0]-'0') * 10 +(arr[1]-'0')) * 60 + ((arr[2]-'0') * 10 + (arr[3]-'0'));
	

	while (sec) {
        arr1[--index] = sec  % 10 + '0';
        sec /= 10;
    }
	CountDown(arr1);
    
	}
  } 
}  
