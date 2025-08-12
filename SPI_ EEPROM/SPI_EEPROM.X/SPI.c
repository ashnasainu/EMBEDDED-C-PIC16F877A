#include <xc.h>
#include "SPI.h"

void SPI_init()
{
    SSPCON = 0x20;
    SSPSTAT = 0x00;
}

void spi_write (unsigned int value)
{
    SSPBUF = value;                  // Load value into the SPI buffer register
    while(!SSPSTATbits.BF);          // Wait until the buffer full (BF) flag is set
}

unsigned char spi_read()
{
    SSPBUF = 0x00;                   // Initiate a bus cycle by sending dummy data
    while(!PIR1bits.SSPIF);          // Wait until the SPI interrupt flag is set (transfer complete)
    return (SSPBUF);                 // Return the received byte from the SPI buffer
}


void write_to_25AA106A(unsigned char msb, unsigned char lsb, unsigned char data)
{
    PORTBbits.RB0 = 0;
    spi_write(0x02);
    spi_write(msb);
    spi_write(lsb);
    spi_write(data);
    PORTBbits.RB0 = 1;
}

unsigned char a=0;
void read_from_25AA160A(unsigned char msb, unsigned char lsb)
{
    PORTBbits.RB0 = 0;
    spi_write(0x03);
    spi_write(msb);
    spi_write(lsb);
    while(!SSPSTATbits.BF);
    a = spi_read();      // received data stored in variable 'a' for further process
    PORTBbits.RB0 = 1;
}
