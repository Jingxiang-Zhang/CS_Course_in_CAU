#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a,b,c,d;
	a=getchar();
	while(a!='\n')
	{
		printf("%c  ",a);
		a=getchar();
	}

	return 0;
}
