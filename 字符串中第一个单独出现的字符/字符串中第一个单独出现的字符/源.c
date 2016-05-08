
#include<stdio.h>
#include<assert.h>
char Find_c(const char *str){
	assert(str);
	const char *pstr = str;
	int num[256] = { 0 };
	while (*str != '\0'){
		num[*str]++;
		str++;
	}
	while (*pstr){
		if (num[*pstr] == 1){
			return *pstr;
		}
		pstr++;
	}
	return 0;
}
int main(){
	char arr[] = "bbcgcryry";
	printf("%c\n", Find_c(arr));
}
