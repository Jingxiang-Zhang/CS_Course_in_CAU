#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int jud(int x);
	int a,b,c;
	scanf("%d",&a);c=a;
	for(b=0;a>1;a--) 
	if(jud(a)==1) b++;
	b=c-b-1;
	printf("%d",b);
	return 0;
}
int jud(int x)
{
	int a,b;
	for(a=x-1;a>1;a--)
	if(x%a==0) break;
	if(a==1) return(0);
	else return(1);
}
