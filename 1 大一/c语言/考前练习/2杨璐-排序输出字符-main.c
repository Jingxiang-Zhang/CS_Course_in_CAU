#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	char m;
	char k[30];
	gets(k);
	a=strlen(k);
	for(b=0;b<a;b++)
	for(c=0;c<a-1;c++)
	if(k[c]>k[c+1])
	{
	    m=k[c];k[c]=k[c+1];k[c+1]=m;	
	} 
	puts(k);
	return 0;
}
