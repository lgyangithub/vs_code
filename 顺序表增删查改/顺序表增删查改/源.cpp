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

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);//初始化
void SeqListoperation(SeqList* ps);
void SeqListDestory(SeqList* ps);//销毁
void SeqListPrint(SeqList* ps);//打印
void SeqListCapacity(SeqList* ps);//增容
void SeqListPushBack(SeqList* ps, SLDateType x);//尾插
void SeqListPushFront(SeqList* ps, SLDateType x);//头插
void SeqListPopFront(SeqList* ps);//头删
void SeqListPopBack(SeqList* ps);//尾删
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
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
		printf("内存分配失败！");
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
void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	SeqListCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListCapacity(SeqList* ps)//增容
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity = 2 * ps->capacity;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType)*ps->capacity);
	}
	if (ps->a == NULL)
	{
		printf("增容失败！");
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
		printf("插入位置有误！\n");
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
	if (SeqListFind(ps, 3))printf("找到了！\n");
	else printf("未找到!\n");
	SeqListInsert(ps, 1, 9);
	SeqListErase(ps, 2);
}