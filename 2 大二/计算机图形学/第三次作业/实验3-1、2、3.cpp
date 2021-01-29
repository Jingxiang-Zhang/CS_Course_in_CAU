/*********************************************************
		程序名称：图形变换
		功能： 5种简单变换，动画效果，任意直线的对称变换
		编译环境：Visual C++ 6.0，EasyX_20190219(beta)
		作 者：张靖祥<2017304010413><1967527237@qq.com>
		最后修改：2019-4-4
*********************************************************/

#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <iostream>      
#include <vector>  
#include <math.h>
#include<ctime>

clock_t start,end;

using namespace std; 
void init(){
	setfillcolor(WHITE);
	setlinecolor(RED);
	setbkmode(BLACK);
	setbkcolor(BLACK);
	settextcolor(BLACK);
	fillrectangle(-10,50,1000,550);
	fillrectangle(-10,-10,1000,45);
	LOGFONT f;
	gettextstyle(&f); 
	f.lfHeight = 15;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY; 
	settextstyle(&f); 

	BeginBatchDraw();
	FlushBatchDraw();
}
void definelimit(double *x,double *y){
	int i;
	double left=1000;
	double right=0;
	double top=1000;
	double bottom=0;
	for(i=0;i<6;i++){
		if(x[i]<left) left=x[i];
		if(x[i]>right) right=x[i];
		if(y[i]<top) top=y[i];
		if(y[i]>bottom) bottom=y[i];
	}
	left-=20;
	right+=20;
	top-=20;
	bottom+=20;
	x[7]=left;
	x[8]=right;
	y[7]=top;
	y[8]=bottom;
}
void mamultiply(double ma1[3][3],double ma2[3][3],double ma3[3][3]){
	int i,j,k;
	for(i=0;i<3;i++)
		for(j=0;j<0;j++){
			double temp=0;
			for(k=0;k<0;k++)
				temp+=ma1[i][k]*ma2[k][j];
			ma3[i][j]=temp;
		}
}

struct linee{
	int x0;
	int y0;
	int x1;
	int y1;
	COLORREF color;
};


void setline(double *x,double *y,COLORREF *col){
	double offsetx,offsety;
	int i;
	offsetx=200;  //图像的偏移量
	offsety=200;
	setcolor(MAGENTA);
	int n=6;
	double t=3.14159*2/n;
	double r=100;
	for(i=0;i<n;i++){ 
		x[i]= (r*cos(i*t)+offsetx);
		y[i]= (r*sin(i*t)+offsety); 
	}
	x[6]=offsetx;
	y[6]=offsety;
	definelimit(x,y);
	//其中0到5表示6个顶点，6表示中点，7到8表示图形的上下左右
	COLORREF tecol[6]={0xd024ff,0x9924ff,0x4824ff,0x24b1ff,0x24ffef,0x24ff86};
	for(i=0;i<6;i++){
		col[i]=tecol[i];
	}
}
void repaint(double *x,double *y,COLORREF *col){
	setfillcolor(BLACK);
	fillrectangle(-10,-10,1000,550);
	setfillcolor(WHITE);
	setlinecolor(RED);
	setbkmode(BLACK);
	setbkcolor(BLACK);
	settextcolor(BLACK);
	fillrectangle(-10,50,1000,550);
	fillrectangle(-10,-10,1000,45);

	setfillcolor(WHITE);
	int i;
	for(i=0;i<5;i++){
		setfillcolor(col[i]);
		setcolor(col[i]);
		POINT pts[] = { {int(x[i]), int(y[i])}, {int(x[i+1]), int(y[i+1])}, {int(x[6]), int(y[6])} };
		fillpolygon(pts, 3);
	}
	setfillcolor(col[5]);
	setcolor(col[5]);
	POINT pts[] = { {x[0], y[0]}, {x[5], y[5]}, {x[6], y[6]} };
	fillpolygon(pts, 3);
	settextcolor(BLACK);
	outtextxy(100,10, _T("选中状态： 平移:拖动  放缩:滚轮  错切:右键拖动  旋转:滚轮+shift" ));
	outtextxy(100,30, _T("非选中状态： 左键为画直线，表示对称轴，选中图形后双击即可对称" ));
}

void move(double offsetx,double offsety,double *x,double *y){
	int i;
//	if(y[7]+offsety<50 &&offsety<0) offsety=0;
	for(i=0;i<9;i++){
		x[i]+=offsetx;
		y[i]+=offsety;
	}

}
void zoom(int size,double *x,double *y){
	int i;
	double s=(size>0)?0.1:-0.1;
	double ma00=1+s;
	double ma20=x[6]*s;
	double ma21=y[6]*s;
	if((y[8]-y[7])*ma00>=500 ||(y[8]-y[7])*ma00<=100 ) 
		return;
	for(i=0;i<6;i++){
		if(i==6)	
			continue;
		x[i]=x[i]*ma00-ma20;
		y[i]=y[i]*ma00-ma21;
	}
	definelimit(x,y);
 
}
void rotate(int size,double *x,double *y){
	int i;
	static double ang=0.001;
	if(ang<0.1){
		ang+=0.001;
	}
	double angle=(size>0)?ang:-ang;
	double cox=cos(angle);
	double six=sin(angle);
	double ma20=-x[6]*cox+y[6]*six+x[6];
	double ma21=-x[6]*six-y[6]*cox+y[6];
	for(i=0;i<6;i++){
		double temp=x[i]*cox-y[i]*six+ma20;
		y[i]=x[i]*six+y[i]*cox+ma21;
		x[i]=temp;
	}
	definelimit(x,y);
}
void shear_warp(double offsetx,double offsety,double *x,double *y){
	bool dirx=true;
	int i;
	if(abs(offsety)>abs(offsetx))
		dirx=false;
	if(dirx){
		double m=offsetx/(x[8]-x[7]);
		double ma21=m*y[6];
		for(i=0;i<6;i++)
			x[i]=x[i]+y[i]*m-ma21;
	}
	else{
		double m=offsety/(y[8]-y[7]);
		double ma21=m*x[6];
		for(i=0;i<6;i++)
				y[i]=y[i]+x[i]*m-ma21;
		
	}
	definelimit(x,y);

}
void symmetry(linee cutline,double *x,double *y){
	double a=cutline.y1-cutline.y0;
	double b=cutline.x0-cutline.x1;
	double c=cutline.x1*cutline.y0-cutline.x0*cutline.y1;
	double ma[3][3];
	double beita=atan(b/a);
	beita=3.1415926-beita;
 
//	double beita=45/180*3.1415926;
/*	
	a=1;
	b=1;
	c=-300;
	beita=135*3.1416/180;
	*/

	ma[0][0]=-pow(cos(beita),2)+pow(sin(beita),2);
	ma[1][1]=-ma[0][0];
	ma[0][1]=ma[1][0]=2*sin(beita)*cos(beita);
	ma[0][2]=ma[2][0]=0;
	ma[2][2]=1;
	ma[2][0]=c/b*ma[0][1];
	ma[2][1]=c/b*(ma[1][1]-1);
	int i;
	for(i=0;i<7;i++){
		double temp=x[i]*ma[0][0]+y[i]*ma[1][0]+ma[2][0];
		y[i]=x[i]*ma[0][1]+y[i]*ma[1][1]+ma[2][1];
		x[i]=temp;
	}
	
	definelimit(x,y);
}
void TwoDimensionTransform(){
	double x[100],y[100];
	COLORREF col[10];
	setline(x,y,col);
	repaint(x,y,col);
	setcolor(BLACK);

	int inx,iny;
	int lastx,lasty;
	FlushBatchDraw();
	bool buttondown=false;
	bool rbuttondown=false;
	bool hasline=false;
	linee cutline;
	start=clock();
	bool flag=false;
	while(true){
		if(flag) break;
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){	

			case WM_LBUTTONDBLCLK:
				if(hasline==true && buttondown){
					hasline=false;
					symmetry(cutline,x,y);
					repaint(x,y,col);
					setcolor(BLUE);
					line(cutline.x0,cutline.y0,cutline.x1,cutline.y1);
				}
				FlushBatchDraw();
				break;
			case WM_LBUTTONDOWN:
				inx=m.x;
				iny=m.y;
				if(m.x>x[7] && m.x<x[8] && m.y>y[7] && m.y<y[8]){
					setcolor(BLUE);
					rectangle(x[7],y[7],x[8],y[8]);
					buttondown=true;
					
					lastx=m.x;
					lasty=m.y;
				}
				else{
					setcolor(0xffffff);
					rectangle(x[7],y[7],x[8],y[8]);
					buttondown=false;
				}
				FlushBatchDraw();
				break;
			case WM_MOUSEMOVE:
				if(m.mkRButton && rbuttondown){
					lastx=m.x;
					lasty=m.y;
					if(abs(lastx-inx)<=2 && abs(lasty-iny)<=2 ) break;
						shear_warp(lastx-inx,lasty-iny,x,y);
					repaint(x,y,col);
					setcolor(BLUE);
					rectangle(x[7],y[7],x[8],y[8]);
					inx=lastx;
					iny=lasty ;
				}
				if(WM_LBUTTONDOWN && m.mkLButton &&!buttondown){
					lastx=m.x;
					lasty=m.y;
					if(abs(lastx-inx)<=10 && abs(lasty-iny)<=10) break;
					setlinecolor(BLUE);
					repaint(x,y,col);
					setcolor(BLUE);
					hasline=true;
					line(inx,iny,lastx,lasty);
					cutline.x0=inx;
					cutline.y0=iny;
					cutline.x1=lastx;
					cutline.y1=lasty;
				}
				if(WM_LBUTTONDOWN && m.mkLButton && buttondown){
					lastx=m.x;
					lasty=m.y;
					if(abs(lastx-inx)<=2 && abs(lasty-iny)<=2 ) break;
					move(lastx-inx,lasty-iny,x,y);
					repaint(x,y,col);
					setcolor(BLUE);
					rectangle(x[7],y[7],x[8],y[8]);
					inx=lastx;
					iny=lasty ;
					hasline=false;
				}
				FlushBatchDraw();
				break;
			case WM_MOUSEWHEEL:
				if(buttondown && m.mkShift){
					rotate(m.wheel/60,x,y);
					repaint(x,y,col);
					setcolor(BLUE);
					rectangle(x[7],y[7],x[8],y[8]);
				}
				else if(buttondown){
					zoom(m.wheel/60,x,y);
					repaint(x,y,col);
					setcolor(BLUE);
					rectangle(x[7],y[7],x[8],y[8]);
				}
				FlushBatchDraw();
				break;
			case WM_RBUTTONDOWN:
				rbuttondown=true;
				inx=m.x;
				iny=m.y;
				break;
			case WM_RBUTTONUP:
				rbuttondown=false;
				break;
			
		}
	}

}
int main(){
	initgraph(1000, 550); 
	init(); 
	FlushBatchDraw();

	TwoDimensionTransform();
	
	_getch();   
	EndBatchDraw();
    closegraph();          // 关闭绘图窗口
	return 0;
}
