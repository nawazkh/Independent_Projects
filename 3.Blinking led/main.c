//program to blink all the LEDS connected in PORTC
#include<avr/io.h>		//This is the header for AVR Microcontroller.
#include "delay.h"  //header file to generate time delay.

int main(void)
 {	
	DDRC=0xF0;			// Port C data direction declaration as out put.
	while(1)			//This is for the the infinity loop.
	{	
	 PORTC=0XF0;
	 delayms(1000);
	 PORTC=0X00;
	 delayms(1000);
	}
	return 0;
}
