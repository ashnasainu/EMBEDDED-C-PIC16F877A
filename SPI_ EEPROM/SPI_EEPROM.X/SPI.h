void SPI_init();
void spi_write (unsigned int value);
unsigned char spi_read();
void write_to_25AA106A(unsigned char msb, unsigned char lsb, unsigned char data);
void read_from_25AA160A(unsigned char msb, unsigned char lsb);


