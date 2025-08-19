void EEPROM_write (unsigned int location, char data);        //function for writing single character to EEPROM
unsigned char EEPROM_read (unsigned int location);         //function for reading single character from EEPROM & to display on LCD 
void EEPROM_write_string(unsigned int location,  unsigned char *str );
void EEPROM_read_string(unsigned int location , unsigned char *data);