#include<stdio.h>
#include<stdlib.h>

int Min_num(int arr[], int index1, int index2){
	int min = arr[index1];
	index1 = index1 + 1;
	for (; index1 <= index2; index1++){
		if (min > arr[index1]){
			min = arr[index1];
		}
	}
	return min;
}

int Min(int arr[], int length){
	if (arr == NULL || length <= 0)
		exit(EXIT_FAILURE);
	int index1 = 0;
	int index2 = length-1;
	int mid = 0;
	while (arr[index1] >= arr[index2]){
		if (index2 - index1 == 1){
			return arr[index2];
		}
		if (arr[index1] == arr[index2] && arr[mid] == arr[index1]){
			return Min_num(arr,index1,index2);
		}
		mid = (index1 + index2) / 2;
		if (arr[mid] >= arr[index1]){
			index1 = mid;
		}
		else if (arr[mid] <= arr[index2]){
			index2 = mid;
		}
	}
	return arr[0];

}

int main(){
	int arr[] = { 1,0,1,1,1};
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n",Min(arr, len));
	return 0;
}