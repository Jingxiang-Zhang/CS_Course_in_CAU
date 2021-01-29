#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c,d;
	scanf("%lf",&a);
	if(a<=240) b=0.53*a;
	else if(a<=400) b=127.2+(a-240)*0.58;
	else b=220+(a-400)*0.83;
	printf("%.2f",b); 
	return 0;
}



/*
第一档电量：每月不超过240千瓦时的电量，电价标准维持现价不变（0.53元/千瓦时）。

第二档电量：每月241一400千瓦时之间的电量，电价标准比第一档电价提高0.05元/千瓦时。

第三档电量：每月超过400千瓦时的电量，电价标准比第一档电价提高0.3元/千瓦时。
*/
