#include<stdio.h>
#include<math.h>
int main ()
{
	int k[10],a,b,c;
	for(a=0;a<10;a++)
		scanf("%d",&k[a]);
	c=abs(k[1]);
	for(a=0;a<10;a++)
	{
		if(abs(k[a])<c) c=k[a];
	}
	printf("%d",c);
	return 0;
}
		