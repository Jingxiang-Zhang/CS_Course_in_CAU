#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[6],b,c,d;
	int *p;
	for(b=0;b<6;b++) scanf("%d",&a[b]);
	p=&a[5];
	for(c=5;c>=0;c--) {printf("%d",*p);p--;if(c!=0)printf(" ");	}
	return 0;
}
