#include<avr/io.h>
#include<util/delay.h>

int readadc1()
{
ADMUX=0b00111100;
ADCSRA=0b11101011;
return(ADCH);
};

int readadc2()
{
ADMUX=0b00011000;
ADCSRA=0b11101011;
return(ADCH);
};

int readadc3()
{
ADMUX=0b00001000;
ADCSRA=0b11101011;
return(ADCH);
};

int readadc4()
{
ADMUX=0b00010000;
ADCSRA=0b11101011;
return(ADCH);
};

int readadc5()
{
ADMUX=0b00000000;
ADCSRA=0b11101011;
return(ADCH);
};

int readadc6()
{
ADMUX=0b00100000;
ADCSRA=0b11101011;
return(ADCH);
};

int readadc7()
{
ADMUX=0b00000100;
ADCSRA=0b11101011;
return(ADCH);
};


void main()
{
DDRA=0b00000000;
DDRB=0b11111111;
int a,a1,a2,a3,a4,a5,a6,a7;
while(1)
{
a=127;
a1=readadc1();
a2=readadc2();
a3=readadc3();
a4=readadc4();
a5=readadc5();
a6=readadc6();
a7=readadc7();
if((a>a1&&a<a2&&a<a3&&a<a4&&a<a5&&a<a6&&a<a7)||(a<a1&&a<a2&&a>a3&&a<a4&&a<a5&&a<a6&&a<a7)||(a<a1&&a<a2&&a<a3&&a>a4&&a<a5&&a<a6&&a<a7))
PORTB=0b00000101;
if(a<a1&&a>a2&&a<a3&&a<a4&&a<a5&&a<a6&&a<a7)
PORTB=0b00000101;
if(a<a1&&a<a2&&a<a3&&a<a4&&a>a5&&a<a6&&a<a7)
PORTB=0b00001010;
if(a<a1&&a<a2&&a<a3&&a<a4&&a<a5&&a>a6&&a<a7)
PORTB=0b00000110;
if(a<a1&&a<a2&&a<a3&&a<a4&&a<a5&&a<a6&&a>a7)
PORTB=0b00001001;
}
}
