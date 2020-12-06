#define _CRT_SECURE_NO_WARNINGS
#define H 9
#define L 9
#define LEI 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void newa(char a[H][L])//给a数组赋‘*’
{
	for (int j = 0; j < H + 1; j++)
	{
		for (int i = 0; i < L + 1; i++)
			a[j][i] = '*';
	}
}
void newb(char b[H+1][L+1])//给数组b赋空格
{
	for (int j = 0; j < H + 1; j++)
	{
		for (int i = 0; i < L + 1; i++)
			b[j][i] = ' ';
	}
}
void bomb(char b[H+1][L+1])//给数组b装雷
{
	
	int count = 0;
	while (count < LEI)
	{
		int h = rand() % H;
		int l = rand() % L;
		if (h>0 && l > 0 && b[h][l] == ' ')
		{
			b[h][l] = '@';
			count++;
		}
	}
}
int num(char b[H + 1][L + 1],int x,int y)//统计雷的个数并返回
{
	int count = 0;
	if (b[x - 1][y - 1] == '@')count++;
	if (b[x - 1][y] == '@')count++;
	if (b[x - 1][y +1] == '@')count++;
	if (b[x][y - 1] == '@')count++;
	if (b[x][y + 1] == '@')count++;
	if (b[x+1][y - 1] == '@')count++;
	if (b[x + 1][y] == '@')count++;
	if (b[x + 1][y + 1] == '@')count++;
	return count;
}
void numb(char b[H+1][L+1])//给数组b填充雷的信息
{
	for (int i = 1; i <= H;i++)
	for (int j = 1; j <= L; j++)
	{
		if(b[i][j]!='@')
		if (num(b, i, j) == 0)b[i][j] = ' ';
		else b[i][j] = num(b, i, j);
	}
}
int Pnum(char a[H][L])//插旗个数
{
	int count = 0;
	for (int i = 0; i < H;i++)
	for (int j = 0; j < L; j++)
	{
		if (a[i][j] == 'P')count++;
	}
	return count;
}
void Qipan(char a[H][L])//显示棋盘以及数组a中的信息
{
	system("CLS");
	printf("\n\n\n\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (j == 0)printf("  ");
			if (i == 0)printf("_%d__", j + 1);
		}
		printf("\n");
		for (int k = 0; k < L; k++)
		{
			if (k == 0)printf("%d", i + 1);
			if (a[i][k] >= 0 && a[i][k]<9)printf("| %d ", a[i][k]);
			else printf("| %c ", a[i][k]);
			if (k == (L - 1))printf("|\n");
		}
		for (int x = 0; x < L; x++)
		{
			if (x == 0)printf(" ");
			printf("|___");
			if (x == (L - 1))printf("|\n");
		}
	}
	printf("\t共%d个雷，插入%d个旗\n",LEI, Pnum(a));
}
void Qipan2(char b[H+1][L+1])//显示棋盘以及数组b中的信息
{
	system("CLS");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (j == 0)printf("  ");
			if (i == 0)printf("_%d__", j + 1);
		}
		printf("\n");
		for (int k = 0; k < L; k++)
		{
			if (k == 0)printf("%d", i + 1);
			if (b[i+1][k+1] >= 0 && b[i+1][k+1]<9)printf("| %d ", b[i+1][k+1]);
			else printf("| %c ", b[i+1][k+1]);
			if (k == (L - 1))printf("|\n");
		}
		for (int x = 0; x < L; x++)
		{
			if (x == 0)printf(" ");
			printf("|___");
			if (x == (L - 1))printf("|\n");
		}
	}
}
void numa(char a[H][L], char b[H + 1][L + 1], int x, int y)//若翻到0则打开周围牌遇到零再翻直至没有零时递归返回
{
	if (b[x][y] == ' ')
	{
		if (x - 2 >= 0 && y - 2 >= 0 && a[x - 2][y - 2] == '*')
		{
			int f = x - 1, g = y - 1;
			a[f-1][g-1] = b[f][g];
			numa(a, b, f, g);
		}
		if (x - 2 >= 0 && a[x - 2][y - 1] == '*')
		{
			int f = x - 1, g = y;
			a[f-1][g-1] = b[f][g];
			numa(a, b, f, g);
		}
		if (x - 2 >= 0 && y <= 8 && a[x - 2][y] == '*')
		{
			int f = x - 1, g = y + 1;
			a[f-1][g-1] = b[ f][ g];
			numa(a, b, f, g);
		}
		if (y - 2 >= 0 && a[x - 1][y - 2] == '*')
		{
			int f = x, g = y - 1;
			a[f-1][g-1] = b[ f][ g];
			numa(a, b, f, g);
		}
		if (y <= 8 && a[x - 1][y] == '*')
		{
			int f = x, g = y + 1;
			a[f - 1][g - 1] = b[f][g];
			numa(a, b, f, g);
		}
		if (x <= 8 && y - 2 >= 0 && a[x][y - 2] == '*')
		{
			int f = x + 1, g = y - 1;
			a[f - 1][g - 1] = b[f][g];
			numa(a, b, f, g);
		}
		if (x <= 8 && a[x][y - 1] == '*')
		{
			int f = x + 1, g = y;
			a[f - 1][g - 1] = b[f][g];
			numa(a, b, f, g);
		}
		if (x <= 8 && y <= 8 && a[x][y] == '*')
		{
			int f = x + 1, g = y + 1;
			a[f - 1][g - 1] = b[f][g];
			numa(a, b, f, g);
		}
	}
	else if(b[x][y]!='@')a[x - 1][y - 1] = b[x][y];
	return;
}
int victory(char a[H][L])//判断是否达到胜利条件
{
	int count = 0;
	for (int i = 0; i < H; i++)
	for (int j = 0; j < L; j++)
	{
		if (a[i][j] != '*' && a[i][j] != 'P')count++;
	}
	if (count == L*H - LEI)
	{
		return 1;
	}
	else return 0;
}
int sweep(char a[H][L], char b[H + 1][L + 1])//玩家下棋并判断输赢
{
	while (1)
	{
		int x, y;
		while (1)
		{
			printf("请输入要走的坐标：\n");
			scanf("%d%d", &x, &y);
			if (x <= 0 || x > 9 || y <= 0 || y > 9||a[x-1][y-1]=='P')
			{
				printf("输入坐标不合法请重新输入！\n");
			}
			else break;
		}
		if (b[x][y] == '@')
		{
			a[x - 1][y - 1] =b[x][y];
			Qipan2(b);
			printf("你输了！\n");
			return 1;
		}
		else numa(a, b, x, y);
		if (victory(a))
		{
			Qipan2(b);
			printf("恭喜你赢了！\n");
			return 1;
		}
		Qipan(a);
		break;
	}
}
void flag(char a[H][L])//插棋
{
	int x, y;
	while (1)
	{
		printf("请输入插旗的位置：\n");
		scanf("%d%d", &x, &y);
		if (a[x - 1][y - 1] != '*')printf("插入位置不合法！请重新输入坐标：\n");
		else
		{
			a[x - 1][y - 1] = 'P';
			break;
		}
	}
}
void deleteflage(char a[H][L])//删除棋
{
	int x, y,z=0;
	for (int i = 0; i < H; i++)
	for (int j = 0; j < L; j++)
	{
		if (a[i][j] != 'P')z++;
	}
	if (z == L*H)
	{
		printf("还未插旗！");
		return;
	}
	while (1)
	{
		printf("请输入删旗的位置：\n");
		scanf("%d%d", &x, &y);
		if (a[x - 1][y - 1] != 'P')printf("删除位置不合法！请重新输入坐标：\n");
		else
		{
			a[x - 1][y - 1] = '*';
			break;
		}
	}
}
void select(char a[H][L],char b[H + 1][L + 1])//选择翻棋、插旗、删棋以及退出功能
{
	int s;
	do
	{
		printf("\t请先选择功能：\n");
		printf("1-翻开\t");
		printf("2-插旗\t");
		printf("3-删除旗\t");
		printf("0-退出本局\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
		{
				 if( sweep(a, b)==1)return;
				  break;
		}
		case 2:
		{
				  flag(a);
				  Qipan(a);
				  break;
		}
		case 3:
		{
				  deleteflage(a);
				  Qipan(a);
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
	} while (s!=0);
}
void playgame(char a[H][L], char b[H + 1][L + 1])//主菜单并调用相应函数
{
	while (1)
	{
		int game;
		printf("=============================================\n");
		printf("=                   选择功能                =\n");
		printf("=                  1-开始游戏               =\n");
		printf("=                  0-退出游戏               =\n");
		printf("=============================================\n");
		scanf("%d", &game);
		switch (game)
		{
		case 1:
		{
				  newa(a);
				  Qipan(a);
				  newb(b);
				  bomb(b);
				  numb(b);
				  select(a, b);
				  break;
		}
		case 0:
		{
				  printf("退出成功！\n");
				  return;
		}
		default:
		{
				   printf("输入不合法!请重新输入：\n");
				   break;
		}
		}
	}
}
int main()//主函数定义存放雷信息的数组b和显示玩家下棋信息的数组a并调用菜单函数
{
	srand((unsigned)time(NULL));//生成随机数种子
	char a[H][L];
	char b[H + 1][L + 1];
	playgame(a, b);
	return 0;
}