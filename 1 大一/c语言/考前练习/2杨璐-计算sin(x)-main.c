#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double jc(double c)
{
	double a,b,d;
	for(a=1;c>0;c--)
	a=c*a;
	return(a);
}


int main(int argc, char *argv[]) {
    double a,b,c,d=1,sin=0;
	int k=0;
    scanf("%lf",&a);
    for(b=a,c=1;fabs(b)>0.00001;c=c+2)
    {
    	b=d*pow(a,c)/jc(c);
    	sin=sin+b;
    	d=-d;	k++;
	}
	printf("%.3f\n%d",sin,k);
	return 0;
}
