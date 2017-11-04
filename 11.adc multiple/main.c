//Program to display digital value of ADC channel 0, channel 1 and channel 2

#include<avr/io.h>
#include"delay.h"
#include"uart.h"
#include"adc.h"

int main(void)
{
 adc_init();
 uartinit();
 while(1)
  {
   
   printchar(13);
   printnum(getdata(0x00));
   delayms(10);
   
  
   printchar(',');
   printnum(getdata(0x01));
   delayms(10);   
   
  
   printchar(',');
   printnum(getdata(0x02));
   delayms(10); 
  }
  
}