#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int Two(int a, int b)
{
	if (a < b)
	{
		int t;
		t = a;
		a = b;
		b = t;
	}
	for (int i = b; i>0; i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("���������������Ϊ��%d\n", i);
			break;
		}
	}
}

int main()
{
	int a, b;
	printf("��������������\n");
	scanf("%d%d", &a, &b);
	Two(a, b);
	return 0;
}