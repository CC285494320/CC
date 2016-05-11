#include<stdio.h>
// 1、二进制序列1的个数
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

//2、二进制序列1的个数(可以根据1的个数,判断一个整数是不是2的整数次方)
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

//输入两个整数m,n判断改变m二进制多少位才能得到n
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