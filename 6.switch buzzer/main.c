//buzzer and switch
//all the lLEDS will glow initially  if any switch is pressed its corresponding LED should off.
#include<avr/io.h>				//This is the header for AVR Microcontroller.
int main(void)
{
	DDRC=0x08;					// Port C data direction configuration as output port.
	PORTA=0xF0;					// configuering the PORTA in pullup mode.
	DDRA=0x00;					// Port A data direction configuration as input port.
	
	while(1)
	{
	 if((PINA & 0x10)==0x00)	
	  {
	   PORTC=0x08;
	  }
	 else
	  {
	  PORTC=0x00;
      } 
	
	}
	return 0;
}
