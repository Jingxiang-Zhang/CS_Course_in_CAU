#include <string.h> 
//StudybarCommentBegin
#include <stdio.h>
#define SIZE 80
int MyStrcmp(char s[],char t[]);
main()
{
    char s[SIZE],t[SIZE],i;
    gets(s);
    gets(t);
    i=MyStrcmp(s,t);
    if(i>0)
        printf("string s>string t.\n");
    else if(i<0)
        printf("string s<string t.\n");
    else
        printf("string s=string t.\n");
}

//StudybarCommentEnd
int MyStrcmp(char s[],char t[])
{
	int a,b,c,d;
	a=strlen(s);b=strlen(t);
	if(a<b) a=b;
	for(b=0;b<a;b++) if(s[b]!=t[b]) break;
	return(s[b]-t[b]);
     	
} 
	
