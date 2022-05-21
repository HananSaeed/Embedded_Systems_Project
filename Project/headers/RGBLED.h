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
void RGB_Output(unsigned char led)
{
	//1. make all data on led is 0, resetting
	GPIO_PORTF_DATA_R &= ~0x0E;
	//set new data
	GPIO_PORTF_DATA_R |= led;
}

//for blinking, while(1){
//	GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E; 
//	time(1);
