#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#define MAX 30
typedef struct stu
{
	char name[20];//����
	char name1[20];//��������ĸ
	int key;//����ĸ��Ӧ����
	int grade;//����
}stu;
int initialize(stu *people)//¼��ѧ����Ϣ
{
	int s,n=0;
	printf("��¼��ѧ����Ϣ!\n");
	for (int i = 0; i < 30; i++)
	{
		printf("�������%d��ѧ�������֣�\n", i + 1);
		scanf("%s",people[i].name);
		printf("�������%d��ѧ��������(��ĸ)��\n",i+1);
		scanf("%s", people[i].name1);
		printf("������%d��ѧ���ĳɼ���\n", i + 1);
		scanf("%d",& people[i].grade);
		printf("�˳�����������:     0\n��������������: ��0���� \n");
		n++;
		scanf("%d", &s);
		if (!s)break;
	}
	return n;
}
void Hashkey(stu*people,int n)//����Ӧ����ĸ��Ӧkey��ֵ
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
void HashSave(stu *people, int n, stu *h)//��ÿ��ѧ����key��29�����������h
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
int HashFetch(stu *h,char k[MAX])//�����������ĸת��Ϊ��Ӧ���֣�����������h�ж�Ӧ���±�
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
	printf("������Ҫ��ѯ����(��ĸ)��\n");
	scanf("%s", k);
	int ok = HashFetch(h, k);
	if (ok == 31)
	{
		printf("û�и�ѧ����Ϣ��\n");
		return;
	}
	printf("Ҫ��ѯ��ѧ����Ϣ���£�\n");
	printf("�ڹ�ϣ����λ�÷���ֵΪ��%d\n", ok);
	printf("������                  %s\n", h[ok].name);
	printf("��������ĸ����          %s\n", h[ok].name1);
	printf("������                  %d\n", h[ok].grade);
}
int main()
{
	char k[20];
	stu people[MAX];
	stu h[MAX];
	memset(h, 0, sizeof(h));//��ʼ������h
	int n=initialize(people);
	Hashkey(people,n);
	HashSave(people, n, h);
	selcah(k, h);
	system("pause");
	return 0;
}
