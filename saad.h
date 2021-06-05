#include "tm4c123gh6pm.h"

	
void dispaly_digit_3(int e){
	switch (e){
		case 0:
		 GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTA_DATA_R |= 0x1C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 1:
		 GPIO_PORTA_DATA_R &= ~ 0x24;
		  GPIO_PORTA_DATA_R |= 0x18;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 2:
		  GPIO_PORTA_DATA_R |= 0x2C;
		  GPIO_PORTA_DATA_R &= ~ 0x10;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 3:
		 GPIO_PORTA_DATA_R |= 0x3C;
		  GPIO_PORTB_DATA_R |= 0x23;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
		case 4:
		 GPIO_PORTA_DATA_R |= 0x38;
		  GPIO_PORTA_DATA_R &= ~ 0x04;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 5:
		 GPIO_PORTA_DATA_R |= 0x34;
		  GPIO_PORTB_DATA_R &= ~ 0x08;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
		case 6:
		 GPIO_PORTA_DATA_R |= 0x30;
		  GPIO_PORTB_DATA_R &= ~ 0x0C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 7:
		 GPIO_PORTA_DATA_R |= 0x1C;
		  GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 8:
		  GPIO_PORTA_DATA_R |= 0x3C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 9:
		  GPIO_PORTA_DATA_R |= 0x3C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
	}
}

void dispaly_digit_2(int w){
	switch (w){
		case 0:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0F;
		  break;
		case 1:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0x80;
		  GPIO_PORTA_DATA_R &= ~ 0x40;
		  GPIO_PORTD_DATA_R |= 0x01;
		  GPIO_PORTD_DATA_R &= ~ 0x0E;
		  break;
		case 2:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x06;
		  GPIO_PORTD_DATA_R &= ~ 0x09;
		  break;
		case 3:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x03;
		  GPIO_PORTD_DATA_R &= ~ 0x0C;
		  break;
		case 4:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0x80;
		  GPIO_PORTA_DATA_R &= ~ 0x40;
		  GPIO_PORTD_DATA_R |= 0x09;
		  GPIO_PORTD_DATA_R &= ~ 0x06;
		  break;
		case 5:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0x40;
		  GPIO_PORTA_DATA_R &= ~ 0x80;
		  GPIO_PORTD_DATA_R |= 0x0B;
		  GPIO_PORTD_DATA_R &= ~ 0x04;
		  break;
		case 6:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R &= ~ 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0F;
		  break;
		case 7:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x01;
		  GPIO_PORTD_DATA_R &= ~ 0x0E;
		  break;
		case 8:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0F;
		  break;
		case 9:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0B;
		  GPIO_PORTD_DATA_R &= ~ 0x04;
		  break;
	}
}

void dispaly_digit_1(int q){
	switch (q){
		case 0:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0C;
		  GPIO_PORTE_DATA_R &= ~ 0x01;
		  break;
		case 1:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |= 0x08;
		  GPIO_PORTE_DATA_R &= ~ 0x05;
		  break;
		case 2:
			GPIO_PORTB_DATA_R &= ~ 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0D;
			break;
		case 3:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |= 0x0D;
			break;
		case 4:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |= 0x09;
		  GPIO_PORTE_DATA_R &= ~ 0x04;
		  break;
		case 5:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |= 0x05;
		  GPIO_PORTE_DATA_R &= ~ 0x08;
		  break;
		case 6:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x01;
		  GPIO_PORTE_DATA_R &= ~ 0x0C;
		  break;
		case 7:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0C;
			GPIO_PORTE_DATA_R &= ~ 0x01;
		  break;
		case 8:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0D;
		  break;
		case 9:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |= 0x0D;
		  break;
	}
}


void print_distance(int x){
	int q, w, e;
	
	e = x/100;
	w = (x-e*100)/10;
	q = (x-e*100-w*10);
	
	dispaly_digit_1( q );
	dispaly_digit_2( w );
	dispaly_digit_3( e );

}
