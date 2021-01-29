#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int let[26];
	char tar[50],t;
	int a,b,c,len,max;
	for(a=0;a<26;a++) let[a]=0;
	scanf("%s",tar);
	len=strlen(tar);
	if(tar[0]=='a'){printf("t");return 0;}
	for (a=0;a<len;a++)
	{
		t=tar[a];
		let[t-97]++;
	}
	for(a=0,max=let[0],b=0;a<len;a++)
	if(let[a]>max)
	{
		max=let[a];
		b=a;
	}
	t=b+97;
	printf("%c",t);
	return 0;
}

