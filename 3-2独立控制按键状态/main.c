#include <REGX52.H>
//该方法为延时效果
void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;

	while(--xms){
	i = 2;
	j = 199;
	do
		{
			while (--j);
		} while (--i);
	}
}

void main(){
	
	//此处实现的效果为按下LED灯会亮起 松开就会熄灭
	//让P20的LED灯点亮
	while(1){
		//如果P31的按钮按下去的时候
		if(P3_1==0){
			//过滤按下抖动
			Delay(20);
			//此时按钮按下不做任何操作
			while(P3_1==0);
			//过滤弹起抖动
			Delay(20);
			//扭转P20灯泡状态
			P2_0=~P2_0;
		}
	}
}