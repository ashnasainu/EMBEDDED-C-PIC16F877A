#define DS1307_address  0xD0                       // rtc macros for ds1307
#define second          0x00
#define minute          0x01
#define hour            0x02
#define day             0x03
#define date            0x04
#define month           0x05
#define year            0x06
#define control_reg     0x07

void i2c_start();
void i2c_stop();
void i2c_write();
void bcd_to_ascii(unsigned char value);
char decimal_to_bcd(unsigned char value);
void DS1307_write(char _second, char _minute, char _hour, char _day, char _date, char _month, char _year);
void DS1307_read(char slave_address, char register_address);
