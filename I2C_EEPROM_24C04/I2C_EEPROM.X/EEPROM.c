#include <xc.h>
#include "EEPROM.h"
#define _XTAL_FREQ 20000000


void i2c_start()
{
    SSPCON2bits.SEN = 1;                // Initiate Start Condition
    while(SEN);                         // Wait for Start condition to complete (SEN bit clears automatically)
    PIR1bits.SSPIF = 0;                 // Clear SSPIF flag (Synchronous Serial Port Interrupt Flag)
}                                

void i2c_stop()
{
    SSPCON2bits.PEN = 1;        // Initiate Stop condition (PEN = Stop Enable bit). This signals the end of the I2C transaction.
    while(PEN);                 // Wait until the hardware finishes generating the Stop condition. The PEN bit will be cleared automatically by the hardware when complete.
}

void i2c_restart()
{
    SSPCON2bits.RSEN = 1;
    while (SSPCON2bits.RSEN);
    PIR1bits.SSPIF = 0;
}        


void i2c_write(int data)
{
    SSPBUF = data;                         // Send the DS1307's I2C slave address (with R/W bit set to 0 for write)
    while(!SSPIF);                         // Wait for acknowledgment (SSPIF is set for every 9th clock cycle, indicating byte sent)
    PIR1bits.SSPIF = 0;                    // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)                // Check if Acknowledgment was NOT received (ACKSTAT is 1 if NACK received)
    {          
        SSPCON2bits.PEN = 1;                // Initiate Stop Condition
        while(PEN);                         // Wait for Stop condition to complete (PEN bit clears automatically)
        return;                             // Exit write (no acknowledgment from slave)
    }
}

int data_read()                             //To read the data ,that already written to the EEPROM 
{
    int read_data=0;
    
    SSPCON2bits.RCEN = 1;            // Enable read for second data
    while (!SSPSTATbits.BF);         // Wait for buffer full

    read_data = SSPBUF;              // Read the sec value (BCD format)
    
    SSPCON2bits.ACKDT = 0;           // Prepare to send ACK
    SSPCON2bits.ACKEN = 1;           // Initiate ACK/NACK sequence
    while (ACKEN);                   // Wait for ACK/NACK to complete
    return read_data;
}


void EEPROM_24C04_write(unsigned int location, unsigned char data)     
{
    i2c_start();                            //  start 
    i2c_write(EEPROM_BLOCK_WRITE);         // slave address(EEPROM 24C04) with write    
    i2c_write(location);                    // address of EEPROM location  
    i2c_write(data);                        // send data (data to be written) 0B10101010
    i2c_stop();
    __delay_ms(10); 
}

void EEPROM_24C04_write_string(unsigned int location,unsigned char *str)     
{
    unsigned char i=0;
    
    i2c_start();                                   //  start 
    i2c_write(EEPROM_BLOCK_WRITE);                // slave address(EEPROM 24C04) with write    ; using Block 0(so selected as 0xA2)
    i2c_write(location);                           // address of EEPROM location  
       
    for(i=0;str[i]!='\0';i++)                      // send data as string
    {
        i2c_write(str[i]);
        __delay_ms(10);            
    }
    i2c_write('\0');
    i2c_stop();
    __delay_ms(10); 
}


unsigned char EEPROM_24C04_read(unsigned int location) 
{
    unsigned char value=0;
    
    i2c_start();                              // Start condition
    i2c_write(EEPROM_BLOCK_WRITE);           // Send slave address with Write (R/W = 0)
    i2c_write(location);                      // register address write  (second register address))  
    i2c_restart();                            // Restart condition
    i2c_write(EEPROM_BLOCK_READ);            // send byte (device address + R) 
    value=data_read();                        // Read function
    i2c_stop();
    
    return value;  
}


void EEPROM_24C04_read_string(unsigned int location,unsigned char *DATA)   
{
    unsigned char i=0;
    
    i2c_start();                              // Start condition
    i2c_write(EEPROM_BLOCK_WRITE);           // Send slave address with Write (R/W = 0)
    i2c_write(location);                      // register address write  (second register address))  
    i2c_restart();                            // Restart condition
    i2c_write(EEPROM_BLOCK_READ);            // send byte (device address + R) 
    
    do                                        // Read function
    {
        DATA[i]=data_read();
        i++;
    }
    while(DATA[i-1]!='\0');         
    i2c_stop();
}



