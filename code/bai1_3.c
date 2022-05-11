#include<p18f4520.h>
#include<delays.h>
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT=OFF
#define PB1 PORTBbits.RB0
unsigned int dem=0,n=0;
void main(void)
{
	ADCON1=0x0f; // thiết lập vào ra số
	TRISB=0b00001111;// chọn chiều vào cho 4 đầu tiên trên port B
	TRISD=0;// thiết lập chiều vào cho port D
	while(1){
	while(PB);
	while(!PB);
	dem++;
	n=dem%16;
	PORTD=n;// xuất giá trị ra PortD

}
}
