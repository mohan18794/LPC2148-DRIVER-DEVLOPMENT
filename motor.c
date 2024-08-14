#include<lpc21xx.h>
void delay(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<268;j++);
	}
}
int main()
{
	PINSEL0=0x00;
	IODIR0=0xe000;
	while(1)
	{
		IOSET0=0x6000;
		IOCLR0=0x8000;
		delay(100000);
		IOCLR0=0xe000;
		delay(100000);
		IOSET0=0xA000;
		IOCLR0=0x4000;
		delay(100000);
		IOCLR0=0xe000;
		delay(100000);
	}
}
		
		