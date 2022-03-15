#include<p18f4520.h>

#define LED PORTDbits.RD1
#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config LVP=OFF

void delay( unsigned t){
unsigned int i,y;
	for( i=0;i<t;i++){
		for( y=1;y<123;y++);
		}
}
void main(){
	TRISD=0;
	ADCON1=0X0F;
	
	while(1){
		LED=0;
	delay(500);
		LED=1;
	delay(500);
	}
}
