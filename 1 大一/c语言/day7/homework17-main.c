#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//StudybarCommentBegin
#include <stdio.h>
void main()
{
	char str1[100], str2[100];
        void strconnect(char *,char *);
	scanf("%s", str1);
	scanf("%s", str2);
	strconnect(str1, str2);
	printf("%s", str1);
}
//StudybarCommentEnd
void strconnect(char *a,char *b)
{
	int c,d,e,f;
	for(c=0;c<100;c++)
	if(a[c]=='\0') break;
	for(d=0;c<100;c++)
	{
		a[c]=b[d];d=d+1;
	}
 } 
