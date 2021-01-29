#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	scanf("%d",&a);
	if(a%2==0) printf("%d\n%d\n%d\n",a-1,a-2,a-3);
	if(a%2==1) printf("%d\n%d\n%d\n",a+1,a+2,a+3);
	return 0;
}
