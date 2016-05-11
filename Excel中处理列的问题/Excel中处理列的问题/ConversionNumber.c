#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int ConversionNumber(const char *str)
{
	assert(str);
	int number = 0;
	if (!*str)
	{
		return number;
	}
	while (*str)
	{
		int tmp = *str - 'A';
		if (!(tmp >= 0 && tmp <= 25))
		{
			exit(EXIT_FAILURE);
		}
		number = number * 26 + tmp + 1;
		str++;
	}
	return number;
}

int main()
{
	char str[] = "AZ";
	int ret = ConversionNumber(str);
	printf("ret = %d\n", ret);
	return 0;

}