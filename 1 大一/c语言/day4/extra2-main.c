#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{

	double a;
	scanf("%lf",&a);
	if(a<0 || a>100) printf("error!");
	else if(a>=90) printf("A");
	else if(a>=80) printf("B");
	else if(a>=70) printf("C");
	else if(a>=60) printf("D");
	else printf("E");

	
	return 0;
}
