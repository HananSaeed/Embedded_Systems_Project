#include "io.h"
#include "stdint.h"
#include "keypad.h"
#include "Systick.h"
void keypad_init(void)
{
  SYSCTL_RCGCGPIO_R |= 0x06; //GPIO C | GPIO B
  
  GPIO_PORTC_DEN_R |= 0xF0; 
  GPIO_PORTC_DIR_R &= ~0xF0; //pins 4->7 as input
  GPIO_PORTC_PUR_R |= 0xF0;
  
  GPIO_PORTB_DEN_R |= 0x0F;
  GPIO_PORTB_DIR_R |= 0x0F; //pins 0->3 as output
  
}

unsigned char keypad_getkey(void)
{
  const unsigned char keymap[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'},
  };
  
  int row,col;
	int i, check;
	int output_B[4] = {0x0E, 0x0D, 0x0B, 0x07};
	GPIO_PORTB_DATA_R = 0;//Enable all rows
	Delay_ms(150000); //Switch debouncing 
		switch (GPIO_PORTC_DATA_R & 0xF0){
	case 0xF0: return 0;
	case 0xE0: col=0; break; // key in column 0
	case 0xD0: col=1; break;// key in column 1
	case 0xB0: col=2; break;// key in column 2
	case 0x70: col=3; break;// key in column 3
		}

	for (i=0 ;i<4; i++)
	{
	GPIO_PORTB_DATA_R = output_B[i];
	Delay_ms(2000);                     // wait for signal to settle 
check = GPIO_PORTC_DATA_R & 0xF0;
if (check != 0xF0) break;
	}
	row = i;
	return keymap[row][col];
}
