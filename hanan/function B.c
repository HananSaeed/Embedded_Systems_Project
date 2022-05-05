else if (Key_Input == 'B') {
	int w =0;
	int i=0;
	int x=0;
  	char arr[2]; 
	char arr1[4] = { '0','0' ,'0' ,'0' };
	int index = 4;
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
	i=0;
w = (arr[0]-'0') * 10 +(arr[1]-'0');
	if ( w <=9)
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


	}	 while( w > 9);

    w = w*30;    
	while (w) {
        arr1[--index] = w  % 10 + '0';
        w /= 10;
    }

	CountDown(arr1);

}
