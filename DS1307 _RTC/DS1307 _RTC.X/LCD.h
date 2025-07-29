#define RS  PORTDbits.RD0   // Register Select Pin (instruction or data register))
#define RW  PORTDbits.RD1   // Read/Write Pin 
#define EN  PORTDbits.RD2   // Enable Pin

void lcd_initialise();
void lcd_data(unsigned char data);
void lcd_command(unsigned char cmnd);
void lcd_string(const unsigned char *str);
void lcd_clear();
void lcd_set_cursor(int a, int b);
