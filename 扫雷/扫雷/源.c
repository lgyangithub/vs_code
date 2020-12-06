#define _CRT_SECURE_NO_WARNINGS
#define H 9
#define L 9
#define LEI 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void newa(char a[H][L])//��a���鸳��*��
{
	for (int j = 0; j < H + 1; j++)
	{
		for (int i = 0; i < L + 1; i++)
			a[j][i] = '*';
	}
}
void newb(char b[H+1][L+1])//������b���ո�
{
	for (int j = 0; j < H + 1; j++)
	{
		for (int i = 0; i < L + 1; i++)
			b[j][i] = ' ';
	}
}
void bomb(char b[H+1][L+1])//������bװ��
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
int num(char b[H + 1][L + 1],int x,int y)//ͳ���׵ĸ���������
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
void numb(char b[H+1][L+1])//������b����׵���Ϣ
{
	for (int i = 1; i <= H;i++)
	for (int j = 1; j <= L; j++)
	{
		if(b[i][j]!='@')
		if (num(b, i, j) == 0)b[i][j] = ' ';
		else b[i][j] = num(b, i, j);
	}
}
int Pnum(char a[H][L])//�������
{
	int count = 0;
	for (int i = 0; i < H;i++)
	for (int j = 0; j < L; j++)
	{
		if (a[i][j] == 'P')count++;
	}
	return count;
}
void Qipan(char a[H][L])//��ʾ�����Լ�����a�е���Ϣ
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
	printf("\t��%d���ף�����%d����\n",LEI, Pnum(a));
}
void Qipan2(char b[H+1][L+1])//��ʾ�����Լ�����b�е���Ϣ
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
void numa(char a[H][L], char b[H + 1][L + 1], int x, int y)//������0�����Χ���������ٷ�ֱ��û����ʱ�ݹ鷵��
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
int victory(char a[H][L])//�ж��Ƿ�ﵽʤ������
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
int sweep(char a[H][L], char b[H + 1][L + 1])//������岢�ж���Ӯ
{
	while (1)
	{
		int x, y;
		while (1)
		{
			printf("������Ҫ�ߵ����꣺\n");
			scanf("%d%d", &x, &y);
			if (x <= 0 || x > 9 || y <= 0 || y > 9||a[x-1][y-1]=='P')
			{
				printf("�������겻�Ϸ����������룡\n");
			}
			else break;
		}
		if (b[x][y] == '@')
		{
			a[x - 1][y - 1] =b[x][y];
			Qipan2(b);
			printf("�����ˣ�\n");
			return 1;
		}
		else numa(a, b, x, y);
		if (victory(a))
		{
			Qipan2(b);
			printf("��ϲ��Ӯ�ˣ�\n");
			return 1;
		}
		Qipan(a);
		break;
	}
}
void flag(char a[H][L])//����
{
	int x, y;
	while (1)
	{
		printf("����������λ�ã�\n");
		scanf("%d%d", &x, &y);
		if (a[x - 1][y - 1] != '*')printf("����λ�ò��Ϸ����������������꣺\n");
		else
		{
			a[x - 1][y - 1] = 'P';
			break;
		}
	}
}
void deleteflage(char a[H][L])//ɾ����
{
	int x, y,z=0;
	for (int i = 0; i < H; i++)
	for (int j = 0; j < L; j++)
	{
		if (a[i][j] != 'P')z++;
	}
	if (z == L*H)
	{
		printf("��δ���죡");
		return;
	}
	while (1)
	{
		printf("������ɾ���λ�ã�\n");
		scanf("%d%d", &x, &y);
		if (a[x - 1][y - 1] != 'P')printf("ɾ��λ�ò��Ϸ����������������꣺\n");
		else
		{
			a[x - 1][y - 1] = '*';
			break;
		}
	}
}
void select(char a[H][L],char b[H + 1][L + 1])//ѡ���塢���졢ɾ���Լ��˳�����
{
	int s;
	do
	{
		printf("\t����ѡ���ܣ�\n");
		printf("1-����\t");
		printf("2-����\t");
		printf("3-ɾ����\t");
		printf("0-�˳�����\n");
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
				  printf("�˳��ɹ���\n");
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
void playgame(char a[H][L], char b[H + 1][L + 1])//���˵���������Ӧ����
{
	while (1)
	{
		int game;
		printf("=============================================\n");
		printf("=                   ѡ����                =\n");
		printf("=                  1-��ʼ��Ϸ               =\n");
		printf("=                  0-�˳���Ϸ               =\n");
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
				  printf("�˳��ɹ���\n");
				  return;
		}
		default:
		{
				   printf("���벻�Ϸ�!���������룺\n");
				   break;
		}
		}
	}
}
int main()//����������������Ϣ������b����ʾ���������Ϣ������a�����ò˵�����
{
	srand((unsigned)time(NULL));//�������������
	char a[H][L];
	char b[H + 1][L + 1];
	playgame(a, b);
	return 0;
}