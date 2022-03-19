#include<p18f4520.h>
#include<delays.h>
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB1
unsigned int dem=0;
void main(void)
{
	ADCON1=0x0f;
	TRISB=0b00000011;
	TRISD=0;
	while(1){
	if(PORTBbits.RB0==1)
	{
		PORTD=0;
		dem=0;
	}
    else{
	while(PB2);
	while(!PB2);
	dem++;
	if(dem==1)
	{
		PORTD=1<<3;
	}else
	{
		if(dem==2)
		{
			PORTD=1<<2;
		}else
	{
		if(dem>=3)
		{
			PORTD=3<<2;
		}	
	}	
	}		
	}	
	
}
}
