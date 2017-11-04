#include<avr/io.h>
#include<util/delay.h>

int readadc()
{
ADMUX=0b00011000;//forward motion
ADCSRA=0b11101011;//a1
return(ADCH);
};
int readadc01()
{
ADMUX=0b00001000;
ADCSRA=0b11101011;//straight
return(ADCH);//a2
};
int readadc10()
{
ADMUX=0b00001000;
ADCSRA=0b11101011;//straight
return(ADCH);//a3
};



int readadc_1()
{
ADMUX=0b00111000;//left
ADCSRA=0b11101011;
return(ADCH);//a4
};
int readadc_2()
{
ADMUX=0b01011000;//left
ADCSRA=0b11101011;
return(ADCH);//a5
};
int readadc_4()
{
ADMUX=0b01111000;//left
ADCSRA=0b11101011;
return(ADCH);//a7
};
int readadc_5()
{
ADMUX=0b11011000;//left
ADCSRA=0b11101011;
return(ADCH);//a8
};



int readadc1()
{
ADMUX=0b00011100;//right
ADCSRA=0b11101011;
return(ADCH);//a9
};
int readadc2()
{
ADMUX=0b00011010;
ADCSRA=0b11101011;//right
return(ADCH);//a10
};

int readadc4()
{
ADMUX=0b00011110;//right
ADCSRA=0b11101011;
return(ADCH);//a12
};
int readadc5()
{
ADMUX=0b00011011;//right
ADCSRA=0b11101011;
return(ADCH);//a13
};



int readadc111()
{
ADMUX=0b01111110;//stop
ADCSRA=0b11101011;
return(ADCH);//a14
};



int readadc__1()
{
ADMUX=0b00100000;//sharpleft
ADCSRA=0b11101011;
return(ADCH);//a15
};
int readadc__2()
{
ADMUX=0b01000000;//sharpleft
ADCSRA=0b11101011;//a16
return(ADCH);
};

int readadc__4()
{
ADMUX=0b01100000;//sharpleft
ADCSRA=0b11101011;
return(ADCH);//a18
};
int readadc__5()
{
ADMUX=0b11000000;//sharpleft
ADCSRA=0b11101011;
return(ADCH);//a19
};


int readadc11()
{
ADMUX=0b00000100;//sharpright
ADCSRA=0b11101011;
return(ADCH);//a20
};
int readadc12()
{
ADMUX=0b00000010;//sharpright
ADCSRA=0b11101011;
return(ADCH);//a21
};

int readadc14()
{
ADMUX=0b00000110;//sharpright
ADCSRA=0b11101011;
return(ADCH);//a23
};



int readadc00()
{
ADMUX=0b00000000;
ADCSRA=0b11101011;//goback
return(ADCH);//a25
};


int readadcjunc1()
{
ADMUX=0b00111100;
ADCSRA=0b11101011;//junc
return(ADCH);//a26
};
int readadcjunc2()
{
ADMUX=0b01011010;
ADCSRA=0b11101011;//junc
return(ADCH);//a27
};


//28 cases
void main()
{
DDRA=0b00000000;
DDRB=0b11111111;
int a,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28;
while(1)
{
a=127;
a1=readadc();
a2=readadc01();
a3=readadc10();
a4=readadc_1();
a5=readadc_2();

a7=readadc_4();
a8=readadc_5();
a9=readadc1();
a10=readadc2();
a12=readadc4();
a13=readadc5();
a14=readadc111();
a15=readadc__1();
a16=readadc__2();

a18=readadc__4();
a19=readadc__5();
a20=readadc11();
a21=readadc12();

a24=readadc14();
a25=readadc00();
a26=readadcjunc1();
a27=readadcjunc2();

if(((a>a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a>a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a>a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00000101;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a>a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a>a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a>a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a>a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a>a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00000100;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a>a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a>a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a>a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a>a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a>a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00000001;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a>a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a>a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a>a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a>a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a>a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00000110;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a>a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a>a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a>a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a>a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a>a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00001001;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a>a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00001111;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a>a25)&&(a<a26)&&(a<a27)&&(a<a28)))
PORTB=0b00001010;
if(((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a>a26)&&(a<a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a>a27)&&(a<a28))||((a<a1)&&(a<a2)&&(a<a3)&&(a<a4)&&(a<a5)&&(a<a6)&&(a<a7)&&(a<a8)&&(a<a9)&&(a<a10)&&(a<a11)&&(a<a12)&&(a<a13)&&(a<a14)&&(a<a15)&&(a<a16)&&(a<a17)&&(a<a18)&&(a<a19)&&(a<a20)&&(a<a21)&&(a<a22)&&(a<a23)&&(a<a24)&&(a<a25)&&(a<a26)&&(a<a27)&&(a>a28)))
PORTB=0b00000101;
}
}
