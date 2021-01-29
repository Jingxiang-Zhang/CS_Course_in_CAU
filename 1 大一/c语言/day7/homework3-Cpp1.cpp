#include<stdio.h>
void swap(int *a,int *b)
{
	int k;
    if(*a<*b)
	{k=*a;*a=*b;*b=k;}
}
void exchange(int *a,int *b, int *c)
{
	swap(b,c);
	swap(a,b);
	swap(b,c);
}




//StudybarCommentBegin
int main( )
{
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
exchange(&a,&b,&c);
printf("%d %d %d",a,b,c);
return 0;
}
//StudybarCommentEnd

