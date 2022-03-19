#include<p18f4520.h>
#include<delays.h>
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB0
int i=0;
void main(void)
{
	ADCON1=0x0f;
	TRISB=0b00001111;
	TRISD=0;
	while(1){
		
	if(PORTB==3)
		i=3;
	if(PORTB==1)
		i=2;
	if(PORTB==2)
		i=1;
	if(PORTB==0)
		i=0;
			
	PORTD=1<<i;
	
}
}
