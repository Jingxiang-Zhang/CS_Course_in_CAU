#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[20],b,c,d,v;
	for(b=0,v=0;b<20;b++)
	{
		scanf("%d",&a[b]);
		v=v+a[b];
	}
	v=v/20;
	
	for(b=0;b<20;b++)
	for(c=0;c<b;c++)
	{
		if(a[b]%a[c]==0) 
		{
			printf("%d ",a[b]);
			break;
		}
	 } 
	 if(a[0]==v ) printf("%d ",a[0]);

	return 0;
}
