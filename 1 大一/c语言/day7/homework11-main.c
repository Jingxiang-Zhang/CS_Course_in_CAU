#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	char x[30];
	for(a=0;a<30;a++)
	 x[a]='\0';
	gets(x);
	for(a=0;a<30;a=a+2)
	 if(x[a]!=0) printf("%c",x[a]); 
	return 0;
}
