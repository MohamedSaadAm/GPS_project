#include “Headers/tm4c123gh6pm.h”

//UART Initialization
Void initUART (void)
{

SYSCTL_RCGCUART_R |= 0x02;     //Enable clock for UART
SYSCTL_RCGCGPIO_R |= 0x02;     //Activate clock for port B
While ((SYSCTL_PRGPIO_R & 0x02) == 0) {};

//Assumes a 16 MHz bus clock, creates 9600 baud rate
UART1_CTL_R &= ~0x00000001; //Disable UART
UART1_IBRD_R = 104;    //IBRD = int (16,000,000/(16*9600)) = 104.1666667
UART1_FBRD_R = 11;     //FBRD = factional ((0.1666667 * 64)+0.5) = 11.16688
UART1_LCRH_R = 0x00000070;      //8 bit, no parity bits, one stop, FIFOs (0b1110000 = 0x70)
UART1_CTL_R = 0x0301;           //Enable RXE, TXE and UART

GPIO_PORTB_AMSEL_R &= ~0x03;    //Disable analog in port B0,B1
GPIO_PORTB_PCTL_R |= 0x00000011;    //PB0 and PB1 configure for UART module
GPIO_PORTB_DIR_R |= 0x02;       //Rx PBo (input) Tx PB1 (output)
GPIO_PORTB_AFSEL_R |= 0x03;     //Use PB0,PB1 alternate function
GPIO_PORTB_DEN_R |= 0x03;      //Enable digital in port B0,B1

}

//UART Input (Char)
//Wait for new input, then return ASCII code
Char readUART (void)
{
 While((UART1_FR_R & 0x0010) != 0 );     //Wait till RXFE is 0
 Return((char)(UART1_DR_R & 0xFF));
}

//UART Output (Char)
//Wait for buffer to be not full, then output
Void writeUART (char data)
{
 While((UART1_FR_R & 0x0020) != 0);     //Wait till TXFF is 0
 UART1_DR_R = data;
}
