#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int CheckSort(int arr[],int size){
	assert(arr);
	if (size <= 0)
		return 0;
	int i = 0;
	for (i = 0; i < size-1; i++){
		if (arr[i]>arr[i + 1])
			return 0;
	}
	return 1;
}

void Connect(int arr1[], int arr2[], int arr1_size1, int arr2_size2){
	assert(arr1);
	assert(arr1);
	if (arr1_size1 <= 0 || arr2_size2 <= 0 )
		return;
	if ( ! (CheckSort(arr1, arr1_size1) && CheckSort(arr2,arr2_size2) ) ){
		printf("Sorting failure\n");
		exit(EXIT_FAILURE);
	}
	int len_size1 = arr1_size1 + arr2_size2 - 1;
	int size1 = arr1_size1 - 1;
	int size2 = arr2_size2 - 1;
	while (size1 >= 0 && size2 >= 0){
		if (arr2[size2]>arr1[size1]){
			arr1[len_size1--] = arr2[size2--];
		}
		else{
			arr1[len_size1--] = arr1[size1--];
		}
	}
	while (size2 >= 0){
		arr1[len_size1--] = arr2[size2--];
	}
}
int main(){
	int arr1[20] = { 2,3,3,4,7,8};
	int arr2[] = { 0,1,3,4,5,6,8,9};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size1 = 6;
	Connect(arr1, arr2, size1, size2);
	for (int i = 0; i < size1 + size2; i++){
		printf("%3d", arr1[i]);
	}
	return 0;
}