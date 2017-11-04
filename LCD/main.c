//printing a string in LCD
#include<avr/io.h>
#include<avr/delay.h>
#include<avr/lcd.h>	//header file for interfacing LCD
int main()
 {
  lcd_init();					//function to initialize the LCD
  lcd_string("varma");	//function to print a string
  while(1)
   {
   
   }
   return 0;
 }