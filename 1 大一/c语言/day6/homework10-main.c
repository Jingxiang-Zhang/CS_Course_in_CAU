//StudybarCommentBegin
#include <stdio.h>
int main()
{void sort(int array[],int n);
int a[10],i;
for(i=0;i<10;i++)scanf("%d",&a[i]);
sort(a,10);
for(i=0;i<10;i++)
printf("%d ",a[i]);
return 0;
}

//StudybarCommentEnd


void sort(int array[],int n)
{
	int i,t,k;
	for(i=0;i<9;i++)
	for(t=0;t<9-i;t++)
	{
		if(array[t]>array[t+1])
		{
			k=array[t+1];
			array[t+1]=array[t];
			array[t]=k;
		}
	}
}
