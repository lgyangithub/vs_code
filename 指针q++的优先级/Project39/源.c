#include<stdio.h>
int main()
{
	char*s = "asdfg";
	*s++;
	int a = 1;
	int*q = &a;
	(*q)++;

	printf("%c,%d,%d\n", *s,&a, q);
	return 0;
}