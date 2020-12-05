void ges(int a)

{

	if (a < 10)printf("%d ", a);
	else
	{
		ges(a / 10);
		printf("%d ", a % 10);
	}
}

int main()
{
	int a;
	printf("请输入要打印的数：\n");
	scanf("%d", &a);
	ges(a);
	return 0;
}