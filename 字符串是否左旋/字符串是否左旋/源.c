#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
void judge(char *a, char *b)
{
	char*tail = a;
	int n = 0;
	while (*tail)
	{
		tail++;
		n++;
	}
	tail--;
	while (n--)
	{
		char*p = tail;
		char s = *tail;
		while (p != a)
		{
			*p = *(p - 1);
			p--;
		}
		*p = s;
		if (!strcmp(a, b))
		{
			printf("b��a��������ַ�����\n");
			return;
		}
	}
	printf("b����a��������ַ�����\n");
}
void main()
{
	char a[] = { "abcdefg" };
	char b[100];
	printf("a:%s\n", a);
	printf("�������ַ���\nb:");
	scanf("%s", b);
	judge(a, b);
	system("pause");
}