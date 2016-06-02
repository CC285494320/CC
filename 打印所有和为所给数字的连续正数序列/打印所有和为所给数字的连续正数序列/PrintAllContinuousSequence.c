#include<stdio.h>
void Print(int start, int end)
{
	for (; start <= end; start++)
	{
		printf("%3d",start);
	}
	printf("\n");
}

void PrintAllContinuousSequence(int sum)
{
	int start = 1;
	int end = 2;
	int Allsum = start+end;
	while (end <= (sum + 1) / 2) 
	{
		while (Allsum < sum)
		{
			end++;
			Allsum += end;
		}
		if (Allsum == sum)
		{
			Print(start, end);
			end++;
			Allsum += end;
		}
		else
		{
			Allsum -= start;
			start++;
		}
	}
}

int main()
{
	int sum = 9;
	PrintAllContinuousSequence(sum);
	return 0;
}