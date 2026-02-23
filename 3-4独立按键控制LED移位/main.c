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
			if(LEDNum>=8)
					LEDNum=0;
			//p2按位左移
			P2=~(0x01<<LEDNum);
		}
		//第二个按键
		if(P3_0==0){
			Delay(20);
			while(P3_0==0);
			Delay(20);
			//因为定义的LEDNum为无符号整型的，需要判断是否等于0
			if(LEDNum==0)
				LEDNum = 7;
			else
				LEDNum--;
		
			//p2按位左移
			P2=~(0x01<<LEDNum);
		}
	}
}
