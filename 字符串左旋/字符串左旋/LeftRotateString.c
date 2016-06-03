#include<stdio.h>
#include<assert.h>
#include<string.h>
void Reverse(char *start, char *end)
{
	assert(start && end);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void LeftRotateString(char str[],int size)
{
	assert(str);
	int length = strlen(str);
	if ((size <= 0) || (size > length))
	{
		return;
	}
	Reverse(str, str + size - 1);
	Reverse(str+size,str+length-1);
	Reverse(str, str + length - 1);
}

int main()
{
	char str[] = "abcdefg";
	LeftRotateString(str, 2);
	printf("%s\n", str);
	return 0;
}