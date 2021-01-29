#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[10],b,c,d,m;
	for(b=0;b<10;b++) scanf("%d",&a[b]);
	for(b=0;b<10;b++)
	for(c=0;c<9;c++)
	if(a[c+1]<a[c])
	{
		d=a[c+1];a[c+1]=a[c];a[c]=d;
	}
	m=a[0]+a[1]+a[2]+a[3]+a[4];
	printf("%d",m);
	return 0;
}

