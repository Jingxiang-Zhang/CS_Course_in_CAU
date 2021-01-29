/*********************************************************
		程序名称：绘制金刚石图案
		功 能：一笔绘制第一题图形
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
	

	//第一道题开始
    setcolor(YELLOW);
	offsetx=80;  //图像的偏移量
	offsety=180;

	moveto(offsetx-60,offsety-150);
	outtext("第一道题");
	moveto(offsetx,offsety);
	setcolor(WHITE);
	for(i=offsetx;i<=offsetx+320;i=i+20){
		lineto(i,offsety-120);
		lineto(offsetx+320,offsety);
		lineto(i,offsety+120);
		lineto(offsetx,offsety);
		Sleep(50);
	}

    _getch();              // 按任意键继续
    closegraph();          // 关闭绘图窗口
 
	return 0;
}