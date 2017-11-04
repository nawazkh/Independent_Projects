//program to control position of a DC motor by potentiometer

#include<avr/io.h>
#include"delay.h"
#include"uart.h"
#include"adc.h"

int main(void)
{
 unsigned char digital,predigital;
 DDRD=0xf0;
 adc_init();
 uartinit();
 while(1)
  {
   digital=getdata(0);		//read ADC from channel 0
   
   printnum(digital);		//print the ADC value in hyper terminal
   printchar(13); 			//carriage return for hyper terminal	
   
   if(digital>predigital) 
    {
	 PORTD=0x40;
	}
   if(digital<predigital) 
    {
	 PORTD=0x80;
	}
  if(digital==predigital) 
    {
	 PORTD=0x00;
	}	
   delayms(1);	
   predigital=digital;
  }
  
}