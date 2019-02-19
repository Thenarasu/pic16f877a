/*-----------------------------------------------------------------*/
/*	Author      : 	Thennarasu.D				   */
/*	Date	    :	11jun2018				   */
/*	Filename    :	display_10.c				   */
/*	Description :   Display 10 using 7-segment 		   */
/*-----------------------------------------------------------------*/

#include <htc.h>

void delay()
{
	int i;
	for(i=0;i<=300;i++);
}

int main()
{
	TRISB = 0;
	TRISC = 0;
    while(1)
	{
		RC0 = 1;
		RC1 = 0;
		PORTB = 0X60;
		delay();
		RC0 = 0;
		RC1 = 1;
		PORTB = 0XFC;
		delay();
		
	}
}
