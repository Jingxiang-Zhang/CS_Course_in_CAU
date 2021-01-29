#include<stdio.h>
int main()
{
	char t[100];
	int a,b,c=0,d=0,k=0;
	gets(t);


	for(a=0,b=0;a<20;a++){
	for(c=0;b<100;b++)
	{if((t[b]>='a' && t[b]<='z')	||(t[b]>='A' && t[b]<='Z')	||t[b]==39) c=c+1;
	 else break;
	}
	if(c!=0)printf("%d",c);
	if(t[b]==' '&&t[b+1]!=' ')printf(" ");
	b=b+1;
	}

	return 0;
}
