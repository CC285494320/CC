#include<stdio.h>
#define AGE 100  //ÄêÁäÄ¬ÈÏ 0-99
void Sort_age(int age[], int size){
	if (age == NULL || size <= 0)
		return;
	int i = 0;
	int j = 0;
	int times_age[AGE] = { 0 };
	for (i = 0; i < size; i++){
		int age1 = age[i];
		if (age1 < 0 || age1 >= AGE)
			return;
		times_age[age1]++;
	}
	int index = 0;
	for (i = 0; i < AGE; i++){
		for (j = 0; j < times_age[i]; j++){
			age[index++] = i;
		}
	}
}

int main(){
	int age[12] = { 23,24,23,25,30,45,36,43,29,34,56,39 };
	int size = sizeof(age) / sizeof(age[0]);
	int i = 0;
	Sort_age(age,size);
	for (i = 0; i < size; i++){
		printf("%3d", age[i]);
	}
	return 0;
}