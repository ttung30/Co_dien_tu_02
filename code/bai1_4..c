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
		//bat dau xet dieu kien neu dung if else se hợp lý hơn
	if(PORTB==3)//11 nhấn nhấn  pb2 pb1
		i=3;
	if(PORTB==1)//01 nhả nhấn
		i=2;
	if(PORTB==2)//10 nhấn nhả
		i=1;
	if(PORTB==0)//00 nhả nhả
		i=0;
			
	PORTD=1<<i;// xuất dữ liệu vừa xét ra port
	
}
}
