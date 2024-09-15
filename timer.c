
#include<lpc21xx.h>
void delay(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<268;j++);
	}
}
void timer(void)
{
	int i;
	T0IR=0x01;
	IODIR0=0xf000;
	for(i=15;i>11;i--)
	{
		IOSET0=1<<i;
		delay(1000000);
	}
	for(i=15;i>11;i--)
	{
		IOCLR0=1<<i;
		delay(100000);
		}
	VICVectAddr0=0x00;
}
void timer_init(void)
{
	PINSEL0=0x20;
	T0TCR=0x02;
	T0MCR=0x03;
	T0MR0=1500000;
	VICVectAddr0=(unsigned long)timer;
	VICVectCntl0=0x24;
	VICIntEnable=0x10;
	T0TCR=0x01;
}
void main()
{
	timer_init();
	IODIR0=0xff;
	while(1)
	{
		IOSET0=0xff;
	}
}
