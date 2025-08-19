#include <xc.h>
#include "EEPROM.h"
#include "LCD.h"

void EEPROM_write (unsigned int location, char data)
{
    EEADR = location;      // EEPROM address to write to
    EEDATA = data;         // Data to be written ('A' = 0x41)

    WREN = 1;             // Enable EEPROM write

    EECON2 = 0x55;        // Required unlock sequence (step 1)
    EECON2 = 0xAA;        // Required unlock sequence (step 2)

    WR = 1;               // Start write operation

    while (EEIF == 0);    // Wait for write to complete
    {
        EEIF = 0;          // Clear the interrupt flag
        WREN = 0;          // Disable further EEPROM writes
        WR = 0;            // Clear WR bit (optional here)
    }
   
}



unsigned char EEPROM_read (unsigned int location)
{
    unsigned char data=0;
    EEADR = location;        // Set the EEPROM address to 0xB2
    RD = 1;              // Initiate a read operation from EEPROM
    data = EEDATA;          // Read the data from EEPROM into variable 'i'
    return data;
}

void EEPROM_write_string(unsigned int location,  unsigned char *str )
{  
    int i=0;
    while(str[i]!='\0')
    {
       EEPROM_write (location, str[i]) ;
       location++;
       i++;
    }
      EEPROM_write (location, '\0') ;
    
}

void EEPROM_read_string(unsigned int location ,unsigned char *data)
{
    int i=0;
    do
    {
        data[i]=EEPROM_read(location);
        location++;
        i++;
    }
    while(data[i-1]!='\0');
    
}
     