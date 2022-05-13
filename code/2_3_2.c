#include <p18f4520.h>
#include <pwm.h>
#include <P18f4520.h>                
#include <timers.h>
//C?u hình cho vi di?u khi?n, ví d?:
#pragma config OSC = HS 	//ch? d? dao d?ng HS
#pragma config MCLRE = ON 	//s? d?ng RE3 làm chân reset (OFF: không s? d?ng)
#pragma config WDT = OFF 	//không dùng Watchdog timer
#pragma config PBADEN = OFF 	//PORTB<4:0> du?c c?u hình thành các chân vào/ra s?
					//ON: PORTB<4:0> du?c c?u hình thành các chân AN8-AN12
#pragma config PWRT=ON 	// s? d?ng Power-up timer
#pragma config BOREN=OFF 	// không s? d?ng ch?c nang Bown-out reset 
//(reset khi Vdd xu?ng th?p du?i 1 ngu?ng)
#pragma config LVP=OFF		//không d?ng ch? d? c?p ngu?n ch? t? m?ch n?p
//(Single-Supply ICSP Programming)
#pragma config CCP2MX = PORTBE    // cau hinh CCP2 tren PORTB (CCP2A/RB3)
void main()
{	
TRISB =0;  // chon CCP1 co chieu ra
OpenTimer2(T2_PS_1_16);
//T2CON=0b00000001;	// he so chia(TMR2 Prescale Value) = 4 
ADCON1=0X0F;	// ADC OFF
OpenPWM2(14);  	// PWM_Period = 80 us 
SetDCPWM2(15);	// PWM Duty Cycle = 20 us
while(1);
}
