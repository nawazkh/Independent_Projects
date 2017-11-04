#include<avr/io.h>
#include<avr/delay.h>
#include<avr/signal.h>
void forward(void);
void left(void);
void right(void);
void stop(void);
void junction(void);
void sharp_right(void);
void sharp_left(void);
void reverse(void);

init_timer(unsigned char TOP)
{
TCCR1A |= 0xA2;//10100010
TCCR1B |= 0x12;//00010010
ICR1=TOP;
OCR1A=0;
OCR1B=0;
}




void forward(void)
{
if(PINA==0b00011000||PINA==0b0001000||PINA==0b00001000)
{
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A=255;
OCR1B=255;
}
}

void left(void)
{
if((PINA==0b00110000||PINA==0b00111000||PINA==0b01011000||PINA==0b01111000||PINA==0b11011000||PINA==0b01110000||PINA==0b10011000||PINA==0b11111000||PINA==0b11000000))
{
PORTD=(0<<PD0) | (0<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A=150;
OCR1B=250;
}
}

void right(void)
{
if((PINA==0b00001100||PINA==0b00011100||PINA==0b00011010||PINA==0b00011110||PINA==0b00011011||PINA==0b00001110||PINA==0b00011001||PINA==0b00011111||PINA==0b00000011))
{
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (0<<PD7);
OCR1A=250;
OCR1B=150;
}
}

void stop(void)
{
if((PINA==0b11111111))
{
PORTD=0b00000000;
OCR1A=0;
OCR1B=0;
}
}




void junction(void)
{
if((PINA==0b00111100||PINA==0b01011010||PINA==0b10011001))
{
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A=250;
OCR1B=250;
}
}

void sharp_right(void)
{
if((PINA==0b00000100||PINA==0b00000010||PINA==0b00000001||PINA==0b00000110||PINA==0b00000011))
{
PORTD=(0<<PD0) | (1<<PD1) | (1<<PD6) | (0<<PD7);
OCR1A=250;
OCR1B=150;
_delay_ms(200);
}
}

void sharp_left(void)
{
if((PINA==0b00100000||PINA==0b01000000||PINA==0b10000000||PINA==0b01100000||PINA==0b11000000))
{
PORTD=(1<<PD0) | (0<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A=150;
OCR1B=250;
_delay_ms(200);
}
}

void reverse(void)
{
if((PINA==0b00000000))
{
PORTD=(1<<PD0) | (0<<PD1) | (1<<PD6) | (0<<PD7);
OCR1A=250;
OCR1B=250;
}
}

int main()
{

DDRA=0b00000000;
PINA=0b00000000;
DDRD=0b11111111;//PWM port & output port
init_timer(255);

while(1)
{
forward();
left();
right();
sharp_left();
sharp_right();
junction();
reverse();
stop();

}
return(0);
}
