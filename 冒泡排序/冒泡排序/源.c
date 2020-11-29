#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a[9] = { 5, 3, 6, 2, 8, 9, 1, 7, 4 };
	printf("≈≈–Ú«∞:");
	for (int z = 0; z < 9; z++)
		printf("%d ", a[z]);
	printf("\n");
	for (int i = 0; i < 9; i++)
	{
		int p = 0;
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				int q = a[j];
				a[j] = a[j + 1];
				a[j + 1] = q;
				p++;
			}
		}
		if (p = 0)break;
	}
	printf("≈≈–Ú∫Û:");
	for (int k = 0; k < 9; k++)
	{
		printf("%d ", a[k]);
	}
	printf("\n");
	system("pause");
	return 0;
}