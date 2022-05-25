void B() {
		 int index = 4;
			int Weight =0;
			int x=0;
		  char Data[]= {'0','\0'}; 
      char TimeCounted[4] = { '0','0' ,'0' ,'0' };
			  	   i=0;
	
				LCD_displayCharacter('B');
			  time(2);
				
			
			 LCD_Command(Clear_Display);
			
	 do{
  	 
		 LCD_displayString("Beef weight?");
			time(2);
			LCD_Command(Clear_Display); 
		 
		 while(SW_Input()!=0x10){
   	x = keypad_getkey();
		if(x != 0){
		Data[i]=x;
		LCD_displayCharacter(Data[i]);
		i++;
		}
	}
	
		 i=0;
		if((Data[1] !='\0')||(Data[0]!=0)) 
			{
    LCD_Command(Clear_Display);
		LCD_displayString("Err");
		time(2);
		LCD_Command(Clear_Display);
    Data[1] = '\0';				
		}
			else
				break;
   
	time(2);

	}while(1);
    Weight = (Data[0]-'0');
    Weight = Weight*30;    
	while (Weight) {
        TimeCounted[--index] = Weight  % 10 + '0';
        Weight /= 10;
    }
  
	  LCD_Command(Clear_Display); 
		time(1);
InterruptStates = Counter;
		CountDown(TimeCounted);
	}
	void C() {
		 int index = 4;
			int Weight =0;
  	  int i=0;
			int x=0;
		  char Data[]= {'0','\0'}; 
			char TimeCounted[4] = { '0','0' ,'0' ,'0' };

				LCD_displayCharacter('C');
			  time(2);

			 LCD_Command(Clear_Display);
			
	 do{
  	 
		 LCD_displayString("Chicken weight?");
			time(2);
			LCD_Command(Clear_Display); 
		 
		 while(SW_Input()!=0x10){
   	x = keypad_getkey();
		if(x != 0){
		Data[i]=x;
		LCD_displayCharacter(Data[i]);
		i++;
		}
	}
	
		 i=0;
		if(Data[1] !='\0'&&Data[0]!=0) 
			{
    LCD_Command(Clear_Display);
		LCD_displayString("Err");
		time(2);
		LCD_Command(Clear_Display);
    Data[1] = '\0';				
		}
			else
				break;
   
	time(2);

	}while(1);
       Weight = (Data[0]-'0');
    Weight = Weight*12;    
	while (Weight) {
        TimeCounted[--index] = Weight  % 10 + '0';
        Weight /= 10;
    
    }
  
	  LCD_Command(Clear_Display); 
		time(1);
	InterruptStates = Counter;
		CountDown(TimeCounted);

}
