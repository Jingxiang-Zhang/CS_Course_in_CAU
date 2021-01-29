#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int x,int y) 
{
	int a,b,c;
	if(x<y) a=x;else a=y;
	for(;a>1;a--)
	if(x%a==0 && y%a==0) break;
	return(a);
}
int lcm(int x,int y)
{
	int a,b;
	a=gcd(x,y);
	b=x*y/a;
	return(b);
}

//StudybarCommentBegin
void main()
{
int x,y;
scanf("%d%d",&x,&y);
printf("%d %d\n",gcd(x,y),lcm(x,y));
}
//StudybarCommentEnd
 
