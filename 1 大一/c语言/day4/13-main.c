#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c,d,e;
	scanf("%lf",&a);
	b=1;
    e=1;
    d=1;
	for(;a>=1;a--,b++)
	{
		for(c=b,d=1;c>=1;c--)
		{
			d=d*c;
		} 
		e=e+1/(d);
	}
	printf("%f",e);
	return 0;
}
