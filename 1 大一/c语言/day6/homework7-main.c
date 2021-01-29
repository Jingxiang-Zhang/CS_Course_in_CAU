#include <stdio.h>
#include <stdlib.h>
#define arr_size 20

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void inverse(char a[arr_size],char b[arr_size])
{
	int x,y,z;
	char m;
	for(x=0;x<20;x++)
	{
		if((a[x]>='a' && a[x]<='z') || a[x]==' ');
		else break;
	}
	for(y=0;y<(x/2);y++)
	{
		m=a[y];
		a[y]=a[x-y];
		a[x-y]=m;
	}
	for(y=0;y<20;y++)
	b[y]=a[y+1];
}
	
	
//StudybarCommentBegin
int main()
{char a[arr_size],b[arr_size];
gets(a);
inverse(a,b);
puts(b);
return 0;
}
//StudybarCommentEnd
