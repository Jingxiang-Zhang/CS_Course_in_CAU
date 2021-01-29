#include <stdio.h>
int main()
{
	double a,A,b,c,d,e;
    scanf("%lf %lf",&a,&A);
	b=11340;
	c=3.141592657;
	d=(4.0/3.0)*c*(a*a*a-A*A*A)/8/1000000;
	e=d*b;
	printf("%f",e);
	return 0;
}