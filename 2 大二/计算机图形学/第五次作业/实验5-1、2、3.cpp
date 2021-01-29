/*********************************************************
		程序名称：绘制曲线
		功能： 3种曲线的绘制：抛物样条曲线，贝塞尔曲线，B样条曲线
		编译环境：Visual C++ 6.0，EasyX_20190219(beta)
		作 者：张靖祥<2017304010413><1967527237@qq.com>
		最后修改：2019-5-2
*********************************************************/

#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <iostream>      
#include <vector>  
#include <math.h>
#include<ctime>
using namespace std; 

struct button{
	int left;
	int top;
	int right;
	int bottom;
	char text[100];
	bool down;
	int number;
	button(int left1,int top1,int right1,int bottom1,char text1[]){
		left=left1;
		top=top1;
		right=right1;
		bottom=bottom1;
		down=false;
		for(int i=0;i<100;i++)
			text[i]=text1[i];
	}
};
struct dot{
	int x;
	int y;
	int down;
	dot(int x1,int y1){
		x=x1;
		y=y1;
		down=false;
	}
};
struct space_dot{
	int x;
	int y;
	int z;
};

struct Window{
	vector<button> button_;
	vector<dot> dot_;
	int button_down_number;
	int dot_down_number;
};

Window init(){
	Window window;
	LOGFONT f;
	gettextstyle(&f); 
	f.lfHeight = 15;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY; 
	settextstyle(&f); 

	button button1(10,10,130,40,"抛物样条曲线");
	button1.number=0;
	window.button_.push_back(button1);
	button button2(200,10,300,40,"Bezier曲线");
	button1.number=1;
	window.button_.push_back(button2);
	button button3(400,10,500,40,"B样条曲线");
	button1.number=2;
	window.button_.push_back(button3);
	button button4(600,10,660,40,"清除");
	button1.number=3;
	window.button_.push_back(button4);
	window.button_down_number=3;
	window.dot_down_number=-1;

	space_dot space_dot_;
	 

	BeginBatchDraw();
	FlushBatchDraw();
	return window;
}



void Affair(int x,int y,Window *window){
	//如果选到了按钮
	int i;
	int button_down_number=window->button_down_number;
	for(i=0;i<window->button_.size();i++){
		if(x<window->button_[i].right && x>window->button_[i].left &&
			y<window->button_[i].bottom && y>window->button_[i].top){
			window->button_down_number=i;
		}
	}
	//如果选择了清除
	if(window->button_down_number==3){
		window->dot_.clear();
		return ;
	}
	//如果选中了点
	bool change=false;
	for(i=0;i<window->dot_.size();i++){
		if(abs(window->dot_[i].x-x)<10 && abs(window->dot_[i].y-y)<10){
			window->dot_down_number=i;
			change=true;
			break;
		}
	}
	if(!change)
		window->dot_down_number=-1;
	else
		return;
	//如果点屏幕
	if(y>60){
		dot tempdot(x,y);
		window->dot_.push_back(tempdot);
	}
	return ;

}
void paint(button bu){
	if(bu.down){
		setfillcolor(GREEN);
		fillrectangle(bu.left,bu.top,bu.right,bu.bottom);
		setfillcolor(WHITE);
	}
	setlinecolor(BLACK);
	rectangle(bu.left,bu.top,bu.right,bu.bottom);
	outtextxy(bu.left+10,bu.top+5, _T(bu.text));
	
}
void Parabolic_splines(vector<dot> dot_){
	if(dot_.size()==0 || dot_.size()==1) return ;
	if(dot_.size()==2){
		line(dot_[0].x,dot_[0].y,dot_[1].x,dot_[1].y);
		return ;
	}
	int i;
	vector<dot> tempdot;
	tempdot.push_back(dot_[0]);
	for(i=0;i<dot_.size();i++){
		tempdot.push_back(dot_[i]);
	}
	tempdot.push_back(dot_[i-1]);
	dot_=tempdot;

	for(i=1;i<dot_.size()-2;i++){
		int x1=dot_[i-1].x,y1=dot_[i-1].y;
		int x2=dot_[i].x,y2=dot_[i].y;
		int x3=dot_[i+1].x,y3=dot_[i+1].y;
		int x4=dot_[i+2].x,y4=dot_[i+2].y;
		double t;
		for(t=0;t<0.5;t=t+0.02){
			double t2=t+0.02;
			double dotx0=(-t*t*t*4+4*t*t-t)*x1+(12*t*t*t-10*t*t+1)*x2+
				(-12*t*t*t+8*t*t+t)*x3+(4*t*t*t-2*t*t)*x4;
			double doty0=(-t*t*t*4+4*t*t-t)*y1+(12*t*t*t-10*t*t+1)*y2+
				(-12*t*t*t+8*t*t+t)*y3+(4*t*t*t-2*t*t)*y4;
			double dotx1=(-t2*t2*t2*4+4*t2*t2-t2)*x1+(12*t2*t2*t2-10*t2*t2+1)*x2+
				(-12*t2*t2*t2+8*t2*t2+t2)*x3+(4*t2*t2*t2-2*t2*t2)*x4;
			double doty1=(-t2*t2*t2*4+4*t2*t2-t2)*y1+(12*t2*t2*t2-10*t2*t2+1)*y2+
				(-12*t2*t2*t2+8*t2*t2+t2)*y3+(4*t2*t2*t2-2*t2*t2)*y4;
			line(dotx0,doty0,dotx1,doty1);
		}

	}
}
void Bezier_splines(vector<dot> dot_){
	if(dot_.size()==0 || dot_.size()==1) return ;
	if(dot_.size()==2){
		line(dot_[0].x,dot_[0].y,dot_[1].x,dot_[1].y);
		return ;
	}
	double t;
	moveto(dot_[0].x,dot_[0].y);
	for(t=0;t<=1.02;t+=0.02){
		int i;
		double x1=0,y1=0;
		double x2=0,y2=0;
		int n=dot_.size()-1;
		for(i=0;i<=n;i++){
			double B=1;
			int k;
			for(k=1;k<=n;k++)	B*=k;
			for(k=1;k<=i;k++)	B/=k;
			for(k=1;k<=n-i;k++)	B/=k;
			for(k=1;k<=i;k++)	B*=t;
			for(k=1;k<=n-i;k++)	B*=(1-t);
			x1=x1+dot_[i].x*B;
			y1=y1+dot_[i].y*B;
		}
		lineto(x1,y1);
	}

}
void B_splines(vector<dot> dot_){
	if(dot_.size()==0 || dot_.size()==1) return ;
	if(dot_.size()==2){
		line(dot_[0].x,dot_[0].y,dot_[1].x,dot_[1].y);
		return ;
	}
	int i;
	vector<dot> tempdot;
	tempdot.push_back(dot_[0]);
	for(i=0;i<dot_.size();i++){
		tempdot.push_back(dot_[i]);
	}
	tempdot.push_back(dot_[i-1]);
	dot_=tempdot;

	for(i=1;i<dot_.size()-2;i++){
		int x1=dot_[i-1].x,y1=dot_[i-1].y;
		int x2=dot_[i].x,y2=dot_[i].y;
		int x3=dot_[i+1].x,y3=dot_[i+1].y;
		int x4=dot_[i+2].x,y4=dot_[i+2].y;
		double t;
		for(t=0;t<1;t=t+0.02){
			double t2=t+0.02;
			double dotx0=(-t*t*t+3*t*t-3*t+1)*x1+(3*t*t*t-6*t*t+4)*x2+\
				(-3*t*t*t+3*t*t+3*t+1)*x3+t*t*t*x4;
			double doty0=(-t*t*t+3*t*t-3*t+1)*y1+(3*t*t*t-6*t*t+4)*y2+\
				(-3*t*t*t+3*t*t+3*t+1)*y3+t*t*t*y4;
			double dotx1=(-t2*t2*t2+3*t2*t2-3*t2+1)*x1+(3*t2*t2*t2-6*t2*t2+4)*x2+\
				(-3*t2*t2*t2+3*t2*t2+3*t2+1)*x3+t2*t2*t2*x4;
			double doty1=(-t2*t2*t2+3*t2*t2-3*t2+1)*y1+(3*t2*t2*t2-6*t2*t2+4)*y2+\
				(-3*t2*t2*t2+3*t2*t2+3*t2+1)*y3+t2*t2*t2*y4;
			line(dotx0/6,doty0/6,dotx1/6,doty1/6);
		}

	}
}
void repaint(Window window){
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

	//绘制按钮
	int i;
	for(i=0;i<window.button_.size();i++){
		int left=window.button_[i].left;
		int right=window.button_[i].right;
		int top=window.button_[i].top;
		int bottom=window.button_[i].bottom;
		bool down=window.button_[i].down;
		if(i==window.button_down_number){
			setfillcolor(GREEN);
			fillrectangle(left,top,right,bottom);
		}
		setlinecolor(BLACK);
		rectangle(left,top,right,bottom);
		outtextxy(left+10,top+10, _T(window.button_[i].text));
	}

	//绘制点
	for(i=0;i<window.dot_.size();i++){
		int x=window.dot_[i].x;
		int y=window.dot_[i].y;
		setfillcolor(BLACK);
		fillcircle(x,y,2);
	}
	if(window.dot_down_number!=-1){
		int x=window.dot_[window.dot_down_number].x;
		int y=window.dot_[window.dot_down_number].y;
		setfillcolor(RED);
		fillcircle(x,y,5);
	}

	//选择方法绘制曲线
	switch(window.button_down_number){
		case 0:
			Parabolic_splines(window.dot_);
			break;
		case 1:
			Bezier_splines(window.dot_);
			break;
		case 2:
			B_splines(window.dot_);
			break;
	}
	

}


void start(Window window){
	COLORREF col[10];
	setcolor(BLACK);
	int inx,iny;
	int lastx,lasty;
	int mode=1;
	repaint(window);
	FlushBatchDraw();
	bool down=false;
	bool flag=false;
	while(true){
		if(flag) break;
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){	
			case WM_LBUTTONDOWN:
				lastx=inx=m.x;
				lasty=iny=m.y;
				Affair(m.x,m.y,&window);
				repaint(window);
				FlushBatchDraw();
				down=true;
				break;
			case WM_MOUSEMOVE:
				if(window.dot_down_number!=-1 && down){
					inx=m.x;
					iny=m.y;
					window.dot_[window.dot_down_number].x+=inx-lastx;
					window.dot_[window.dot_down_number].y+=iny-lasty;
					lastx=m.x;
					lasty=m.y;
					repaint(window);
					FlushBatchDraw();
				}
				break;
	/*		case WM_LBUTTONDBLCLK:
				if(window.dot_down_number!=-1){
					vector<dot> dot_;
					int i;
					for(i=0;i<window.dot_down_number;i++)
						dot_.push_back(window.dot_[i]);
					for(i+=2;i<window.dot_.size();i++)
						dot_.push_back(window.dot_[i]);
					window.dot_=dot_;
				}
				
				break;*/
			case WM_LBUTTONUP:
				down=false;
				break;
			
		}
	}

}
int main(){
	initgraph(1000, 550); 
	Window window;
	window=init(); 
	start(window);
	_getch();   
	EndBatchDraw();
    closegraph();          // 关闭绘图窗口
	return 0;
}
