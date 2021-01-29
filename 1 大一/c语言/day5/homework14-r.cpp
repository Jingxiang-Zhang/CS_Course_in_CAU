#include<stdio.h>
int main ()
{
	char x[20],y[20];
	int i,j,k;
	for(i=0;i<20;i++)
	{scanf("%c",&x[i]);
	if(x[i]=='\n') break;}

	for(i=0;i<20;i++)
	{scanf("%c",&y[i]);
	if(y[i]=='\n') break;}

	for(i=0;i<20 &&((x[i]>='0' && x[i]<='9') || (x[i]>='a' && x[i]<='z') || (x[i]>='A' && x[i]<='Z'));i++)
	 printf("%c",x[i]);

	for(i=0;i<20 &&((y[i]>='0' && y[i]<='9') || (y[i]>='a' && y[i]<='z') || (y[i]>='A' && y[i]<='Z'));i++)
    printf("%c",y[i]);
	return 0;
}
