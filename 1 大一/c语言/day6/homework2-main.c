#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jud(int x)
{
	int i,j;
	for(i=2;i<x;i++)
	{
		if(x%i==0)break;
	}
	if(i==x)return(1);
	else return(0);
}

int main(int argc, char *argv[]) {
	int jud(int x);
	int a,b,c,k,m;
	scanf("%d",&a);
	if(a<6 || a%2==1) {printf("Input an even num (>=6)");return 0;	} 
	for(b=2;b<(a/2);b++)
	{
		for(c=b;jud(c)==0;c++){b=c;}
		k=a-b;
		if(jud(k)==1) break;
	 } 
	 printf("%d+%d",b,k);
	
	return 0;
}
