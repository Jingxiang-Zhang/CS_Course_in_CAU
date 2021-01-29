#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[3][3];
	int b,c,d;
	a[0][0]=3; 	a[0][1]=5; 	a[0][2]=5; 
	a[1][0]=12; a[1][1]=5; 	a[1][2]=81; 
	a[2][0]=33; a[2][1]=55; a[2][2]=77; 
	int max,x=0,y=0; max=a[0][0];
	for(b=0;b<3;b++)
	for(c=0;c<3;c++)
	if(a[b][c]>max) {max=a[b][c];x=b;y=c;} 
	printf("最大值a[%d][%d]的坐标为%d,%d",x,y,x,y);

	

	
	return 0;
}

