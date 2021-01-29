#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fab(int x)
{
	int a,b,c,i,j,m;
	a=1;b=1;
	if(x==2 || x==1) return(1);
	x=x-2;
	for(;1;)
	{
		a=a+b;
		x=x-1;
		if(x==0){m=a;break;}
		else b=a+b;
		x=x-1;
		if(x==0){m=b;break;}
		
	}
	return (m);
 } 
//StudybarCommentBegin
#include <stdio.h>
int main()
{int n;
scanf("%d",&n);
printf("%d",fab(n));
return 0;
}
//StudybarCommentEnd
