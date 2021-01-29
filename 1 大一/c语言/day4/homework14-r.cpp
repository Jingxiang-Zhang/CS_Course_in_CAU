#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a,b;
	a=getchar();
	while(a!='\n')
	{
		if(a>='a' && a<='z')
		{
			if(a>='x') a=a-23;
			else a=a+3;
		}
		else break;
		printf("%c",a);
		a=getchar();
	}
	return 0;
}