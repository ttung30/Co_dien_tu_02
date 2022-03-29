#include<p18f4520.h>
#include<stdio.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF
unsigned int dem=0;

void ngat_ngoai(void);

#pragma code uu_tien_cao = 0x08

void ngat_cao(void)
{
ngat_ngoai();
}

#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)

{ 
	INTCON3bits.INT1IF=0;
	dem++;
}

void main()
{
ADCON1=0x0F;
TRISD=0; 
INTCONbits.GIE=1;
INTCON3bits.INT1IE=1;  
INTCON2bits.INTEDG1=1; //ngat bang suon am
while(1)
{

PORTD=0b00001000|dem;
Delay10KTCYx(50);
PORTD=0b11110111&dem;
Delay10KTCYx(50);
if(dem>7){
	INTCON3bits.INT1IE=0;
}	
} 

}
