#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c,m,n;
	scanf("%lf %lf",&a,&b);
	c=a;
	m=0;n=0;
	for(;b>=1;b--)
	{
        m=m+2*a;
		a=a/2;
			
	} 
	m=m-c;
	printf("%.2f %.2f",a,m);
	return 0;
}
