//program to control a servo using time delay
#include<avr/io.h>
#include "delay.h" //header file for genarating time delay
int main()
 {
  PORTA=0XFF;		//initialization of port A in pullup mode
  DDRA=0X00;		//configuring port A as input port
  PORTB=0X00;		//initialization of port B all bits low 
  DDRB=0XFF;		//configuring port B as output port
   while(1)
   {
    if((PINA&0x10)==0x00)		//if sw1 is pressed //rotate the servo to minimum degree
	 {
		while((PINA&0x10)==0x00)	//while sw1 is pressed
		 {
			PORTB=0X00;				
			delayus(18000);		
			PORTB=0XFF;
			delayus(2000);
		 }
	 }	 
	
	if((PINA&0x20)==0x00)		//if sw2 is pressed //rotate the servo to maximum degree
	 {
		while((PINA&0x20)==0x00)		//while sw2 is pressed
		 {
			PORTB=0X00;			
			delayus(19000);
			PORTB=0XFF;
			delayus(1000);
		 }
	 }	 
	 
	if((PINA&0x40)==0x00)			//if sw2 is pressed //rotate the servo to middle degree
	 {
		while((PINA&0x40)==0x00)		//if sw2 is pressed
		 {
			PORTB=0X00;
			delayus(18500);
			PORTB=0XFF;
			delayus(1500);
		 }
	 }	  
   }
 }