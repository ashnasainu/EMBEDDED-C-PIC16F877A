#define BUTTON_PIN      PORTBbits.RB0
#define RELAY_PIN       PORTBbits.RB1
#define BUTTON_TRIS     TRISBbits.TRISB0
#define RELAY_TRIS      TRISBbits.TRISB1

void relay_init();
int button_pressed();
void relay_on();
void relay_off();
