#include <stdio.h>
int main()
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	if(a>b) a=a;
	else a=b;
	printf("%.2f",a);



return 0;
}