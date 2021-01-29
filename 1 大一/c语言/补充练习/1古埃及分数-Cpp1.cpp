#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	double k;
	scanf("%lf/%lf",&a,&b);
	a=a/b;
    for(k=1; ;k++)
	{   
		c=a-1/k;
		if(c>=0 || (c<=0 && c>=-0.000000001))
		{printf("1/%.0f",k);
		 a=a-1/k;
		 if(a<0.00001) break;
		 else printf("+");
		}
	}
	return 0;
}