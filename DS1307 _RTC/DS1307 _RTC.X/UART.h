void UART_write(char data);
void UART_write_string(const unsigned char *str);
void UART_init();
char UART_receive();
void receive_string(unsigned char *string);
void UART_write_int(int num);      // convert int to string and displays on terminal




