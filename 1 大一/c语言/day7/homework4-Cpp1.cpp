#include<stdio.h>
int main()
{
	int i,a[10],*p;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	p=a;
	for(;p<a+10;p++)
		printf("%d ",*p);
	return 0;
}

