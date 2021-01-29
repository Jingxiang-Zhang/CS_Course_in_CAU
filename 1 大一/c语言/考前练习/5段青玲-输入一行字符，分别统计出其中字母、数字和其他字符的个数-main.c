#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[20];
	int b,c,d,le=0,nu=0,sp=0,ot=0;
	gets(a);
	for(b=0;a[b]!='\0';b++)
	if(a[b]>='0' && a[b]<='9') nu++;
	else if((a[b]>='a' && a[b]<='z')||(a[b]>='A' && a[b]<='Z')) le++;
	else ot++;
	printf("letter:%d\ndigit:%d\nother:%d",le,nu,ot);

	return 0;
}

/*letter:11

digit:4

other:3*/
