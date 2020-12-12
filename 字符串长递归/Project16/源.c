#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int strlen(char *s)
{
	if (*s == '\0')return 0;
	return 1 + strlen(++s);
}
void main()
{
	char *s = "123fafw221";
	printf("%d\n",strlen(s));
}
//void Ges(int a)
//
//{
//
//	if (a < 10)printf("%d ", a);
//	else
//	{
//		Ges(a / 10);
//		printf("%d ", a % 10);
//	}
//}
//
//int main()
//{
//	int a;
//	printf("请输入要打印的数：\n");
//	scanf("%d", &a);
//	Ges(a);
//	return 0;
//}