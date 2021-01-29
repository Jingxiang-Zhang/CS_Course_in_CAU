#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d %d %d",&a,&b,&c);
    d=a%2;e=b%2;f=c%2;
	if(d==1) 
		printf("%d is odd number!\n",a);
	if(e==1)
		printf("%d is odd number!\n",b);
	if(f==1)
		printf("%d is odd number!\n",c);
	return 0;
}