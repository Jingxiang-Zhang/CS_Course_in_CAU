#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c,d;
	scanf("%lf",&a);
	b=fmod(a,1.0);
	if(b!=0) a=a-b+1;
	if(a<=10) a=30;
	else if(a<=50) a=(a-10)*3+30;
	else a=150+(a-50)*1;
	printf("%.0f",a);
	
	return 0;
}

//  30元           <=10小时
//费用=  每小时3元       10—50小时

//       每小时2元       >=50小时
