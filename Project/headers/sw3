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
	GPIO_PORTE_IS_R |= 0x04;
	GPIO_PORTE_IEV_R &= ~0x04;
	GPIO_PORTE_ICR_R &= ~0x04;
	GPIO_PORTE_IBE_R &= 0x00;
	GPIO_PORTE_IM_R |= 0x04;
  NVIC_EN0_R = 0x10;
	EnableInterrupts();

}
