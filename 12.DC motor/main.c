//program to control a DC motor

#include<avr/io.h>
#include"delay.h"
#include"uart.h"
#include"adc.h"

int main(void)
{
 DDRD=0xF0;     //Setting the data direction of Port-D where motors are connected
 DDRC=0xf0;		//Setting the data direction of Port-C where LED are connected
 while(1)
  {
   PORTD=0x80;		//moving motor clockwise
   PORTC=0x80;		//LED4 on
   delayms(1000);
   PORTD=0x40;		//moving motor anticlockwise
   PORTC=0x40;		//LED3 on
   delayms(1000);
  
  }
  
}