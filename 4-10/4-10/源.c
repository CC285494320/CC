//1.ÿƿ��ˮ1Ԫ��������ƿ�����û�һƿ��ˮ,
//������20Ԫ������ܺȶ���ƿ��ˮ�������ʵ�֣���
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


