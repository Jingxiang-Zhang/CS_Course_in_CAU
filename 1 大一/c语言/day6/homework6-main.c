#include <stdio.h>
#include <stdlib.h>
#define arr_size1 15
#define arr_size2 15

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mystrcat(char t[15],char s[15])
{
	int a,b;
	for(a=0;a<30;a++)
	{
		if(t[a]>='a' && t[a]<='z') ; 
		else break;
    }
    for(b=0;b<15;b++)
    {
    	if(s[b]>='a' && s[b]<='z') {t[a]=s[b];a++;}
    	else t[a]='\0';
	}

 } 
 
//StudybarCommentBegin
int main()
{
char s[arr_size1],t[arr_size2];
gets(s);
gets(t);
mystrcat(t,s);
printf("The concatenate string is :");
puts(t);
return 0;
}

//StudybarCommentEnd
