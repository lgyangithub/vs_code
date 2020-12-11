#include<Windows.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListoperation(SeqList* ps);
void SeqListDestory(SeqList* ps);//����
void SeqListPrint(SeqList* ps);//��ӡ
void SeqListCapacity(SeqList* ps);//����
void SeqListPushBack(SeqList* ps, SLDateType x);//β��
void SeqListPushFront(SeqList* ps, SLDateType x);//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListPopBack(SeqList* ps);//βɾ
// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);

int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListoperation(&s);
	SeqListPrint(&s);
	system("pause");
	return 0;
}
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SeqList)*4);
	if (ps->a == NULL)
	{
		printf("�ڴ����ʧ�ܣ�");
		return;
	}
	ps->capacity = 4;
	ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf(" %d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)//β��
{
	SeqListCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListCapacity(SeqList* ps)//����
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity = 2 * ps->capacity;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType)*ps->capacity);
	}
	if (ps->a == NULL)
	{
		printf("����ʧ�ܣ�");
		exit(-1);
	}
}
void SeqListPushFront(SeqList*ps,int x)
{
	SeqListCapacity(ps);
	for (int i = 0; i <=ps->size; i++)
	{
		ps->a[ps->size - i] = ps->a[ps->size - i-1];
		if (ps->size - i == 0)ps->a[0] = x;
	}
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	ps->a[ps->size-1] = 0;
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])return 1;
	}
	return 0;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	if (pos>ps->size)
	{
		printf("����λ������\n");
		return;
	}
	if (ps->size == ps->capacity)SeqListCapacity(ps);
	for (int i = 0; i <= ps->size; i++)
	{
		ps->a[ps->size - i] = ps->a[ps->size - 1 - i];
		if (ps->size - i == pos-1)
		{
			ps->a[pos - 1] = x;
			ps->size++;
			break;
		}
	}
}
void SeqListErase(SeqList* ps, size_t pos)
{
	if (pos == ps->size)
	{
		ps->a[ps->size - 1] = 0;
		ps->size--;
	}
	else for (int i = pos-1; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListoperation(SeqList* ps)
{
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushFront(ps, 3);
	SeqListPushFront(ps, 4);
	SeqListPushFront(ps, 5);
	SeqListPopFront(ps);
	SeqListPopBack(ps);
	if (SeqListFind(ps, 3))printf("�ҵ��ˣ�\n");
	else printf("δ�ҵ�!\n");
	SeqListInsert(ps, 1, 9);
	SeqListErase(ps, 2);
}