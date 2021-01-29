#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,n;
	scanf("%d",&a);
	c=a;
	
	for(n=0;a>1;n=c)
	{
		b=a%2;
		if(b==1)a=a*3+1;
		else a=a/2;
		if(c<a)c=a;
	}
	printf("%d",n);
	return 0;
}
