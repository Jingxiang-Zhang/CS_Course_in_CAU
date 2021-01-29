#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[6],b,c,d,e;
	for(b=0;b<6;b++) scanf("%d",&a[b]);
	for(b=0;b<5;b++)
	{
		for(c=b,d=b+1;d<6;d++)
		if(a[c]>a[d]) c=d;
		if(c!=b) {e=a[c];a[c]=a[b];a[b]=e;}
	}
	for(b=0;b<6;b++) {printf("%d",a[b]);if(b!=5) printf(" ");}
	return 0;
}
