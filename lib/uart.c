#include <xc.h>
#include "uart.h"

#define _XTAL_FREQ 8000000      // Oszillatorfrequenz PBA6: 8MHz (ohne PLL) // for delay

void uart_init(void)
{
    TXSEL = 0; // RC6
    RXSEL = 0; // RC7
    
    TXSTAbits.BRGH = 1;     // High Baud Rate Select bit: High-Speed
    TXSTAbits.SYNC = 0;     // asynchronous mode
    TXSTAbits.TXEN = 1;     // Enable EUSART Modul
    
    RCSTAbits.SPEN = 1;
    RCSTAbits.CREN = 1;
    
    SPBRGL = 51;            // Setting Baudrate: 9600Bd
}

void uart_send(unsigned char byte)
{
    // *** Wait for transmission complete ***
    while(!TRMT);
    // *** Zeichen senden ***
    TXREG = byte;
}

void putch(unsigned char byte)
{
    uart_send(byte);
    __delay_ms(5);
}
