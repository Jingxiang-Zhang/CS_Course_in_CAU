#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int chai(int k,int x)
{
	int a=0,b=0,aa=0,bb=0;
	b=k%10;
	a=(k-b)/10;
	bb=x%10;
	aa=(x-b)/10%10;
	if(k<10 && b==bb) return 1;
	else if(k>10 && a==aa && b==bb) return 1;
	else return 0;
}
int main(int argc, char *argv[]) {
	int k,x,y;
	for(k=1;k<100;k++)
	{
		x=k*k;
		if(chai(k,x)) printf("%d\n",k);
	}
	return 0;
}
