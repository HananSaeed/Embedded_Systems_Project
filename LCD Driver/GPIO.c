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



