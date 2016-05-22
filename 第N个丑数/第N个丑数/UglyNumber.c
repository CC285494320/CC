#include<stdio.h>
#define INDEX 1500 
int Min(int num1, int num2, int num3)
{
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;
	return min;
}

int UglyNumber(int index)
{
	if (index<= 0)
		return 0;
	int Uglyarr[INDEX] = { 0 };
	int *Ugly2 = Uglyarr;
	int *Ugly3 = Uglyarr;
	int *Ugly5 = Uglyarr;
	int Nextindex = 1;
	Uglyarr[0] = 1;
	while (Nextindex < index)
	{
		int min = Min(*Ugly2 * 2, *Ugly3 * 3, *Ugly5 * 5);
		Uglyarr[Nextindex] = min;
		while (*Ugly2*2<=Uglyarr[Nextindex])
		{
			Ugly2++;
		}
		while (*Ugly3 * 3 <= Uglyarr[Nextindex])
		{
			Ugly3++;
		}
		while (*Ugly5 * 5 <= Uglyarr[Nextindex])
		{
			Ugly5++;
		}
		Nextindex++;
	}
	return Uglyarr[index-1];
}

int main()
{
	int ret = UglyNumber(INDEX);
	printf("%d\n", ret);
}