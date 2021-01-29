#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void insert(int a[],int n)
{
	int b,c,d,e;
	for(b=0;b<10;b++)
	if(n<a[b]) break;
	for(c=10;c>b;c--)
	a[c]=a[c-1];
	a[b]=n;
}
//StudybarCommentBegin
main()
{
int a[11]={10,20,30,40,50,60,70,80,90,100};
int number,i;
scanf("%d",&number);
insert(a,number);
for(i=0;i<11;i++)
  printf("%d ",a[i]);
}
//StudybarCommentEnd
