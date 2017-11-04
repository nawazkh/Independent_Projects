//motor LED and Buzzer control usiing PWM
#include<avr/io.h>		//This is the header for AVR Microcontroller.
#include<avr/interrupt.h>
#include"delay.h"

ISR (TIMER0_OVF_vect) //void timer0_ovf_isr(void)
{
	PORTD=0x50;     //motor
	PORTC=0x18;		//LED-4 and buzzer
}

ISR (TIMER0_COMP_vect)
{
	PORTD=0x00;
	PORTC=0x00;
}


int main(void)         
{
	
	DDRD=0xFF; 			// Port B data direction configuration as output port.
	DDRC=0x18;
	PORTA=0xf0;
	TIMSK=0x03;			//This is for interrupt enable for timer0.
	TCCR0=0x4A;			//This is for timer0 initialization.
	TCNT0=0x00;
	OCR0=150;
	sei();
	
 while(1)
  {
	if((PINA & 0x10)==0)
		{
		delayms(15);
		OCR0++;
		if(OCR0>=251){OCR0=251;}
		}
	if((PINA & 0x20)==0)
		{
		delayms(15);
		OCR0--;
		if(OCR0<=3){OCR0=3;}
		}	
  }
  
}
