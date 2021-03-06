/* $CSK: lesson6.c,v 1.2 2009/05/17 06:22:44 ckuethe Exp $ */

#include <avr/io.h>
#include <util/delay.h>

void serial_init(unsigned int bittimer)
{
	/* Set the baud rate */
	UBRR0H = (unsigned char) (bittimer >> 8);
	UBRR0L = (unsigned char) bittimer;
	/* set the framing to 8N1 */
	UCSR0C = (3 << UCSZ00);
	/* Engage! */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	return;
}

unsigned char serial_read(void)
{
	while( !(UCSR0A & (1 << RXC0)) )
		;
	return UDR0;
}

void serial_write(unsigned char c)
{
	while ( !(UCSR0A & (1 << UDRE0)) )
		;
	UDR0 = c;
}

#define SPEED 9600
int main (void)
{
	int old_state = 0, ledstate = 0;
	/* set PORTB for output*/
	DDRB = 0xFF;
	/* set PORTD for input*/
	DDRD &= 0xFB;
	PORTD |= 0x04;

	/* let the preprocessor calculate this */
	serial_init( ( F_CPU / SPEED / 16 ) - 1);

	while (1) {
		/* read a character and echo back the next one */
		serial_write( serial_read() + 1);
		/* read serial port */
		/* test button */
		if (PIND & 0x04){
			_delay_ms(2);
			ledstate = ~ledstate;
		}

		if (ledstate)
			PORTB &= ~0x20;
		else
			PORTB |=  0x20;
	}
	return 0;
}
