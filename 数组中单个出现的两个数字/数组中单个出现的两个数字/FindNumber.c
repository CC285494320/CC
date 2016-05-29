#include<stdio.h>
#include<assert.h>
int Findindex(num)
{
	int i = 0;
	for (i=0; i < 8 * sizeof(int); i++)
	{
		if ( ((num >> i)&1)== 1)
		{
			break;
		}
	}
	return i;
}
void FindNumber(int arr[], int size,int *num1,int *num2)
{
	assert(arr);
	if (size <= 0)
	{
		return;
	}
	*num1 = *num2 = 0;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num ^= arr[i];
	}
	int numindex = Findindex(num);
	for (int j = 0; j < size; j++)
	{
		if ( ((arr[j] >> numindex)&1) == 1)
		{
			*num1 ^= arr[j];
		}
	}
	*num2 = *num1^num;
}
int main()
{
	int num1 = 0; 
	int num2 = 0;
	int arr[] = { 1, 2, 1, 4, 3, 6, 3, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	FindNumber(arr,size,&num1,&num2);
	printf("num1=%d,num2=%d\n", num1, num2);
	return 0;
}