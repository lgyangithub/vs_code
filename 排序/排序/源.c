#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 100
#include<Windows.h>
typedef struct stu
{
	char name[20];
	long long stunum;
	int score;
}stu;
int creat(stu *a)
{
	int s = 1,n=0;
	do
	{
		printf("�������%d��ѧ�������֣�\n",n+1);
		scanf("%s", a[n].name);
		printf("������ѧ�ţ�\n");
		scanf("%d", &a[n].stunum);
		printf("������ɼ���\n");
		scanf("%d", &a[n].score);
		n++;
		printf("����0����¼����Ϣ:\n�����0������¼��:\n");
		scanf("%d", &s);
	} while (s);
	printf("============================================\n");
	return n;
}
void sort(stu*a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int s = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j].stunum>a[j + 1].stunum)
			{
				stu tamp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tamp;
				s = 1;
			}
		}
		if (!s)break;
	}
	printf("��ѧ�����򣺣�ѧ����С����\n");
	for (int k = 0; k < n; k++)
	{
		printf("������%s\n", a[k].name);
		printf("ѧ�ţ�%d\n", a[k].stunum);
		printf("�ɼ���%d\n\n", a[k].score);
	}
	for (int i = 0; i < n; i++)
	{
		int s = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j].score<a[j + 1].score)
			{
				stu tamp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tamp;
				s = 1;
			}
			if (a[j].score == a[j+1].score)
			if (a[j].stunum>a[j + 1].stunum)
			{
				stu tamp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tamp;
			}
		}
		if (!s)break;
	}
	printf("============================================\n");
	printf("���ɼ�����(�ɼ��ɸߵ���)\n");
	for (int k = 0; k < n; k++)
	{
		printf("������%s\n", a[k].name);
		printf("ѧ�ţ�%d\n", a[k].stunum);
		printf("�ɼ���%d\n\n", a[k].score);
	}
}
int main()
{
	stu student[MAX];
	int n = creat(student);
	sort(student, n);
	system("pause");
	return 0;
}