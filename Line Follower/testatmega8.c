#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB=0xff;
while(1)
{
PORTB=0b1111111;
_delay_ms(1000);
PORTB=0b0000000;
_delay_ms(1000);
}
}