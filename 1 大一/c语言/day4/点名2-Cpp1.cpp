#include<stdio.h>
int main()
{
	int a,b;
	for(a=0,b=1;b<=101;b=b+2)
		a=a+b;
	printf("%d",a);
	return 0;
}