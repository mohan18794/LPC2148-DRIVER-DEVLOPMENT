#include<lpc21xx.h>
void delay(int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<268;j++);
	}
}
	void main(){
		int i,j;
		PINSEL0=0x00;
		IODIR0=0xf000;
		while(1)
		{
			for(i=0;i<16;i++)
			{
				IOSET0=1<<i;
				delay(10000);
			}
			for(i=0;i<16;i++)
			{
				IOCLR0=1<<i;
				delay(1000);
			}
		}
	}