/*------------------------------------------------------------------*/
/*	Author	    : Thennarasu.D				    */
/*	Date	    : 6Jan2019					    */
/*	Filename    : pwm.c					    */
/*	Description : Pulse_Width_modulation			    */
/*------------------------------------------------------------------*/




#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(HS & WDTDIS & PWRTDIS & BOREN & LVPDIS );

void delay();

int main()
{
	unsigned char i=0;
	TRISC2 	= 0; //ccp1 output
	CCP1CON	= 0x3C;
	TMR2 	= 0;
	PR2 	= 0xFF;
	T2CON 	= 0x07;
	CCPR1L 	= 0x10;
	delay();
	
	for (i=0;i<16;i++)
	{
		CCPR1L = CCPR1L + 0x10 ;
		delay();
	}
	
}

void delay()
{
		TMR1CS=0;
		
		T1CKPS0=1;
		T1CKPS1=1;
		TMR1H=0X3C;		
		TMR1L=0XB0;
		TMR1ON=1;
		while(!TMR1IF);
				TMR1IF=0;
				TMR1ON=0;
}
