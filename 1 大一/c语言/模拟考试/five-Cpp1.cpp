#include<stdio.h>
int main()
{
	int a,b,c;
	int x[20],y[20];
	for(a=0;a<20;a++) x[a]=0;
	for(a=0;a<20;a++) y[a]=0;
	for(a=0;a<20;a++)
	{scanf("%d",&x[a]);
	if(x[a]<=0) {x[a]=0;break;}}
	for(a=0;a<20;a++)
	{scanf("%d",&y[a]);
	if(y[a]<=0) {y[a]=0;break;}}
	
	for(a=0;a<20;a++)
		for(b=0;b<19;b++)
			if(x[b]<x[b+1])
			{
				c=x[b+1];
				x[b+1]=x[b];
				x[b]=c;
			}
	for(a=0;a<20;a++)
		for(b=0;b<19;b++)
			if(y[b]<y[b+1])
			{
				c=y[b+1];
				y[b+1]=y[b];
				y[b]=c;
			}





	for(a=0;a<20;a++)
		if(x[a]!=y[a]) {printf("n");return 0;}
	printf("y") ;
	return 0;
}