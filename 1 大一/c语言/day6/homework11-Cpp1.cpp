#include<stdio.h>
int main()
{
	int k(int t);
	int a,b;
    scanf("%d",&a);
	b=k(a);
	printf("%d",b);
	return 0;
}
int k(int t)
{
	int a;
	if(t==0 || t==1)a=1;
	else a=k(t-1)*t;
	return(a);
}
