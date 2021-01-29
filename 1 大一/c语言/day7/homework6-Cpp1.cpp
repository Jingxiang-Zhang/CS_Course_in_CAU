#include<stdio.h>
void FindMaxandMin(int a[10],int b,int *maxnum,int *minnum)
{
	int m,x,y;
	x=0;y=0;
	for(m=0;m<10;m++)
		if(a[m]>x) x=m;
	for(m=0;m<10;m++)
		if(a[m]<y) y=m;
	*maxnum=a[x];
	*minnum=a[y];

}

    
//StudybarCommentBegin
int main()
{
int a[10],i,maxnum,minnum;

for(i=0;i<10;i++)
          scanf("%d",&a[i]);

FindMaxandMin(a,10,&maxnum,&minnum);

printf("%d %d",maxnum,minnum);

}
//StudybarCommentEnd
