// In 24C04 EEPROM , the total memory locations are divided in to 2 blocks , ie block 0 & block 1.We can write to block 0 as well as to block 1.

#define EEPROM_BLOCK_WRITE  0xA0
#define EEPROM_BLOCK_READ   0xA1

// Block 0                        
//EEPROM_BLOCK0_WRITE  0xA0
//EEPROM_BLOCK0_READ   0xA1

// Block 1
//EEPROM_BLOCK1_WRITE  0xA2
//EEPROM_BLOCK1_READ   0xA3

void i2c_start();
void i2c_stop();
void i2c_write();
void i2c_restart();
void EEPROM_24C04_write(unsigned int  location, unsigned char data);                   // for character
void EEPROM_24C04_write_string(unsigned int location,unsigned char *str);              //for string
unsigned char EEPROM_24C04_read(unsigned int location);                                // for character
void EEPROM_24C04_read_string(unsigned int location,unsigned char *DATA);              //for string
