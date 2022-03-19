#include<p18f4520.h>
#include<delays.h>
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT=OFF
#define PB PORTBbits.RB0
unsigned int dem=0;
void main(void)
{
	ADCON1=0x0f;
	TRISB=0b00001111;
	TRISD=0;
	while(1){
	while(PB);
	while(!PB);
	dem++;
	PORTD=1<<(dem-1);
	if(dem>=5)
	PORTD=15<<0;

}
