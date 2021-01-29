#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	double x[3],q,s,t,k;
	for(a=0;a<3;a++) scanf("%lf",&x[a]);	
	for(a=0;a<3;a++)
	for(b=0;b<2;b++)
	if(x[b]>x[b+1]) {c=x[b];x[b]=x[b+1];x[b+1]=c;}
	if(x[0]+x[1]<=x[2]) {printf("They can't form a triangle.");return 0;} 
	q=(x[0]+x[1]+x[2])/2;
	s=q*(q-x[0])*(q-x[1])*(q-x[2]) ;
	t=sqrt(s);
	k=x[0]+x[1]+x[2];
	printf("%.2f %.2f",k,t);
	
	return 0;
}



/*
三角形成立的判断条件是任意两边之和大于第三边。
三角形面积=sqrt（p(p-a)(p-b)(p-c)）, 其中p=(a+b+c)/2
三角形面积（结果保留2位小数）
*/
