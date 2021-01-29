#include<stdio.h>
int main()
{
	int a,b,c=0,d=0,e=0;
	scanf("%d",&a);
    while(1)
	{
		b=a%10;
		c=c+1;
		e=e+b;
		a=a-b;
		if(a==0) break;
		else a=a/10;
	}
	printf("count=%d\n",c);
	printf("sum=%d\n",e);
	return 0;
}
