#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void Memmove(char *r, const char *f, int n)
{
	if (n < 0)
	{
		printf("移动字符个数不合法,拷贝失败！");
		return;
	}
	char *p = f,*q=r;
	int m = n;
	while (*q)
	{
		if (m == 0)break;
		m--;
		*q = *p;
		p++;
		q++;
	}
}
void main()
{
	char s[] = "abcdef gh";
	char a[10];
	Memmove(a, s, 10);
	printf("%s\n", a);
	system("pause");
}