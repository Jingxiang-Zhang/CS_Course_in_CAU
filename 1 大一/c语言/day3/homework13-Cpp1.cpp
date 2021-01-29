#include<stdio.h>
int main()
{
	double a,b,c,flag,d,e,flag2,A,B,C,m,n,x;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	if(a<=0 || b<=0 || c<0){printf("不是三角形");return 0;}
    flag=1;
	flag2=1;
	if(a>=b) d=a;
	else d=b;
	if(d>=c) d=d;
	else d=c;
	if(d>=a+b){printf("不是三角形");return 0;}
	A=a*a;
	B=b*b;
	C=c*c;
	if(a==b || a==c || b==c) flag=0;

	if(A>=B)m=A;
	else m=B;
	if(m>=C)m=m;
	else m=C;

	if(A>=B)n=B;
	else n=A;
	if(n>=C)n=C;
	else n=n;

	if(m==A && n==B)x=C;
    else if(m==B && n==A)x=C;
	else if(m==C && n==A)x=B;
	else if(m==A && n==C)x=B;
	else if(m==B && n==C)x=A;
	else x=A;
	 
	x=m-n-x;
	if(x<=0.1  &&  x>=-0.1)flag2=0;
	else flag2=1;

	if(flag==0 && flag2==0) printf("等腰直角三角形");
	else if(flag==0 && flag2==1) printf("等腰三角形");
	else if(flag==1 && flag2==0) printf("直角三角形");
	else printf("一般三角形");
	return 0;

}