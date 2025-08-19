#include <xc.h>
#include "I2C.h"

void I2C_init()
{
    SSPCON = 0x28;   // I2C Master mode
    SSPADD = 0x3F;   // I2C speed
}
