#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x[6],a,b,c,d;
	for(a=0;a<5;a++) scanf("%d",&x[a]);x[6]=100;
	for(a=0;a<5;a++)
	for(b=0;b<4;b++) 
	if(x[b]>x[b+1]) {c=x[b];x[b]=x[b+1];x[b+1]=c;}
	a=0;b=0;
	while(1)
	{
		if(x[b]!=a) {printf("%d\n",a);a++;}
		else {for(c=b;1;c++)
			if(x[c]!=a) break;
			b=c;a++;} 
		if(a==10) break;
		
		     
		
	}
	return 0;
}
