#include <P18f4520.h>
#include <delays.h>
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
//chuong trình chính
#define xung PORTDbits.RD0
void main (void)
{
ADCON1=0x0f;
TRISD=0;
T0CON=0b00000100;

xung=0;
while(1){
TMR0L=(65536-1875)%256;
TMR0H=(65536-1875)/256;
T0CONbits.TMR0ON=1;
	while(!INTCONbits.TMR0IF);
	xung= ~xung;
	INTCONbits.TMR0IF=0;
T0CONbits.TMR0ON=0;
}	
} 
