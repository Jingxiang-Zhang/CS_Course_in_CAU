#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,d,sin,t,x;
	int n;
	scanf("%lf",&a);
	sin=0;
	x=1;n=0;
	for(b=1,c=1;fabs(t)>=0.00001;b=b+2,n=n+1)
	{
		for(c=1,d=1;d<=b;d++)
		{c=c*d;}
		sin=sin+x*pow(a,b)/c;
		t=x*pow(a,b)/c;
		x=-x;	
	}
	printf("%.3f\n",sin);
	printf("%d",n);
	return 0;
}
