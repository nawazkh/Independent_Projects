#define F_CPU 1000000UL

#include<avr/io.h>
#include<util/delay.h>

unsigned int i;
void main()
{
DDRA=0b11111111;
while(1)
{
PORTA=0b11111111;
for(i=0;i<4;i++)
{
_delay_ms(250);
}
}
}
