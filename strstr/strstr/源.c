#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
char* Strstr(const char*str1,char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		printf("传入了空指针！");
		return NULL;
	}
	char *p = str1;
	while (*p)
	{
		char *q = str2;
		if (*p == *q)
		{
			char *r = p;
			while (1)
			{
				if (*q == '\0')
				{
					printf("有\n");
					return r;
				}
				else if (*p != *q)break;
				q++;
				p++;
			}
		}
		p++;
	}
	printf("没有\n");
	return NULL;
}
void main()
{
	char *a = "123456789";
	char *b = "23456";
	char *s=Strstr(a, b);
	printf("%c\n", *s);
	system("pause");
}