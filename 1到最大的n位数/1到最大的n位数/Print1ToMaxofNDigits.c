#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Increase(char num[], int n)
{
	int i = 0;
	int over = 0;
	for (i = n - 1; i >= 0; i--)
	{
		int number = num[i] - '0' + over;
		if (i == n - 1)
		{
			number++;
		}
		if (number >= 10)
		{
			if (i == 0)
			{
				return 1;
			}
			else
			{
				num[i] = '0';
				over = 1;
			}
		}
		else
		{
			num[i] = '0' + number;
			return 0;
		}
	}
	return 1;
}

void Print(char num[])
{
	int i = 0;
	while (num[i] == '0')
	{
		i++;
	}
	printf("%s\n", num + i);
}

void Print1ToMaxofNDigits(int n)
{
	if (n <= 0)
		return;
	int i = 0;
	int over = 0;
	char *num = (char *)malloc(n + 1);
	if (NULL == num)
		exit(EXIT_FAILURE);
	memset(num,'0',n+1 );
	num[n] = '\0';
	while(!Increase(num, n))
	{
		Print(num);
	}

}

int main()
{
	int n = 4;
	Print1ToMaxofNDigits(n);
	return 0;
}