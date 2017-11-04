#define F_CPU 8000000UL// 8mhz
#include<avr/io.h>



void main()
{
unsigned char data;
UBRRL=51;//9600 bps
UBRRH=0;

UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);

DDRC=0xFF;
DDRD=(0<<PD0);//PDO as RxD

UCSRB=(1<<RXEN); // Rx enabled

while(1)
{
while(!(UCSRA&(1<<RXC)))
{
 //wait for Rx
 }

 data=UDR;
 PORTC=data;

 }
 }
