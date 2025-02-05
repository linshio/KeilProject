#include <REGX52.H>
void main()
{
	//实现按下点亮一个LED 松手就熄灭 
	while(1){
		if(P3_1 == 0){
			P2_0 = 0;
		}else{
			P2_0 = 1;
		}
	}
}