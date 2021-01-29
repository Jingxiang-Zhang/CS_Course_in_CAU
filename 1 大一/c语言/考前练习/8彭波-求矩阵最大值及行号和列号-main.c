#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d,x,y,n,m;
	int z[10][10];
	printf("请输入矩阵行和列：");
	scanf("%d %d",&x,&y);
	printf("请输入矩阵元素值："); 
	for(a=0;a<x;a++)
	for(b=0;b<y;b++)
	scanf("%d",&z[a][b]);
	m=z[0][0];c=0;d=0;
	for(a=0;a<x;a++)
	for(b=0;b<y;b++)
	if(z[a][b]>m){m=z[a][b];c=a;d=b;}
	printf("该矩阵最大元素值：max=%d\n最大元素行和列号：row=%d，col=%d",z[c][d],c,d);
	return 0;
}
/*
请输入矩阵行和列：请输入矩阵元素值：该矩阵最大元素值：max=10
最大元素行和列号：row=2，col=1
*/
