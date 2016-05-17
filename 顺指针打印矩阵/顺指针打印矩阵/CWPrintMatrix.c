#include<stdio.h>
#include<assert.h>
#define COL 4
#define ROW 4

void PrintNumber(int arr[][COL], int row,int col,int start)
{
	int endx = col - 1 - start;
	int endy = row - 1 - start;
	//从左到右
	for (int i = start; i <= endx;i++)
	{
		printf("%3d", arr[start][i]);
	}
	//从上到下
	if (endy>start)
	{
		for (int j = start + 1; j <= endy; j++)
		{
			printf("%3d", arr[j][endx]);
		}
	}
	//从右到左
	if (endx>start && endy>start)
	{
		for (int i = endx - 1; i >= start; i--)
		{
			printf("%3d", arr[endy][i]);
		}
	}
	//从下到上
	if (endx>start && endy-1>start)
	{
		for (int j = endy - 1; j >= start + 1; j--)
		{
			printf("%3d", arr[j][start]);
		}
	}
}

void CWPrintMatrix(int arr[][COL],int row,int col)
{
	assert(arr);
	if (row <= 0 || col <= 0)
	{
		return ;
	}
	int start = 0;
	while ((row > start * 2) && (col > start * 2))
	{
		PrintNumber(arr, row,col,start);
		start++;
	}

}
int main()
{
	int arr[ROW][COL] = {
		{1,  2,  3,  4},
		{5,  6,  7,  8},
		{9, 10, 11, 12},
		{13,14, 15, 16}
	};
	CWPrintMatrix(arr, ROW, COL);
	return 0;
}