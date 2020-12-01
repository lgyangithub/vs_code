#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef struct stu//ѧ����Ϣ�ṹ��
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
typedef struct sstu//�ṹ�����飨ÿ��Ԫ�ش洢һ��ѧ����Ϣ��
{
	stu people[MAX];
	int stusize;
}sstu;
void menu()//ͨѶ¼�˵���ӡ
{
	printf("=================================================================\n");
	printf("=\t\t\tѧ����Ϣ����ϵͳ\t\t\t=\n");
	printf("=\t\t\t      ����      \t\t\t=\n");
	printf("=\t\t\t  1-¼����Ϣ   \t\t\t\t=\n");
	printf("=\t\t\t  2-��ʾ������Ϣ\t\t\t=\n");
	printf("=\t\t\t  3-��ѯ��Ϣ   \t\t\t\t=\n");
	printf("=\t\t\t  4-ɾ����Ϣ   \t\t\t\t=\n");
	printf("=\t\t\t  5-�޸���Ϣ   \t\t\t\t=\n");
	printf("=\t\t\t  6-�����������Ϣ   \t\t\t=\n");
	printf("=\t\t\t  0-�˳�ϵͳ   \t\t\t\t=\n");
	printf("=================================================================\n");
}
void initialize(sstu *a)//��ʼ���ṹ������
{
	assert(a != NULL);
	a->stusize = 0;
	memset(a->people, 0, sizeof(a->people));
}
void entering(sstu *a)//¼��ѧ����Ϣ
{
	assert(a != NULL);
	int s;
	do
	{
		if (a->stusize == MAX)
		{
			printf("ͨѶ¼������\n");
			return;
		}
		printf("\n\n\n\n������ѧ������:");
		scanf("%s", a->people[a->stusize].name);
		printf("������ѧ������:");
		scanf("%d", &a->people[a->stusize].age);
		printf("������ѧ���Ա�:");
		scanf("%s", a->people[a->stusize].gender);
		printf("������ѧ��ѧ��:");
		scanf("%s", a->people[a->stusize].stunum);
		printf("������ѧ��רҵ�༶:");
		scanf("%s", a->people[a->stusize].class);
		printf("������ѧ���ֻ�����:");
		scanf("%s", a->people[a->stusize].pnum);
		printf("������ѧ��QQ:");
		scanf("%s", a->people[a->stusize].qq);
		printf("������ѧ����ͥ��ַ��*ʡ*�У��ݣ�*�أ�����:");
		scanf("%s", a->people[a->stusize].house);
		a->stusize++;
		printf("\n¼����ɣ���¼��%d��ѧ����Ϣ��\n�˳�¼�����������:   0\n����¼�����������:   1\n\n", a->stusize);
		scanf("%d", &s);
		while (1)
		{
			if (s != 0 && s != 1)
			{
				printf("���벻�Ϸ�!\n");
				printf("�˳�¼�����������:   0\n����¼�����������:   1\n");
				printf("�����룺\n\n\n");
				scanf("%d", &s);
			}
			if (s == 1 || s == 0)break;
		}
	} while (s);
}
void show(sstu a)//��ӡ����ѧ����Ϣ
{
	if (a.stusize == 0)printf("��û��¼��ѧ����Ϣ��\n");
	for (int i = 0; i < a.stusize; i++)
	{
		printf("��%d��ѧ����\n", i + 1);
		printf("������%s\n",a.people[i].name);
		printf("���䣺%d\n", a.people[i].age);
		printf("�Ա�%s\n", a.people[i].gender);
		printf("ѧ�ţ�%s\n", a.people[i].stunum);
		printf("רҵ�༶:%s\n", a.people[i].class);
		printf("�ֻ����룺%s\n", a.people[i].pnum);
		printf("QQ��%s\n", a.people[i].qq);
		printf("��ͥ��ַ��%s\n\n\n", a.people[i].house);
	}
}
void find(sstu a)//����������ѧ�Ų���ѧ����Ϣ
{
	int s;
	do
	{
		printf("\n\n\n\n���������������룺    1\n��ѧ�Ų��������룺    2\n�˳����������룺      0\n");
		scanf("%d", &s);
		switch(s)
		{
		case 1:
		{
				  int i = 0, j = 1;
				  char name1[20];
				  printf("������Ҫ����ѧ����������");
				  scanf("%s",name1);
				  for (i; i < a.stusize; i++)
				  {
					  if (!strcmp(name1, a.people[i].name))
					  {
						  j = 0;
						  printf("������%s\n", a.people[i].name);
						  printf("���䣺%d\n", a.people[i].age);
						  printf("�Ա�%s\n", a.people[i].gender);
						  printf("ѧ�ţ�%s\n", a.people[i].stunum);
						  printf("רҵ�༶:%s\n", a.people[i].class);
						  printf("�ֻ����룺%s\n", a.people[i].pnum);
						  printf("QQ��%s\n", a.people[i].qq);
						  printf("��ͥ��ַ��%s\n\n\n", a.people[i].house);
					  }
				  }
				  if ((i == a.stusize) && j)printf("���޴��ˣ�\n");
				  break;
		}
		case 2:
		{
				  int i = 0, j = 1;
				  char stunum1[20];
				  printf("������Ҫ����ѧ����ѧ�ţ�");
				  scanf("%s", stunum1);
				  for (i; i < a.stusize; i++)
				  {
					  if (!strcmp(stunum1, a.people[i].stunum))
					  {
						  j = 0;
						  printf("������%s\n", a.people[i].name);
						  printf("���䣺%d\n", a.people[i].age);
						  printf("�Ա�%s\n", a.people[i].gender);
						  printf("ѧ�ţ�%s\n", a.people[i].stunum);
						  printf("רҵ�༶:%s\n", a.people[i].class);
						  printf("�ֻ����룺%s\n", a.people[i].pnum);
						  printf("QQ��%s\n", a.people[i].qq);
						  printf("��ͥ��ַ��%s\n\n\n", a.people[i].house);
					  }
				  }
				  if ((i == a.stusize) && j)printf("���޴��ˣ�\n");
				  break;
				  break;
		}
		case 0:
		{
				  printf("�˳��ɹ���\n\n\n\n");
				  break;
		}
		default :
			{
				printf("���벻�Ϸ������������룺\n");
				break;
			}
		}
	} while (s!=0);
}
void delete(sstu*a)//��ѧ�Ż����������ҵ�ѧ����ȷ�������ɾ��
{
	int s;
	do
	{
		printf("\n\n\n\n������Ҫɾ��ѧ������Ϣ\n���������������룺    1\n��ѧ�Ų��������룺    2\n�˳������룺          0\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				  int i = 0, j = 1,k;
				  char name2[20];
				  printf("������ѧ��������\n");
				  scanf("%s", name2);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(name2, a->people[i].name))
					  {
						  j = 0;
						  printf("������%s\n", a->people[i].name);
						  printf("���䣺%d\n", a->people[i].age);
						  printf("�Ա�%s\n", a->people[i].gender);
						  printf("ѧ�ţ�%s\n", a->people[i].stunum);
						  printf("רҵ�༶:%s\n", a->people[i].class);
						  printf("�ֻ����룺%s\n", a->people[i].pnum);
						  printf("QQ��%s\n", a->people[i].qq);
						  printf("��ͥ��ַ��%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("���޴��ˣ�\n");
					  break;
				  }
				  printf("ȷ��ɾ�������룺    1\n�˳������룺        0\n");
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
									printf("ɾ���ɹ���\n");
									a->stusize--;
									break;
								}
							}
							break;

				  }
				  case 0:
				  {
							printf("�˳��ɹ���\n");
							break;
				  }
				  default:
				  {
							 printf("���벻�Ϸ������������룺\n");
							 break;
				  }
				  }
				  break;
		}
		case 2:
		{
				  int i = 0, j = 1, k;
				  char stunum2[20];
				  printf("������ѧ��ѧ�ţ�\n");
				  scanf("%s", stunum2);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(stunum2, a->people[i].stunum))
					  {
						  j = 0;
						  printf("������%s\n", a->people[i].name);
						  printf("���䣺%d\n", a->people[i].age);
						  printf("�Ա�%s\n", a->people[i].gender);
						  printf("ѧ�ţ�%s\n", a->people[i].stunum);
						  printf("רҵ�༶:%s\n", a->people[i].class);
						  printf("�ֻ����룺%s\n", a->people[i].pnum);
						  printf("QQ��%s\n", a->people[i].qq);
						  printf("��ͥ��ַ��%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("���޴��ˣ�\n");
					  break;
				  }
				  printf("ȷ��ɾ�������룺    1\n�˳������룺        0\n");
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
									printf("ɾ���ɹ���\n");
									a->stusize--;
									break;
								}
							}
							break;

				  }
				  case 0:
				  {
							printf("�˳��ɹ���\n");
							break;
				  }
				  default:
				  {
							 printf("���벻�Ϸ������������룺\n");
							 break;
				  }
				  }
				  break;
		}
		case 0:
		{
				  printf("�˳��ɹ���\n");
				  break;
		}
		default:
		{
				   printf("���벻�Ϸ������������룺\n");
				   break;
		}
		}
	} while (s);
}
void alter(sstu*a)//�����ֻ���ѧ�Ų��ҵ�ѧ�����ٽ����޸�
{

	int s;
	do
	{
		printf("\n\n\n\n������Ҫ�޸�ѧ������Ϣ\n���������������룺    1\n��ѧ�Ų��������룺    2\n�˳������룺          0\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				  int i = 0, j = 1, k;
				  char name3[20];
				  printf("������ѧ��������\n");
				  scanf("%s", name3);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(name3, a->people[i].name))
					  {
						  j = 0;
						  printf("������%s\n", a->people[i].name);
						  printf("���䣺%d\n", a->people[i].age);
						  printf("�Ա�%s\n", a->people[i].gender);
						  printf("ѧ�ţ�%s\n", a->people[i].stunum);
						  printf("רҵ�༶:%s\n", a->people[i].class);
						  printf("�ֻ����룺%s\n", a->people[i].pnum);
						  printf("QQ��%s\n", a->people[i].qq);
						  printf("��ͥ��ַ��%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("���޴��ˣ�\n");
					  break;
				  }
				  printf("ȷ���޸������룺    1\n�˳������룺        0\n");
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
									printf("\n\n\n\n������ѧ������:");
									scanf("%s", a->people[n].name);
									printf("������ѧ������:");
									scanf("%d", &a->people[n].age);
									printf("������ѧ���Ա�:");
									scanf("%s", a->people[n].gender);
									printf("������ѧ��ѧ��:");
									scanf("%s", a->people[n].stunum);
									printf("������ѧ��רҵ�༶:");
									scanf("%s", a->people[n].class);
									printf("������ѧ���ֻ�����:");
									scanf("%s", a->people[n].pnum);
									printf("������ѧ��QQ:");
									scanf("%s", a->people[n].qq);
									printf("������ѧ����ͥ��ַ��*ʡ*�У��ݣ�*�أ�����:");
									scanf("%s", a->people[n].house);
									printf("�޸���ɣ�\n");
									break;
								}
							}
							break;

				  }
				  case 0:
				  {
							printf("�˳��ɹ���\n");
							break;
				  }
				  default:
				  {
							 printf("���벻�Ϸ������������룺\n");
							 break;
				  }
				  }
				  break;
		}
		case 2:
		{
				  int i = 0, j = 1, k;
				  char stunum3[20];
				  printf("������ѧ��ѧ�ţ�\n");
				  scanf("%s", stunum3);
				  for (i; i < a->stusize; i++)
				  {
					  if (!strcmp(stunum3, a->people[i].stunum))
					  {
						  j = 0;
						  printf("������%s\n", a->people[i].name);
						  printf("���䣺%d\n", a->people[i].age);
						  printf("�Ա�%s\n", a->people[i].gender);
						  printf("ѧ�ţ�%s\n", a->people[i].stunum);
						  printf("רҵ�༶:%s\n", a->people[i].class);
						  printf("�ֻ����룺%s\n", a->people[i].pnum);
						  printf("QQ��%s\n", a->people[i].qq);
						  printf("��ͥ��ַ��%s\n\n\n", a->people[i].house);
					  }
				  }
				  if ((i == a->stusize) && j)
				  {
					  printf("���޴��ˣ�\n");
					  break;
				  }
				  printf("ȷ���޸������룺    1\n�˳������룺        0\n");
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
									printf("\n\n\n\n������ѧ������:");
									scanf("%s", a->people[n].name);
									printf("������ѧ������:");
									scanf("%d", &a->people[n].age);
									printf("������ѧ���Ա�:");
									scanf("%s", a->people[n].gender);
									printf("������ѧ��ѧ��:");
									scanf("%s", a->people[n].stunum);
									printf("������ѧ��רҵ�༶:");
									scanf("%s", a->people[n].class);
									printf("������ѧ���ֻ�����:");
									scanf("%s", a->people[n].pnum);
									printf("������ѧ��QQ:");
									scanf("%s", a->people[n].qq);
									printf("������ѧ����ͥ��ַ��*ʡ*�У��ݣ�*�أ�����:");
									scanf("%s", a->people[n].house);
									printf("�޸���ɣ�\n");
									break;

								}
							}
							break;

				  }
				  case 0:
				  {
							printf("�˳��ɹ���\n");
							break;
				  }
				  default:
				  {
							 printf("���벻�Ϸ������������룺\n");
							 break;
				  }
				  }
				  break;
		}
		case 0:
		{
				  printf("�˳��ɹ���\n");
				  break;
		}
		default:
		{
				   printf("���벻�Ϸ������������룺\n");
				   break;
		}
		}
	} while (s);
}
void select()//�˵����ø������ܺ���
{
	sstu a;
	initialize(&a);
	int s;
	do
	{
		printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
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
				  printf("ȷ���������ѧ����Ϣ�����룺    1\n");
				  printf("�˳������룺                    0\n");
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
					  printf("���벻�Ϸ�,�������˵�!\n");
					  menu();
					  break;
				  }
				  printf("���������Ϣ�ɹ���\n");
				  menu();
				  break;
		}
		case 0:
		{
				  printf("�˳��ɹ�����ӭ�´�ʹ�ã�\n");
				  break;
		}
		default:
		{
				   printf("���벻�Ϸ������������룺\n");
				   menu();
				   break;
		}
		}
	} while (s);
}
int main()//��������ӡ�˵�������select�����������ø������ܺ���
{
	menu();
	select();
	return 0;
}
