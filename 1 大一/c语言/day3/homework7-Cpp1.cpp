#include<stdio.h>
int main ()
{
	int a;
	char b;
	scanf("%d",&a);
	if(a>=90) b='A';
	else if (a>=60 && a<=89) b='B';
	else b='C';
	printf("%d belongs to %c.",a,b);
	return 0;
}