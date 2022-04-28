#include "SysTick.h"

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFF;  			// maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
  NVIC_ST_CTRL_R = 0x00000005;					// enable SysTick with core clock
  
}

// The delay parapmeter in units of 80 MHz 12.5ns
void SysTick_wait(unsigned long delay){
	NVIC_ST_RELOAD_R = delay - 1; 	// number of counts
	NVIC_ST_CURRENT_R = 0;					// clear any  value in current
	while((NVIC_ST_CTRL_R & 0x00010000) == 0){}
	// we wait until the flag is set to one which means that counting is over
}

//Call this routine to wait for delay*10ms
void SysTick_wait10ms(unsigned long delay){
	unsigned long i;
	for(i=0; i<delay; i++)
	{
		SysTick_wait(800000); //wait 10ms as 12.5ns*800000 = 10ms
	}
}

