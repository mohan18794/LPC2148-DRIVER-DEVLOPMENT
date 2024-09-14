#include<lpc21xx.h>
void uart()
{
	PINSEL0=0x05;
	U0LCR=0x83;
	U0DLL=97;
	U0LCR=0x03;
}
void main(){
	int x;
	uart();
	while(1){
		while(!(U0LSR &0x01));
		x=U0RBR;
		U0THR=x;
		while(! (U0LSR &0x20));
	}
}
