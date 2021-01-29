
//StudybarCommentBegin
#include <string.h>
#include <stdio.h>
int main()
{
	char s1[100], s2[100];
        int CountSubstr( char  s1[], char  s2[] );
	scanf("%s", s1);
	scanf("%s", s2);
	printf("%d", CountSubstr(s1, s2));
}
//StudybarCommentEnd

int CountSubstr(char s1[], char s2[])
{
	int a,b,c,d,m;
	int x,y;
	x=strlen(s2);
	for(a=0,b=0;s1[a];a++)
	{
		for(m=a,c=0;c<x;c++,m++) 
		{
			if(s1[m]!=s2[c]) break;
		}
		if(x==c) {b++;	}
	}
	return (b);
}

