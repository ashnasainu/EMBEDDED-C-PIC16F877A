#include <xc.h>
#include "SPI.h"
//#include "LCD.h"
#include "UART.h"
#define _XTAL_FREQ 20000000

void main(void)
{
    UART_init();     // Initialize UART
    write_string("UART Initialized\r\n");
   
    
    TRISCbits.TRISC3 = 0;   // SERIAL CLOCK AS OUTPUT
    TRISCbits.TRISC4 = 1;   // MISO AS INPUT
    TRISCbits.TRISC5 = 0;   // MOSI AS OUTPUT
    TRISBbits.TRISB0 = 0;   // SLAVE SELECT PIN AS OUTPUT
    write_string("PORTS setting\r\n");
    
    
    SPI_init();
    write_string("SPI initialised\r\n");
    __delay_ms(500);
    
    PORTBbits.RB0 = 0; // slave select low               // write enable sequence
    spi_write(0x06);
    PORTBbits.RB0 = 1; // slave select high
    write_string("Write enabled\r\n");
    __delay_ms(500);
    
    write_to_25AA106A(0x03,0x43,0x09);                  // write function for writing 0x09 (msb of 16 bit address=0x03 , lsb = 0x43)       
    write_string("Write function performed\r\n");
    __delay_ms(500);
    
    PORTBbits.RB0 = 0; // slave select low                // write disable sequence
    spi_write(0x04);
    PORTBbits.RB0 = 1; // slave select high
    write_string("Write disabled\r\n");
    __delay_ms(500);
    
    while(1)
    {
       
        read_from_25AA160A(0x03,0x43);
        write_string("Read function performed\r\n");
        __delay_ms(1000);
    }

    return;
}
