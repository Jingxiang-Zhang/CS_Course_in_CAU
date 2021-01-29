#include <stdio.h>
int main ()
{
	int a,b,c;
	double x,y,z;
	char c1,c2;
	a=3;
	b=4;
	c=5;
	x=1.2;
	y=2.4;
	z=-3.6;
	c1='a';
	c2='b';
	printf("a= %d b= %d c= %d\n",a,b,c);
	printf("x= %.2f,y= %.2f,z=%.2f\n",x,y,z);
	printf("c1='%c' or %d(ASCLL)\n",c1,c1);
	printf("c2='%c' or %d(ASCII)\n",c2,c2);
	return 0;
}
