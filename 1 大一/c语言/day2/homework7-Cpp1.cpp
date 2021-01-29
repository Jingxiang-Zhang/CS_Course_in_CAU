#include <stdio.h>
int main ()
{
	double r,h,s,v,a;
	scanf("%lf%lf",&r,&h);
    a=3.1415926;
	s=2*a*r*h;
	v=a*r*r*h;
	printf("s=%.2f,v=%.2f",s,v);
	return 0;
}