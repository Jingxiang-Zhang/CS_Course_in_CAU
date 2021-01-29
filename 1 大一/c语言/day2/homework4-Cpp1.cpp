#include <stdio.h>
int main()
{
	double a,b,c,p,s;
	scanf("%lf %lf %lf",&a,&b,&c);
    p=(a+b+c)/2;
	s=p*(p-a)*(p-b)*(p-c);
	printf("%.2f",s);
}

