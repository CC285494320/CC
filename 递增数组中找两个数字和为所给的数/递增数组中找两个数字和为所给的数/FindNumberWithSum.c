#include<stdio.h>
#include<assert.h>
int flag = 0;
void FindNumberWithSum(int arr[], int size,int sum,int* num1,int *num2)
{
	assert(arr && num1 &&num2);
	if (size <= 1)
	{
		return;
	}
	int *start = arr;
	int *end = arr+size-1;
	while (start < end)
	{
		if ((*start + *end) > sum)
		{
			end--;
		}
		else if ((*start + *end) < sum)
		{
			start++;
		}
		else
		{
			*num1 = *start;
			*num2 = *end;
			flag = 1;
			return;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 4, 7, 11, 15 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int sum = 11;
	int num1 = 0;
	int num2 = 0;
	FindNumberWithSum(arr, size, sum, &num1, &num2);
	if (flag == 1)
	{
		printf("num1=%d,num=%d\n", num1, num2);
	}
	return 0;
}