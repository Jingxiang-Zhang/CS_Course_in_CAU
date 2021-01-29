#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[10],b,c,d;
	for(b=0;b<10;b++)
	{
		scanf("%d",&a[b]);
	}
	
	for(b=0;b<10;b++)
	for(c=0;c<10;c++)
	{
		if(a[c]>a[c+1]) 
		{
			d=a[c];
			a[c]=a[c+1];
			a[c+1]=d;
			
		}
	}
	for(b=0;b<10;b++)
	{
		printf("%d ",a[b]);
	}
	return 0;
}
