//LED and switch
//all the lLEDS will glow initially  if any switch is pressed its corresponding LED should off.
#include<avr/io.h>				//This is the header for AVR Microcontroller.
int main(void)
{
	DDRC=0xF0;					// Port B data direction configuration as output port.
	PORTA=0xFF;					// configuering the PORTA in pullup mode.
	DDRA=0x00;					// Port A data direction configuration as input port.
	
	while(1)
	{
		
	PORTC=PINA;
	}
	return 0;
}
