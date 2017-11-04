#include<avr/io.h> 
#include<util/delay.h>

void main()
{
DDRA=0b00000000;
DDRC=0b11111111;

while(1)
{
if(PINA==0b00000110)//go straight
PORTC=0b01010000;
if(PINA==0b00001000)//sharp left
PORTC=0b10010000;
if(PINA==0b00000001)//sharp right
PORTC=0b01100000;
if(PINA==0b00000000)//backwards
PORTC=0b10100000;

if(PINA==0b00000010||PINA==0b000001000)// go straight
PORTC=0b01010000;
}
}

