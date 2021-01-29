#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[10][10],b,c,d,x,y,z;
	for (d=0,b=0;b<10;b=b+1)
	for (c=0;c<=b;c=c+1)
	{
		d=d+1;
		a[b][c]=d;
	 } 
	 scanf("%d",&x);
	for (d=0,b=0;b<10;b=b+1)
	for (c=0;c<=b;c=c+1)
	{
		d=d+1;
		if(x==d) 
		{
			printf("%d %d",b,c);
			break;			
		}
	 } 
	return 0;
}
