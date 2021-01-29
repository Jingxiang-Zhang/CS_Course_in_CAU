#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	char x[20],y[3];
	gets(x);
	a=strlen(x);
	for(b=a-3;b>a-6;b--) printf("%c",x[b]);
	
	return 0;
}
