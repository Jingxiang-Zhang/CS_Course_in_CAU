#include<stdio.h>
int main()
{
	int a,b;
	int *A,*B,*P;
	scanf("%d %d",&a,&b);
	A=&a;B=&b;
	if(*A<*B) 
	{
		P=A;
		A=B;
		B=P;
	}
	printf("%d %d",*A,*B);
	return 0;
}
