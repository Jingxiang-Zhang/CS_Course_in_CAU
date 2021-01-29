#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jud(int a)
{
	int b,c,d;
	for(b=1,c=0;b<a;b++)
	if(a%b==0) c=c+b;
	if(c==a) return(1);
	else return(0);
}
int main(int argc, char *argv[]) {
	int a,b,c,d;
	for(a=400;a<500;a++)
	if(jud(a)) printf("%d",a);
	return 0;
}

//一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程找出400至500之间的所有完数。

