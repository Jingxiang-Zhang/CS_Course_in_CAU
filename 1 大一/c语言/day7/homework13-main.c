#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//StudybarCommentBegin
#include <stdio.h>
void main()
{
	char str1[100], str2[100];
        int n;
        int strcompare(char *p1,char *p2);
	scanf("%s", str1);
	scanf("%s", str2);
	n=strcompare(str1, str2);
	printf("%d", n);
}
//StudybarCommentEnd
int strcompare(char *p1,char *p2)
{
	int a,b,c,d,e;
	for(a=0;a<30;a++)
	if(p1[a]=='\0') break;
	for(b=0;b<30;b++)
	if(p2[b]=='\0') break;
	if(a>b) c=b;else c=a;
	
	for(d=0;d<c;d++)
	if(p1[d]!=p2[d]) break;
	if(d==c && a==b) return(0);
	else if(d==c &&a>b) return(1);
	else if(d==c &&a<b) return(-1);	
	else {e=p1[d]-p2[d];return (e);}	
 } 

