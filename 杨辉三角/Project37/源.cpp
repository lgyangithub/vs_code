#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
void main()
{
	int a[5][5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			a[i][j] = a[i-1][j-1]+a[i-1][j];
			a[i][0] = 1;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}