#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,x[10],aa,bb,k;
	for(a=0;a<10;a++) scanf("%d",&x[a]);
	k=abs(x[0]-x[1]);aa=0;bb=1;
	for(a=0;a<10;a++)
	for(b=a+1;b<10;b++)
	if(abs(x[a]-x[b])<k) {aa=a;bb=b;k=abs(x[a]-x[b]);	}
	printf("%d %d %d",x[aa],x[bb],k);
	return 0;
}
