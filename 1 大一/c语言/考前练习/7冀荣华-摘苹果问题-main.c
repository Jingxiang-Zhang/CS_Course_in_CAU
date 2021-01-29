#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x[5],y,a,b,c;
	for(a=0;a<5;a++) scanf("%d",&x[a]);
	scanf("%d",&y);
	for(a=0,b=0;a<5;a++)
	if(y+10>=x[a]) b++;
	printf("%d",b);
	return 0;
}
