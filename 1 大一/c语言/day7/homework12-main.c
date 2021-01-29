#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
//StudybarCommentBegin
#include <stdio.h>
void main()
{
	char a[80];
	char b[80];
        void swap(char *, char *);
        gets(a);
        gets(b);
	printf("%s %s\n", a, b );
	swap(a,b);
	printf("%s %s\n", a, b );
}
//StudybarCommentEnd
void swap(char *a,char *b)
{
	int m,n;
	for(m=0;m<80;m++)
	{
		n=a[m];a[m]=b[m];b[m]=n;
	}
	
 } 
