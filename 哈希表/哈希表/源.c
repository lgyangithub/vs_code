#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#define MAX 30
typedef struct stu
{
	char name[20];//名字
	char name1[20];//名字首字母
	int key;//首字母对应数字
	int grade;//分数
}stu;
int initialize(stu *people)//录入学生信息
{
	int s,n=0;
	printf("请录入学生信息!\n");
	for (int i = 0; i < 30; i++)
	{
		printf("请输入第%d个学生的名字：\n", i + 1);
		scanf("%s",people[i].name);
		printf("请输入第%d个学生的名字(字母)：\n",i+1);
		scanf("%s", people[i].name1);
		printf("请输入%d个学生的成绩：\n", i + 1);
		scanf("%d",& people[i].grade);
		printf("退出输入请输入:     0\n继续输入请输入: 非0整数 \n");
		n++;
		scanf("%d", &s);
		if (!s)break;
	}
	return n;
}
void Hashkey(stu*people,int n)//给对应首字母对应key赋值
{
	for (int i = 0; i < n; i++)
	{
		people[i].key = 0;
		int j = 0;
		do
		{
			people[i].key= people[i].name1[j] + people[i].key;
			j++;
		} while (people[i].name1[j] != '\0');
	}
}
void HashSave(stu *people, int n, stu *h)//由每个学生的key对29求余存入数组h
{
	for (int i = 0; i < n; i++)
	{
		int m = people[i].key % 29,t=1;
		while (t)
		{
			if (h[m].key== 0)
			{
				h[m] = people[i];
				t = 0;
			}
			else
			{
				m++;
				if (m > 29)m = 0;
			}
		}
	}
}
int HashFetch(stu *h,char k[MAX])//对输入的首字母转化为对应数字，并返回数组h中对应的下标
{
	int i = 0,sum=0 ,t=1;
	do
	{
		sum = k[i] + sum;
		i++;
	} while (k[i] != '\0');
	int f = sum % 29;
	int count = 0;
	while (t)
	{
		count++; 
		if (count > 30)return count;
		if (h[f].key == sum)
			return f;
		else
		{
			f++;
			if (f > 29)f = 0;
		}
	}

}
void selcah(char k[],stu* h)
{
	printf("\n\n\n=============================\n");
	printf("请输入要查询名字(字母)：\n");
	scanf("%s", k);
	int ok = HashFetch(h, k);
	if (ok == 31)
	{
		printf("没有该学生信息！\n");
		return;
	}
	printf("要查询的学生信息如下：\n");
	printf("在哈希表中位置返回值为：%d\n", ok);
	printf("姓名：                  %s\n", h[ok].name);
	printf("姓名（字母）：          %s\n", h[ok].name1);
	printf("分数：                  %d\n", h[ok].grade);
}
int main()
{
	char k[20];
	stu people[MAX];
	stu h[MAX];
	memset(h, 0, sizeof(h));//初始化数组h
	int n=initialize(people);
	Hashkey(people,n);
	HashSave(people, n, h);
	selcah(k, h);
	system("pause");
	return 0;
}
