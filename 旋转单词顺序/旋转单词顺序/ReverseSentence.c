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

void RevereseSentence_1(char arr[])
{
	assert(arr);
	int length = strlen(arr);
	char* start = arr;
	char* end = arr + length - 1;
	Reverse(arr,end);
	end = arr;
	while (*end != '\0')
	{
		while ( (*end != ' ') && (*end != '\0') )
		{
			*end++;
		}
		Reverse(start, end - 1);
		if (*end != '\0')
		{
			start = ++end;
		}
	}
}

void RevereseSentence_2(char arr[])
{
	assert(arr);
	int length = strlen(arr);
	char* start = arr;
	char* end = arr + length - 1;
	Reverse(arr, end);
	end = arr;
	while (*start != '\0')
	{
		if (*start == ' ')
		{
			start++;
			end++;
		}
		else if ( (*end ==' ') || (*end=='\0') )
		{
			Reverse(start,--end);
			start = ++end;
		}
		else 
		{
			end++;
		}
	}
}

int main()
{
	char arr[] = "I am a student.";
	RevereseSentence_2(arr);
	printf("%s\n", arr);
	return 0;
}