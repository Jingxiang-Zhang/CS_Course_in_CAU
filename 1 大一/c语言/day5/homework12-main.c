#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d,e,k[10][10];
	c=1;
	for(a=0;a<10;a++)
	for(b=0;b<=a;b++)
	{
		if(a==0 && b==0) 
		{    k[a][b]=1;
		    printf("%d\n",k[a][b]);
		}
		else if(b==0) 
		{
			k[a][b]=1;
		    printf("%d ",k[a][b]);
		}
		else if(a!=b){
			k[a][b]=k[a-1][b-1]+k[a-1][b];
			printf("%d ",k[a][b]);	
		}
		else 
		{
			k[a][b]=1;
			printf("%d\n",k[a][b]); 
		}
	    
	}
	return 0;
}
