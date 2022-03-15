#include<p18f4520.h> 
#include<delays.h>
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 
//khai báo tên chuong trình con ph?c v? ng?t (CTCPVN) 
void ngat_ngoai(void); 
//Ði?m d?t chuong trình ph?c v? ng?t có m?c uu tiên cao //(vector 0008H) 
#pragma code uu_tien_cao = 0x08 
//Tên CTCPVN uu tiên cao (tùy ch?n) 
void ngat_cao(void) 
{ 
 ngat_ngoai(); //g?i d?n CTCPVN 
} 
//Ði?m vi?t CTCPVN 
#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{ 
//Ki?m tra bit c? c?a ngu?n ng?t th? nh?t, n?u = 1. 
if(INTCONbits. INT0IF==1)
{ 
PORTD=2;//chan 2 sang
Delay10TCYx(2500);
//Xóa c? c?a ngu?n ng?t th? nh?t 
//Các l?nh x? lý khi có ng?t t? ngu?n th? nh?t 
}
INTCONbits. INT0IF=0;// xoa co ngat
} 
//Chuong trình chính 
void main() 
{ 
ADCON1=0x0f;
TRISB=7;
TRISD=0;
INTCON=0b10010000;

INTCON2bits.INTEDG0=0;


// blink led1
while(1)
{
PORTD=1;
Delay10TCYx(250);
PORTD=0;
Delay10TCYx(250);
}

} 