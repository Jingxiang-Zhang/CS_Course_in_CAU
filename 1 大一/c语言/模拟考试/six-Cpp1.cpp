#include<stdio.h>
int main()
{
	int t[8],x,a,b;
	for(a=0;a<8;a++) t[a]=0;
	scanf("%d",&x);
	for(a=0;a<8;a++)
	{
		b=x%2;
		if(b==1){
			t[a]=1;
			x=(x-1)/2;}
		else x=x/2;
	}
	for(a=7;a>=0;a--)
		printf("%d",t[a]);
	return 0;
}