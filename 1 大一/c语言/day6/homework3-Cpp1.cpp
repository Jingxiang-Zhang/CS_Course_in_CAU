//StudybarCommentBegin
#include<stdio.h>

int main()
{
	double equation(double x,int n);
	double x,n,k;
    scanf("%lf %lf",&x,&n);
	k=equation(x,n);
    printf("%f",k);
	return 0;
}
//StudybarCommentEnd

double fact(double n)
{
    double a;
	if(n==0 || n==1)a=1;
	else a=fact(n-1)*n;
	return(a);
}
double mypow(double x,double n)
{
	double a,b;
	for(a=n,b=1;a>0;a--)
		b=b*x;
	return(b);
}
double equation(double x,int n)
{
	double a,b,c;
	for(a=1,b=1,c=0;a<=n;a++)
	{
	    c=c+b*mypow(x,a)/fact(a);
		b=-b;
	}
	return(c);
}




