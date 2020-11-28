#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char data;
	struct Node*L;
	struct Node*R;
}BiTNode,*BiTree;
void CreaBiTree(BiTree *b)
{
	char s;
	s = getchar();
	if (s == ' ')*b = NULL;
	else
	{
		*b = (BiTree)malloc(sizeof(BiTNode));
		(*b)->data = s;
		CreaBiTree(&((*b)->L));
		CreaBiTree(&((*b)->R));
	}
}
void ReadBiTreeFront(BiTree b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		ReadBiTreeFront(b->L);
		ReadBiTreeFront(b->R);
	}
}
void ReadBiTreeCenter(BiTree b)
{
	if (b != NULL)
	{
		ReadBiTreeCenter(b->L);
		printf("%c", b->data);
		ReadBiTreeCenter(b->R);
	}
}
void ReadBiTreeQueen(BiTree b)
{
	if (b != NULL)
	{
		ReadBiTreeQueen(b->L);
		ReadBiTreeQueen(b->R);
		printf("%c", b->data);
	}
}
void main()
{
	BiTree b;
	printf("���������У�\n");
	CreaBiTree(&b);
	printf("�����������������Ϊ��");
	ReadBiTreeFront(b);
	printf("\n");
	printf("�����������������Ϊ��");
	ReadBiTreeCenter(b);
	printf("\n");
	printf("������к���������Ϊ��");
	ReadBiTreeQueen(b);
	printf("\n");
}