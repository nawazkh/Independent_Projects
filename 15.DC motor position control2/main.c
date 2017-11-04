//program to control position of a multiple DC motor by potentiometer

#include<avr/io.h>
#include"delay.h"
#include"uart.h"
#include"adc.h"

int main(void)
{
 unsigned char digital1,digital2,predigital1,predigital2;
 DDRD=0xf0;
 adc_init();
 uartinit();
 while(1)
  {
   digital1=getdata(0);		//read ADC from channel 0
   digital2=getdata(1);		//read ADC from channel 1
   
  // printnum(digital1);		//print the ADC value in hyper terminal
  // printchar(','); 
  // printnum(digital2);		//print the ADC value in hyper terminal
  // printchar(13); 			//carriage return for hyper terminal	
   
    PORTD=0x00;
   if(digital1>predigital1) 
    {
	 PORTD=0x40;
	}
   if(digital1<predigital1) 
    {
	 PORTD=0x80;
	}
  
   
   if(digital2>predigital2) 
    {
	 PORTD|=0x10;
	}
   if(digital2<predigital2) 
    {
	 PORTD|=0x20;
	}
     
   delayms(1);	
   
   predigital1=digital1;
   predigital2=digital2;
  }
  
}