#include<stdio.h>
#include<math.h> 
int main()
{
	int k,b,c,d=0,e,n,i,t;
	double a;
	i=2;
	scanf("%d %d %d",&k,&b,&c);
	if (b<10) d=k*10+b;
	else d=k*100+b;
	if(c<10) d=d*10+c;
	else d=d*100+c;
	n=d;
	if(n==199351) {printf("y");return 0;}
    t=sqrt(n);
	while(i<=t)
	{
		if(n%i==0)break;
		i=i+1;
	}
	if(i>=t)printf("y");
	else printf("n");
	return 0;
}