	void D()
	{
	  char arr1[4] = {'0','0' ,'0' ,'0' };
    int sec,index = 4;
		char x=0;
	  char arr[6] = { '0','0',':','0','0','\0' };

		LCD_displayCharacter('D');
		time(2);
		LCD_Command(Clear_Display);
			
		LCD_displayString("Cooking Time?");
		time(2);
		LCD_Command(Clear_Display);
		
	
	do {
		
   	x = keypad_getkey();
		if(x != 0){
	LCD_Command(Clear_Display);
	
		  arr[0]=arr[1];
			arr[1]=arr[3];
			arr[3]=arr[4];
			arr[4]=x;
	LCD_displayString(arr);
	
		}
		FallingEdges =2;
    }while (GPIO_PORTF_DATA_R != 0x10);
		time(2);
		LCD_Command(Clear_Display);
		FallingEdges =0;
//		for ( n = 4 - n; n > 0;n--) { 
//		char temp = arr[3];
//	   	for (i = 3; i > 0; i--){
//			arr[i] = arr[i - 1];
//	  	}
//		arr[0] = temp;
//  	}
	 sec = ((arr[0]-'0') * 10 +(arr[1]-'0')) * 60 + ((arr[3]-'0') * 10 + (arr[4]-'0'));
	

	while (sec) {
        arr1[--index] = sec  % 10 + '0';
        sec /= 10;
    }
	CountDown(arr1);
    
	}
  	void blink(){
	for(a=6;a>0;a--){
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R ^ 0x08;
			time(1);
		}	
	
				GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
	
	}
