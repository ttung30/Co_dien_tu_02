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
	while(PB);// chờ cho nút nhấn
	while(!PB);// chờ nút nhả
	dem++;// sau khi thực hiện 1 chu trình nhấn nhả mới tăng biến đếm, khong đươc dùng thẳng if bởi vì khi nhấn nút nó sẽ không hiểu là nhấn bao nhiêu lần
	PORTD=1<<(dem-1);// ví dụ lần dầu nhân dem =1 thì phải trừ đi 1 để dịch trái từ 0
	if(dem>=5)
	PORTD=15<<0;// dịch trái sau 15 lần nhấn

}
}
