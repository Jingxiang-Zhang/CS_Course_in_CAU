
#include<stdio.h>
int max_value(int a[3][4])
{
	int b,c,d;
	d=a[0][0];
	for(b=0;b<3;b++)
		for(c=0;c<4;c++)
		{
			if(a[b][c]>d)d=a[b][c];
		}
		return(d);
}

//StudybarCommentBegin
int main()
{
int a[3][4],i,j;
for(i=0;i<3;i++)
for(j=0;j<4;j++)
scanf("%d",&a[i][j]);
printf("Max value is %d\n",max_value(a));
return 0;
}
//StudybarCommentEnd

