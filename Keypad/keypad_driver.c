#include "keypad_driver.h"
#include "tm4c123.h"
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
  GPIO_PORTB_DATA_R = 0;
  col = GPIO_PORTC_DATA_R & 0xF0;
  if(col == 0xF0)
    return 0;
  
  while(1)
  {
    row = 0;
    GPIO_PORTB_DATA_R = 0x0E; //row 0
    SysTick_waituS(2);
    col = GPIO_PORTC_DATA_R & 0xF0;
    if(col != 0xF0)
      break;
    
    row = 1;
    GPIO_PORTB_DATA_R = 0x0D; //row 1
     SysTick_waituS(2);
    col = GPIO_PORTC_DATA_R & 0xF0;
    if(col != 0xF0)
      break;
    
    row = 2;
    GPIO_PORTB_DATA_R = 0x0B; //row 2
    SysTick_waituS(2);
    col = GPIO_PORTC_DATA_R & 0xF0;
    if(col != 0xF0)
      break;
    
    row = 3;
    GPIO_PORTB_DATA_R = 0x07; //row 3
    SysTick_waituS(2);
    col = GPIO_PORTC_DATA_R & 0xF0;
    if(col != 0xF0)
      break;
    
    return 0;
  }
  
  if(col == 0xE0)
    return keymap[row][0]; //col 0
  if(col == 0xD0)
    return keymap[row][1]; //col 1
  if(col == 0xB0)
    return keymap[row][2]; //col 2
  if(col == 0x70)
    return keymap[row][3]; //col 3
  
  return 0;
}

unsigned char keypad_getchar(void)
{
   unsigned char key;
   do{
      while(keypad_getkey() != 0);
      SysTick_wait10ms(2);
    }while(keypad_getkey() != 0);
    
    do{
      key = keypad_getkey();
      SysTick_wait10ms(2);
    }while(keypad_getkey() != key); 
   

   
    return key;
}