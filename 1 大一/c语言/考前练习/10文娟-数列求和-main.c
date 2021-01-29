#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int c,d,n;
	double a,b,m=0;
	a=1;b=1;
	scanf("%d",&n);
	while(1)
	{
		a=a+b;n--;m=m+a/b;
		if(n==0) {c=a;break;}
		b=a+b;n--;m=m+b/a;
		if(n==0) {c=b;break;}
	}
	printf("%.2f",m);
	return 0;
}
