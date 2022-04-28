#include "LCD.h"


/******* Pins Connection ******
RS = PD0
RW = PD1
EN = PD2

D7 = PA7	|	D3 = PA3
D6 = PA6	|	D2 = PA2
D5 = PA5	|	D1 = PD6
D4 = PA4	|	D0 = PD7
*******************************/

//Initialization Function
void LCD_Init(void)
{
	// Direction of datapins and config pins ? Output pins
	GPIO_PORTA_DIR_R |= 0xFC; 			//1111 1100
	GPIO_PORTD_DIR_R |= 0xC7;				//1100 0111
	
	// Digitalise the datapins and config pins
	GPIO_PORTA_DEN_R |= 0xFC; 			//1111 1100
	GPIO_PORTD_DEN_R |= 0xC7;				//1100 0111
	
	//Commands
	LCD_Command(Two_Line_LCD_8bit_Mode);
	LCD_Command(Increment_Cursor);
	LCD_Command(DisplayOn_CursourOff);
	LCD_Command(Clear_Display);
}

//Commands Function
void LCD_Command(unsigned char cmd)
{
	Give_Data_to_LCD(cmd); 						 //Pass the 8-bit data to the LCD pins
	GPIO_PORTD_DATA_R &= ~(1<<1);  //Make RW = 0 to enable write operation
	GPIO_PORTD_DATA_R &= ~(1<<0);   //RS = 0 to write data intruction register
	GPIO_PORTD_DATA_R |= (1<<2);	 //E = 1 turn on enable of LCD
	SysTick_wait10ms(1);					 //delay
	GPIO_PORTD_DATA_R &= ~(1<<2);	 //E = 0 turn off enable of LCD
}

//Display Character Function
void LCD_displayCharacter(unsigned char data)
{
	Give_Data_to_LCD(data); 						 //Pass the 8-bit data to the LCD pins
	GPIO_PORTD_DATA_R &= ~(1<<1);  //Make RW = 0 to enable write operation
	GPIO_PORTD_DATA_R |= (1<<0);   //RS = 1 to write data on Data reister of LCD
	GPIO_PORTD_DATA_R |= (1<<2);	 //E = 1 turn on enable of LCD
	SysTick_wait10ms(1);					 //delay
	GPIO_PORTD_DATA_R &= ~(1<<2);	 //E = 0 turn off enable of LCD
}

//Print CHaracter Function
void LCD_displayString(char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

void Give_Data_to_LCD(unsigned char data)
{
	//seventh bit = D7 = PA7
	if((data&0x80) == 0x80) {GPIO_PORTA_DATA_R |= (1<<7); }
	else										{GPIO_PORTA_DATA_R &= ~(1<<7);}
	//sixth bit = D6 = PA6
	if((data&0x40) == 0x40) {GPIO_PORTA_DATA_R |= (1<<6); }
	else										{GPIO_PORTA_DATA_R &= ~(1<<6);}
	//fifth bit = D5 = PA5
	if((data&0x20) == 0x20) {GPIO_PORTA_DATA_R |= (1<<5); }
	else										{GPIO_PORTA_DATA_R &= ~(1<<5);}
	//fourth bit = D4 = PA4
	if((data&0x10) == 0x10) {GPIO_PORTA_DATA_R |= (1<<4); }
	else										{GPIO_PORTA_DATA_R &= ~(1<<4);}
	//third bit = D3 = PA3
	if((data&0x08) == 0x08) {GPIO_PORTA_DATA_R |= (1<<3); }
	else										{GPIO_PORTA_DATA_R &= ~(1<<3);}
	//second bit = D2 = PA2
	if((data&0x04) == 0x04) {GPIO_PORTA_DATA_R |= (1<<2); }
	else										{GPIO_PORTA_DATA_R &= ~(1<<2);}
	//first bit = D1 = PD6
	if((data&0x02) == 0x02) {GPIO_PORTD_DATA_R |= (1<<6); }
	else										{GPIO_PORTD_DATA_R &= ~(1<<6);}
	//zero bit = D0 = PD7
	if((data&0x01) == 0x01) {GPIO_PORTD_DATA_R |= (1<<7); }
	else										{GPIO_PORTD_DATA_R &= ~(1<<7);}	
}

void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
	uint8_t Address;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0x80+Address */
	LCD_Command(Address | Set_Cursour_Location); 
}

//Function that counts down from 59 till 0
void CountDown_59to0 (void)
{
	uint8_t count = 59;
	
	while(count)
	{
		LCD_displayCharacter(count);
		SysTick_wait10ms(100);  //10ms x 100 = 1second
	}
}
