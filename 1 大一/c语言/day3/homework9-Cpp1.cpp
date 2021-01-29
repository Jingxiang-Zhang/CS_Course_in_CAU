#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d",&a);
	a=(a*3+3)*3;
	b=a%10;
	c=(a-b)/10;
	a=b+c;
	if(a==1) printf("前任男友女友");
	if(a==2) printf("现在身边的人");
	if(a==3) printf("曾经暧昧的人");
	if(a==4) printf("好朋友");
	if(a==5) printf("家里的亲戚");
	if(a==6) printf("现任男友女友");
	if(a==7) printf("父母");
	if(a==8) printf("同学");
	if(a==9) printf("编程语言老师");
	if(a==10) printf("情敌");

	return 0;
}
