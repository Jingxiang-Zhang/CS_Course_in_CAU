/*********************************************************
		程序名称：绘制金刚石图案
		功 能：绘制钻石
		编译环境：Visual C++ 6.0，EasyX_20190219(beta)
		作 者：张靖祥<2017304010413><1967527237@qq.com>
		最后修改：2019-2-28
*********************************************************/

#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
int main()
{
	int i,j;
    initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
	int offsetx,offsety;
	

	//第二道题开始
	
	offsetx=150;  //图像的偏移量
	offsety=150;
	moveto(offsetx-100,offsety-120);
	setcolor(YELLOW);
	outtext("第二道题");
	setcolor(MAGENTA);
	int n=20;
	double t=3.14159*2/n;
	double r=100;
	double x[50],y[50];
	for(i=0;i<n;i++){ 
		x[i]=r*cos(i*t)+offsetx;
		y[i]=r*sin(i*t)+offsety; 
	}
	for(i=0;i<=n-2;i++)
		for(j=i+1;j<=n-1;j++)
			line(x[i],y[i],x[j],y[j]);	


    _getch();              // 按任意键继续
    closegraph();          // 关闭绘图窗口
 
	return 0;
}