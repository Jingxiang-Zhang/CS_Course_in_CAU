#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[10],b,c,k,i,m;
	for(b=0,c=0;b<10;b++)
	{
		scanf("%d",&a[b]);
		c=c+a[b];
	 } 
	 c=c/10;
	 for(k=0,i=0;k<10;k++)
	 {
	 	if(a[k]>c) i=i+1;
	 }
	 printf("%d",i);
	return 0;
}
