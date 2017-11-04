//Genarating time delay using timer
//toggling LED0 and buzzer at a perticular interval of time set by the timer
#include<avr/io.h>		//This is the header for AVR Microcontroller.
#include<avr/interrupt.h>

ISR (TIMER0_OVF_vect) //void timer0_ovf_isr(void)
{
	
	PORTC^=0x18;   //toggling LED4 and buzzer
}


int main(void)         
{
	DDRC=0xF8; 			// Port C data direction configuration as output port for buzzer and LED.
	TIMSK=0x01;			//This is for interrupt enable for timer0.
	TCCR0=0x05;			//This is for timer0 initialization.
	TCNT0=0x00;
	sei();
	
 while(1)
  {
        
  }
  
}
