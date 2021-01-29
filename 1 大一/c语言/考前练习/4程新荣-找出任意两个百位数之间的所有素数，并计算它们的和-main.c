#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jud(int a)
{
	int x,y;
	for(x=2;x<a;x++)
	if(a%x==0) break;
	if(x==a) return(1);
	else return(0) ;
}
int main(int argc, char *argv[]) {
	int a,b,c,d,m,n;
	scanf("%d %d",&m,&n);
	for(a=m,b=0;a<n;a++)
	if(jud(a)) b=b+a;
	printf("%d",b);
	return 0;
}
