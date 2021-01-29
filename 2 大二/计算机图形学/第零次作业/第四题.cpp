/*********************************************************
		程序名称：绘制金刚石图案
		功 能：绘制第四题 
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
	

	//第四道题开始
	
	offsetx=100;  //图像的偏移量
	offsety=100;
	moveto(offsetx-50,offsety);
	setcolor(YELLOW);
	outtext("第四道题");
	setcolor(MAGENTA);

	int point1[]={100,0,128,0,48,80,150,80,170,100,0,100,100,0};
	int point2[]={0,100,20,120,220,120,128,28,113,43,170,100,0,100};
	int point3[]={76,80,128,28,220,120,228,100,128,0,48,80,76,80};
	for(i=0;i<7;i++){
		point1[i*2]+=offsetx;
		point2[i*2]+=offsetx;
		point3[i*2]+=offsetx;
		point1[i*2+1]+=offsety;
		point2[i*2+1]+=offsety;
		point3[i*2+1]+=offsety;
	}

	setcolor(RED);
	moveto(offsetx+100,offsety);
	for(i=0;i<7;i++){
		lineto(point1[i*2],point1[i*2+1]);
	}
	setfillcolor(RED);
	floodfill(offsetx+110, offsety+10, RED, 0);

	Sleep(400);
	setcolor(YELLOW);
	moveto(offsetx,offsety+100);
	for(i=0;i<7;i++){
		lineto(point2[i*2],point2[i*2+1]);
	}
	setfillcolor(YELLOW);
	floodfill(offsetx+20, offsety+110, YELLOW, 0);

	Sleep(400);
	setcolor(BLUE);
	moveto(offsetx+76,offsety+80);
	for(i=0;i<7;i++){
		lineto(point3[i*2],point3[i*2+1]);
	}
	setfillcolor(BLUE);
	floodfill(offsetx+70, offsety+79, BLUE, 0);
    _getch();              // 按任意键继续
    closegraph();          // 关闭绘图窗口
 
	return 0;
}
