#include<stdio.h>
int main()
{
	int a,b,c,k[4][3],max,row,colum;
	for (a=0;a<4;a++)
	{
		for(b=0;b<3;b++)
		{
			scanf("%d",&k[a][b]);
		}
		getchar();
	}
	max=k[1][1];

	for(a=0;a<4;a++)
		for(b=0;b<3;b++)
		{
			if(k[a][b]>max)
			{
		    max=k[a][b];
			row=a;
			colum=b;
			}
		}
	printf("max=%d\nrow=%d\ncolum=%d\n",max,row,colum);
	return 0;
}


