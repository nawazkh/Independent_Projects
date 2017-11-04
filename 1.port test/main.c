//Program to send data 01010000 to port C

#include<avr/io.h>			//basic header file for avr micro controllers

int main(void)
{
	
	DDRC=0b11110000;			// data direction declaration of port C higher bits as output port.	
	PORTC=0b01010000;			//sending binary data (01010000) to port C
	
	while(1)
	{
		
	}
}
