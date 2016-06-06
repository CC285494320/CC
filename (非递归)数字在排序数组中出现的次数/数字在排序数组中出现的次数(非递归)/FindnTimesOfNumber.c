#include<stdio.h>
int FirstNumber(int arr[],int size,int value)
{
	if (NULL == arr || size <= 0)
	{
		return 0;
	}
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == value)
		{
			if (mid == 0 || arr[mid - 1] != value)
			{
				return mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		else if (arr[mid]>value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}

int NumberofTimes(int arr[], int size,int value)
{
	int firstnum = FirstNumber(arr, size, value);
	int count = 0;
	for (int i = firstnum; i < size; i++)
	{
		if (arr[i] == value)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int main()
{
	int arr[] = { 1, 2, 2, 3, 3, 3, 3, 3, 4, 5 };
	int size = sizeof(arr)/sizeof(arr[0]);
	int count = 0;
	int value = 3;
	count =NumberofTimes(arr, size, value);
	printf("count = %d\n", count);
	return 0;
}