#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct people
{
	char name[20];
	char gender[5];
	char tel[11];
	char city[40];
	int eip;
	struct people*next;
}people;
void menu()
{
	printf("           <欢迎您使用本通讯系统>            \n");
	printf("`````````````````````````````````````````````\n");
	printf("`````````````````````````````````````````````\n");
	printf("``               请选择功能                ``\n");
	printf("``           1-创建新的通讯录              ``\n");
	printf("``           2-录入通讯录信息              ``\n");
	printf("``           3-查询联系人信息              ``\n");
	printf("``           4-修改联系人信息              ``\n");
	printf("``           5-删除联系人信息              ``\n");
	printf("``           6-查看所有联系人信息          ``\n");
	printf("``           0-退出通讯录系统              ``\n");
	printf("``                                         ``\n");
	printf("`````````````````````````````````````````````\n");
	printf("`````````````````````````````````````````````\n");
}
void Create(people **Pp,int *ok)
{
	*Pp = (people*)malloc(sizeof(people));
	printf("\n创建新的通讯录成功！\n\n");
	*ok = 0;
}
void Add(people** Pp,int *n)
{
	if ((*n) == 0)
	{
		int f;
		printf("\n请录入联系人信息  \n");
		printf("请    输   入   姓   名：");
		scanf("%s", (*Pp)->name);
		printf("请    输   入   性   别：");
		scanf("%s", (*Pp)->gender);
		printf("请 输 入  手  机  号 码：");
		scanf("%s", (*Pp)->tel);
		printf("请 输 入  所  在  城 市：");
		scanf("%s", (*Pp)->city);
		printf("请 输 入 该 城 市 邮 编：");
		scanf("%d", &(*Pp)->eip);
		(*Pp)->next = NULL;
		(*n)++;
		printf("共录入%d个人信息", *n);
		printf("\n继续录入请输入:  1\n结束录入请输入:  0\n");
		while (1)
		{
			scanf("%d", &f);
			if (f != 1 && f != 0)printf("输入不合法！请重新输入：\n");
			if (f == 0)return;
			if (f == 1)break;
		}
	}
	while (1)
	{
		people* Ll=*Pp;
		while (Ll->next != NULL)
		{
			Ll = Ll->next;
		}
		people* Ss = (people*)malloc(sizeof(people));
		printf("\n请录入联系人信息  ");
		printf("\n请    输   入   姓   名：");
		scanf("%s", Ss->name);
		printf("请    输   入   性   别：");
		scanf("%s", Ss->gender);
		printf("请 输 入  手  机  号 码：");
		scanf("%s", Ss->tel);
		printf("请 输 入  所  在  城 市：");
		scanf("%s", Ss->city);
		printf("请 输 入 该 城 市 邮 编：");
		scanf("%d", &Ss->eip);
		(*n)++;
		Ss->next = NULL;
		printf("共录入%d个人信息", *n);
		printf("\n继续录入请输入:  1\n结束录入请输入:  0\n");
		Ll->next = Ss;
		Ll = Ss;
		while (1)
		{
			int g;
			scanf("%d", &g);
			if (g != 1 && g != 0)printf("输入不合法！请重新输入：\n");
			if (g == 0)return;
			if (g == 1)break;
		}
	}
}
void Find(people* Pp)
{
	people*L = Pp;
	int count = 0;
	char a[20];
	printf("请输入要查询的人名：\n");
	scanf("%s", a);
	while (L!= NULL)
	{
		if (!strcmp(a,L->name))
		{
			printf("叫此名的人信息如下：\n");
			printf("姓        名：%s\n", Pp->name);
			printf("性        别：%s\n", Pp->gender);
			printf("手 机 号 码 ：%s\n", Pp->tel);
			printf("所 在 城 市 ：%s\n", Pp->city);
			printf("所在城市邮编：%d\n", Pp->eip);
			count++;
		}
		L = L->next;
	}
	if(count==0)printf("未查询到此人！\n");
}
void Alter(people** Pp)
{
	people*L = *Pp;
	char a[20];
	printf("请输入要修改联系人的名字：\n");
	scanf("%s", a);
	while (L!= NULL)
	{
		if (!strcmp(a,L->name))
		{
			printf("该人信息如下：\n");
			printf("姓        名：%s\n", L->name);
			printf("性        别：%s\n", L->gender);
			printf("手 机 号 码 ：%s\n", L->tel);
			printf("所 在 城 市 ：%s\n", L->city);
			printf("所在城市邮编：%d\n", L->eip);
			printf("\n请    输    入   姓  名：");
			scanf("%s", L->name);
			printf("\n请    输    入   性  别：");
			scanf("%s", L->gender);
			printf("\n请 输  入  手  机 号 码： ");
			scanf("%s", L->tel);
			printf("\n请 输  入  所  在 城 市： ");
			scanf("%s", L->city);
			printf("\n请 输 入 该 城 市 邮 编： ");
			scanf("%d", &L->eip);
			printf("修改成功！\n");
			printf("修改后该人信息如下：\n");
			printf("姓        名：%s\n", L->name);
			printf("性        别：%s\n", L->gender);
			printf("手 机 号 码 ：%s\n", L->tel);
			printf("所 在 城 市 ：%s\n", L->city);
			printf("所在城市邮编：%d\n", L->eip);
			return;
		}
		L = L->next;
	}
	printf("未查询到此人信息！\n");
}
void Delete(people** Pp,int *n)
{
	people*L = *Pp; people*F;
	char a[20];
	printf("\n请输入要删除联系人的名字：\n");
	scanf("%s", a);
	while (L != NULL)
	{
		if (!strcmp(a, L->name))
		{
			if (L == *Pp)//头删
			{
				printf("该人信息如下：\n");
				printf("姓        名：%s\n", L->name);
				printf("性        别：%s\n", L->gender);
				printf("手 机 号 码 ：%s\n", L->tel);
				printf("所 在 城 市 ：%s\n", L->city);
				printf("所在城市邮编：%d\n", L->eip);
				*Pp = (*Pp)->next;
				free(L);
				printf("删除成功！");
				return;
			}
			if (L->next == NULL)//中间删
			{
				printf("该人信息如下：\n");
				printf("姓        名：%s\n", L->name);
				printf("性        别：%s\n", L->gender);
				printf("手 机 号 码 ：%s\n", L->tel);
				printf("所 在 城 市 ：%s\n", L->city);
				printf("所在城市邮编：%d\n", L->eip);
				F->next = NULL;
				free(L);
				printf("删除成功！");
				return;
			}
			else//尾删
			{
				printf("该人信息如下：\n");
				printf("姓        名：%s\n", L->name);
				printf("性        别：%s\n", L->gender);
				printf("手 机 号 码 ：%s\n", L->tel);
				printf("所 在 城 市 ：%s\n", L->city);
				printf("所在城市邮编：%d\n", L->eip);
				F->next = L->next;
				free(L);
				printf("删除成功！");
				return;
			}
		}
		F = L;
		L = L->next;
	}
	printf("未查询到此人！\n");
}
void List(people* Pp)
{
	int i= 1;
	people*L = Pp;
	while (L!=NULL)
	{
		printf("\n第%d个人通讯信息：\n",i);
		printf("姓        名：%s\n", L->name);
		printf("性        别：%s\n", L->gender);
		printf("手 机 号 码 ：%s\n", L->tel);
		printf("所 在 城 市 ：%s\n", L->city);
		printf("所在城市邮编：%d\n", L->eip);
		L = L->next;
		i++;
	}
}
void select(people **Pp)
{
	int s,ok=1,n=0;
	do
	{
	menu();
	scanf("%d", &s);
	switch(s)
	{
	case 1:
	{
			  Create(Pp,&ok);
			  break;
	}
	case 2:
	{
			  if (ok)
			  {
				  printf("还未创建通讯录！请先创建新的通讯录。\n");
				  break;
			  }
			  Add(Pp,&n);
			  break;
	}
	case 3:
	{
			  if (n==0)
			  {
				  printf("还未录入联系人信息！\n");
				  break;
			  }
			  Find(*Pp);
			  break;
	}
	case 4:
	{
			  if (n == 0)
			  {
				  printf("还未录入联系人信息！\n");
				  break;
			  }
			  Alter(Pp);
			  break;
	}
	case 5:
	{
			  if (n == 0)
			  {
				  printf("还未录入联系人信息！\n");
				  break;
			  }
			  Delete(Pp,&n);
			  break;

	}
	case 6:
	{
			  if (n == 0)
			  {
				  printf("还未录入联系人信息！\n");
				  break;
			  }
			  List(*Pp);
			  break;
	}
	case 0:
	{
			  printf("退出成功！欢迎下次使用本系统。\n");
			  break;
	}
	default:
	{
			   printf("输入不合法，请重新输入：\n");
			  break;
	}
	}
	} while (s!=0);
}
void main()
{
	people *Pp=NULL;
	select(&Pp);
	system("pause");
}