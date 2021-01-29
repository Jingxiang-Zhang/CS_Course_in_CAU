#include<stdio.h>
int main()
{
	double a,b,c;
	int n,k;
	scanf("%d",&n);
	for(b=1,c=2,k=1;n>=2;n--)
	{
		b=b+k*1/c;
		k=-k;
		c=c+1;
	}
	printf("%.3f",b);
	return 0;
}




