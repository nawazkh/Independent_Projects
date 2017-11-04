#include "nawaz/LotL.h"

void assign(void)
{
if(PINA==(PINA=(1<<PA7)))
{
s1=1;
}

if(PINA==(PINA=(1<<PA6)))
{
s2=1;
}
if(PINA==(PINA=(1<<PA5)))
{
s3=1;
}
if(PINA==(PINA=(1<<PA4)))
{
s4=1;
}
if(PINA==(PINA=(1<<PA3)))
{
s5=1;
}
if(PINA==(PINA=(1<<PA2)))
{
s6=1;
}
if(PINA==(PINA=(1<<PA1)))
{
s7=1;
}
if(PINA==(PINA=(1<<PA0)))
{
s8=1;
}
}

SIGNAL (SIG_INTERRUPT0)						// left switch
{
	delay(0.3);	
	
	switch(menu)
	{
		case 0:
			if(pause == true)
				pause = false;
			menu = 10;
			break;
		case 10:
			if(pause == false)
				pause = true;	
			menu = 0;
			break;
		case 20:
			menu = 80;
			break;
		case 30:
		case 40:
		case 50:			
		case 60:
		case 70:
		case 80:
			menu -= 10;	
			break;
		case 25:
			maxspeed--;
			break;
		case 35:
			basespeed--;
			break;
		case 45:
			Kp--;
			break;
		case 55:
			Ki--;
			break;
		case 65:
			Kd--;
			break;
	}
	DispMenu(menu);
}

SIGNAL (SIG_INTERRUPT2)						// middle switch		
{
		delay(0.3);	
		switch(menu)
		{			
			case 20:
			case 30:
			case 40:
			case 50:
			case 60:
			case 70:
				menu += 5;
				break;
			case 80:
				menu = 0;
				break;
			case 25:
			case 35:
			case 45:
			case 55:
			case 65:
			case 75:
				menu -= 5;
				break;				
		}
		DispMenu(menu);		
		
	

}

SIGNAL (SIG_INTERRUPT1)				// right switch	
{
	delay(0.3);
	
	switch(menu)
	{
		case 0:
		case 10:
			menu = 20;
			break;
		case 20:			
		case 30:
		case 40:
		case 50:	
		case 60:
		case 70:
			menu += 10;	
			break;
		case 80:
			menu = 20;	
			break;
		case 25:
			maxspeed++;
			break;
		case 35:
			basespeed++;
			break;
		case 45:
			Kp++;
			break;
		case 55:
			Ki++;
			break;
		case 65:
			Kd++;
			break;
	}
	DispMenu(menu);
}

int main(void)
{	
	unsigned int p;
	
	//call all initializing functions
	InitPorts();
	InitInterrupts();
	InitPWM();		
	InitLCD(0);								//LS_BLINK|LS_ULINE
	LCDClear();
	sei();								//enables interrupts
	
	//prints the openning screen
	BacklightOn();	
	LCDClear();
	LCDGotoXY(0,0);
	LCDWriteString("Lord ofthe Lines");
	delay(1);
	
	LCDGotoXY(3, 1);
	LCDWriteString("$Nawaz$");		
	delay(1);
	DispMenu(0);							//displays home screen
	
	while(true)
	{		
		if(pause == false)					
		{					
				
			
			if((PINA==0b00000000))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;
				
PORTD=(1<<PD0) | (0<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A = 255-leftpulse;
				OCR1B = 255-rightpulse;
}			
				
			
			else  									//robot on line
			{
			
			
			
				
							
if(PINA==0b00011000||PINA==0b00010000||PINA==0b00001000)
{
assign();

	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A = 255-leftpulse;
				OCR1B = 255-rightpulse;
}

if((PINA==0b00110000||PINA==0b00111000||PINA==0b01011000||PINA==0b01111000||PINA==0b11111000||PINA==0b11100000))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=(0<<PD0) | (0<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A =255-leftpulse;
				OCR1B =255-rightpulse;
}

if((PINA==0b00001100||PINA==0b00011100||PINA==0b00011010||PINA==0b00011110||PINA==0b00011111||PINA==0b00000111))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (0<<PD7);
OCR1A =255-leftpulse;
				OCR1B =255-rightpulse;
}

if((PINA==0b11111111))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=0b00000000;
OCR1A =255-leftpulse;
				OCR1B =255-rightpulse;
}





if((PINA==0b00111100||PINA==0b01011010||PINA==0b10011001))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (0<<PD7);
OCR1A = 255-leftpulse;
				OCR1B = 255-rightpulse;
}

if((PINA==0b00000100||PINA==0b00000010||PINA==0b00000001||PINA==0b00000110||PINA==0b00000011||PINA==0b00011011||PINA==0b00001110||PINA==0b00011001))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=(0<<PD0) | (1<<PD1) | (0<<PD6) | (0<<PD7);
OCR1A = 255-leftpulse;
				OCR1B = 255-rightpulse;

}


if((PINA==0b00100000||PINA==0b01000000||PINA==0b10000000||PINA==0b01100000||PINA==0b11000000||PINA==0b11011000||PINA==0b01110000||PINA==0b10011000))
{
assign();
	CalcError();
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;	
PORTD=(0<<PD0) | (0<<PD1) | (0<<PD6) | (1<<PD7);
OCR1A = 255-leftpulse;
				OCR1B = 255-rightpulse;

}

			
							
			}
		}
	
		_delay_ms(10);
	}
		
}

void DispMenu(int m)
{
	switch(m)
	{
		case 0:
			
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Lord ofthe Lines");
			
			LCDGotoXY(0 ,1);
			LCDWriteString("Start");	
			LCDGotoXY(8 ,1);
			LCDWriteString("Settings");
			break;
			
		case 10:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Lord ofthe Lines");
			
			LCDGotoXY(0 ,1);
			LCDWriteString("Pause");	
			LCDGotoXY(8 ,1);
			LCDWriteString("Settings");
			break;
		
		case 20:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("1. Max Speed");
			break;		
			
		case 30:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("2. Base Speed");
			break;
			
		case 40:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("3. Propotional");
			break;
		
		case 50:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("4. Integral");
			break;
			
		case 60:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("5. Derivative");
			break;
		
		case 70:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("7. Adjust Sensor");
			break;
		
		case 80:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("6. Done");
			break;
		
		case 25:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("Max Speed: ");
			LCDWriteInt(maxspeed, 3);
			break;		
			
		case 35:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("Base Speed: ");
			LCDWriteInt(basespeed, 3);
			break;
			
		case 45:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("Propotional: ");
			LCDWriteInt(Kp, 2);
			break;
		
		case 55:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("Integral: ");
			LCDWriteInt(Ki, 2);
			break;
			
		case 65:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Settings");
			
			LCDGotoXY(0, 1);
			LCDWriteString("Derivative: ");
			LCDWriteInt(Kd, 2);
			break;
		case 75:
			LCDClear();
			LCDGotoXY(0, 0);
			LCDWriteString("Sensors");			
			DispAdjustmentMenu();
			break;
	}
}

void DispAdjustmentMenu(void)
{		
	
	LCDGotoXY(0, 1);
	LCDWriteInt(s1, 1);	
	
	LCDGotoXY(2, 1);
	LCDWriteInt(s2, 1);
	
	LCDGotoXY(4, 1);
	LCDWriteInt(s3, 1);

	LCDGotoXY(6, 1);
	LCDWriteInt(s4, 1);
	
	LCDGotoXY(9,1);
	LCDWriteInt(s5, 1);

	LCDGotoXY(11, 1);
	LCDWriteInt(s6, 1);	

	LCDGotoXY(13, 1);
	LCDWriteInt(s7, 1);	
	
	LCDGotoXY(15, 1);
	LCDWriteInt(s8, 1);			
	
		
}
