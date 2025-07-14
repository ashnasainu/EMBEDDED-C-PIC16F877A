#define digit1 PORTBbits.RB3
#define digit2 PORTBbits.RB2
#define digit3 PORTBbits.RB1
#define digit4 PORTBbits.RB0

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

void seven_segment_init();
void seven_segment_show(int i);

#endif	/* SEVEN_SEGMENT_H */
