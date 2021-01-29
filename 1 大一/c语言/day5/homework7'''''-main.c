#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d,x[17] ,k;
	scanf("%llf",&k);
	for(a=16;a>=0;a--)
	{
		d=k%10;
		x[a]=d;
		k=(k-d)/10;
		printf("%d",x[a]);
		
	}

	d=7*x[0]+9*x[1]+10*x[2]+5*x[3]+8*x[4]+4*x[5]+2*x[6]+1*x[7]+6*x[8]+3*x[9]+7*x[10]+9*x[11]+10*x[12]+5*x[13]+8*x[14]+4*x[15]+2*x[16];
	printf("%d",d);
	return 0;
}
