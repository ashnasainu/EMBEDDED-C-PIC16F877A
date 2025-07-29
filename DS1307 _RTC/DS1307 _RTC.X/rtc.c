#include <xc.h>
#include "rtc.h"
#include "LCD.h"

int value = 0;

void i2c_start()
{
    SEN = 1;                      // Initiate Start condition on SDA and SCL lines
    while (SSPIF == 0);           // Wait for the Start condition to complete
    SSPIF = 0;                    // Clear the interrupt flag
}                                

void i2c_stop()
{
    PEN = 1;                      // Initiate Stop condition on SDA and SCL lines
    while (SSPIF == 0);           // Wait for the Stop condition to complete
    SSPIF = 0;                    // Clear the interrupt flag
}

void i2c_write(int data)
{
    SSPBUF = data;                // Load data into the SSP buffer register
    while(SSPIF == 0);            // Wait until transmission is complete (SSPIF is set)
    SSPIF = 0;                    // Clear the interrupt flag
}

int decimal_bcd(int value)        // give BCD value 
{
    int j;
    j = ((value / 10) << 4) + (value % 10);
    return j;
}


void rtc_write(int data)
{
    i2c_start();                  // Send START condition to begin I2C communication
    i2c_write(0xd0);              // Send slave address (e.g., RTC at 0x68) with write bit at last
    i2c_write(0x02);              // Select register address (e.g., Hours register in RTC)
    value = decimal_bcd(data);    // Convert decimal data to BCD format (for RTC)
    i2c_write(value);             // Write the BCD value to the selected register
    i2c_stop();                   // Send STOP condition to end I2C communication

}

void bcd_to_ascii(unsigned char bcd, unsigned char *ascii)
{
    ascii[0] = ((bcd >> 4) & 0x0F) + '0';
    ascii[1] = (bcd & 0x0F) + '0';
    ascii[2] = '\0';
}



int rtc_read()
{
    int hour_bcd;

    i2c_start();                // Start I2C communication
    i2c_write(0xD0);            // RTC I2C address + Write (0xD0)
    i2c_write(0x02);            // Point to the Hours register

    i2c_start();                // Restart condition (Repeated START)
    i2c_write(0xD1);            // RTC I2C address + Read (0xD1)

    while (BF == 0);            // Wait until buffer is full (data received)
    hour_bcd = SSPBUF;         // Read the BCD data (hours)

    ACKDT = 1;                  // Send NACK (no more data to read)
    ACKEN = 1;                  // Enable acknowledgment sequence
    while (ACKEN);              // Wait for ACK to complete

    i2c_stop();                 // Stop I2C communication

    return hour_bcd;

}