#include "stdint.h"
#include "io.h"
#define RED 0x02
#define Blue 0x04
#define Green 0x08

void SW_Init(){
	 
	GPIO_PORTF_LOCK_R = 0X4C4F434B;
	GPIO_PORTF_CR_R |= 0x11;
  GPIO_PORTF_AMSEL_R &= ~0x11;		
	GPIO_PORTF_PCTL_R &= ~0x000F000F;
	GPIO_PORTF_AFSEL_R &=~0x11;
	GPIO_PORTF_DIR_R &= ~0x11;
	GPIO_PORTF_DEN_R |= 0x11;
	GPIO_PORTF_PUR_R |= 0x11;

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
unsigned char SW1_input(void){
return GPIO_PORTF_DATA_R & 0x11;
}
unsigned char button1=0;
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} //do nothing for 1 ms 
}
void RGP_out() //leds blink 3 times
{
	//RGBLED_Init();
	int i;
	for( i=3;i>0;i--){
	GPIO_PORTF_DATA_R |= 0x0E;
	delayMs(100); // 1 sec
	GPIO_PORTF_DATA_R &= ~0x0E;
	delayMs(100);		
	}
	
}
	int main(){
RGBLED_Init();
SW_Init();
		while(1){ 
button1 = SW1_input();

	
	 
    if(button1 == 0x00){
			 RGP_out();
			break;
		 }}
	}
	 

/*void cookingtime() {
	//LCD_out("“Cooking Time?”");
	int n = 0;
	char arr[4] = { '0','0','0','0' };
	while (n<4) {
		//arr[n] = keyPadin();
		//LCD_out(arr[n]);
		n++;
}
		for (int i = 4 - n; i > 0;i--) { //this part should be added to SW2 code
		char temp = arr[3];
		for (int i = 3; i > 0; i--){
			arr[i] = arr[i - 1];
	}
		arr[0] = temp;
	}
	int sec = ((arr[0]-'0') * 10 +(arr[1]-'0')) * 60 + ((arr[2]-'0') * 10 + (arr[3]-'0'));
	
	char arr1[4] = {'0','0' ,'0' ,'0' };
  int index = 4;
	while (sec) {

        arr1[--index] = sec  % 10 + '0';//3-->a[3] = '3' 8--> arr[2]='8' 

        sec /= 10;//8-0
    }
	countdown(arr1);
    
	}
	
 */

