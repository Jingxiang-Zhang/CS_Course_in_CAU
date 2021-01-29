#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,f,m,x1,x2,x,y,k;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0 && b==0) printf("Not an equation");
	else if(a==0) {
		x1=-c/b;
		printf("%.2f",x1);}
	else 
	{
		f=b*b-4*a*c;
		if(f>=0) 
		{
			m=sqrt(f);
			x1=(-b+m)/(2*a);
			x2=(-b-m)/(2*a);
			if(x2>=x1) 
			{
				k=x1;
				x1=x2;
				x2=k;
			}
			printf("%.2f %.2f",x1,x2);
		}
		else
		{
			m=sqrt(-f);
			if(a<0)
			{
				a=-a;
				b=-b;
				c=-c;
			}
			x1=-b/(2*a);
			x2=x1;
			x=m/(2*a);
			y=x;
		    printf("%.2lf+%.2lfi %.2lf-%.2lfi",x1,x,x2,y);
		}


	
    }
	return 0;
}
