#include<stdio.h>
// 0Õı³£ ,1Òì³£
int flag = 0;
int Check(int number[],int length,int value)
{
	int i = 0;
	int times = 0;
	for (i = 0; i < length; i++)
	{
		if (number[i] == value)
		{
			times++;
		}
	}
	if (times * 2 <= length)
	{
		return 0;
	}
	return 1;
	
}

int MoreThanHalfNum(int number[],int length)
{
	if ((NULL == number) || (length <= 0))
	{
		flag = 1;
		return 0;
	}
	int value = number[0];
	int times = 1;
	for (int i = 1; i < length; i++)
	{
		if (times == 0)
		{
			value = number[i];
			times = 1;
		}
		else
		{
			if (number[i] != value)
			{
				times--;
			}
			else
			{
				times++;
			}
		}
	}
	if (0==Check(number, length, value))
	{
		flag = 1;
		return 0;
	}
	
	return value;
}

int main()
{
	int arr[] = { 1,2};
	int ret = MoreThanHalfNum(arr, sizeof(arr) / sizeof(arr[0]));
	if (flag==0)
		printf("%d\n",ret);
	
}