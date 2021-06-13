#include "tm4c123gh6pm.h"

void initportF()
{

  SYSCTL_RCGCGPIO_R |= 0x20;   
  while ((SYSCTL_PRGPIO_R & 0x20)==0);   
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R|= 0x0E;
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_AFSEL_R &= ~0x0E;
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	GPIO_PORTF_DIR_R |= 0x0E;          
	GPIO_PORTF_DEN_R |= 0x0E;
}
void turn_led_Red(){
	  GPIO_PORTF_DATA_R |= (0x02);
}
void turn_led_Green(){
	  GPIO_PORTF_DATA_R |= (0x04);
}
void turn_led_blue(){
	  GPIO_PORTF_DATA_R |= (0x08);
}
