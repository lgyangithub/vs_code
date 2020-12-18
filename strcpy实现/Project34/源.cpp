#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char* Strcpy(char*q,char*p)
{
	while (*p != '\0')
	{
		*q = *p;
		p++;
		q++;
	}
	*q = '\0';
	return q;
}
void main()
{
	char p[] = "qwertyuiop[]";
	char q[13]= "";
	Strcpy(q, p);
	printf("%s\n", q);
}