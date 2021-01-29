#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char x[20];
	int a,b,c,d;
	gets(x);
	a=strlen(x);
	for(b=0,c=0;b<a;b++)
	c=c+x[b]-48;
	printf("%d",c);
	return 0;
}
