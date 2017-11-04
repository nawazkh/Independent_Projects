//UART rx
//program to glow the LED according to the key pressed

#include<avr/io.h>
#include "delay.h"
#include "uart.h"

int main(void)
{
	
uartinit();

printchar('a');								//to print a charactor
printchar('\n');							//newline							
printstring("varma");				//to print a string
printchar('\n');							//newline
printnum(210);								//to print a integer number
printchar('\n');							//newline
printchar('\n');							//newline
	
while(1)
  {
	
  }
}
  
