#include <xc.h>
#include "rtc.h"

int value = 0;
unsigned char bcd=' ';


void i2c_start()
{
    SSPCON2bits.SEN = 1;                // Initiate Start Condition
    while(SEN);                         // Wait for Start condition to complete (SEN bit clears automatically)
    PIR1bits.SSPIF = 0;                 // Clear SSPIF flag (Synchronous Serial Port Interrupt Flag)
}                                

void i2c_stop()
{
    /* stop bits */
    SSPCON2bits.PEN = 1;        // Initiate Stop condition (PEN = Stop Enable bit). This signals the end of the I2C transaction.
    while(PEN);     // Wait until the hardware finishes generating the Stop condition. The PEN bit will be cleared automatically by the hardware when complete.
}

void i2c_restart()
{
    SSPCON2bits.RSEN = 1;
    while (SSPCON2bits.RSEN);
    PIR1bits.SSPIF = 0;
}        


void i2c_write(int data)
{
    SSPBUF = data;            // Send the DS1307's I2C slave address (with R/W bit set to 0 for write)
    while(!SSPIF);             // Wait for acknowledgment (SSPIF is set for every 9th clock cycle, indicating byte sent)
    PIR1bits.SSPIF = 0;                 // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)            // Check if Acknowledgment was NOT received (ACKSTAT is 1 if NACK received)
    {          
        SSPCON2bits.PEN = 1;            // Initiate Stop Condition
        while(PEN);             // Wait for Stop condition to complete (PEN bit clears automatically)
        return;                             // Exit write (no acknowledgment from slave)
    }
}

int decimal_bcd(int value)        // give BCD value 
{
    int j;
    j = ((value / 10) << 4) + (value % 10);
    return j;
}

int data_read()
{
    int sec = 0;int min=0;int hour=0;int read_data=0;
    
    SSPCON2bits.RCEN = 1;       // Enable read for second data
    while (!SSPSTATbits.BF);    // Wait for buffer full

    read_data = SSPBUF;              // Read the sec value (BCD format)
    
    SSPCON2bits.ACKDT = 0;     // Prepare to send ACK
    SSPCON2bits.ACKEN = 1;     // Initiate ACK/NACK sequence
    while (ACKEN);             // Wait for ACK/NACK to complete
    return read_data;
}

int hr_read()
{
    int sec = 0;int min=0;int hour=0;int read_data=0;
    
    SSPCON2bits.RCEN = 1;       // Enable read for second data
    while (!SSPSTATbits.BF);    // Wait for buffer full

    read_data = SSPBUF;              // Read the sec value (BCD format)
    
    SSPCON2bits.ACKDT = 1;     // Prepare to send ACK
    SSPCON2bits.ACKEN = 1;     // Initiate ACK/NACK sequence
    while (ACKEN);             // Wait for ACK/NACK to complete
    return read_data;
}

int bcd_int(int value)
{
   int a =0;int b=0;int c=0;int d=0; 
   a=(value>>4);
   b=a*10;
   c=value&0x0f;
   d=b+c;
   return d;
}

void rtc_read_time ( int *sec_data,int *min_data,int *hour)
{
    *sec_data=data_read();      // sec data read
    *min_data=data_read();      // min data read     
    *hour=hr_read();            //hr data read
}


void EEPROM_24C04_write(int sec, int min, int hr) 
{
    int SEC=0;int MIN=0;int HR=0;
    
    i2c_start();              //  start 
    i2c_write(0xd0);         // slave address write
    i2c_write(0x00);         // register address write  (second register address))      
    SEC= decimal_bcd(sec);        
    i2c_write(SEC);
    MIN= decimal_bcd(min);      
    i2c_write(MIN);
    HR= decimal_bcd(hr);        
    i2c_write(HR);
    i2c_stop();
}


void rtc_read(int *second, int *minute, int *hour)
{
    // RTC constants ? internal to the function
    //char slave_address = 0xD0;  // slave(RTC)  address with write (R/W=0 ) 
    //char slave_address  = 0xD1;  // slave(RTC) address with  read (R/W=1)
    //char register_address = 0x00;  // Seconds register address 
    
    int sec = 0;int min=0;int hr=0;
     
    i2c_start();               // Start condition
    i2c_write(0xd0);           // Send slave address with Write (R/W = 0)
    i2c_write(0x00);           // register address write  (second register address))  
    i2c_restart();             // Restart condition
    i2c_write(0xd1);           // Send slave address with Read (R/W = 1)
    rtc_read_time(&sec, &min, &hr);
    *hour=bcd_int(hr);
    *minute=bcd_int(min);
    *second=bcd_int(sec);
    i2c_stop();
   
}


