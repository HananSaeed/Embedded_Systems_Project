void A(){
	char Seconds[] = "0059";
			LCD_displayCharacter('A');
			time(2);
			LCD_Command(Clear_Display);
			
			LCD_displayString("Popcorn");
			time(2);
		  while(SW_Input() != 0x10);
			LCD_Command(Clear_Display);
		InterruptStates = Counter;
	     CountDown(Seconds);
			LCD_Command(Clear_Display);
		

}
