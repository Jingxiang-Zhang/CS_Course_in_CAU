#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[6],b,c,d;
	for(b=0;b<6;b++) scanf("%d",&a[b]);
	for(b=0;b<6;b++)
	{
		d=0;
		for(c=b;c<6;c++) {printf("%d",a[c]);d++;if(d!=6)printf(" ");}
		for(c=0;c<b;c++) {printf("%d",a[c]);d++;if(d!=6)printf(" ");}
		printf("\n");
	}
	return 0;
}
