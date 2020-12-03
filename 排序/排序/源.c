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
		printf("请输入第%d个学生的名字：\n",n+1);
		scanf("%s", a[n].name);
		printf("请输入学号：\n");
		scanf("%d", &a[n].stunum);
		printf("请输入成绩：\n");
		scanf("%d", &a[n].score);
		n++;
		printf("输入0结束录入信息:\n输入非0数结束录入:\n");
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
	printf("按学号排序：（学号由小到大）\n");
	for (int k = 0; k < n; k++)
	{
		printf("姓名：%s\n", a[k].name);
		printf("学号：%d\n", a[k].stunum);
		printf("成绩：%d\n\n", a[k].score);
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
	printf("按成绩排序：(成绩由高到低)\n");
	for (int k = 0; k < n; k++)
	{
		printf("姓名：%s\n", a[k].name);
		printf("学号：%d\n", a[k].stunum);
		printf("成绩：%d\n\n", a[k].score);
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