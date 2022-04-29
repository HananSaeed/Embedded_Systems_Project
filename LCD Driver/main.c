#include "tm4c123.h"
#include "LCD.h"
#include "GPIO.h"
#include "SysTick.h"

//Function prototypes
void SW1_SW2_init(void);
void RGB_Init(void);
unsigned char SW_Input(void);
void RGB_Output(unsigned char data);	
	


//Main Function
int main()
{
	SW1_SW2_init();
	RGB_Init();
	RGB_Output(0x00);
	SysTick_Init();
	PORT_Init();
	LCD_Init();

	
	while(1)
	{
		// red is 0000 0010
		// blue is 0000 0100
		//green is 0000 1000
		
		if(SW_Input() == 0x00 )
		{
			RGB_Output(0x02);
			LCD_displayString("59");
		}
		else if(SW_Input() == 0x10 )
		{
			RGB_Output(0x08);
			LCD_displayString("59");
			
		}
		else if(SW_Input() == 0x01 )
		{
			RGB_Output(0x04);
			LCD_displayString("59");
			
		}
		else
		{
			RGB_Output(0x00);
			
		}
	}
}



//Functions
void SW1_SW2_init (void)
{
	/*PF7	PF6	PF5	PF4	PF3	PF2	PF1	PF0
		 0   0   0   1   0   0   0   1*/
	
	//1. Activate clock for used PORT -> F
	SYSCTL_RCGCGPIO_R |= 0x20;
	while ((SYSCTL_PRGPIO_R & 0x20)==0); //delay
	//2. Unlock pins for this port
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	//3. disable analog function on the required port
	GPIO_PORTF_AMSEL_R &= ~0x11; //0001 0001
	GPIO_PORTF_CR_R |= 0x11; //Enable Change register
	//4. Disable alternate function for used pins
	GPIO_PORTF_AFSEL_R &= ~0x11;
	//5. Enable digital port DEN reg
	GPIO_PORTF_DEN_R |= 0x11;
	//6. Clear PCTL register to use as GPIO
	GPIO_PORTF_PCTL_R &= ~0x000F000F;
	//7. Initialize DIR register (0 -> Input)
	GPIO_PORTF_DIR_R &= ~0x11;
	//8. Enable PUllup register
	GPIO_PORTF_PUR_R |= 0x11;
}

void RGB_Init(void)
{
	//1. Activate clock for used PORT ?? F
	SYSCTL_RCGCGPIO_R |= 0x20;
	while ((SYSCTL_PRGPIO_R & 0x20)==0); //delay
	//2. Unlock pins for this port
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	//3. disable analog function on the required pins
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_CR_R |= 0x0E; //Enable Change register
	//4. Disable alternate function for used pins
	GPIO_PORTF_AFSEL_R &= ~0x0E;
	//5. Enable digital port DEN reg
	GPIO_PORTF_DEN_R |= 0x0E;
	//6. Clear PCTL register to use as GPIO
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	//7. Initialize DIR register (1 ?? OUTPUT)
	GPIO_PORTF_DIR_R |= 0x0E;
	//8.Initialize Data on ports
	GPIO_PORTF_DATA_R &= ~0x0E;

}

unsigned char SW_Input(void)
{
	return GPIO_PORTF_DATA_R & 0x11;
}

void RGB_Output(unsigned char data)
{
	//1. make all data on led is 0, resetting
	GPIO_PORTF_DATA_R &= ~0x0E;
	//set new data
	GPIO_PORTF_DATA_R |= data;
}
