#include<stdio.h>
int main()
{
	int a,b,c,d,e,m,n;
	a=100;
	while(a<=999)
	{
		b=a;
		c=b%10;
		d=(b-c)/10%10;
		e=(b-c-10*d)/100;
		if(c+d+e==b) printf("%d\n",a);
		else if(c*c+d*d+e*e==b) printf("%d\n",a);
		else if(c*c*c+d*d*d+e*e*e==b) printf("%d\n",a);
		else if(c*c*c*c+d*d*d*d+e*e*e*e==b) printf("%d\n",a);
		else if(c*c*c*c*c+d*d*d*d*d+e*e*e*e*e==b) printf("%d\n",a);
	

		a=a+1;
	}

	return 0;
}