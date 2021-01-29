#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[10];
	int b,c,d;
	gets(a);
	for(b=0,c=0;a[c]!='\0';c++)
	for(d=c+1;a[d]!='\0';d++)
	if(a[c]>a[d]) b++;
	printf("%d",b);
	
	return 0;
}
