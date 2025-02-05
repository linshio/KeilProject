#include <REGX52.H>
void Delayms(unsigned int ms)		//@12.000MHz
{
	while(ms)
	{
		unsigned char i, j;
		i = 2;
		j = 239;
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

