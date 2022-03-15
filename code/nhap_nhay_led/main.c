#include<p18f4520.h>
#include<delays.h>
#pragma config MCLRE=ON
#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config WDT=OFF


#define led PORTDbits.RD1

void delay(unsigned int t){
	unsigned int x,y;
	for(x=1;x<t;x++){
		for(y=1;y<123;y++);
	}
}
void main(){
	TRISD=0;
	ADCON1=0x0f;
	while(1){
		PORTD=1<<1;
		Delay10TCYx(250);
		PORTD=0<<1;
		Delay10TCYx(250);
	}
}
