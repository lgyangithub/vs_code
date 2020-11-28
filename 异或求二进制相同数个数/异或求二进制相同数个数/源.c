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
	printf("请输入两个整数：\n");
		scanf("%d%d", &a, &b);
		printf("%d和%d的二进制(32位)共有：%d位不相同\n",a,b, Yi(a, b));
}