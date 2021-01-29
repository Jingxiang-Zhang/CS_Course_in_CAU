#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[20];
	int b,c,d;
	gets(a);
	b=strlen(a);
	c=b/2;
	for(d=0;d<c;d++)
	if(a[d]!=a[b-d-1]) break;
	if(d==c) printf("Y");
	else printf("N");
	return 0;
}

