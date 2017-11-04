#include<avr/io.h>
#include"delay.h"
#include<avr/interrupt.h>
#include"adc.h"
#include"servo.h"

int main(void)
{
 unsigned char actual1,actual,x,past1,past;
 DDRD=0xf0;
 adc_init();
  servo_init();
 while(1)
  {
   actual1=getdata(0);	//read ADC from channel 0 for base motor
   actual=getdata(1);	//read ADC from channel 1 for claw motor
   x=getdata(2);	//read ADC from channel 2 for servo motor
   deg(x,0);
    PORTD=0x00;
   if(actual1>past1) 
    {
	 PORTD=0x40;
   }
   if(actual1<past1) 
    {
	 PORTD=0x80;
    }
  
   if(actual>past) 
    {
	 PORTD|=0x10;
   }
   if(actual<past) 
    {
	 PORTD|=0x20;
    }
     
   delayms(1);	
   
   past1=actual1;
   past=actual;
  }
  
}