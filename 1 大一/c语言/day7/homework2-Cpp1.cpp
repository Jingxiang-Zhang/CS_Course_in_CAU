#include<stdio.h> 
void swap(int *a,int *b)
{
	int x;
	x=*a;
	*a=*b;
	*b=x;
}





//StudybarCommentBegin
int main( )
{
int a,b;
scanf("%d%d",&a,&b);
swap(&a,&b);
printf("%d %d",a,b);
return 0;
}
//StudybarCommentEnd

 