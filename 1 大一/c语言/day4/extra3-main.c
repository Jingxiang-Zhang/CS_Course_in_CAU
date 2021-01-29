#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	double a,b,c;
	scanf("%lf",&a);
	for(b=1;a>=0;a--)
	{
		b=b*(365-a)/365;	  	
	} 
	c=1-b;
	printf("%.2f",c);
	return 0;
}
