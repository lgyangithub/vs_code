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
	printf("������Ҫ��ӡ������\n");
	scanf("%d", &a);
	ges(a);
	return 0;
}