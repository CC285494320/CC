#include<stdio.h>
#include<stdlib.h>
#define ROW 4
#define COL 13
void Print(int arr[][COL], int row, int col)
{
	for (int k = 0; k<row; k++) {
		for (int i = 0; i<col; i++)
			printf("%d ", arr[k][i]);
		printf("\n");
	}
}

void Deal(int arr[][COL],int row,int col)
{
	srand((unsigned)time(NULL));
	int cnt[4] = { 0 };
	for (int i = 0; i<52; i++) {
		int index = rand() % 4;
		while (cnt[index] == 13)
			index = (index + 1) % 4;
		arr[index][cnt[index]++] = i;
	}
	Print(arr, row, col);
}

int main() {
	int arr[ROW][COL] = {0};
	Deal(arr,ROW,COL);
	return 0;
}