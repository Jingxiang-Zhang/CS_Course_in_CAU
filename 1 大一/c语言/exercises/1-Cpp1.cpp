#include<stdio.h>
#include<math.h>
int main()
{
	int b;
	double c,a;
	scanf("%lf",&a);
	if(a<0) c=exp(-a);
	else if(a==0) c=1;
	else  c=exp(a);
	printf("%f",c);
	return 0;
}
