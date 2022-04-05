#include<p18f4520.h>
#include<delays.h>
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF
//khai báo tên chương trình con phục vụ ngắt (CTCPVN)
void ngat_ngoai(void);
//Điểm đặt chương trình phục vụ ngắt có mức ưu tiên cao //(vector 0008H)
#pragma code uu_tien_cao = 0x08
//Tên CTCPVN ưu tiên cao (tùy chọn)
void ngat_cao(void)
{
 ngat_ngoai(); //gọi đến CTCPVN
}int i=0;
//Điểm viết CTCPVN
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
{T0CONbits.TMR0ON=0;
 INTCONbits.TMR0IF=0;
 for(i=0;i<5;i++){
 	PORTDbits.RD0=0;
 	PORTDbits.RD1=1;
	Delay10KTCYx(100);
	PORTDbits.RD1=0;
	Delay10KTCYx(100);	
}

} 
void main()
{	ADCON1=0X0F;
	TRISD=0;
	INTCONbits.GIE=1;
	INTCONbits.TMR0IE=1;
	T0CON=0B00000100;
	INTCON2bits.TMR0IP=1;	

	while(1)
	{	
	TMR0L=(65536-15625)%256;
	TMR0H=(65536-15625)/256;
	T0CONbits.TMR0ON=1;
	PORTDbits.RD0=1;
	Delay10KTCYx(50);
	PORTDbits.RD0=0;
	Delay10KTCYx(50);
	}	
}	
