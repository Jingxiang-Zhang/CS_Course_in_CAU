#include <stdio.h>
int main()
{
	char x[30],y[30];
	int i,j,k,t;
	gets(x);
	for(i=0,j=0;i<30;i++)
	{
		if(x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u' || x[i]=='A' || x[i]=='E' || x[i]=='I' || x[i]=='O' || x[i]=='U')
		{y[j]=x[i]; j++;}
	}
	for(i=0;i<30;i++)
		for(j=0;j<29;j++)
			if(y[j]>y[j+1])
			{t=y[j+1];y[j+1]=y[j];y[j]=t;}
	for(i=0;i<30;i++)
	{
		if((y[i]>='a' && y[i]<='z')||(y[i]>='A' && y[i]<='Z'))
			break;
	}



	for(;i<30;i++)
		if((y[i]>='a' && y[i]<='z')||(y[i]>='A' && y[i]<='Z'))
		printf("%c",y[i]);
	return 0;
}