/*
 * LED_0220_HJP.c
 *
 * Created: 2018-02-20 오전 9:25:32
 * Author : stc_180
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void l_sh();
void r_sh();
unsigned char a;
///////////////////////////////////////////////////////////////////////
int main(void)
{
    /* Replace with your application code */
	DDRC = 0xff;
	PORTC = 0x00;
	DDRF = 0x00;
	PORTF = 0xff;
	DDRA = 0xff;
	PORTA = 0x00;
	
    while (1) 
    {
		if ((a&0x01)==0)
		{
			l_sh();
		}
		else if ((a&0x02)==0)
		{
			r_sh();
		}
	}
}
void l_sh()
{
	do 
	{
		a=0x01;
		while(a!=0x00)
		{
			PORTC=a;
			a<<=1;
			_delay_ms(200);
		}
		PORTC=a;
		
		a=0x80;
		while(a!=0x00)
		{
			PORTA=a;
			a>>=1;
			_delay_ms(200);
		}
		PORTA=a;
	} while (((a&0x01)!=0)&&((a&0x02)==0));
}
void r_sh()
{
	do 
	{
			a=0x01;
			while(a!=0x00)
			{
				PORTA=a;
				a<<=1;
				_delay_ms(200);
			}
			PORTA=a;
			
			a=0x80;
			while(a!=0x00)
			{
				PORTC=a;
				a>>=1;
				_delay_ms(200);
			}
			PORTC=a;
		} while (((a&0x01)!=0)&&((a&0x02)==0));
}