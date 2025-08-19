#include <xc.h>
#include "SPI.h"
#define _XTAL_FREQ 20000000

void SPI_init()
{
    SSPCON = 0x20;
    SSPSTAT = 0x00;  
    SCK  = 0;  // Output
    MISO = 1;  // Input
    MOSI = 0;  // Output
    SS   = 0;  // Output
}

void spi_write (unsigned int value)
{
    SSPBUF = value;                  // Load value into the SPI buffer register
    while(!SSPSTATbits.BF);          // Wait until the buffer full (BF) flag is set   or while(SSPIF==0) , SSPIF=0;
}

unsigned char spi_read()
{
    PIR1bits.SSPIF = 0;
    SSPBUF = 0x00;                   // Initiate a bus cycle by sending dummy data
    while(!PIR1bits.SSPIF);          // Wait until the SPI interrupt flag is set (transfer complete)
    return (SSPBUF);                 // Return the received byte from the SPI buffer
}

void write_to_25AA106A(unsigned int  msb,unsigned int  lsb, unsigned char data)    // for single charachter
{
    PORTBbits.RB0 = 0; // slave select low               // write enable sequence
    spi_write(0x06);
    PORTBbits.RB0 = 1; // slave select high
    
    PORTBbits.RB0 = 0;                                   // write function
    spi_write(0x02);
    spi_write(msb);
    spi_write(lsb);
    spi_write(data);
    PORTBbits.RB0 = 1;
    
    PORTBbits.RB0 = 0; // slave select low                // write disable sequence
    spi_write(0x04);
    PORTBbits.RB0 = 1; // slave select high
}


void write_string_25AA106A(unsigned int  msb,unsigned int  lsb,unsigned char *str)    // for string
{
    unsigned char i=0;
    
    PORTBbits.RB0 = 0; // slave select low               // write enable sequence
    spi_write(0x06);
    PORTBbits.RB0 = 1; // slave select high
    
    PORTBbits.RB0 = 0;                                   // write function
    spi_write(0x02);        
    spi_write(msb);
    spi_write(lsb);
    
    for(i=0;str[i]!='\0';i++)
    {
        spi_write(str[i]);
        __delay_ms(10);            
    }
    spi_write('\0');
    PORTBbits.RB0 = 1;
    
    PORTBbits.RB0 = 0; // slave select low                // write disable sequence
    spi_write(0x04);
    PORTBbits.RB0 = 1; // slave select high
    
}

unsigned char read_from_25AA160A(unsigned int  msb, unsigned int  lsb)       // for single charachter
{
    unsigned char value=0;
    PORTBbits.RB0 = 0;
    spi_write(0x03);         // read instruction
    spi_write(msb);
    spi_write(lsb);
    while(!SSPSTATbits.BF);
    value= spi_read();      // received data stored in variable 'a' for further proces 
    PORTBbits.RB0 = 1;
    return value;
}

void read_string_25AA160A(unsigned int  msb, unsigned int  lsb,unsigned char *DATA)   // for string
{
    unsigned char i=0;
    
    PORTBbits.RB0 = 0;
    spi_write(0x03);
    spi_write(msb);
    spi_write(lsb);
    while(!SSPSTATbits.BF);
    do
    {
        DATA[i]=spi_read();
        i++;
    }
    while(DATA[i-1]!='\0');
    //my_data= spi_read();      // received data stored in variable 'a' for further proces
    //return value;
    PORTBbits.RB0 = 1;
}