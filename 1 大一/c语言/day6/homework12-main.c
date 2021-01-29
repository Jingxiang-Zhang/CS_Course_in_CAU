#include <stdio.h>
#include <stdlib.h>
#define arr_size 20

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void inverse(char a[arr_size])
{
	int x,y,z;
	char m;
	for(x=0;x<20;x++)
	{
		if((a[x]>='a' && a[x]<='z') || a[x]==' ' || (a[x]>='0' && a[x]<='9'));
		else break;
	}
	for(y=0;y<(x/2);y++)
	{
		m=a[y];
		a[y]=a[x-y];
		a[x-y]=m;
	}
	for(y=0;y<20;y++)
	a[y]=a[y+1];
}
	
	
//StudybarCommentBegin
int main()
{char a[arr_size];
gets(a);
inverse(a);
puts(a);
return 0;
}
//StudybarCommentEnd
