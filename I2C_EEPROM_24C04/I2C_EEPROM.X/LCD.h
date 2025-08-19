// Control pins
#define RS  PORTDbits.RD0
#define RW  PORTDbits.RD1
#define EN  PORTDbits.RD2

// Data pins (D4-D7)    , 4 bit mode
#define DATA_PINS  PORTD

void lcd_initialise();
void lcd_data(unsigned char data);
void lcd_command(unsigned char cmnd);
void lcd_string(const unsigned char *str);
void lcd_clear();
void lcd_set_cursor(int a, int b);
void lcd_int(int num);