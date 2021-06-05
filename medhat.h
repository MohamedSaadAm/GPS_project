void initportA(){
	SYSCTL_RCGCGPIO_R |= 0x01;          
	while ((SYSCTL_PRGPIO_R & 0x01)==0);
	GPIO_PORTA_DIR_R |= 0xFC;
	GPIO_PORTA_DEN_R |= 0xFC;
	GPIO_PORTA_AMSEL_R &= ~ 0xFC;
	GPIO_PORTA_AFSEL_R &= ~ 0xFC;
	GPIO_PORTA_PCTL_R &= ~ 0xFFFFFF00;  
	}
	void initportB(){
	SYSCTL_RCGCGPIO_R |= 0x02;        
	while ((SYSCTL_PRGPIO_R & 0x02)==0);  
	GPIO_PORTB_DIR_R |= 0x1C; 
	GPIO_PORTB_DEN_R |= 0x1C;
	GPIO_PORTB_AMSEL_R &= ~ 0x1C; 
	GPIO_PORTB_AFSEL_R &= ~ 0x1C;
	GPIO_PORTB_PCTL_R &= ~ 0x001FFF00;   
	}
	void initportD(){
	SYSCTL_RCGCGPIO_R |= 0x08;          
	while ((SYSCTL_PRGPIO_R & 0x08)==0); 
	GPIO_PORTD_LOCK_R = 0x4C4F434B;    
	GPIO_PORTD_CR_R |= 0x80;
	GPIO_PORTD_DIR_R |= 0xCF;
	GPIO_PORTD_DEN_R |= 0xCF;
	GPIO_PORTD_AMSEL_R &= ~ 0xCF;  
	GPIO_PORTD_AFSEL_R &= ~ 0xCF;
	GPIO_PORTD_PCTL_R &= ~ 0xFF00FFFF;   
	}
	void initportE(){
	SYSCTL_RCGCGPIO_R |= 0x10;        
	while ((SYSCTL_PRGPIO_R & 0x10)==0); 
	GPIO_PORTE_DIR_R |= 0x3F;
	GPIO_PORTE_DEN_R |= 0x3F;            
	GPIO_PORTE_AMSEL_R &= ~ 0x3F;  
	GPIO_PORTE_AFSEL_R &= ~ 0x3F;  
	GPIO_PORTE_PCTL_R &= ~ 0x00FFFFFF;
	}
