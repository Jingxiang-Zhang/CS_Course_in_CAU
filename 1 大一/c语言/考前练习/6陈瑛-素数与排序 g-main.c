#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jud(int x)
{
	int a,b,c;
	for(a=2;a<x;a++)
	if(x%a==0) break;
	if(a==x) return(1);
	else return(0);
}
int main(int argc, char *argv[]) {
	int x[10],a,b,c;
	for(a=0;a<10;a++) scanf("%d",&x[a]); 
	for(a=0;a<10;a++)
	for(b=0;b<9;b++)
	if(x[b]>x[b+1]) {c=x[b];x[b]=x[b+1];x[b+1]=c;}
	for(a=0,b=0;a<10;a++)
	if(jud(x[a])) {printf("%d ",x[a]);b=1;}
	if(b==0) printf("No prime");
	return 0;
}
