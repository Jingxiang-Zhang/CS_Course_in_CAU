#include<stdio.h>
int main()
{
	double w,h,t;
	scanf("%lf %lf",&w,&h);
	t=w/h/h;
	if(t<18) printf("lower weight");
	else if(t>=18 && t<25) printf("normal weight");
	else if(t>=25 && t<27) printf("higher weight");
	else printf("obesity");
	return 01;
}