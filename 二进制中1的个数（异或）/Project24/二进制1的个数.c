#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Gy(int a)
{
	int count=0;
	for (int i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) == 1)count++;
	}
	return count;
}
int main()
{
	int a;
	printf("������һ��������\n");
	scanf("%d", &a);
	printf("%d�������ƣ���1�ĸ���Ϊ��%d\n", a,Gy(a));
	return 0;
}