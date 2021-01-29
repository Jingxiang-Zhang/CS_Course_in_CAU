/*********************************************************
		程序名称：绘制折线，椭圆，以及加粗折线和椭圆
		功 能：绘制折线，椭圆，以及加粗折线和椭圆
		编译环境：Visual C++ 6.0，EasyX_20190219(beta)
		作 者：张靖祥<2017304010413><1967527237@qq.com>
		最后修改：2019-3-10
*********************************************************/


#include <graphics.h>    
#include <iostream>  
#include <conio.h>
#include <math.h>
using namespace std;
bool bold;
inline void draw_point(int x,int y,COLORREF col){
	if(y>100){
		putpixel(x,y,col);
	}
}

void draw_line(int x1,int y1,int x2,int y2,COLORREF col){

	//不加粗
if(bold==false){


	if(x2-x1<0){
		int temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
	}
	int a=y2-y1;
	int b=x2-x1;
	double k;
	if(b!=0){
		k=double(a)/double(b);
	}
	int x=x1;
	int y=y1;
	if(x1==x2){
		if(y1>y2) {
			int temp=y1;
			y1=y2;
			y2=temp;
		}
		y=y1;
		putpixel(x,y,col);
		while(y<y2){
			y++;
			putpixel(x,y,col);
		}

	}
	else if(k>=0 && k<=1){
		a=-a;
		int d=2*a+b;
		int EA=2*a;
		int EE=2*a+2*b;
		putpixel(x,y,col);
		while(x<x2){
			if(d>0){
				d=d+EA;
			}
			else{
				d=d+EE;
				y++;
			}
			x++;
			putpixel(x,y,col);
		}
	}
	else if(k>1){
		b=-b;
		int d=a+2*b;
		putpixel(x,y,col);
		int EB=2*b;
		int EE=2*a+2*b;
		while(y<y2){
			if(d>0){
				d=d+EB;
			}
			else{
				d=d+EE;
				x++;
			}
			y++;
			putpixel(x,y,col);
		}	
	}
	else if(k<0 && k>=-1){
		int d=2*a+b;
		putpixel(x,y,col);
		int EA=2*a;
		int EE=2*a+2*b;
		while(x<x2){
			if(d>0){
				d=d+EA;
			}
			else{
				d=d+EE;
				y--;
			}
			x++;
			putpixel(x,y,col);
		}
	}
	else if(k<-1){
		int d=a+2*b;
		a=-a;
		b=-b;
		putpixel(x,y,col);
		y=y2;
		x=x2;
		int EB=2*b;
		int EE=2*a+2*b;
		while(y<y1){
			if(d>0){
				d=d+EB;
			}
			else{
				d=d+EE;
				x--;
			}
			y++;
			putpixel(x,y,col);
		}	
	}
}
//加粗

else{

	if(x2-x1<0){
		int temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
	}
	int a=y2-y1;
	int b=x2-x1;
	double k;
	if(b!=0){
		k=double(a)/double(b);
	}
	int x=x1;
	int y=y1;
	if(x1==x2){
		if(y1>y2) {
			int temp=y1;
			y1=y2;
			y2=temp;
		}
		y=y1-1;
		putpixel(x,y,col);
		putpixel(x-1,y,col);
		putpixel(x-2,y,col);
		putpixel(x+1,y,col);
		putpixel(x+2,y,col);

		while(y<y2+1){
			y++;
			putpixel(x,y,col);
			putpixel(x-1,y,col);
			putpixel(x-2,y,col);
			putpixel(x+1,y,col);
			putpixel(x+2,y,col);
		}

	}
	else if(k>=0 && k<=1){
		a=-a;
		int d=2*a+b;
		int EA=2*a;
		int EE=2*a+2*b;
			putpixel(x,y,col);
			putpixel(x,y+1,col);
			putpixel(x,y+2,col);
			putpixel(x,y-1,col);
			putpixel(x,y-2,col);
		x=x-1;
		while(x<x2+1){
			if(d>0){
				d=d+EA;
			}
			else{
				d=d+EE;
				y++;
			}
			x++;
			putpixel(x,y,col);
			putpixel(x,y+1,col);
			putpixel(x,y+2,col);
			putpixel(x,y-1,col);
			putpixel(x,y-2,col);
		}
	}
	else if(k>1){
		b=-b;
		int d=a+2*b;
		putpixel(x,y,col);
		putpixel(x-1,y,col);
		putpixel(x-2,y,col);
		putpixel(x+1,y,col);
		putpixel(x+2,y,col);
		int EB=2*b;
		int EE=2*a+2*b;
		y=y-1;
		while(y<y2+1){
			if(d>0){
				d=d+EB;
			}
			else{
				d=d+EE;
				x++;
			}
			y++;
			putpixel(x,y,col);
			putpixel(x-1,y,col);
			putpixel(x-2,y,col);
			putpixel(x+1,y,col);
			putpixel(x+2,y,col);
		}	
	}
	else if(k<0 && k>=-1){
		int d=2*a+b;
		putpixel(x,y,col);
		putpixel(x,y+1,col);
		putpixel(x,y+2,col);
		putpixel(x,y-1,col);
		putpixel(x,y-2,col);
		int EA=2*a;
		int EE=2*a+2*b;
		x=x-1;
		while(x<x2+1){
			if(d>0){
				d=d+EA;
			}
			else{
				d=d+EE;
				y--;
			}
			x++;
			putpixel(x,y,col);
			putpixel(x,y+1,col);
			putpixel(x,y+2,col);
			putpixel(x,y-1,col);
			putpixel(x,y-2,col);
		}
	}
	else if(k<-1){
		int d=a+2*b;
		a=-a;
		b=-b;
		putpixel(x,y,col);
		putpixel(x-1,y,col);
		putpixel(x-2,y,col);
		putpixel(x+1,y,col);
		putpixel(x+2,y,col);
		y=y2-1;
		x=x2;
		int EB=2*b;
		int EE=2*a+2*b;
		while(y<y1+1){
			if(d>0){
				d=d+EB;
			}
			else{
				d=d+EE;
				x--;
			}
			y++;
			putpixel(x,y,col);
			putpixel(x-1,y,col);
			putpixel(x-2,y,col);
			putpixel(x+1,y,col);
			putpixel(x+2,y,col);
		}	
	}





}
}
inline void EllipsePoints(int rx,int ry,int x,int y,COLORREF color,bool vertical){
	if(bold==false){
		draw_point(rx+x,ry+y,color);
		draw_point(rx-x,ry+y,color);
		draw_point(rx-x,ry-y,color);
		draw_point(rx+x,ry-y,color);
	}
	else if(vertical==false){
		draw_point(rx+x,ry+y,color);
		draw_point(rx+x,ry+y-1,color);
		draw_point(rx+x,ry+y+1,color);

		draw_point(rx-x,ry+y,color);
		draw_point(rx-x,ry+y-1,color);
		draw_point(rx-x,ry+y+1,color);

		draw_point(rx-x,ry-y,color);
		draw_point(rx-x,ry-y-1,color);
		draw_point(rx-x,ry-y+1,color);

		draw_point(rx+x,ry-y,color);
		draw_point(rx+x,ry-y-1,color);
		draw_point(rx+x,ry-y+1,color);
	}
	else{
		draw_point(rx+x,ry+y,color);
		draw_point(rx+x-1,ry+y,color);
		draw_point(rx+x+1,ry+y,color);

		draw_point(rx-x,ry+y,color);
		draw_point(rx-x-1,ry+y,color);
		draw_point(rx-x+1,ry+y,color);

		draw_point(rx-x,ry-y,color);
		draw_point(rx-x-1,ry-y,color);
		draw_point(rx-x+1,ry-y,color);

		draw_point(rx+x,ry-y,color);
		draw_point(rx+x-1,ry-y,color);
		draw_point(rx+x+1,ry-y,color);
	}

	
}
void draw_oval(int rx,int ry,int a,int b,COLORREF color){
	a=a>0?a:-a;
	b=b>0?b:-b;
	if(a<=1){
		draw_line(rx,ry-b,rx,ry+b,color);
		return ;
	}
	if(b<=1){
		draw_line(rx-a,ry,rx+a,ry,color);
		return ;
	}
	int x,y,d;
	int xP,yP;
	int squarea,squareb;
	squarea=a*a;
	squareb=b*b;
	xP=(int)(0.5+(float)squarea/sqrt((float)(squarea+squareb)));
	yP=(int)(0.5+(float)squareb/sqrt((float)(squarea+squareb)));
	x=0;
	y=b;
	d=4*(squareb-squarea*b)+squarea;
	EllipsePoints(rx,ry,x,y,color,false);
	int squareaa=4*squarea;
	int squarebb=4*squareb;
	int squareaaa=8*squarea;
	int squarebbb=8*squareb;
	while(x<=xP){
		if(d<=0)
			d+=squarebb*(2*x+3);
		else{
			d+=squarebb*(2*x+3)-squareaaa*(y-1);
			y--;
		}
		x++;
		EllipsePoints(rx,ry,x,y,color,false);
	}
	x=a;
	y=0;
	d=4*(squarea-squareb*a)+squareb;
	EllipsePoints(rx,ry,x,y,color,true);
	while(y<=yP){
		if(d<=0)
			d+=squareaa*(2*y+3);
		else{
			d+=squareaa*(2*y+3)-squarebbb*(x-1);
			x--;
		}
		y++;
		EllipsePoints(rx,ry,x,y,color,true);
	}

}
void CirclePoints(int rx,int ry,int x,int y,COLORREF color){
	if(bold==false){
		draw_point(rx+x,ry+y,color);
		draw_point(rx-x,ry+y,color);
		draw_point(rx+x,ry-y,color);
		draw_point(rx-x,ry-y,color);
		draw_point(rx+y,ry+x,color);
		draw_point(rx-y,ry+x,color);
		draw_point(rx+y,ry-x,color);
		draw_point(rx-y,ry-x,color);
	}
	else{
		draw_point(rx+x,ry+y,color);
		draw_point(rx+x,ry+y-1,color);
		draw_point(rx+x,ry+y+1,color);

		draw_point(rx-x,ry+y,color);
		draw_point(rx-x,ry+y-1,color);
		draw_point(rx-x,ry+y+1,color);

		draw_point(rx+x,ry-y,color);
		draw_point(rx+x,ry-y-1,color);
		draw_point(rx+x,ry-y+1,color);

		draw_point(rx-x,ry-y,color);
		draw_point(rx-x,ry-y-1,color);
		draw_point(rx-x,ry-y+1,color);

		draw_point(rx+y,ry+x,color);
		draw_point(rx+y-1,ry+x,color);
		draw_point(rx+y+1,ry+x,color);

		draw_point(rx-y,ry+x,color);
		draw_point(rx-y-1,ry+x,color);
		draw_point(rx-y+1,ry+x,color);

		draw_point(rx+y,ry-x,color);
		draw_point(rx+y-1,ry-x,color);
		draw_point(rx+y+1,ry-x,color);

		draw_point(rx-y,ry-x,color);
		draw_point(rx-y-1,ry-x,color);
		draw_point(rx-y+1,ry-x,color);
	}
	
}
void draw_circle(int rx,int ry,int radius,COLORREF color){
	int x,y,d;
	x=0;
	y=radius;
	d=5-4*radius;
	int deltaE=12;
	int deltaSE=20-8*radius;
	CirclePoints(rx,ry,x,y,color);
	while(y>x){
		if(d<=0){
			d+=deltaE;
			deltaSE+=8;
		}
		else{
			d+=deltaSE;
			deltaSE+=16;
			y--;
		}
		deltaE+=8;
		x++;
		CirclePoints(rx,ry,x,y,color);
	}

}

void init(){
	setfillcolor(WHITE);
	fillrectangle(0,0,800,100);
	bold=false;
	setlinecolor(BLACK);
	rectangle(50,20,120,70);
	rectangle(250,20,320,70);
	rectangle(450,20,520,70);
	rectangle(650,20,720,70);

	setbkmode(WHITE);
	settextcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 12; 
	settextstyle(&f);
	outtextxy(0,0, _T("按下shift可将椭圆转化为圆，单击屏幕为开始画线，双击屏幕为完成画线"));
	f.lfHeight = 25;                      // 设置字体高度为 25
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	outtextxy(60,30, _T("折线"));
	outtextxy(260,30, _T("椭圆"));
	outtextxy(460,30, _T("退出"));
	outtextxy(660,30, _T("加粗"));
}

int deal_mouth_affair(int x,int y,int incident){
	if(x>=450 && x<=520 && y>=20 && y<=70)
		exit(0);
	if(x>=250 && x<=330 && y>=20 && y<=70)
		return 2;
	if(x>=50 && x<=120 && y>=20 && y<=70)
		return 1;
	if(x>=650 && x<=720 && y>=20 && y<=70){
		if(bold==false){
			setfillcolor(RED);
			bold=true;
		}
		else{
			setfillcolor(WHITE);
			bold=false;
		}
		fillrectangle(651,21,719,69);
		outtextxy(660,30, _T("加粗"));
		FlushBatchDraw();
	}
	return incident;
}

int main()
{
	initgraph(800, 700); 
	BeginBatchDraw();
	init();
	FlushBatchDraw();
	int pointx,pointy;
	int pointxx,pointyy;
	int incident=1;
	bool flag=false,timefirst=true;
	int radius;
	bool lasttimeshift=false;
	while(true){
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){
			case WM_LBUTTONDOWN:
				incident=deal_mouth_affair(m.x,m.y,incident);
				if(m.y<=100) break;
				pointx=m.x;
				pointy=m.y;
				if(timefirst==true && incident!=2){
					pointxx=m.x;
					pointyy=m.y;
					timefirst=false;
					radius=0;
				}
				flag=true;
				break;
			case WM_MOUSEMOVE:	
				if(m.y<=100) break;
				if(flag==true && incident==1){
					draw_line(pointx,pointy,pointxx,pointyy,BLACK);
					pointxx=m.x;
					pointyy=m.y;
					draw_line(pointx,pointy,pointxx,pointyy,WHITE);
				}
				if(flag==true && incident==2 && m.mkShift==false){
					if(lasttimeshift==true)
						draw_circle(pointx,pointy,radius,BLACK);
					draw_oval(pointx,pointy,pointxx-pointx,pointyy-pointy,BLACK);
					pointxx=m.x;
					pointyy=m.y;
					draw_oval(pointx,pointy,pointxx-pointx,pointyy-pointy,WHITE);
					lasttimeshift=false;
				}
				if(flag==true && incident==2 && m.mkShift==true){
					if(lasttimeshift==false)
						draw_oval(pointx,pointy,pointxx-pointx,pointyy-pointy,BLACK);
					draw_circle(pointx,pointy,radius,BLACK);
					int aa=pointxx-pointx;
					int bb=pointyy-pointy;
					aa=aa>0?aa:-aa;
					bb=bb>0?bb:-bb;
					radius=aa>bb?aa:bb;
					pointxx=m.x;
					pointyy=m.y;
					draw_circle(pointx,pointy,radius,WHITE);
					lasttimeshift=true;
				}

	
				FlushBatchDraw();
				break;
			case WM_LBUTTONDBLCLK:
				if(m.y<=100) break;
				timefirst=true;
				flag=false;
				break;
		}
	}
	EndBatchDraw();
    _getch();              
    closegraph();   
	return 0;
}