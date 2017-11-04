#include<avr/io.h>
#include<util/delay.h> //HEADER FILES INCLUDED
//DELAY.H IS A HEADER FILE WHICH CONTAINS _delay_ms(); FUNCTION

void main()
{
DDRA=0b00000000;
// data direction register A, all the pins of A are declared as input pins
DDRB=0b11111111;
//all the pins of B are declared as output pins
DDRC=0xFF;//all the portC pins are decalred as output pins.. 
//above code written in hexa decimal format
while(1)
{
if(PINA==0b10101010)// if the input to portA is this
{
PORTB=0b11001100;//then give this output
_delay_ms(1000);//wait for 1000 milli seconds 
}
if(PINA==0b11110000)
{
PORTB=(1<<PB7)|(1<<PB6)|(1<<PB6)|(1<<PB5);//another way of writing the the program
_delay_ms(1000);
}
if(PINA==0b11111111)
{
PORTB=0b11001100;//then give this output
_delay_ms(1000);
PORTB=0b00110110;//then give this output
_delay_ms(1000);
PORTB=0b11111100;//then give this output
_delay_ms(1000);
PORTB=0b11001111;//then give this output
_delay_ms(1000);
PORTB=0b11000000;//then give this output
_delay_ms(1000);
}
}//end of while
}//end of main
