//khai báo các thu vi?n, ví d?:
#include <P18f4520.h>
#include <delays.h>
#include <adc.h>
//C?u hình cho vi di?u khi?n, ví d?:
#pragma config OSC = HS //ch? d? dao d?ng HS
#pragma config MCLRE = ON //s? d?ng RE3 làm chân reset (OFF: không s? d?ng)
#pragma config WDT = OFF //không dùng Watchdog timer
#pragma config PBADEN = OFF //PORTB<4:0> du?c c?u hình thành các chân vào/ra s?
//ON: PORTB<4:0> du?c c?u hình thành các chân AN8-AN12
#pragma config PWRT=ON // s? d?ng Power-up timer
#pragma config BOREN=OFF // không s? d?ng ch?c nang Bown-out reset
//(reset khi Vdd xu?ng th?p du?i 1 ngu?ng)
#pragma config LVP=OFF //không d?ng ch? d? c?p ngu?n ch? t? m?ch n?p
//(Single-Supply ICSP Programming)
/*khai báo bi?n s?,h?ng s?,c?u trúc,chuong trình con, ví d?:*/
int x;
char m[10];
//Khai báo tên các chuong trình con, ví d?:
void high_isr (void);
//vi?t các chuong trình con, ví d?:
void high_isr (void)
{
//các câu l?nh
}
float dienap;
//chuong trình chính
void main (void)
{
ADCON1=0b00001110;
TRISA=0xFF; TRISD=0; TRISC=0; TRISEbits.TRISE1=0;
OpenADC(ADC_FOSC_16&ADC_RIGHT_JUST&ADC_8_TAD,ADC_CH0&
ADC_INT_OFF&ADC_VREFPLUS_VDD&ADC_VREFMINUS_VSS,0b1110);
while(1)
{
ConvertADC();
while(BusyADC()); //cho bien doi xong
x=ReadADC();

dienap=(5*x)*1.0/1023;

PORTC=x/256;
PORTD=x%256;
if(dienap>=3)
{
	PORTE=2;
}
else
{
	PORTE=0;
}	
}
}
