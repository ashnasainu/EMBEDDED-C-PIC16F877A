#define RS  PORTBbits.RB0   // Register Select Pin (instruction or data register))
#define RW  PORTBbits.RB1   // Read/Write Pin 
#define EN  PORTBbits.RB2   // Enable Pin

void lcd_initialise(void);
void lcd_data(unsigned char data);
void lcd_command(unsigned char cmnd);
void lcd_string(const unsigned char *str);
void lcd_set_cursor(int a, int b);
