#define _CRT_SECURE_NO_WARNINGS
#define Hang 3
#define Lie 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()//菜单
{
	printf("=======================================\n");
	printf("=-------------1 进行游戏--------------=\n");
	printf("=-------------0 退出游戏--------------=\n");
	printf("=======================================\n");
}
Qipan2(int a,int b)//初始话棋盘格子
{
		for (int i = 0; i < Hang; i++)
		{
			printf("---");
			if (i < Hang - 1)printf("|");
		}
		printf("\n");
}
void Qipan1(char a[Hang][Lie], int h, int l)//初始化棋盘并使得二维数组数值为：空格
{
	for (int i = 0; i < Hang; i++)
	{	
		for (int j = 0; j < Lie; j++)
		{
			a[i][j] = ' ';
			printf(" %c ",a[i][j]);
			if (j < Lie - 1)printf("|");
		}
		printf("\n");
		if(i<Hang-1)Qipan2(Hang, Lie);
	}
}
void Qipan3(char a[Hang][Lie], int h, int l)//下棋后显示棋盘与棋子
{
	for (int i = 0; i < Hang; i++)
	{
		for (int j = 0; j < Lie; j++)
		{
			printf(" %c ", a[i][j]);
			if (j < Lie - 1)printf("|");
		}
		printf("\n");
		if (i<Hang - 1)Qipan2(Hang, Lie);
	}
}

void Computer(char a[Hang][Lie], int h, int l)//电脑落棋
{
	int x, y;
	while (1)
	{
		x = rand() % h;
		y = rand() % l;
		if (x >= 0 && x<Hang&&y>=0 && y < Lie)
		{
			if (a[x][y]== ' ')
			{
				a[x][y] = 'O'; Qipan3(a, h, l);
				break;
			}
		}
	}
}
int Pk1(char a[Hang][Lie], int h, int l)//判断是否为平局
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l;j++)
		if (a[i][j] == ' ')return 0;
	}
	return 1;
}
char Pk(char a[Hang][Lie], int h, int l)//判断输赢以及平局和未下完返回对应字符
{
	for (int i = 0; i < h; i++)
	{
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ')
		{
			return a[i][0];
		}
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ')
		{
			return a[0][i];
		}
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != ' ')
	{
		return a[0][0];
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][1] && a[1][1] != ' ')
	{
		return a[0][2];
	}
	if (Pk1(a, h, l) == 1)
	{
		return 'p';
	}
	return ' ';
}
void Myself(char a[Hang][Lie], int h, int l)//玩家落棋后电脑落棋并判断输赢
{
	int x, y;
	char m = ' ';
	while (1)
	{
		while (1)
		{
			printf("请输入要落棋的坐标：\n");
			scanf("%d%d", &x, &y);
			if (x > 0 && x <= Hang&&y > 0 && y <= Lie&&a[x-1][y-1] == ' ')
			{
				a[x-1][y-1] = 'X';
				Qipan3(a, h, l);
				break;
			}
			else
			{
				printf("输入的坐标不合法，请重新输入！\n");
				Qipan3(a, h, l);
			}
		}
		m = Pk(a, h, l);
		printf("\n");
		if (m != ' ')break;
		Computer(a, Hang, Lie);
		m = Pk(a, h, l);
		if (m != ' ')break;
		}
	if (m == 'X')
	{
		printf("恭喜你赢了！\n");
		return;
	}
	if (m == 'O')
	{
		printf("电脑赢了！\n");
		return;
	}
	if (m == 'P')
	{
		printf("平局！\n");
		return;
	}
}
void Qipan()//创建二维数组并调用函数
{
	char a[Hang][Lie];
	Qipan1(a, Hang, Lie);
	Myself(a, Hang, Lie);
}
void playgame()//开始选择菜单并调用游戏函数
{
	int s;
	do
	{
		menu();
		printf("请输入你的操作：\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				  Qipan();
				  break;
		}
		case 0:
		{
				  printf("退出游戏成功！\n");
				  break;
		}
		default:
		{
				   printf("输入有误！请重新输入。\n");
				   break;
		}
		}
	} while (s!=0);
}
void main()
{
	srand((unsigned)time(NULL));
	playgame();
}