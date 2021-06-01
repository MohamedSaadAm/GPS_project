#include "tm4c123gh6pm.h"

void initportA(){
	SYSCTL_RCGCGPIO_R |= 0x01;          // active clock for port A
	while ((SYSCTL_PRGPIO_R&0x01)==0); // wait for satilization
	//GPIO_PORTA_CR_R |= 0xE0;            // allow changes to PA 5-7
	GPIO_PORTA_AMSEL_R &= ~ 0xE0;         // disable analog on port A
	GPIO_PORTA_PCTL_R &= ~ 0xFFF00000;    //PCTL GPIO on Port A
	GPIO_PORTA_DIR_R |= 0xE0;           // PA 5-7 out
	GPIO_PORTA_AFSEL_R &= ~ 0xE0;         // disable alt function on Port A 
	GPIO_PORTA_DEN_R |= 0xE0;           //enable digital i/o on PA 5-7
}
void initportB(){
	SYSCTL_RCGCGPIO_R |= 0x02;          // active clock for port B
	while ((SYSCTL_PRGPIO_R&0x02)==0); // wait for satilization
	//GPIO_PORTB_CR_R |= 0x3F;            // allow changes to PB 0-5
	GPIO_PORTB_AMSEL_R &= ~ 0x3F;         // disable analog on port B
	GPIO_PORTB_PCTL_R &= ~ 0x00FFFFFF;    //PCTL GPIO on Port B  
	GPIO_PORTB_DIR_R |= 0x3F;           // PB 0-5 out
	GPIO_PORTB_AFSEL_R &= ~ 0x3F;         // disable alt function on PB 0-5
	GPIO_PORTB_DEN_R |= 0x3F;           //enable digital i/o on PB 0-5
}
void initportD(){
	SYSCTL_RCGCGPIO_R |= 0x08;          // active clock for port D
	while ((SYSCTL_PRGPIO_R&0x08)==0); // wait for satilization
	GPIO_PORTD_LOCK_R = 0x4C4F434B;     // unlock GPIO Port D
	GPIO_PORTD_CR_R |= 0xCF;            // allow changes to PD 0-3 and 6-7
	GPIO_PORTD_AMSEL_R &= ~ 0xCF;         // disable analog on port D
	GPIO_PORTD_PCTL_R &= ~ 0xFF00FFFF;    //PCTL GPIO on Port D  
	GPIO_PORTD_DIR_R |= 0xCF;           // PD 0-3 and 6-7 out
	GPIO_PORTD_AFSEL_R &= ~ 0xCF;         // disable alt function on PD 7-0
	GPIO_PORTD_DEN_R |= 0xCF;           //enable digital i/o on PD 0-3 and 6-7 
	
}
void initportE(){
	SYSCTL_RCGCGPIO_R |= 0x10;          // active clock for port E
	while ((SYSCTL_PRGPIO_R&0x10)==0); // wait for satilization
	GPIO_PORTE_CR_R = 0x3F;            // allow changes to PE 0-5
	GPIO_PORTE_AMSEL_R &= ~ 0x00;         // disable analog on port E
	GPIO_PORTE_PCTL_R &= ~ 0x00FFFFFF;    //PCTL GPIO on Port B  
	GPIO_PORTE_DIR_R |= 0x3F;           // PE 0-5 out
	GPIO_PORTE_AFSEL_R &= ~ 0x3F;         // disable alt function on Port E 
	GPIO_PORTE_DEN_R |= 0x3F;           //enable digital i/o on PE 0-5
}
	
void initportF(){
	SYSCTL_RCGCGPIO_R |= 0x20;          // active clock for port F
	while ((SYSCTL_PRGPIO_R&0x20)==0){}; // wait for satilization
	GPIO_PORTF_LOCK_R = 0x4C4F434B ;    // unlock GPIO Port F
	GPIO_PORTF_CR_R |= 0x01;            // allow changes to P F1
	GPIO_PORTF_AMSEL_R |= 0x02;         // disable analog on port F1
	GPIO_PORTF_PCTL_R &= ~0x000000F0;    // PCTL GPIO on P F1
	GPIO_PORTF_DIR_R |= 0x02;           // Port F1 out
	GPIO_PORTF_AFSEL_R = 0x02;         // disable alt function on Port F
	GPIO_PORTF_DEN_R |= 0x02;           // enable digital i/o on P F1
	
}
void turn_led_on(){
	initportF();
	GPIO_PORTF_DATA_R |= 0x02;
}
void dispaly_digit_3(int e){
	switch (e){
		case 0:
			GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTB_DATA_R |= 0x33;
		  GPIO_PORTE_DATA_R |=0x30;
		  break;
		case 1:
			GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTB_DATA_R |= 0x03;
		  GPIO_PORTB_DATA_R &= ~ 0x30;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 2:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x21;
		  GPIO_PORTB_DATA_R &= ~ 0x12;
		  GPIO_PORTE_DATA_R |=0x30;
		  break;
		case 3:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x23;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R |=0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
		case 4:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x13;
		  GPIO_PORTB_DATA_R &= ~ 0x20;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 5:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x12;
		  GPIO_PORTB_DATA_R &= ~ 0x21;
		  GPIO_PORTE_DATA_R |=0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
		case 6:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x12;
		  GPIO_PORTB_DATA_R &= ~ 0x21;
		  GPIO_PORTE_DATA_R |=0x30;
		  break;
		case 7:
		  GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTB_DATA_R |= 0x23;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 8:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x33;
		  GPIO_PORTE_DATA_R |=0x30;
		  break;
		case 9:
			GPIO_PORTA_DATA_R |= 0x20;
		  GPIO_PORTB_DATA_R |= 0x33;
		  GPIO_PORTE_DATA_R |=0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
	}
}

void dispaly_digit_2(int w){
	switch (w){
		case 0:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |=0x0F;
		  break;
		case 1:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0x80;
		  GPIO_PORTA_DATA_R &= ~ 0x40;
		  GPIO_PORTD_DATA_R |=0x01;
		  GPIO_PORTD_DATA_R &= ~ 0x0E;
		  break;
		case 2:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |=0x06;
		  GPIO_PORTD_DATA_R &= ~ 0x09;
		  break;
		case 3:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |=0x03;
		  GPIO_PORTD_DATA_R &= ~ 0x0C;
		  break;
		case 4:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0x80;
		  GPIO_PORTA_DATA_R &= ~ 0x40;
		  GPIO_PORTD_DATA_R |=0x09;
		  GPIO_PORTD_DATA_R &= ~ 0x06;
		  break;
		case 5:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0x40;
		  GPIO_PORTA_DATA_R &= ~ 0x80;
		  GPIO_PORTD_DATA_R |=0x0B;
		  GPIO_PORTD_DATA_R &= ~ 0x04;
		  break;
		case 6:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R &= ~ 0xC0;
		  GPIO_PORTD_DATA_R |=0x0F;
		  break;
		case 7:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |=0x01;
		  GPIO_PORTD_DATA_R &= ~ 0x0E;
		  break;
		case 8:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |=0x0F;
		  break;
		case 9:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |=0x0B;
		  GPIO_PORTD_DATA_R &= ~ 0x04;
		  break;
	}
}

void dispaly_digit_1(int q){
	switch (q){
		case 0:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |=0x0C;
		  GPIO_PORTE_DATA_R &= ~ 0x01;
		  break;
		case 1:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |=0x08;
		  GPIO_PORTE_DATA_R &= ~ 0x05;
		  break;
		case 2:
			GPIO_PORTB_DATA_R &= ~ 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |=0x0D;
			break;
		case 3:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |=0x0D;
			break;
		case 4:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |=0x09;
		  GPIO_PORTE_DATA_R &= ~ 0x04;
		  break;
		case 5:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |=0x05;
		  GPIO_PORTE_DATA_R &= ~ 0x08;
		  break;
		case 6:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |=0x01;
		  GPIO_PORTE_DATA_R &= ~ 0x0C;
		  break;
		case 7:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |=0x04;
			GPIO_PORTE_DATA_R &= ~ 0x09;
		  break;
		case 8:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |=0x0D;
		  break;
		case 9:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |=0x0D;
		  break;
	}
}
