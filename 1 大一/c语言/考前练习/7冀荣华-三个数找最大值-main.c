#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
//StudybarCommentBegin
#include "stdio.h"
void main()
{
	void max(int,int,int);
	int in1,in2,in3;
	scanf("%d%d%d",&in1,&in2,&in3);
	max(in1,in2,in3);
}


//StudybarCommentEnd
void max(int a,int b,int c)
{
	if(b>a) a=b;
	if(c>a) a=c;
	printf("%d",a);
}
