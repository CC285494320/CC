#include<stdio.h>
#include<assert.h>
void OddEven(int arr[], int size)
{
	int left = 0;
	int right = size - 1;
	assert(arr);
	while (left < right){
		while ((left < right) && (arr[left] & 1) != 0)
		{
			left++;
		}
		while ((left < right) && (arr[right] & 1) == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void Show(int arr[], int size)
{
	for (int i = 0; i < size;i++)
		printf("%3d", arr[i]);
}
int main()
{
	int arr[] = { 2,1,4,5,6,7,9,8,3,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	OddEven(arr, size);
	Show(arr, size);
}