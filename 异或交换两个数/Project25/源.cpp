#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Jh(int *a, int *b)
{
	*a =( *a)^(*b);
	*b = *a^*b;
	*a = *a^*b;
}
int main()
{
	int a, b;
	printf("请输入两个整数：\n");
	scanf("%d%d", &a, &b);
	printf("交换前a=%d,b=%d\n", a, b);
	Jh(&a,& b);
	printf("交换后a=%d,b=%d\n", a, b);
	return 0;
}