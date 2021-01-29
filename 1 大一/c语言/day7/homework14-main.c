#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//StudybarCommentBegin
void main()
{
 int n;
 char a[100]={0};
 char b[100]={0};
void strcpyn(char *s,char *t, int n);
 scanf("%s",a);
 scanf("%d",&n);
 strcpyn(a,b,n);
 printf("%s",b);
}
//StudybarCommentEnd
void strcpyn(char *s,char *t, int n)
{
	int a=0;
	for(n--;n<100;n++,a++)
    t[a]=s[n];

} 
