#include<stdio.h>
int main()
{
	int age(int t);
	int a,b,c;
	scanf("%d",&a);
	b=age(a);
	printf("%d",b);
	return 0;
}
int age(int t)
{
	int a,b,c;
	if(t==1) b=10;
	else b=age(t-1)+2;
	return(b);
}

