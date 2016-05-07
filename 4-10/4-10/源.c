//1.每瓶汽水1元，两个空瓶可以置换一瓶汽水,
//现在有20元，最多能喝多少瓶汽水。（编程实现）。
#include<stdio.h>
int main(){
	int sum = 0;
	int blank_bottle = 0;
	int water_bottle = 20;
	int flag = 0;
	while (water_bottle>0){
		sum += water_bottle;
		blank_bottle = water_bottle+flag;
		if (blank_bottle % 2 == 0){
			water_bottle = blank_bottle / 2;
			flag = 0;
		}	
		else{
			water_bottle = blank_bottle / 2 ;
			flag = 1;
		}		
	}
	printf("sum=%d\n",sum);
	system("pause");
	return 0;
}


