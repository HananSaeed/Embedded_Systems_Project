#include "GPIO.h"


void PORT_Init(void)
{
	/* P7	 P6	 P5	 P4	 P3	 P2	 P1	 P0
		 0   0   0   0   0   0   0   0*/	
	//1. Activate clock for used PORT -> A,D
	SYSCTL_RCGCGPIO_R |= 0x09;				   // 0000 1001
	while ((SYSCTL_PRGPIO_R & 0x09)==0); //delay
	
	//PORT A initialization	-> PA7 to PA2
	//1. Unlock pins for this port
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	//2. disable analog function on the required pins
	GPIO_PORTA_AMSEL_R &= ~0xFC;
	GPIO_PORTA_CR_R |= 0xFC; //Enable Change register
	//3. Disable alternate function for used pins
	GPIO_PORTA_AFSEL_R &= ~0xFC;
	//4. Clear PCTL register to use as GPIO
	GPIO_PORTA_PCTL_R &= ~0x000000FF;
	
	
	//PORT D initialization
	//1. Unlock pins for this port
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	//2. disable analog function on the required pins PD7,6,2,1,0
	GPIO_PORTD_AMSEL_R &= ~0xC7;
	GPIO_PORTD_CR_R |= 0xC7; //Enable Change register
	//3. Disable alternate function for used pins
	GPIO_PORTD_AFSEL_R &= ~0xC7;
	//4. Clear PCTL register to use as GPIO
	GPIO_PORTD_PCTL_R &= ~0x00FFF00F;
	
	
}

void SW3_init(void)
{
	/*PF7	PF6	PF5	PF4	PF3	PF2	PF1	PF0
		 0   0   0   0   0   1   0   0*/
	
	//1. Activate clock for used PORT -> E
	SYSCTL_RCGCGPIO_R |= 0x10;
	while ((SYSCTL_PRGPIO_R & 0x10)==0); //delay
	//2. Unlock pins for this port
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	//3. disable analog function on the required port
	GPIO_PORTE_AMSEL_R &= ~0x04; //0001 0001
	GPIO_PORTE_CR_R |= 0x04; //Enable Change register
	//4. Disable alternate function for used pins
	GPIO_PORTE_AFSEL_R &= ~0x04;
	//5. Enable digital port DEN reg
	GPIO_PORTE_DEN_R |= 0x04;
	//6. Clear PCTL register to use as GPIO
	GPIO_PORTE_PCTL_R &= ~0x00000F00;
	//7. Initialize DIR register (0 -> Input)
	GPIO_PORTE_DIR_R &= ~0x04;
	//8. Enable PUllup register
	GPIO_PORTE_PUR_R |= 0x04;
}
