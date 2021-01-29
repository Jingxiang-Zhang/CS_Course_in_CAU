#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d",&a);
	c=1;
	while(a>=1)
	{
		b=c*c%391;
		if(b==13) printf("%d ",c);
		c=c+1;
		a=a-1;
	}
	return 0;
}
