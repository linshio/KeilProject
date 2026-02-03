#include <REGX52.H>

void Delayms(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;
	while(ms)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		--ms;
	}
}

void main()
{
	while(1){
		P2 = 0xFE;//1111 1110
		Delayms(100);
		P2 = 0xFD;//1111 1101
		Delayms(100);
		P2 = 0xFB;//1111 1011
		Delayms(100);
		P2 = 0xF7;//1111 0111
		Delayms(100);
		P2 = 0xEF;//1110 1111
		Delayms(100);
		P2 = 0xDF;//1101 1111
		Delayms(100);
		P2 = 0xBF;//1011 1101
		Delayms(100);
		P2 = 0x7F;//0111 1101
		Delayms(100);
	}
	
}

