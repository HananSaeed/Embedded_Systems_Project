#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "LCD.h"
enum InterruptStates{Counter, ClearLCD, ReturnMain};
void EnableInterrupts(void);
void WaitForInterrupt(void);
void RGB_Output(unsigned char led);
volatile unsigned long FallingEdges = 0;
volatile unsigned long counter =0;
void EdgeCounter_Init1(void){
FallingEdges = 0;
GPIO_PORTF_LOCK_R = 0X4C4F434B;
GPIO_PORTF_CR_R |= 0x01;
GPIO_PORTF_AMSEL_R &= ~0x01;
GPIO_PORTF_PCTL_R &= ~0x0000000F;
GPIO_PORTF_AFSEL_R &=~0x01;
GPIO_PORTF_DIR_R &= ~0x01;
GPIO_PORTF_DEN_R |= 0x01;
GPIO_PORTF_PUR_R |= 0x01;
GPIO_PORTF_IS_R &= ~0x01; //edge senstive
GPIO_PORTF_IBE_R &= ~0x01;//is single edge
GPIO_PORTF_IEV_R &= ~0x01;//falling edge
GPIO_PORTF_ICR_R = 0x01; //clear flag
GPIO_PORTF_IM_R |= 0x01;//arm interrupt on PF4
//NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000;
NVIC_EN0_R = 0x40000000;
EnableInterrupts();//clear the I bit
}

void EdgeCounter_Init2(void){

SYSCTL_RCGC2_R |= 0x00000020; //activate port F
FallingEdges = 0;
GPIO_PORTF_LOCK_R = 0X4C4F434B;
GPIO_PORTF_CR_R |= 0x10;
GPIO_PORTF_AMSEL_R &= ~0x10;
GPIO_PORTF_PCTL_R &= ~0x000F0000;
GPIO_PORTF_AFSEL_R &=~0x10;
GPIO_PORTF_DIR_R &= ~0x10;
GPIO_PORTF_DEN_R |= 0x10;
GPIO_PORTF_PUR_R |= 0x10;
GPIO_PORTF_IS_R &= ~0x10; //edge senstive
GPIO_PORTF_IBE_R &= ~0x10;//is single edge
GPIO_PORTF_IEV_R &= ~0x10;//falling edge
GPIO_PORTF_ICR_R = 0x10; //clear flag
GPIO_PORTF_IM_R |= 0x10;//arm interrupt on PF4
//NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000;
NVIC_EN0_R = 0x40000000;
EnableInterrupts();//clear the I bit
}
void RGBLED_Init(){
		SYSCTL_RCGCGPIO_R |=0X20;
		while ((SYSCTL_PRGPIO_R & 0x20) == 0){}
		GPIO_PORTF_LOCK_R = 0X4C4F434B;
		GPIO_PORTF_CR_R |= 0x0E;
    GPIO_PORTF_AMSEL_R &= ~0x0E;		
		GPIO_PORTF_PCTL_R &= ~0x000FFF0;
		GPIO_PORTF_AFSEL_R &=~0x0E;
		GPIO_PORTF_DIR_R |= 0x0E;
		GPIO_PORTF_DEN_R |=0x0E;
		GPIO_PORTF_DATA_R &= ~0x0E;
		}
void RGB_Output(unsigned char led){
GPIO_PORTF_DATA_R &= ~0x0E;
GPIO_PORTF_DATA_R |= led;

}


void GPIOF_Handler(void)
{
  GPIO_PORTF_ICR_R = 0x01;
  counter = 0x00;
if((GPIO_PORTF_MIS_R & 0x10) && counter ==0x00){

GPIO_PORTF_ICR_R = 0x10; // acknowledge flag4
	Delay_ms(100);
counter = counter + 1;

while(1){

if((GPIO_PORTF_MIS_R & 0x10)&& counter == 0x01) // SW1 pressed for second time (clear)
{
	GPIO_PORTF_ICR_R = 0x10;
	LCD_Command(Clear_Display);  
        EdgeCounter_Init2(); 
        EdgeCounter_Init1();	
         break;
}
if (GPIO_PORTF_MIS_R & 0x01 && counter == 0x01) //SW2
{
GPIO_PORTF_ICR_R = 0x01;
break;
}

}
}
}
/*void GPIOF_Handler(void)
{

 if((GPIO_PORTF_MIS_R & 0x10) && InterruptStates ==Counter){
	 time(1);
   if((GPIO_PORTF_DATA_R & 0x11)==0x01){
	    RGB_Output(0x00);
	    LCD_Command(Clear_Display);	
	    GPIO_PORTF_ICR_R = 0x10;
      Delay_ms(100);		 
    	EdgeCounter_Init1();
		  
    	main();
		
				}
    if ((GPIO_PORTF_MIS_R & 0x11) ==0x11 ){
       
       GPIO_PORTF_ICR_R = 0x11;
       Delay_ms(100);

        }

   }

else if((GPIO_PORTF_MIS_R & 0x10) && InterruptStates == ClearLCD){
	InterruptStates =ReturnMain;
	LCD_Command(Clear_Display);
	GPIO_PORTF_ICR_R = 0x10; 

}
else if((GPIO_PORTF_MIS_R & 0x10)){GPIO_PORTF_ICR_R = 0x10; }
if(GPIO_PORTF_MIS_R & 0x01){GPIO_PORTF_ICR_R = 0x01;}

}*/
