#include<stdio.h>
#include<assert.h>
int GetFirstIndex(int arr[],int length,int k,int start,int end)
{
	if (start > end)
	{
		return -1;
	}
	int middle = start + (end - start) / 2;
	if (arr[middle] == k)
	{
		if ((middle == 0) || (arr[middle - 1] != k) )
		{
			return middle;
		}
		else
		{
			end = middle - 1;
		}
	}
	else if (arr[middle] > k)
	{
		end = middle - 1;
	}
	else
	{
		start = middle + 1;
	}
	return GetFirstIndex(arr, length, k, start, end);
}

int GetLastIndex(int arr[], int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middle = start + (end - start) / 2;
	if (arr[middle] == k)
	{
		if ((middle == length-1) || (arr[middle + 1] != k))
		{
			return middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	else if (arr[middle] > k)
	{
		end = middle - 1;
	}
	else
	{
		start = middle + 1;
	}
	return GetLastIndex(arr, length, k, start, end);
}

int GetNumberDigits(int arr[],int length,int k)
{
	assert(arr);
	if (length <= 0)
	{
		return 0;
	}
	int start= GetFirstIndex(arr, length, k, 0, length - 1);
	int end   = GetLastIndex(arr, length, k, 0, length - 1);
	int number = 0;
	if (start != -1 && end != -1)
	{
		number = end - start + 1;
	}
	return number;
}

int main()
{
	int arr[10] = { 1, 2,3,3,3,3, 4, 5 };
	int digits  =GetNumberDigits(arr, sizeof(arr) / sizeof(arr[0]) ,3);
	printf("digits=%d\n", digits);
	return 0;
}