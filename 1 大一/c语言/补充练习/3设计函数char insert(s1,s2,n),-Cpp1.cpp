//StudybarCommentBegin
#include <stdio.h>
char* insert(char* s1,char* s2,int n);
void main() 
{ 
 int n;
 char s1[100], s2[100];
 char *ss;
 scanf("%s", s1);
 scanf("%s", s2);
 scanf("%d", &n);
 ss=insert(s1,s2,n);
 printf("%s",ss);
}
//StudybarCommentEnd

char* insert(char* s2,char* s1,int n)
{
	int a,b,c,d,x,y,z;
	for(a=0;a<100;a++)
		if(s1[a]=='\0') break;
	c=a;
	for(b=0;b<100;b++)
		if(s2[b]=='\0') break;
    d=b;

    for(x=n;x<b;x++,c++)
		s1[c]=s2[x];

	s1[c]='\0';
	a=a+b-n;

	for(x=n,y=0;x<100;x++,y++)
		s2[x]=s1[y];
	return(s2);
}
    
