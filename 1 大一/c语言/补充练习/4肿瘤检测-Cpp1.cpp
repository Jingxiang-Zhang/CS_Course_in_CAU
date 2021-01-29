#include<stdio.h>
int main()
{
	int a[20][20];
	int b,c,d,e,x=0,y=0;
	scanf("%d",&b);
	for(c=0;c<b;c++)
		for(d=0;d<b;d++)
			a[c][d]=99;
	for(c=0;c<b;c++)
		for(d=0;d<b;d++)
			scanf("%d",&a[c][d]);
	for(c=0;c<b;c++)
		for(d=0;d<b;d++)
		{
			if(a[c][d]<=50)
			{x++;
			 if(a[c-1][d]>50 || a[c+1][d]>50 || a[c][d-1]>50 || a[c][d+1]>50)
				 y++;
			}
		}
		printf("%d %d",x,y);
		return 0;
}

