#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void Sxh(int n)
{
	int s=0,count = 0, a = n,b=n,c;
	while (a != 0)
	{
		a = a / 10;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		 c= b%10;
		 b = b / 10;
		s = s + pow(c, count);
	}
	if (s == n)printf("%d ", n);
}
void main()
{
	printf("1-100000之间的水仙花数为：\n");
	for (int i = 1; i <= 100000;i++)
	Sxh(i);
	printf("\n");
}