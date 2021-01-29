#include <stdio.h>
int main()
{
	double a,b,d;
	char c;
	scanf("%lf%c%lf",&a,&c,&b);
	if(c=='+') d=a+b;
	else if(c=='-') d=a-b;
	else if(c=='*') d=a*b;
	else if(c=='/') 
	{
		if(b==0) {printf("error"); return 0;}
        else d=a/b;
	} 
	printf("%.2f",d);

return 0;
}