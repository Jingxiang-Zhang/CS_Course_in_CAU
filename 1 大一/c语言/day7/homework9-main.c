#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[40],b[40],c[40	];
	int x,y,z;
	gets(a);gets(b);gets(c);
	for(x=0;x<3;x++)
		if(a[x]!=b[x] && b[x]!=c[x]) break;
	if(a[x]>b[x] && b[x]>c[x]){puts(c);puts(b);puts(a);}
	if(a[x]>c[x] && c[x]>b[x]){puts(b);puts(c);puts(a);}
	if(b[x]>a[x] && a[x]>c[x]){puts(c);puts(a);puts(b);}
	if(b[x]>c[x] && c[x]>a[x]){puts(a);puts(c);puts(b);}
	if(c[x]>b[x] && b[x]>a[x]){puts(a);puts(b);puts(c);}
	if(c[x]>a[x] && a[x]>b[x]){puts(b);puts(a);puts(c);}
	
	return 0;
}
