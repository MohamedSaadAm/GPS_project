#include "tm4c123gh6pm.h"

void initUART1 (void)
{
  
SYSCTL_RCGCUART_R |= 0x02 ;  
SYSCTL_RCGCGPIO_R |= 0x02 ;  
while ((SYSCTL_PRGPIO_R & 0x02) == 0){} ;  
  
// Assumes a 16 MHz bus clock, creates 9600 baud rate 
UART1_CTL_R &= ~0x00000001 ;    // disable UART 
UART1_IBRD_R = 104 ;    // IBRD = int (16,000,000/(16*9600)) = 104.1666667 
UART1_FBRD_R = 11 ;    // FBRD = factional ((0.1666667 * 64)+0.5) = 11.16688 
UART1_LCRH_R = 0x00000070 ;  // 8 bit, no parity bits, one stop, FIFOs   (0b1110000 = 0x70) 
UART1_CTL_R = 0x0301;   
  
 
GPIO_PORTB_AMSEL_R &= ~0x03;  
GPIO_PORTB_PCTL_R |= 0x00000011 ; 
GPIO_PORTB_DIR_R |= 0x02 ;    
GPIO_PORTB_AFSEL_R |= 0x03 ;    
GPIO_PORTB_DEN_R  |= 0x03 ;   
  
}

char readUART1 (void) {
  while((UART1_FR_R & 0x0010) != 0 ) ;      
  return((char)(UART1_DR_R)) ;
}
