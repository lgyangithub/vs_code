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
	printf("           <��ӭ��ʹ�ñ�ͨѶϵͳ>            \n");
	printf("`````````````````````````````````````````````\n");
	printf("`````````````````````````````````````````````\n");
	printf("``               ��ѡ����                ``\n");
	printf("``           1-�����µ�ͨѶ¼              ``\n");
	printf("``           2-¼��ͨѶ¼��Ϣ              ``\n");
	printf("``           3-��ѯ��ϵ����Ϣ              ``\n");
	printf("``           4-�޸���ϵ����Ϣ              ``\n");
	printf("``           5-ɾ����ϵ����Ϣ              ``\n");
	printf("``           6-�鿴������ϵ����Ϣ          ``\n");
	printf("``           0-�˳�ͨѶ¼ϵͳ              ``\n");
	printf("``                                         ``\n");
	printf("`````````````````````````````````````````````\n");
	printf("`````````````````````````````````````````````\n");
}
void Create(people **Pp,int *ok)
{
	*Pp = (people*)malloc(sizeof(people));
	printf("\n�����µ�ͨѶ¼�ɹ���\n\n");
	*ok = 0;
}
void Add(people** Pp,int *n)
{
	if ((*n) == 0)
	{
		int f;
		printf("\n��¼����ϵ����Ϣ  \n");
		printf("��    ��   ��   ��   ����");
		scanf("%s", (*Pp)->name);
		printf("��    ��   ��   ��   ��");
		scanf("%s", (*Pp)->gender);
		printf("�� �� ��  ��  ��  �� �룺");
		scanf("%s", (*Pp)->tel);
		printf("�� �� ��  ��  ��  �� �У�");
		scanf("%s", (*Pp)->city);
		printf("�� �� �� �� �� �� �� �ࣺ");
		scanf("%d", &(*Pp)->eip);
		(*Pp)->next = NULL;
		(*n)++;
		printf("��¼��%d������Ϣ", *n);
		printf("\n����¼��������:  1\n����¼��������:  0\n");
		while (1)
		{
			scanf("%d", &f);
			if (f != 1 && f != 0)printf("���벻�Ϸ������������룺\n");
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
		printf("\n��¼����ϵ����Ϣ  ");
		printf("\n��    ��   ��   ��   ����");
		scanf("%s", Ss->name);
		printf("��    ��   ��   ��   ��");
		scanf("%s", Ss->gender);
		printf("�� �� ��  ��  ��  �� �룺");
		scanf("%s", Ss->tel);
		printf("�� �� ��  ��  ��  �� �У�");
		scanf("%s", Ss->city);
		printf("�� �� �� �� �� �� �� �ࣺ");
		scanf("%d", &Ss->eip);
		(*n)++;
		Ss->next = NULL;
		printf("��¼��%d������Ϣ", *n);
		printf("\n����¼��������:  1\n����¼��������:  0\n");
		Ll->next = Ss;
		Ll = Ss;
		while (1)
		{
			int g;
			scanf("%d", &g);
			if (g != 1 && g != 0)printf("���벻�Ϸ������������룺\n");
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
	printf("������Ҫ��ѯ��������\n");
	scanf("%s", a);
	while (L!= NULL)
	{
		if (!strcmp(a,L->name))
		{
			printf("�д���������Ϣ���£�\n");
			printf("��        ����%s\n", Pp->name);
			printf("��        ��%s\n", Pp->gender);
			printf("�� �� �� �� ��%s\n", Pp->tel);
			printf("�� �� �� �� ��%s\n", Pp->city);
			printf("���ڳ����ʱࣺ%d\n", Pp->eip);
			count++;
		}
		L = L->next;
	}
	if(count==0)printf("δ��ѯ�����ˣ�\n");
}
void Alter(people** Pp)
{
	people*L = *Pp;
	char a[20];
	printf("������Ҫ�޸���ϵ�˵����֣�\n");
	scanf("%s", a);
	while (L!= NULL)
	{
		if (!strcmp(a,L->name))
		{
			printf("������Ϣ���£�\n");
			printf("��        ����%s\n", L->name);
			printf("��        ��%s\n", L->gender);
			printf("�� �� �� �� ��%s\n", L->tel);
			printf("�� �� �� �� ��%s\n", L->city);
			printf("���ڳ����ʱࣺ%d\n", L->eip);
			printf("\n��    ��    ��   ��  ����");
			scanf("%s", L->name);
			printf("\n��    ��    ��   ��  ��");
			scanf("%s", L->gender);
			printf("\n�� ��  ��  ��  �� �� �룺 ");
			scanf("%s", L->tel);
			printf("\n�� ��  ��  ��  �� �� �У� ");
			scanf("%s", L->city);
			printf("\n�� �� �� �� �� �� �� �ࣺ ");
			scanf("%d", &L->eip);
			printf("�޸ĳɹ���\n");
			printf("�޸ĺ������Ϣ���£�\n");
			printf("��        ����%s\n", L->name);
			printf("��        ��%s\n", L->gender);
			printf("�� �� �� �� ��%s\n", L->tel);
			printf("�� �� �� �� ��%s\n", L->city);
			printf("���ڳ����ʱࣺ%d\n", L->eip);
			return;
		}
		L = L->next;
	}
	printf("δ��ѯ��������Ϣ��\n");
}
void Delete(people** Pp,int *n)
{
	people*L = *Pp; people*F;
	char a[20];
	printf("\n������Ҫɾ����ϵ�˵����֣�\n");
	scanf("%s", a);
	while (L != NULL)
	{
		if (!strcmp(a, L->name))
		{
			if (L == *Pp)//ͷɾ
			{
				printf("������Ϣ���£�\n");
				printf("��        ����%s\n", L->name);
				printf("��        ��%s\n", L->gender);
				printf("�� �� �� �� ��%s\n", L->tel);
				printf("�� �� �� �� ��%s\n", L->city);
				printf("���ڳ����ʱࣺ%d\n", L->eip);
				*Pp = (*Pp)->next;
				free(L);
				printf("ɾ���ɹ���");
				return;
			}
			if (L->next == NULL)//�м�ɾ
			{
				printf("������Ϣ���£�\n");
				printf("��        ����%s\n", L->name);
				printf("��        ��%s\n", L->gender);
				printf("�� �� �� �� ��%s\n", L->tel);
				printf("�� �� �� �� ��%s\n", L->city);
				printf("���ڳ����ʱࣺ%d\n", L->eip);
				F->next = NULL;
				free(L);
				printf("ɾ���ɹ���");
				return;
			}
			else//βɾ
			{
				printf("������Ϣ���£�\n");
				printf("��        ����%s\n", L->name);
				printf("��        ��%s\n", L->gender);
				printf("�� �� �� �� ��%s\n", L->tel);
				printf("�� �� �� �� ��%s\n", L->city);
				printf("���ڳ����ʱࣺ%d\n", L->eip);
				F->next = L->next;
				free(L);
				printf("ɾ���ɹ���");
				return;
			}
		}
		F = L;
		L = L->next;
	}
	printf("δ��ѯ�����ˣ�\n");
}
void List(people* Pp)
{
	int i= 1;
	people*L = Pp;
	while (L!=NULL)
	{
		printf("\n��%d����ͨѶ��Ϣ��\n",i);
		printf("��        ����%s\n", L->name);
		printf("��        ��%s\n", L->gender);
		printf("�� �� �� �� ��%s\n", L->tel);
		printf("�� �� �� �� ��%s\n", L->city);
		printf("���ڳ����ʱࣺ%d\n", L->eip);
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
				  printf("��δ����ͨѶ¼�����ȴ����µ�ͨѶ¼��\n");
				  break;
			  }
			  Add(Pp,&n);
			  break;
	}
	case 3:
	{
			  if (n==0)
			  {
				  printf("��δ¼����ϵ����Ϣ��\n");
				  break;
			  }
			  Find(*Pp);
			  break;
	}
	case 4:
	{
			  if (n == 0)
			  {
				  printf("��δ¼����ϵ����Ϣ��\n");
				  break;
			  }
			  Alter(Pp);
			  break;
	}
	case 5:
	{
			  if (n == 0)
			  {
				  printf("��δ¼����ϵ����Ϣ��\n");
				  break;
			  }
			  Delete(Pp,&n);
			  break;

	}
	case 6:
	{
			  if (n == 0)
			  {
				  printf("��δ¼����ϵ����Ϣ��\n");
				  break;
			  }
			  List(*Pp);
			  break;
	}
	case 0:
	{
			  printf("�˳��ɹ�����ӭ�´�ʹ�ñ�ϵͳ��\n");
			  break;
	}
	default:
	{
			   printf("���벻�Ϸ������������룺\n");
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