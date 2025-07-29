void rtc_write(int data);
void i2c_start();
void i2c_stop();
void i2c_write();
int decimal_bcd();
int rtc_read();
void bcd_to_ascii(unsigned char bcd, unsigned char *ascii);
