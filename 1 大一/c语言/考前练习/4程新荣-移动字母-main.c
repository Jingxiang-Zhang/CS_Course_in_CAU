//StudybarCommentBegin
#include <stdio.h>
#include <string.h>
void shift(char s[]);
int main()
{
    char s[10];
    gets(s);
    shift(s);
    printf("%s\n", s);       
    return 0; 
}
//StudybarCommentEnd
 
void shift(char s[])
{
	int a,b,c,d;
	a=strlen(s);
	char x,y,z;
	x=s[0];y=s[1];z=s[2];
	for(b=0;b<a-3;b++)
	s[b]=s[b+3];
	s[a-3]=x;s[a-2]=y;s[a-1]=z;
}

