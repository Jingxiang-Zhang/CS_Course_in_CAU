#include <stdio.h>
int main()
{
	int x,y,a,b,c,d,e;
	char g;
	scanf("%d %d",&x,&y);
	a=x+y;
	b=x-y;
	c=x*y;
	d=x/y;
	e=x%y;
	g='%';
	printf("%d+%d=%d\n",x,y,a);
	printf("%d-%d=%d\n",x,y,b);
	printf("%d*%d=%d\n",x,y,c);
	printf("%d/%d=%d\n",x,y,d);
	printf("%d%c%d=%d\n",x,g,y,e);
	return 0;
}
