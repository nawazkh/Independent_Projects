#include<avr/io.h>
#include<avr/delay.h>
void forward(void);
void left(void);
void right(void);
void stop(void);
void junction(void);
void sharp_right(void);
void sharp_left(void);
void reverse(void);

void forward(void)
{
if(PINB==(0b00011000))
{
PORTD=0b00001010;
}
}

void left(void)
{
if((PINB==0b00111000||PINB==0b01011000||PINB==0b10011000||PINB==0b01111000||PINB==0b11011000))
{
PORTD=0b00001000;
}
}

void right(void)
{
if((PINB==0b00011100||PINB==0b00011010||PINB==0b00011001||PINB==0b00011110||PINB==0b00011011))
{
PORTD=0b00000010;
}
}

void stop(void)
{
if((PINB==0b11111111))
{
PORTD=0b00000000;
}
}

void junction(void)
{
if((PINB==0b00111100||PINB==0b01011010||PINB==0b10011001))
{
PORTD=0b00001010;
}
}

void sharp_right(void)
{
if((PINB==0b00000100||PINB==0b00001000||PINB==0b00000010||PINB==0b00000001||PINB==0b00000110||PINB==0b00000011))
{
PORTD=0b00000110;
}
}

void sharp_left(void)
{
if((PINB==0b00100000||PINB==0b00010000||PINB==0b01000000||PINB==0b10000000||PINB==0b01100000||PINB==0b11000000))
{
PORTD=0b00001001;
}
}

void reverse(void)
{
if((PINB==0b00000000)||(PINB==0b00000000&&PINA==0b00000000))
{
PORTD=0b00000101;
}
}

int main()
{
DDRA=0b00000000;
DDRB=0b00000000;
DDRD=0b11111111;
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
