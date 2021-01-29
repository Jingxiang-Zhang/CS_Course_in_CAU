#include <stdio.h>
int main()
{
	int a,b,c,d,e;
    scanf("%d",&a);
	b=a%10;
	c=(a-b)/10%10;
	d=(a-10*c-b)/100%10;
	printf("%d%d%d\n",b,c,d);
	return 0;
}