#include<p18f4520.h>

#pragma config MCLRE=ON
#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config WDT=OFF

#define button PORTDbits.RD0
#define led PORTDbits.RD1

void delay(unsigned int t){
	unsigned int x,y;
	for(x=1;x<t;x++){
		for(y=1;y<123;y++);
	}
}
void main(){
	TRISD=1;
	ADCON1=0x0f;
	while(1){
		if(button==1){
			led=1;
		}else{
			led=0;
		}
	}
}