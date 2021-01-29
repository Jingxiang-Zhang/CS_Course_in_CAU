#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int k[3][3],a,b,c;
	for(a=0;a<3;a++)
	for(b=0;b<3;b++)
	scanf("%d",&k[a][b]);
	a=k[0][0]+k[1][1]+k[2][2]+k[0][2]+k[2][0];
	printf("%d",a);

	
	
	return 0;
}
