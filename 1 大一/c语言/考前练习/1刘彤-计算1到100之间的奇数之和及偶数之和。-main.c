#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b=0,c=0;
	for(a=100;a>0;a--)
	if(a%2==0) b=b+a;
	else c=c+a;
	printf("1到100间的偶数的和为%d\n",b); 
	printf("1到100间的奇数的和为%d\n",c); 
	return 0;
}
