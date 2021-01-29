#include <stdio.h>
#include <math.h>
int main()
{
	int a1,a2,b1,b2,c1,c2,d,e1,e2;
	scanf("%d %d%d %d",&a1,&a2,&b1,&b2);
    c1=a1*60+a2;
    c2=b1*60+b2;
    d=c2-c1;
	d=fabs(d);
	e1=d%60;
	e2=(d-e1)/60;
	printf("%d %d",e2,e1);
}