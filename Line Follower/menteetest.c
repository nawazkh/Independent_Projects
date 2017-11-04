#include<avr/io.h>
#include<util/delay.h>


void main()
{
DDRA=0b11111111;
DDRB=0b00000000;
while(1)
{


if(PINB==0b00000001)
{
PORTA=0b10011001;
_delay_ms(1000);
}
else
{
PORTA=0b00000000;
_delay_ms(1000);
PORTA=0b11111111;
_delay_ms(1000);
PORTA=0b10101010;
_delay_ms(1000);
PORTA=0b11001100;
_delay_ms(1000);
}
}
}
