//bipping buzzer
//all the lLEDS will glow initially  if any switch is pressed its corresponding LED should off.
#include<avr/io.h>		
#include "delay.h"		//This is the header for AVR Microcontroller.
int main(void)
{
	DDRC=0x08;					// Port C data direction configuration as output port.
	
	while(1)
	{
	 PORTC=0x08;
	 delayms(1000);
	 PORTC=0x00;
	 delayms(1000);
	
	}
	return 0;
}
