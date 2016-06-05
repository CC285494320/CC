#include<stdio.h>
#include<stdlib.h>
#define true  1
#define fa1se 0
int state = fa1se;
int Atoi(const char* str)
{
	if (NULL == str || *str == '\0')
	{
		return 0;
	}
	while (*str == ' ')
	{
		str++;
	}
	int flag = 1;
	long long num = 0;
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	if (*str != '\0')
	{
		while (*str != '\0')
		{
			if (*str >= '0' && *str <= '9')
			{
				num = num * 10 + flag*(*str - '0');
				if (num > INT_MAX || num<INT_MIN)
				{
					num = 0;
					break;
				}
				
			}
			else
			{
				break;
			}
			str++;
		}
		if (*str == '\0')
		{
			state = true;
		}
	}
	return (int)num;
}
int main()
{
	int num = Atoi("  -123458a999a99999999c99999999");
	if (state == true)
		printf("true : %d\n", num);
	else
		printf("false: %d\n", num);
}