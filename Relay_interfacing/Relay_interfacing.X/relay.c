#include <xc.h>
#include "relay.h"

void relay_init()
{
    BUTTON_TRIS =1;
    RELAY_TRIS =0;      
}

int button_pressed()
{
    return BUTTON_PIN ;
}

void relay_on()
{
    RELAY_PIN=1;
}

void relay_off()
{
    RELAY_PIN=0;
}