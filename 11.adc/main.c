//Program to display digital value of ADC channel 0

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
  // getdata(0x00);
   printchar(13);
   printnum(getdata(0x00));
   delayms(100);   
  }
  
}