#include<avr/io.h>
#include<util/delay.h>
unsigned char data;

#define F_CPU 8000000UL

int rx()
{
while(!(UCSRA&(1<<UDRE))){}
data=UDR;
return data;
}


void main()
{
DDRC=0b11111111;
DDRD=(0<<DD0)|(1<<PD1);
UCSRB=(1<<RXEN)|(1<<TXEN);
UCSRC=(1<<URSEL)|(0<<USBS)|(1<<UCSZ1)|(1<<UCSZ0);
UBRRL=51;
UBRRH=0;
while(!(UCSRA&(1<<TXC))){}
UDR='N';
_delay_ms(1000);
UDR='A';
_delay_ms(1000);
UDR='W';
_delay_ms(1000);
UDR='A';
_delay_ms(1000);
UDR='Z';
_delay_ms(1000);

data=rx();
if(data=='y')
{
PORTC=0b10101010;
_delay_ms(1000);
}
}
