#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int strlen(char *s)
{
	if (*s == '\0')return 0;
	return 1 + strlen(++s);
}
void main()
{
	char *s = "123fafw221";
	printf("%d\n", strlen(s));
}