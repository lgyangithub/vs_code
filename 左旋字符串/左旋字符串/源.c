#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void left(char*p, int n)
{
	char *tail = p;
	while (*tail)
	{
		tail++;
	}
	tail--;
	while (n--)
	{
		char *move = tail;
		char s = *tail;
		while (move != p)
		{
			*move = *(move - 1);
			move--;
		}
		*move = s;
	}
}
void main()
{
	char a[100]; int n;
	printf("请输入字符串：");
	scanf("%s", a);
	printf("请输入要左旋字符串的个数：");
	scanf("%d", &n);
	left(a, n);
	printf("旋转后的字符串为：%s\n",a);
	system("pause");
}