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
	printf("�������ַ�����");
	scanf("%s", a);
	printf("������Ҫ�����ַ����ĸ�����");
	scanf("%d", &n);
	left(a, n);
	printf("��ת����ַ���Ϊ��%s\n",a);
	system("pause");
}