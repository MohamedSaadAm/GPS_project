void initportF()
{

  SYSCTL_RCGCGPIO_R |= 0x20;   
  while ((SYSCTL_PRGPIO_R & 0x20)==0);   
	GPIO_PORTF_AMSEL_R &= ~(0x02);
	GPIO_PORTF_AFSEL_R &= ~(0x02);
	GPIO_PORTF_PCTL_R &= ~(0x02);
	GPIO_PORTF_DIR_R |= 0x02;          
	GPIO_PORTF_DEN_R |= 0x02;
}
void turn_led_on(){
	  GPIO_PORTF_DATA_R |= (0x02);
}
