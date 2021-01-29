#include<stdio.h>;
#include<math.h>;
int main()
{
	double r,c,n,d,y;
	char x,k;
	scanf("%lf,%lf",&c,&n);
	scanf("%c%c",&k,&x);
	if(n==1) r=0.0225;
	else if(n==2) r=0.0243;
	else if(n==3) r=0.0270;
	else if(n==5) r=0.0288;
	else if(n==8) r=0.0300;
	else {printf("Error year!");return 0;}
	if(x=='c')
	{
		y=1+r;
		y=pow(y,n);
		d=c*y;
	}
	if(x=='n')
	{
		y=r*n;
		d=c*(1+y);
	}
	printf("rate=%.4f,deposit=%.4f\n",r,d);
	return 0;
}