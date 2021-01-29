#include <stdio.h>
#include <stdlib.h>
#define arr_size 80

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void inverse(char a[])
{
	int b,c,d;
	char k;
	for(b=0;a[b]!='\0';b++);b--;
	c=b/2+1;
	for(d=0;d<c;d++)
	{
		k=a[d];a[d]=a[b-d];a[b-d]=k;
	}
	
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
