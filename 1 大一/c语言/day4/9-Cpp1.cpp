#include <stdio.h>


int main() {
	char a,b,c,d;
	a=getchar();
	while(a!='\n')
	{
		printf("%c  ",a);
		a=getchar();
	}

	return 0;
}
