#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d,m,n;
	scanf("%d %d",&a,&b);
	c=a;
	while(c>=2)
	{
	
	    if(a%c==0)
	    {
	    	if(b%c==0)
			{
				n=c;
				break;
			}; 
		}
		c=c-1;
	};
	m=a*b/n;
	printf("%d %d",n,m);
	
	return 0;
}
