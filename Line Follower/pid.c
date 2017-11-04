#include "nawaz/LotL.h"

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
	LCDWriteString("NAWAZ");		
	delay(1);
	DispMenu(0);							//displays home screen
	
	while(true)
	{		
		if(pause == false)					
		{					
			CalcError();			
			
			if((s1+s2+s3+s4+s5+s6+s7+s8) == 0)		//robot has overshot
			{
				if(lastreading == 'r')				//checks if the last sensor to the activated was right
				{
					RightMB();						//turn right at full speed
					LeftMF();
					OCR1A = 255;
					OCR1B = 255;	
				}
				
				else if(lastreading == 'l')			//checks if the last sensor to the activated was left
				{
					RightMB();						//turn left at full speed

					LeftMF();	
					OCR1A = 255;
					OCR1B = 255;					
				}	
			
			}			
				
			
			else  									//robot on line
			{	
				P = error * Kp;
				
				I += error;
				I = I * Ki;
				
				D = error - perror;
				
				correction = P + I + D;
				
				rightpulse =  basespeed + correction;
				leftpulse = basespeed - correction;				
				
			
			
					
				if(leftpulse > 255)
				leftpulse = 255;
				
				if(rightpulse > 255)
					rightpulse = 255;	

				OCR1A = leftpulse;
				OCR1B = rightpulse;	
				
				if(P<0)
				{
				LeftMS();
				RightMF();
				}
				
				if(P>0)
				{
				LeftMF();
				RightMS();
				}
				
				if(P==0)
				{
				LeftMF();
				RightMF();
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
