#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//StudybarCommentBegin
#include <stdio.h>
int replace(char *src, char *dest);
void main()
{
	int count;
	char src[100], dest[100];
	gets(src);
	count = replace( src, dest );
	printf("%s\n%d", dest, count);
}
//StudybarCommentEnd
int replace(char *src, char *dest)
{
	int a,b=0;
	for(a=0;a<100;a++)
	{
		if(src[a]=='t') 
		{b=b+1;dest[a]='e'; }
		else if(src[a]=='T') 
		{b=b+1;dest[a]='E'; }
		else dest[a]=src[a];
	}
	return (b);
 } 
