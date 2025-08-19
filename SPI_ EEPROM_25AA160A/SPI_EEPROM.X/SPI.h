// SPI Pin Direction Macros
#define SCK  TRISCbits.TRISC3   // Serial Clock
#define MISO  TRISCbits.TRISC4   // Master In Slave Out
#define MOSI  TRISCbits.TRISC5   // Master Out Slave In
#define SS    TRISBbits.TRISB0   // Slave Select

void SPI_init();
void spi_write (unsigned int value);
unsigned char spi_read();
void write_to_25AA106A(unsigned int  msb,unsigned int  lsb, unsigned char data);
void write_string_25AA106A(unsigned int  msb,unsigned int  lsb,unsigned char *str);
unsigned char read_from_25AA160A(unsigned int  msb, unsigned int  lsb);
void read_string_25AA160A(unsigned int  msb, unsigned int  lsb,unsigned char *DATA);


