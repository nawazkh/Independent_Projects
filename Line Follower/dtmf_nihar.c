#include<avr/io.h>
#include<util/delay.h>
#include<avr/signal.h>

void main()
{
DDRC=0b00000000;
DDRB=0b11111111;

while(1)
{
if(PINC==0b00000110)
{
PORTB=0b00010100;
}

if(PINC==0b00001100)
PORTB=0b00000100;

if(PINC==0b00010010)
PORTB=0b00010000;

if(PINC==0b00011000)
{
PORTB=0b00001010;
}

else
PORTB=0b00000000;
}
}
