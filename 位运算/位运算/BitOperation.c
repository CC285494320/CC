#include<stdio.h>
// 1������������1�ĸ���
int Numberof1_1(int num)
{
	int flag = 1;
	int count = 0;
	while (flag)
	{
		if(num & flag)
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

//2������������1�ĸ���(���Ը���1�ĸ���,�ж�һ�������ǲ���2�������η�)
int Numberof1_2(int num)
{
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	return count;
}

//������������m,n�жϸı�m�����ƶ���λ���ܵõ�n
int ChangeBit(int m,int n)
{
	int num = m^n;
	int count = 0;
	count = Numberof1_2(num);
	return count;
}

int main(){
	printf("%d\n", Numberof1_1(-1));
	printf("%d\n", Numberof1_2(15));
	printf("%d\n", ChangeBit(8, 7));
	return 0;
}