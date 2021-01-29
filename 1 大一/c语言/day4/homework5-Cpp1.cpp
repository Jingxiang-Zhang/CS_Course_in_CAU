#include<stdio.h>
int main ()
{
	int a,b,n,c;
	scanf("%d",&n);
    a=1;
	b=1;	
	if(n==1) {printf("%d",a);return 0;}
	else{
	n=n-1;

	
	while(n>=1)
	{
		a=a+b;
		c=a;
		n=n-1;
		if(n==1) break;
		else b=b+a;
		n=n-1;
		c=b;
		if(n==1) break;
	}
	};
	printf("%d",c);

	return 0;
}

