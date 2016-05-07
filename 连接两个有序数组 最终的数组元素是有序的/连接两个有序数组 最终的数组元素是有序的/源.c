#include<stdio.h>
#include<assert.h>
void Connect(int arr1[], int arr2[], int arr1_size1, int arr2_size2){
	assert(arr1);
	assert(arr1);
	if (arr1_size1 <= 0 || arr2_size2 <=0)
		return;
	int len_size1 = arr1_size1 + arr2_size2 - 1;
	int size1 = arr1_size1 - 1;
	int size2 = arr2_size2 - 1;
	while (size1 >= 0 && size2 >= 0){
		if (arr2[size2]>arr1[size1]){
			arr1[len_size1--] = arr2[size2--];
		}
		if (arr1[size1] >= arr2[size2]){
			arr1[len_size1--] = arr1[size1--];
		}
	}
	if (size2 >= 0){
		arr1[len_size1--] = arr2[size2];
	}
}
int main(){
	int arr1[20] = { 1, 2, 2, 4, 5 };
	int arr2[] = { 0, 3, 5, 6, 6, 8, 9, 9 };
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size1 = 5;
	Connect(arr1, arr2, size1, size2);
	for (int i = 0; i < size1 + size2; i++){
		printf("%3d", arr1[i]);
	}
	return 0;
}