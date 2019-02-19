/*-------------------------------------------------*/
/*	Auhor	    : Thennarasu.D		   */
/*	Date	    : 28june2018		   */
/*	Filename    : led_blink.c	 	   */
/*	Description : led blinking 		   */
/*-------------------------------------------------*/


#include <htc.h>

void delay()
{
		TMR1H = 0X0B;
		TMR1L = 0XDB;
		TMR1ON = 1;
		while(!TMR1IF);
		TMR1IF = 0;
		TMR1ON = 0;
}

int main()
{
	char value = 0X01,i;
	T1CKPS0 = 1;  //timer1 clock PS0 = 1
	T1CKPS1 = 1;  //timer1 clock PS1 = 1
	TMR1CS = 0;   //timer1 clock source select bit
	TMR1H = 0X0B; //holding register for the most significant byte of the 16-bit TMR1 register
	TMR1L = 0XDB; //holding register for the register most significant byte on the 16-bit TMR1 register
	TRISB = 0;	  
	while(1)
	{
		for(i=0;i<8;i++)
		{
			PORTB = value;
			value = value<<1;
			delay();
		}
		value = 0x01;
	}
	
}
