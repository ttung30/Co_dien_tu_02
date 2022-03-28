#include<p18f4520.h>
#include<stdio.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF
#define LED1	PORTCbits.RC1 
#define LED2	PORTCbits.RC2 

unsigned int dem=0;

void ngat_ngoai(void);

#pragma code uu_tien_cao = 0x08

void ngat_cao(void)
{
ngat_ngoai();
}
	 int i;
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)

{ 
	INTCONbits.INT0IF=0;
	LED1=0;
	for(i=0;i<5;i++)
	{
		LED2=1;
		Delay10KTCYx(100);
		LED2=0;
		Delay10KTCYx(100);
		}
}

void main()
{
ADCON1=0x0F;
TRISC=0; 
 //ngat bang suon am
TRISB=7;
INTCONbits.GIE=1;
INTCONbits.INT0IE=1;
INTCON2bits.INTEDG0=0;
 
while(1)
{
		LED1=1;
		Delay10KTCYx(100);
		LED1=0;
		Delay10KTCYx(100);
}
}
