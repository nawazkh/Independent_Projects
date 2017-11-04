#include<avr/io.h>
#include<avr/signal.h>
#include<avr/delay.h>

volatile int flag=0;

void init_timer(unsigned int TOP)
{       TCCR1A |= 0xA2;
                TCCR1B |= 0x12;
                        ICR1 = TOP;
                                OCR1B = 0;
								OCR1A = 0;

}

void moveleft(void)
{
	OCR1A=350;
	OCR1B=200;flag=1;
	//_delay_ms(100);
}

void movestrongleft(void)
{
	OCR1A=300;
	OCR1B=50;flag=2;
	//_delay_ms(5);
}

void moveright(void)
{
	OCR1A=200;
	OCR1B=350;flag=3;
	//_delay_ms(100);
}

void movestrongright(void)
{
	OCR1A=50;
	OCR1B=300;flag=4;
	//_delay_ms(5);
}

void moveforward(void)
{
	OCR1A=250;
	OCR1B=250;flag=5;
	//_delay_ms(100);
}

void stop(void)
{
	//int j;
	OCR1B = 0;
	OCR1A = 0;
	flag=0;
	//for(j=0;j<10;j++)
	//_delay_ms(100);
	
}

int main(void)
{

	int i=0,j,k;
	char  path[14]={'F','F','F','F','F','F','F','F','F','F','F','F','F','F'};
	
	
	DDRC=0;
	PORTC=0;
	DDRB=0xFF;
	init_timer(600);
	
	k=1;
	while(1)
	{
		
		i=PINC&7;
		j=PINC&8;
	
		if(i==3) moveright();
		else if(i==6) moveleft();
		else if(i==1) movestrongright();
		else if(i==4)	movestrongleft();
		else if( (i==2)|(i==7) ) moveforward();
		
		else 
		{
			if(flag==1)	moveleft();
			else if(flag==2)	movestrongleft();
			else if(flag==3)	moveright();
			else if(flag==4)	movestrongright();
			else if(flag==5|flag==0)	moveforward();
		//	else if(flag==6)
		}
		if ((j>>3)&1)
		{   
			if(path[k]=='F')flag==0;
			else if(path[k]=='L')
			{
				movestrongright();
				_delay_ms(5);
				while(1)
				{
					i=PINC&7;
					if(i==1)break;
				}
				flag=0;
			}
			else if(path[k]=='R')
			{
				movestrongleft();
				_delay_ms(10);
				while(1)
				{
					i=PINC&7;
					if(i==1)break;
				}
				flag=0;
			}
		     k=k+2;
		}
				i=0;
	}
}	
	
