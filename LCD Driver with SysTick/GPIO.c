#include "GPIO.h"


void PORT_Init(void)
{
	/* P7	 P6	 P5	 P4	 P3	 P2	 P1	 P0
		 0   0   0   0   0   0   0   0*/	
	//1. Activate clock for used PORT -> A,B,D,E
	SYSCTL_RCGCGPIO_R |= 0x1B;				   // 0001 1011
	while ((SYSCTL_PRGPIO_R & 0x1B)==0); //delay
	
	//PORT A initialization	-> PA7, PA6, PA5
	//1. Unlock pins for this port
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	//2. disable analog function on the required pins
	GPIO_PORTA_AMSEL_R &= ~0xE0;
	GPIO_PORTA_CR_R |= 0xE0; //Enable Change register
	//3. Disable alternate function for used pins
	GPIO_PORTA_AFSEL_R &= ~0xE0;
	//4. Clear PCTL register to use as GPIO
	GPIO_PORTA_PCTL_R &= ~0xFFF00000;
	
	//PORT B initialization
	//1. Unlock pins for this port
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	//2. disable analog function on the required pins
	GPIO_PORTB_AMSEL_R &= ~0x0E;
	GPIO_PORTB_CR_R |= 0x0E; //Enable Change register
	//3. Disable alternate function for used pins
	GPIO_PORTB_AFSEL_R &= ~0x0E;
	//4. Clear PCTL register to use as GPIO
	GPIO_PORTB_PCTL_R &= ~0x00010011;
	
	//PORT D initialization
	//1. Unlock pins for this port
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	//2. disable analog function on the required pins
	GPIO_PORTD_AMSEL_R &= ~0x0E;
	GPIO_PORTD_CR_R |= 0x0E; //Enable Change register
	//3. Disable alternate function for used pins
	GPIO_PORTD_AFSEL_R &= ~0x0E;
	//4. Clear PCTL register to use as GPIO
	GPIO_PORTD_PCTL_R &= ~0x00000111;
	
	//PORT E initialization
	//1. Unlock pins for this port
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	//2. disable analog function on the required pins
	GPIO_PORTE_AMSEL_R &= ~0x0E;
	GPIO_PORTE_CR_R |= 0x0E; //Enable Change register
	//3. Disable alternate function for used pins
	GPIO_PORTE_AFSEL_R &= ~0x0E;
	//4. Clear PCTL register to use as GPIO
	GPIO_PORTE_PCTL_R &= ~0x00110000;
	
}



