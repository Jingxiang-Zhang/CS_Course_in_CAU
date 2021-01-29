#include<stdio.h>
int main()
{
	double a,b,c,d,e,m;
	scanf("%lf",&m);
	a=1;
	b=2;
	c=0;
	m=m+1;
	while(1)
	{
		c=b/a+c;
		a=a+b;
		m=m-1;
		if(m==1)break;
		else c=a/b+c;
		b=b+a;
		m=m-1;
		if(m==1)break;
	}
	printf("%.2f",c);
	return 0;
}
