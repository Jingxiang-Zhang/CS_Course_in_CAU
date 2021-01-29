#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//StudybarCommentBegin
int main()
{
	int n;
	void jdgprime(int n);
	scanf("%d",&n);
	jdgprime(n);
	return 0;
}

//StudybarCommentEnd

void jdgprime(int n)
{
	int a,b,c,d;
	for(a=2;a<n;a++)
	if(n%a==0) break;
	if(a==n) printf("y");
	else {
		b=n/a;
		printf("%d*%d",a,b);
	}
}

