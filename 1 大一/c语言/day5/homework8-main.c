#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[3][3],b,c,d;
	for(b=0;b<3;b++)
	for(c=0;c<3;c++)
	scanf("%d",&a[b][c]);
	for(b=0;b<3;b++)
	for(c=0;c<3;c++)
	{
		printf("%d",a[c][b]);
		if(c!=2) printf(" "); 
		if(c==2) printf("\n");
	}
	return 0;
}
