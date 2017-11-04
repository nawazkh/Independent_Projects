#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRD=0b00000000;
DDRB=0b11111111;
while(1)
{
if(PIND==0b11111111)
{
PORTB=0b11111111;
_delay_ms(1000);
PORTB=0b00000000;
_delay_ms(1000);
}
else
{
PORTB=0b00000000;
_delay_ms(1000);
}
}
}
