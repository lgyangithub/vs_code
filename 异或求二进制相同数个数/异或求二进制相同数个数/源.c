#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Yi(int a, int b)
{
	int c = a^b; int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((c >> i) & 1) == 1)count++;
	}
	return count;
}
void main()
{
	int a, b;
	printf("����������������\n");
		scanf("%d%d", &a, &b);
		printf("%d��%d�Ķ�����(32λ)���У�%dλ����ͬ\n",a,b, Yi(a, b));
}