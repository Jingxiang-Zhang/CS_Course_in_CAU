//StudybarCommentBegin
#include <stdio.h>
#include <string.h>
int main()
{
	void copystr(char s1[],char s2[],int n);
        int m;
        char str1[20],str2[20];
        gets(str1);
        scanf("%d",&m);
        if(strlen(str1)<m)  printf("input error!");
        else
        {
  	        copystr(str1,str2,m);
                printf("%s",str2);
        }
        return 0;
}

//StudybarCommentEnd

void copystr(char s1[],char s2[],int n)
{
	int a,b,c;
	if(n==1)
	{for(a=0;a<20;a++) s2[a]=s1[a];}
	else
	{for(a=0;a<20;a++)
	{
		if((s1[a+n-2]>='0' && s1[a+n-2]<='9')||(s1[a+n-2]>='a' && s1[a+n-2]<='z')||(s1[a+n-2]>='A' && s1[a+n-2]<='Z'))  s2[a]=s1[a+n-1];
		else break;
}}}



