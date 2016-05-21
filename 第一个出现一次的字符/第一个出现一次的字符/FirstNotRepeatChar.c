#include<stdio.h>
#include<assert.h>
char FirstNotRepeatChar(const char *str)
{
	assert(str);
	int hashtable[256] = { 0 };
	const char* pstr = str;
	while (*pstr)
	{
		char ch = *pstr;
		hashtable[ch]++;
		pstr++;
	}
	pstr = str;
	while (*pstr)
	{
		char ch = *pstr;
		if (hashtable[ch] == 1)
		{
			return ch;
		}
		pstr++;
	}
	return 0;
}

int main()
{
	char arr[] = "12321352436";
	char ret = FirstNotRepeatChar(arr);
	printf("ret=%c\n", ret);
}
