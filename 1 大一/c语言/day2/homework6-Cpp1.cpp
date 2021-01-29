#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,d,x1,x2;
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);
	printf("%.2f %.2f",x1,x2);
	return 0;
}
