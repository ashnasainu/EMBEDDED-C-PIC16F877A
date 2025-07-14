#define RS  PORTDbits.RD0   // Register Select Pin (instruction or data register))
#define RW  PORTDbits.RD1   // Read/Write Pin 
#define EN  PORTDbits.RD2   // Enable Pin

void lcd_initialise(void);
void lcd_data(unsigned char data);
void lcd_command(unsigned char cmnd);
void lcd_string(const unsigned char *str);
void lcd_set_cursor(int a, int b);
void lcd_int(int value);
void integer_string(int ADC_data,unsigned char *buffer);