#include<stdio.h>
int main()
{
	char a[7];
	int b,c,d;
	for(b=0;b<7;b++)
	{scanf("%c",&a[b]);
	if(a[b]=='\n') break;}

	for(d=0;d<b;d++)
	{for(c=d;c<b;c++)
		printf("%c",a[c]);
	printf("\n");
	if(d==b-1)return 0;
	}		

}
