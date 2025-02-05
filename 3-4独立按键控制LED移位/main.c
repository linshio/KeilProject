#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;

	while(--xms){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main(){
	unsigned char LEDNum = 0;
	//p2初始值需要确定以一下
	P2 = ~0x01;
	while(1){	
		//第一个按键
		if(P3_1==0){
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LEDNum++;
			LEDNum = LEDNum >= 8 ? 0 : LEDNum;
			//p2按位左移
			P2=~(0x01<<LEDNum);
		}
		//第二个按键
		if(P3_0==0){
			Delay(20);
			while(P3_0==0);
			Delay(20);
			LEDNum--;
			LEDNum = LEDNum <= 0 ? 7 : LEDNum;
			//p2按位左移
			P2=~(0x01<<LEDNum);
		}
	}
}
