#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c;
	scanf("%lf",&a);
	if(a>0) a=a+1;
	else if(a==0) a=1;
	else if(a<0) a=a*3;
	printf("%.0lf",a);
	return 0;
}
