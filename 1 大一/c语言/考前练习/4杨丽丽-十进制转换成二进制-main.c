#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void  DToB(int a)
{
	int b,c,d,e,m[8];
	for(b=0;b<8;b++)
	{
		if(a%2==0) m[b]=0;
		else m[b]=1;
		a=(a-m[b])/2;
	}
	for(b=7;b>=0;b--)
	printf("%d",m[b]);
}
//StudybarCommentBegin
main()
{
int a;
scanf("%d",&a);
DToB(a);
}
//StudybarCommentEnd

