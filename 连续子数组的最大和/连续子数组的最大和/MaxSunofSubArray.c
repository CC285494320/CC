#include<stdio.h>
int state = 0;
int MaxSunofSubArray(int arr[],int size)
{
	if ((arr == NULL) || (size <= 0))
	{
		state = 1;
		return 0;
	}
	int Curnum = 0;
	int MaxSum = 0x80000000;
	for (int i = 0; i < size; i++)
	{
		if (Curnum <= 0)
		{
			Curnum = arr[i];
		}
		else
		{
			Curnum += arr[i];
		}
		if (Curnum>MaxSum)
		{
			MaxSum = Curnum;
		}
	}
	return MaxSum;
}

int main()
{
	int arr[10] = { -2, 3, -6, 6, -7, 8, 9, -3, 5, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = MaxSunofSubArray(arr, size);
	if (state == 0)
	{
		printf("%d\n", ret);
	}

}