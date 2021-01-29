#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x[10],a,b,c,d;
	for(a=0;a<10;a++)
	{	
	    scanf("%d",&x[a]);
	    getchar();
	}
	for(b=0;b<10;b++)
	for(c=0;c<10;c++)
	{
		if(x[c]>x[c+1]) 
		{
			d=x[c];
			x[c]=x[c+1];
			x[c+1]=d;
			
		}
	}
	for(a=9,b=0;a>4;a--)
	b=b+x[a];

    printf("%d",b);
	return 0;
}
