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
	printf("����������������\n");
	scanf("%d%d", &a, &b);
	printf("����ǰa=%d,b=%d\n", a, b);
	Jh(&a,& b);
	printf("������a=%d,b=%d\n", a, b);
	return 0;
}