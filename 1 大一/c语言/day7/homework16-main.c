#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[20],x;
	int b,c,d;
	gets(a);
	for(b=0;b<20;b++)
	if(a[b]=='\0')break;
	for(c=0;c<b;c++)
	for(d=0;d<b-1;d++)
	if(a[d]>a[d+1]) {x=a[d];a[d]=a[d+1];a[d+1]=x;}
	puts(a);
	return 0;
}
