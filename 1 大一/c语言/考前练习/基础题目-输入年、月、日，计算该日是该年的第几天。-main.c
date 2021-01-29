#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x,y,z,k;
	int a,b,c;
	scanf("%d %d %d",&x,&y,&z);
	if((x%4==0 && x%100!=0) || (x%400==0)) k=1 ;else k=0;
	if(y==1) a=z;
	else if(y==2) a=31+z;
	else if(y==3) a=59+z;
	else if(y==4) a=90+z;
	else if(y==5) a=120+z;
	else if(y==6) a=151+z;
	else if(y==7) a=181+z;
	else if(y==8) a=212+z;
	else if(y==9) a=243+z;
	else if(y==10) a=274+z;
	else if(y==11) a=304+z;
	else if(y==12) a=334+z;
	if(k==1 && y>2) a++;
	printf("%d",a);	 
	return 0;
}
