void D()
	{
    char TimeCounted[4] = {'0','0' ,'0' ,'0' };
    int sec,index = 4;
		char x=0;
	  char Data[6] = { '0','0',':','0','0','\0' };

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
	
		  Data[0]=Data[1];
			Data[1]=Data[3];
			Data[3]=Data[4];
			Data[4]=x;
	LCD_displayString(Data);
	if(InterruptStates ==ReturnMain) main();
		}
		InterruptStates = ClearLCD;
    }while (GPIO_PORTF_DATA_R != 0x10);
		time(2);
		LCD_Command(Clear_Display);

    InterruptStates = Counter;
	 sec = ((Data[0]-'0') * 10 +(Data[1]-'0')) * 60 + ((Data[3]-'0') * 10 + (Data[4]-'0'));
	

	while (sec) {
        TimeCounted[--index] = sec  % 10 + '0';
        sec /= 10;
    }
	CountDown(TimeCounted);
    
	}
  	void blink(){
	for(RGBCounter=6 ; RGBCounter>0 ; RGBCounter--){
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R ^ 0x08;
			time(1);
		}	
	
				GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
	
	}
