#include <xc.h>
#include "rtc.h"
#include "LCD.h"

char decimal_to_bcd(unsigned char value) 
{
    unsigned char msb, lsb, hex;

    msb = value / 10;             // Get the tens digit (most significant BCD nibble)
    lsb = value % 10;              // Get the units digit (least significant BCD nibble)

    hex = ((msb << 4) + lsb);    // Shift msb to the upper 4 bits, then add lsb & Combine them into a single BCD byte
    return hex;
}

void bcd_to_ascii(unsigned char value) 
{
    unsigned char bcd;

    // Process the tens digit
    bcd = value;
    bcd = bcd & 0xF0;   // Mask out lower 4 bits (units digit)
    bcd = bcd >> 4;     // Shift upper 4 bits (tens digit) to lower 4 bits
    bcd = bcd | 0x30;   // Convert to ASCII character ('0' through '9')
    lcd_data(bcd);      // Send to LCD

    // Process the units digit
    bcd = value;
    bcd = bcd & 0x0F;   // Mask out upper 4 bits (tens digit)
    bcd = bcd | 0x30;   // Convert to ASCII character ('0' through '9')
    lcd_data(bcd);      // Send to LCD
}

void DS1307_write(char _second, char _minute, char _hour, char _day, char _date, char _month, char _year) // ... (function parameters are declared, likely with 'char' type, as seen in previous prototypes)
{
    /* start bit*/
    SSPCON2bits.SEN = 1;                // Initiate Start Condition
    while(SEN);             // Wait for Start condition to complete (SEN bit clears automatically)
    PIR1bits.SSPIF = 0;                     // Clear SSPIF flag (Synchronous Serial Port Interrupt Flag)

    /* slave address bits*/
    SSPBUF = DS1307_address;            // Send the DS1307's I2C slave address (with R/W bit set to 0 for write)
    while(!SSPIF);             // Wait for acknowledgment (SSPIF is set for every 9th clock cycle, indicating byte sent)
    PIR1bits.SSPIF = 0;                 // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)            // Check if Acknowledgment was NOT received (ACKSTAT is 1 if NACK received)
    {          
        SSPCON2bits.PEN = 1;            // Initiate Stop Condition
        while(PEN);             // Wait for Stop condition to complete (PEN bit clears automatically)
        return;                             // Exit write (no acknowledgment from slave)
    }

    // This section is for sending the 'second' value.
    // It appears there's a typo in the comment, as it says "send the slave address high" which is incorrect here.
    SSPBUF = second;                        // Send the 'seconds' data byte to the DS1307 register
    while(!SSPIF);                              // Wait for acknowledgment (SSPIF is set)
    PIR1bits.SSPIF = 0;                                 // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)                          // Check if Acknowledgment was NOT received after sending seconds byte
    {                                      
        SSPCON2bits.PEN = 1;                                    // Initiate Stop Condition
        while(PEN);                             // Wait for Stop condition to complete
        return;                                                         // Exit write (no acknowledgment)
    }

    SSPBUF = decimal_to_bcd(_second);        // Send the BCD value of seconds
    while(!SSPIF);                            // Wait for acknowledgment (SSPIF is set)
    PIR1bits.SSPIF = 0;                        // Clear SSPIF flag

    SSPBUF = decimal_to_bcd(_minute);   
    while(!SSPIF);             
    PIR1bits.SSPIF = 0;                  

    SSPBUF = decimal_to_bcd(_hour);    
    while(!SSPIF);                      
    PIR1bits.SSPIF = 0;                  

    SSPBUF = decimal_to_bcd(_day);   
    while(!SSPIF);                  
    PIR1bits.SSPIF = 0;                   

    SSPBUF = decimal_to_bcd(_date);  
    while(!SSPIF);                     
    PIR1bits.SSPIF = 0;                  

    SSPBUF = decimal_to_bcd(_month);  
    while(!SSPIF);                     
    PIR1bits.SSPIF = 0;                  

    SSPBUF = decimal_to_bcd(_year);     
    while(!SSPIF);                          
    PIR1bits.SSPIF = 0;      
   
    SSPBUF = 0x00;                // Send the data (likely the value 0x00 to the DS1307's Control Register, which is typically at address 0x07 after sequential writes).
    while(!SSPIF);      // Wait for acknowledgment (SSPIF flag set when byte transmission complete and ACK/NACK received).
    PIR1bits.SSPIF = 0;          // Clear the SSPIF flag for future I2C operations.

    /* stop bits */
    SSPCON2bits.PEN = 1;        // Initiate Stop condition (PEN = Stop Enable bit). This signals the end of the I2C transaction.
    while(PEN);     // Wait until the hardware finishes generating the Stop condition. The PEN bit will be cleared automatically by the hardware when complete.

}

void DS1307_read(char slave_address, char register_address)
{
    /* start bit*/
    SSPCON2bits.SEN = 1;      // Initiate Start Condition
    while(SEN);   // Wait for Start condition to complete (SEN bit clears automatically)
    PIR1bits.SSPIF = 0;       // Clear SSPIF flag

    /* slave address bits*/
    SSPBUF = slave_address;   // Send the DS1307's I2C slave address (with R/W bit set to 0 for write)
    while(!SSPIF);   // Wait for the address byte transmission to complete and for acknowledgment.
    PIR1bits.SSPIF = 0;       // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)          // Check if Acknowledgment was NOT received (ACKSTAT is 1 if NACK received)
    {
        SSPCON2bits.PEN = 1;                 // Initiate Stop Condition
        while(PEN);                        // Wait for Stop condition to complete
        return;                            // Exit read (no acknowledgment from slave for address)
    }

    /* slave address bits*/ // This comment is misleading; this is the REGISTER ADDRESS, not slave address.
    SSPBUF = register_address; // Send the internal register address within the DS1307 that we want to read from.
    while(!SSPIF);    // Wait for the register address byte transmission to complete and for acknowledgment.
    PIR1bits.SSPIF = 0;        // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)          // Check if Acknowledgment was NOT received after sending register address
    { 
        SSPCON2bits.PEN = 1;  // Initiate Stop Condition
        while(PEN); // Wait for Stop condition to complete
        return;               // Exit read (no acknowledgment for register address)
    }

    /* Repeated start bit*/
    SSPCON2bits.RSEN = 1;     // Initiate Repeated Start Condition (RSEN = Repeated Start Enable)
    while(RSEN);  // Wait for Repeated Start condition to complete (RSEN bit clears automatically)
    PIR1bits.SSPIF = 0;       // Clear SSPIF flag

    /* slave address bits*/
    SSPBUF = (slave_address + 1);           // Send the DS1307's I2C slave address with R/W bit set to 1 (for Read). // Adding 1 to the slave_address (which should have R/W=0 as LSB) flips the LSB to 1.
                                 
    while(!SSPIF);                       // Wait for the address byte transmission to complete and for acknowledgment.
    PIR1bits.SSPIF = 0;                    // Clear SSPIF flag

    if (SSPCON2bits.ACKSTAT)   // Check if Acknowledgment was NOT received (ACKSTAT is 1 if NACK received)
    { 
        SSPCON2bits.PEN = 1;  // Initiate Stop Condition
        while(PEN); // Wait for Stop condition to complete
        return;               // Exit read (no acknowledgment from slave for the read address)
    }

    /* Receive enable bit*/
    SSPCON2bits.RCEN = 1;     // Initiate Receive Enable 
    while(!SSPSTATbits.BF);   // Wait for BUFFER TO BE FULL 
    _sec = SSPBUF;            
                      

    SSPCON2bits.ACKDT = 0;    // Prepare to send ACK (ACKDT = Acknowledge Data bit; 0 for ACK, 1 for NACK)
    SSPCON2bits.ACKEN = 1;    // Initiate to send ACK (ACKEN = Acknowledge Enable)
    while(ACKEN); // Wait for ACK condition to complete (ACKEN clears automatically)

    /* Receive enable bit*/
    SSPCON2bits.RCEN = 1;    
    while(!SSPSTATbits.BF);                           
    _min = SSPBUF;   
    
    SSPCON2bits.ACKDT = 0;  
    SSPCON2bits.ACKEN = 1;  
    while(ACKEN); 
    
    SSPCON2bits.RCEN = 1;    
    while(!SSPSTATbits.BF);                           
    _hr = SSPBUF;   
    
    SSPCON2bits.ACKDT = 0;  
    SSPCON2bits.ACKEN = 1;  
    while(ACKEN); 
    
    SSPCON2bits.RCEN = 1;    
    while(!SSPSTATbits.BF);                           
    _day = SSPBUF;   
    
    SSPCON2bits.ACKDT = 0;  
    SSPCON2bits.ACKEN = 1;  
    while(ACKEN); 
                     
    
    SSPCON2bits.RCEN = 1;    
    while(!SSPSTATbits.BF);                           
    _date = SSPBUF;   
    
    SSPCON2bits.ACKDT = 0;  
    SSPCON2bits.ACKEN = 1;  
    while(ACKEN); 
    
    SSPCON2bits.RCEN = 1;    
    while(!SSPSTATbits.BF);                           
    _month = SSPBUF;   
    
    SSPCON2bits.ACKDT = 0;  
    SSPCON2bits.ACKEN = 1;  
    while(ACKEN); 
    
    SSPCON2bits.RCEN = 1;    
    while(!SSPSTATbits.BF);                           
    _year = SSPBUF;   
    
    SSPCON2bits.ACKDT = 0;  
    SSPCON2bits.ACKEN = 1;  
    while(ACKEN);
    
    /* Receive enable bit */
    SSPCON2bits.RCEN = 1;         // initiate receive enable
    while(!SSPSTATbits.BF);       // wait for BUFFER TO BE FULL (data received)
    __con = SSPBUF;               // read the data from buffer (clears SSPIF flag)

    SSPCON2bits.ACKDT = 1;        // Prepare to send NACK
    SSPCON2bits.ACKEN = 1;        // Initiate to send NACK
    while(ACKEN);                 // WAIT FOR NACK TO COMPLETE
    
    /* stop bits */
    SSPCON2bits.PEN = 1;          // initiate stop condition
    while(PEN);                   // wait for stop condition to complete
    
    lcd_cmd(0x88);               // Set cursor to desired LCD position (1st row, 9th position)
    bcd_to_ascii(__hr);          // Display hours (in BCD to ASCII format)
    lcd_data(':');               // Print colon
    bcd_to_ascii(__min);         // Display minutes
    lcd_data(':');               // Print colon
    bcd_to_ascii(__sec);         // Display seconds
    lcd_cmd(0xC7);               // Set cursor to desired position (2nd row, 8th position)
    bcd_to_ascii(__date);        // Display date
    lcd_data('/');               // Print slash
    bcd_to_ascii(__month);       // Display month
    lcd_data('/');               // Print slash
    bcd_to_ascii(__yr);          // Display year
 
}



