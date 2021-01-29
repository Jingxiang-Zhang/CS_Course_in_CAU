#include<stdio.h>
int main()
{
	char x[30];
	int i,j=0,k=0;
	char c;
	gets(x);
	for(i=0;(c=x[i])!='\0';i++)
	{if(c==' ') j=0;
		else if(j==0)
		{j=1;k=k+1;}}
	printf("%d",k);
	return 0;
}
