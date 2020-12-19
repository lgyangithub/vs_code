#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void Memcpy(char *dest, char *src, int n)
{
	if (src == NULL || dest == NULL)
	{
		printf("传入参数不合法！\n");
		return;
	}
	char *p = src, *q = dest;
	int m = n;
	while (*q)
	{
		if (m == 0)break;
		m--;
		*q = *p;
		q++;
		p++;
	}
	if (*(q) != '\0')*(q) = '\0';
}
void main()
{
	char *s = "abcdef gh";
	char a[10];
	Memcpy(a, s, strlen(s));
	printf("%s\n", a);
	system("pause");
}