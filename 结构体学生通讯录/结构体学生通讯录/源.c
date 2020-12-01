#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef struct stu//学生信息结构体
{
	char name[20];
	int age;
	char gender[5];
	char stunum[20];
	char class[20];
	char pnum[11];
	char qq[11];
	char house[40];
}stu;
typedef struct sstu//结构体数组（每个元素存储一个学生信息）
{
	stu people[MAX];
	int stusize;
}sstu;
void menu()//通讯录菜单打印
{
	printf("=================================================================\n");
	printf("=\t\t\t学生信息管理系统\t\t\t=\n");
	printf("=\t\t\t      功能      \t\t\t=\n");
	printf("=\t\t\t  1-录入信息   \t\t\t\t=\n");
	printf("=\t\t\t  2-显示所有信息\t\t\t=\n");
	printf("=\t\t\t  3-查询信息   \t\t\t\t=\n");
	printf("=\t\t\t  4-删除信息   \t\t\t\t=\n");
	printf("=\t\t\t  5-修改信息   \t\t\t\t=\n");
	printf("=\t\t\t  6-清空所有人信息   \t\t\t=\n");
	printf("=\t\t\t  0-退出系统   \t\t\t\t=\n");
	printf("=================================================================\n");
}
void initialize(sstu *a)//初始化结构体数组
{
	assert(a != NULL);
	a->stusize = 0;
	memset(a->people, 0, sizeof(a->people));
}
void entering(sstu *a)//录入学生信息
{
	assert(a != NULL);
	int s;
	do
	{
		if (a->stusize == MAX)
		{
			printf("通讯录已满！\n");
			return;
		}
		printf("\n\n\n\n请输入学生姓名:");
		scanf("%s", a->people[a->stusize].name);
		printf("请输入学生年龄:");
		scanf("%d", &a->people[a->stusize].age);
		printf("请输入学生性别:");
		scanf("%s", a->people[a->stusize].gender);
		printf("请输入学生学号:");
		scanf("%s", a->people[a->stusize].stunum);
		printf("请输入学生专业班级:");
		scanf("%s", a->people[a->stusize].class);
		printf("请输入学生手机号码:");
		scanf("%s", a->people[a->stusize].pnum);
		printf("请输入学生QQ:");
		scanf("%s", a->people[a->stusize].qq);
		printf("请输入学生家庭地址（*省*市（州）*县（区）:");
		scanf("%s", a->people[a->stusize].house);
		a->stusize++;
		printf("\n录入完成！共录入%d个学生信息！\n退出录入操作请输入:   0\n继续录入操作请输入:   1\n\n", a->stusize);
		scanf("%d", &s);
		while (1)
		{
			if (s != 0 && s != 1)
			{
				printf("输入不合法!\n");
				printf("退出录入操作请输入:   0\n继续录入操作请输入:   1\n");
				printf("请输入：\n\n\n");
				scanf("%d", &s);
			}
			if (s == 1 || s == 0)break;
		}
	} while (s);
}
void show(sstu a)//打印所有学生信息
{
	if (a.stusize == 0)printf("还没有录入学生信息！\n");
	for (int i = 0; i < a.stusize; i++)
	{
		printf("第%d个学生：\n", i + 1);
		printf("姓名：%s\n",a.people[i].name);
		printf("年龄：%d\n", a.people[i].age);
		printf("性别：%s\n", a.people[i].gender);
		printf("学号：%s\n", a.people[i].stunum);
		printf("专业班级:%s\n", a.people[i].class);
		printf("手机号码：%s\n", a.people[i].pnum);
		printf("QQ：%s\n", a.people[i].qq);
		printf("家庭地址：%s\n\n\n", a.people[i].house);
	}
}
void find(sstu a)//按姓名或者学号查找学生信息
{
	int s;
	do
	{
		printf("\n\n\n\n按姓名查找请输入：    1\n按学号查找请输入：    2\n退出查找请输入：      0\n");
		scanf("%d", &s);
		switch(s)
		{
		case 1:
		{
				  int i = 0, j = 1;
				  char name1[20];
				  printf("请输入要查找学生的姓名：");
				  scanf("%s",name1);
				  for (i; i < a.stusize; i++)
				  {
					  if (!strcmp(name1, a.people[i].name))
					  {
						  j = 0;
						  printf("姓名：%s\n", a.people[i].name);
						  printf("年龄：%d\n", a.people[i].age);
						  printf("性别：%s\n", a.people[i].gender);
						  printf("学号：%s\n", a.people[i].stunum);
						  printf("专业班级:%s\n", a.people[i].class);
						  printf("手机号码：%s\n", a.people[i].pnum);
						  printf("QQ：%s\n", a.people[i].qq);
						  printf("家庭地址：%s\n\n\n", a.people[i].house);
					  }
				  }
				  if ((i == a.stusize) && j)printf("查无此人！\n");
				  break;
		}
		case 2:
		{
				  int i = 0, j = 1;
				  char stunum1[20];
				  printf("请输入要查找学生的学号：");
				  scanf("%s", stunum1);
				  for (i; i < a.stusize; i++)
				  {
					  if (!strcmp(stunum1, a.people[i].stunum))
					  {
						  j = 0;
						  printf("姓名：%s\n", a.people[i].name);
						  printf("年龄：%d\n", a.people[i].age);
						  printf("性别：%s\n", a.people[i].gender);
						  printf("学号：%s\n", a.people[i].stunum);
						  printf("专业班级:%s\n", a.people[i].class);
						  printf("手机号码：%s\n", a.people[i].pnum);
						  printf("QQ：%s\n", a.people[i].qq);
						  printf("家庭地址：%s\n\n\n", a.people[i].house);
					  }
				  }
				  if ((i == a.stusize) && j)printf("查无此人！\n");
				  break;
				  break;
		}
		case 0:
		{
				  printf("退出成功！\n\n\n\n");
				  break;
		}
		default :
			{
				printf("输入不合法！请重新输入：\n");
				break;
			}
		}
	} while (s!=0);
}
void delete(sstu*a)//按学号或者姓名查找到学生，确定后进行删除
{
	int s;
	do
	{
		printf("\n\n\n\n请输入要删除学生的信息\n按姓名查找请输入：    1\n按学号查找请输入：    2\n退出请输入：          0\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				  int i = 0, j = 1,k;
				  char name2[20];
				  printf("请输入学生姓名：\n");
				  scanf("%s", name2);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(name2, a->people[i].name))
					  {
						  j = 0;
						  printf("姓名：%s\n", a->people[i].name);
						  printf("年龄：%d\n", a->people[i].age);
						  printf("性别：%s\n", a->people[i].gender);
						  printf("学号：%s\n", a->people[i].stunum);
						  printf("专业班级:%s\n", a->people[i].class);
						  printf("手机号码：%s\n", a->people[i].pnum);
						  printf("QQ：%s\n", a->people[i].qq);
						  printf("家庭地址：%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("查无此人！\n");
					  break;
				  }
				  printf("确定删除请输入：    1\n退出请输入：        0\n");
				  scanf("%d", &k);
				  switch(k)
				  {
				  case 1:
				  {
							int n=0;
							for (n; n < a->stusize; n++)
							{
								if (!strcmp(name2, a->people[n].name))
								{
									for (int m = n; m <a->stusize; m++)
									{
										a->people[m] = a->people[m + 1];
										a->stusize;
									}
									printf("删除成功！\n");
									a->stusize--;
									break;
								}
							}
							break;

				  }
				  case 0:
				  {
							printf("退出成功！\n");
							break;
				  }
				  default:
				  {
							 printf("输入不合法！请重新输入：\n");
							 break;
				  }
				  }
				  break;
		}
		case 2:
		{
				  int i = 0, j = 1, k;
				  char stunum2[20];
				  printf("请输入学生学号：\n");
				  scanf("%s", stunum2);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(stunum2, a->people[i].stunum))
					  {
						  j = 0;
						  printf("姓名：%s\n", a->people[i].name);
						  printf("年龄：%d\n", a->people[i].age);
						  printf("性别：%s\n", a->people[i].gender);
						  printf("学号：%s\n", a->people[i].stunum);
						  printf("专业班级:%s\n", a->people[i].class);
						  printf("手机号码：%s\n", a->people[i].pnum);
						  printf("QQ：%s\n", a->people[i].qq);
						  printf("家庭地址：%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("查无此人！\n");
					  break;
				  }
				  printf("确定删除请输入：    1\n退出请输入：        0\n");
				  scanf("%d", &k);
				  switch (k)
				  {
				  case 1:
				  {
							int n = 0;
							for (n; n < a->stusize; n++)
							{
								if (!strcmp(stunum2, a->people[n].stunum))
								{
									for (int m = n; m < a->stusize; m++)
									{
										a->people[m] = a->people[m + 1];
									}
									printf("删除成功！\n");
									a->stusize--;
									break;
								}
							}
							break;

				  }
				  case 0:
				  {
							printf("退出成功！\n");
							break;
				  }
				  default:
				  {
							 printf("输入不合法！请重新输入：\n");
							 break;
				  }
				  }
				  break;
		}
		case 0:
		{
				  printf("退出成功！\n");
				  break;
		}
		default:
		{
				   printf("输入不合法！请重新输入：\n");
				   break;
		}
		}
	} while (s);
}
void alter(sstu*a)//按名字或者学号查找到学生，再进行修改
{

	int s;
	do
	{
		printf("\n\n\n\n请输入要修改学生的信息\n按姓名查找请输入：    1\n按学号查找请输入：    2\n退出请输入：          0\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				  int i = 0, j = 1, k;
				  char name3[20];
				  printf("请输入学生姓名：\n");
				  scanf("%s", name3);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(name3, a->people[i].name))
					  {
						  j = 0;
						  printf("姓名：%s\n", a->people[i].name);
						  printf("年龄：%d\n", a->people[i].age);
						  printf("性别：%s\n", a->people[i].gender);
						  printf("学号：%s\n", a->people[i].stunum);
						  printf("专业班级:%s\n", a->people[i].class);
						  printf("手机号码：%s\n", a->people[i].pnum);
						  printf("QQ：%s\n", a->people[i].qq);
						  printf("家庭地址：%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("查无此人！\n");
					  break;
				  }
				  printf("确定修改请输入：    1\n退出请输入：        0\n");
				  scanf("%d", &k);
				  switch (k)
				  {
				  case 1:
				  {
							int n = 0;
							for (n; n < a->stusize; n++)
							{
								if (!strcmp(name3, a->people[n].name))
								{
									printf("\n\n\n\n请输入学生姓名:");
									scanf("%s", a->people[n].name);
									printf("请输入学生年龄:");
									scanf("%d", &a->people[n].age);
									printf("请输入学生性别:");
									scanf("%s", a->people[n].gender);
									printf("请输入学生学号:");
									scanf("%s", a->people[n].stunum);
									printf("请输入学生专业班级:");
									scanf("%s", a->people[n].class);
									printf("请输入学生手机号码:");
									scanf("%s", a->people[n].pnum);
									printf("请输入学生QQ:");
									scanf("%s", a->people[n].qq);
									printf("请输入学生家庭地址（*省*市（州）*县（区）:");
									scanf("%s", a->people[n].house);
									printf("修改完成！\n");
									break;
								}
							}
							break;

				  }
				  case 0:
				  {
							printf("退出成功！\n");
							break;
				  }
				  default:
				  {
							 printf("输入不合法！请重新输入：\n");
							 break;
				  }
				  }
				  break;
		}
		case 2:
		{
				  int i = 0, j = 1, k;
				  char stunum3[20];
				  printf("请输入学生学号：\n");
				  scanf("%s", stunum3);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(stunum3, a->people[i].stunum))
					  {
						  j = 0;
						  printf("姓名：%s\n", a->people[i].name);
						  printf("年龄：%d\n", a->people[i].age);
						  printf("性别：%s\n", a->people[i].gender);
						  printf("学号：%s\n", a->people[i].stunum);
						  printf("专业班级:%s\n", a->people[i].class);
						  printf("手机号码：%s\n", a->people[i].pnum);
						  printf("QQ：%s\n", a->people[i].qq);
						  printf("家庭地址：%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("查无此人！\n");
					  break;
				  }
				  printf("确定修改请输入：    1\n退出请输入：        0\n");
				  scanf("%d", &k);
				  switch (k)
				  {
				  case 1:
				  {
							int n = 0;
							for (n; n < a->stusize; n++)
							{
								if (!strcmp(stunum3, a->people[n].name))
								{
									printf("\n\n\n\n请输入学生姓名:");
									scanf("%s", a->people[n].name);
									printf("请输入学生年龄:");
									scanf("%d", &a->people[n].age);
									printf("请输入学生性别:");
									scanf("%s", a->people[n].gender);
									printf("请输入学生学号:");
									scanf("%s", a->people[n].stunum);
									printf("请输入学生专业班级:");
									scanf("%s", a->people[n].class);
									printf("请输入学生手机号码:");
									scanf("%s", a->people[n].pnum);
									printf("请输入学生QQ:");
									scanf("%s", a->people[n].qq);
									printf("请输入学生家庭地址（*省*市（州）*县（区）:");
									scanf("%s", a->people[n].house);
									printf("修改完成！\n");
									break;

								}
							}
							break;

				  }
				  case 0:
				  {
							printf("退出成功！\n");
							break;
				  }
				  default:
				  {
							 printf("输入不合法！请重新输入：\n");
							 break;
				  }
				  }
				  break;
		}
		case 0:
		{
				  printf("退出成功！\n");
				  break;
		}
		default:
		{
				   printf("输入不合法！请重新输入：\n");
				   break;
		}
		}
	} while (s);
}
void select()//菜单调用各个功能函数
{
	sstu a;
	initialize(&a);
	int s;
	do
	{
		printf("请选择您需要的功能：\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				  entering(&a);
				  menu();
				  break;
		}
		case 2:
		{
				  show(a);
				  menu();
				  break;
		}
		case 3:
		{
				  find(a);
				  menu();
				  break;
		}
		case 4:
		{
				  delete(&a);
				  menu();
				  break;
		}
		case 5:
		{
				  alter(&a);
				  menu();
				  break;
		}
		case 6:
		{
				  int s;
				  printf("确定清除所有学生信息请输入：    1\n");
				  printf("退出请输入：                    0\n");
				  scanf("%d", &s);
				  if (s == 1)
				  initialize(&a);
				  if (s == 0)
				  {
					  menu();
					  break;
				  }
				  if (s != 1 && s != 0)
				  {
					  printf("输入不合法,返回主菜单!\n");
					  menu();
					  break;
				  }
				  printf("清除所有信息成功！\n");
				  menu();
				  break;
		}
		case 0:
		{
				  printf("退出成功！欢迎下次使用！\n");
				  break;
		}
		default:
		{
				   printf("输入不合法！请重新输入：\n");
				   menu();
				   break;
		}
		}
	} while (s);
}
int main()//主函数打印菜单并调用select函数进而调用各个功能函数
{
	menu();
	select();
	return 0;
}
