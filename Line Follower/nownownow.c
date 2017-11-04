#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRA=0b11111111;
while(1)
{
PORTA=0b00111111;
_delay_ms(100);
PORTA=0b00011111;
_delay_ms(100);
PORTA=0b00001111;
_delay_ms(100);
PORTA=0b00000111;
_delay_ms(100);
PORTA=0b00000011;
_delay_ms(100);
PORTA=0b00000001;
_delay_ms(100);

}
}
