#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	for(a=1;;a++)
	{
		if(a%2==1) 
		if(a%3==2)
		if(a%5==4)
		if(a%6==5)
		if(a%7==0)
		break;
	}
	printf("%d",a);
	return 0;
}
/*
有一条长阶梯，若每步跨2阶，最后剩下1阶；若每步跨3阶，最后剩下2阶；若每步跨5阶，最后剩下4阶；若每步
跨6阶，则最后剩下5阶；只有每步跨7阶，最后才正好1阶不剩。编写程序计算这条阶梯至少有多少阶。*/
