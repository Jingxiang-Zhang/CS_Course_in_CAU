/*********************************************************
		程序名称：直线裁剪，金刚石图案裁剪 
		功能：两种算法的直线裁剪和金刚石图案的裁剪 
		编译环境：Visual C++ 6.0，EasyX_20190219(beta)
		作 者：张靖祥<2017304010413><1967527237@qq.com>
		最后修改：2019-3-23
*********************************************************/




#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <iostream>      
#include <vector>  
#include <math.h>
//默认的多边形点数为9，取消下面一行注释，可以调整多边形点数
//点数应大于等于5小于等于13，且必须为奇数，否则重新定义无效

//#define POLYGON 5

using namespace std; 
void init(){
	
	 
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	setbkmode(BLACK);
	setbkcolor(BLACK);
	settextcolor(BLACK);
	fillrectangle(0,0,1000,500);
	fillrectangle(0,505,1000,550);
	line(500,0,500,500);
	LOGFONT f;
	gettextstyle(&f); 
	f.lfHeight = 15;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY; 
	settextstyle(&f); 
	outtextxy(60,30, _T("请在左面出一个矩形，表示裁剪区"));

	BeginBatchDraw();
	FlushBatchDraw();
}
struct rect{
	int left;
	int top;
	int right;
	int bottom;
};
void drawframe(rect *clipframe){
	int inx,iny;
	int lastx,lasty;

	bool has_down=false;
	bool finish=false;
	FlushBatchDraw();
	while(true){	
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){
			case WM_LBUTTONDOWN:
				if(m.x<500){
				//	if()
					rectangle(0,0,500,500 );
					inx=m.x;
					iny=m.y;
					lastx=m.x;
					lasty=m.y;
					has_down=true;
				}
				break;
			case WM_MOUSEMOVE:
				if(m.mkLButton && has_down ){
					int left=min(lastx,inx);
					int right=max(lastx,inx);
					int top=min(lasty,iny);
					int bottom=max(lasty,iny);
					if(right>=500)right=499;
					if(bottom>=500)bottom=499;
					fillrectangle(0,0,1000,500);
					outtextxy(60,30, _T("请在左面出一个矩形，表示裁剪区"));
					line(500,0,500,500);
					lastx=m.x;
					lasty=m.y;
					rectangle(left,top,right,bottom);
					rectangle(left+500,top,right+500,bottom);
					FlushBatchDraw();
				}
				break;
			case WM_LBUTTONUP:
				finish=true;
				break;

		}
		if(finish)
			break; 
	}
	
	int left=min(lastx,inx);
	int right=max(lastx,inx);
	int top=min(lasty,iny);
	int bottom=max(lasty,iny);
	if(right>=500)right=499;
	if(bottom>=500)bottom=499;
	fillrectangle(0,0,1000,500);
	line(500,0,500,500);
	rectangle(left,top,right,bottom);
	rectangle(left+500,top,right+500,bottom);
	FlushBatchDraw();
	clipframe->left=left;
	clipframe->right=right;
	clipframe->top=top;
	clipframe->bottom=bottom;
}
bool ClipT(double q,double d,double *t0,double *t1){
	double r;
	r=d/q;
	if(q<0){
		if(r>*t1) return false;
		else{
			if(r>*t0)	*t0=r;
			return true;
		}
	}
	else if(q>0){
		if(r<*t0)	return false;
		else{
			if(r<*t1)	*t1=r;
			return true;
		}
	}
	else if(d<0) return false;
	return true;
}

struct linee{
	int x0;
	int y0;
	int x1;
	int y1;
	COLORREF color;
};
linee Liang_Barsky (int x0,int y0,int x1,int y1,rect clipframe,COLORREF color){
	double delatx,delaty,t0,t1;
	t0=0;
	t1=1;
	delatx=double(x1-x0);
	int nx1=0,nx0=0,ny0=0,ny1=0;
	if(ClipT(-delatx,double(x0-clipframe.left),&t0,&t1)){	
		if(ClipT(delatx,double(clipframe.right-x0),&t0,&t1)){
			delaty=double(y1-y0);	
			if(ClipT(-delaty,double(y0-clipframe.top),&t0,&t1)){		
				if(ClipT(delaty,double(clipframe.bottom-y0),&t0,&t1)){
					nx0=(int)(x0+t0*delatx);
					ny0=(int)(y0+t0*delaty);
					nx1=(int)(x0+t1*delatx);
					ny1=(int)(y0+t1*delaty);
/**/				setlinecolor(color);
					line(nx0,ny0,nx1,ny1);
				}
			}
		}
	}
	linee neli;
	neli.x0=nx0;
	neli.x1=nx1;
	neli.y0=ny0;
	neli.y1=ny1;
	neli.color=color;
	return neli;
}

int encode(double x, double y, int *code,rect clipframe)
{ 
	int c;
	c=0;
	if (x<clipframe.left) c=c|1;
	else if (x>clipframe.right) c=c|2;
	if (y<clipframe.top) c=c|4;
	else if (y>clipframe.bottom) c=c|8;
	/***********************************************/
	*code=c; 
	return 0;
}


linee Cohen_Sutherland(int xx1,int yy1,int xx2,int yy2,rect clipframe,COLORREF color){
	int code1,code2,code;
	double x1=xx1;
	double y1=yy1;
	double x2=xx2;
	double y2=yy2;
	double XL=clipframe.left;
	double XR=clipframe.right;
	double YB=clipframe.top;
	double YT=clipframe.bottom ;
	double x,y;
	int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
	encode(x1,y1,&code1,clipframe);
	encode(x2,y2,&code2,clipframe);
	linee templine;
	while (code1!=0 || code2!= 0){
		if ((code1 & code2) != 0) {
			templine.x0=0;
			templine.x1=0;
			templine.y0=0;
			templine.y1=0;
			return templine;
		}
			
		code=code1;
		if (code1==0) code=code2;
		if ((LEFT & code) != 0){
			x=XL;
			y=y1+(y2-y1)*(XL-x1)/(x2-x1);
		}
		else if ((RIGHT & code) != 0){
			x=XR;
			y=y1+(y2 -y1)*(XR-x1)/(x2-x1); }
		else if ((BOTTOM & code) != 0){
			y=YB;
			x=x1+(x2-x1)*(YB-y1)/(y2-y1);}
		else if ((TOP & code) != 0){
			y=YT;
			x=x1+(x2-x1)*(YT-y1)/(y2-y1); }
		if (code==code1){
			x1=x; 
			y1=y; 
			encode(x,y, &code1,clipframe); 
		}
		else{
			x2=x; 
			y2=y; 
			encode(x,y, &code2,clipframe); 
		} 
	}
	setlinecolor(color);
	line(x1,y1,x2,y2); 
	templine.x0=x1;
	templine.y0=y1;
	templine.x1=x2;
	templine.y1=y2;
	templine.color=color;
	return templine;
}
void repaint(vector<linee> record,rect clipframe){
	fillrectangle(0,0,1000,500);
	line(500,0,500,500);
	rectangle(clipframe.left,clipframe.top,clipframe.right,clipframe.bottom);
	rectangle(clipframe.left+500,clipframe.top,clipframe.right+500,clipframe.bottom);
	
	vector<linee>::iterator it;
	for(it=record.begin();it!=record.end();it++){
		setlinecolor(it->color);
		line(it->x0,it->y0,it->x1,it->y1);

	}
	setlinecolor(BLACK);
}
void reverse(vector<linee> *record,rect clipframe){
	if(record->empty()) return ;
	vector<linee>::iterator it,at;
	it=record->begin();
	at=it;
	it++;
	while(it!=record->end()){
		at=it;
		it++;
	}
	record->erase(at);
	it=record->begin();
	at=it;
	it++;
	while(it!=record->end()){	
		at=it;
		it++;
	}
	record->erase(at);
	repaint(*record,clipframe);
}
linee clipway(int x0,int y0,int x1,int y1,rect clipframe,bool Liang){
	linee cr;
	if(Liang==true)
		cr=Liang_Barsky(x0,y0,x1,y1,clipframe,RED);
	else 
		cr=Cohen_Sutherland(x0,y0,x1,y1,clipframe,GREEN);
	setlinecolor(BLACK);
	return cr;

}
void change(bool *Liang){
	setlinecolor(WHITE);
	if(*Liang){
		*Liang=false;
		fillrectangle(0,530,1000,550);
		outtextxy(60,530, _T("当前选择为Cohen-Sutherland算法，双击左键可改变为Liang-Barsky算法"));
	}
	else{
		*Liang=true;
		fillrectangle(0,530,1000,550);
		outtextxy(60,530, _T("当前选择为Liang-Barsky算法，双击左键可改变为Cohen-Sutherland算法"));
	}
	setlinecolor(BLACK);
}

void startpolygonclip(vector<linee> *polyline){
	fillrectangle(0,0,1000,500);
	line(500,0,500,500);
	fillrectangle(0,505,1000,550);
	outtextxy(60,505, _T("提示：中键进入直线裁剪模式"));
	outtextxy(60,530, _T("当前选择为多边形裁剪"));
	linee li;

	int n=9,i,j;
#ifdef POLYGON
	if(POLYGON>=5 && POLYGON<=13 && POLYGON%2==1)
	n=POLYGON;
#endif
	int offsetx,offsety;
	offsetx=250;  //图像的偏移量
	offsety=250;
	double t=3.14159*2/n;
	double r=150;  //图像的尺寸
	double x[50],y[50];
	double orix,oriy;
	moveto(offsetx-100,offsety-120);
	setcolor(GREEN);
	t=3.14159*2/n;
	moveto(offsetx+r,offsety);
	orix=offsetx+r;
	oriy=offsety;
	for(i=0;i<n;i++){ 
		x[i]=r*cos(i*t)+offsetx;
		y[i]=r*sin(i*t)+offsety; 
	}	
	int num=0;
	for(i=0;i<n;i++){
		for(j=1;j<=(n-1)/2;j++){
			int tempx=x[num];
			int tempy=y[num];
			lineto(tempx,tempy);
			li.x0=orix;
			li.y0=oriy;
			li.x1=tempx;
			li.y1=tempy;
			polyline->push_back(li);
			orix=tempx;
			oriy=tempy;
			num=(num+j)%n;
		}
	}
	li.x0=orix;
	li.y0=oriy;
	li.x1=x[0];
	li.y1=y[0];
	polyline->push_back(li);
	lineto(x[0],y[0]);
	
}
void repaint2(vector<linee> polylin){
	
	fillrectangle(0,0,1000,500);
	line(500,0,500,500);
	setcolor(GREEN);
	vector<linee>::iterator it;
	for(it=polylin.begin();it!=polylin.end();it++){
		line(it->x0,it->y0,it->x1,it->y1);

	}

}
/***************************************/
void drawpoli(vector<linee> polylin,rect rectclip){
	vector<linee>::iterator it;
	linee li;
	for(it=polylin.begin();it!=polylin.end();it++){
		li=Liang_Barsky(it->x0,it->y0,it->x1,it->y1,rectclip,0xFFD700);
		setcolor(GREEN);
		line(li.x0+500,li.y0,li.x1+500,li.y1);
	}

}

void polygonclip(){
	vector<linee> polylin;
	startpolygonclip(&polylin);
	FlushBatchDraw();
	bool ret=false;
	bool down=false;
	int inx,iny;
	int lastx,lasty;
	rect rectclip;
	while(true){
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){	
			case WM_MBUTTONDOWN:
				ret=true;
				break;
			case WM_LBUTTONDOWN:
				if(m.x<500 && m.y<500){
					inx=m.x;
					iny=m.y;
					lastx=m.x;
					lasty=m.y; 
					down=true;
				}
				break;
			case WM_MOUSEMOVE:
				if(WM_LBUTTONDOWN && m.mkLButton){
					repaint2(polylin);
					lastx=m.x;
					lasty=m.y;
					int minx=min(lastx,inx);
					int miny=min(lasty,iny);
					int maxx=max(lastx,inx);
					int maxy=max(lasty,iny);
					if(maxx>500) maxx=499;
					if(maxy>500) maxy=499;

					setcolor(BLUE);
					setfillcolor(0xFFEFD5);

					fillrectangle(minx,miny,maxx,maxy);
					drawpoli(polylin,rectclip);
					setcolor(BLUE);
					rectangle(minx+500,miny,maxx+500,maxy);
					rectangle(minx,miny,maxx,maxy);
					rectclip.left=minx;
					rectclip.right=maxx;
					rectclip.top=miny;
					rectclip.bottom=maxy;
					setfillcolor(WHITE);
					setcolor(BLACK);
					FlushBatchDraw();
				}
				break;
			case WM_LBUTTONUP:
			
				break;

		}
		if(ret) break;
	}

}
void drawline(rect clipframe){
	int inx,iny;
	int lastx,lasty;
	int down=false;
	rect newframe;
	newframe.bottom=clipframe.bottom;
	newframe.top=clipframe.top;
	newframe.left=clipframe.left+500;
	newframe.right=clipframe.right+500;
	vector<linee> record;
	linee trline;
	bool flag=false;
	bool Liang=true;
	outtextxy(60,510, _T("提示：右键为撤销,中键进入多边形裁剪模式"));
	outtextxy(60,530, _T("当前选择为Liang-Barsky算法，双击左键可改变为Cohen-Sutherland算法"));
	while(true){
		MOUSEMSG m = GetMouseMsg();
		if(flag) break;
		switch(m.uMsg){	
			case WM_LBUTTONDBLCLK:
				change(&Liang);
				break;
			case WM_LBUTTONDOWN:
				if(m.x<500 && m.y<500){
					inx=m.x;
					iny=m.y;
					lastx=m.x;
					lasty=m.y; 
			//		if(Liang)
					circle(inx,iny,2);
					down=true;
				}
				break;
			case WM_MOUSEMOVE:
				if(WM_LBUTTONDOWN && m.mkLButton){
					repaint(record,clipframe);
					lastx=m.x;
					lasty=m.y;
					if(lastx>=500) lastx=499;
					if(lasty>=500) lasty=499;
					circle(inx,iny,2);
					circle(inx+500,iny,2);
					trline=clipway(inx+500,iny,lastx+500,lasty,newframe,Liang);
					setlinecolor(trline.color);
					line(inx,iny,lastx,lasty);
					setlinecolor(BLACK);
					FlushBatchDraw();
				}
			break;
			case WM_LBUTTONUP:
				circle(lastx,lasty,2);
				circle(lastx+500,lasty,2);
				linee neli;
				neli.x0=inx;
				neli.y0=iny;
				neli.x1=lastx;
				neli.y1=lasty;
				neli.color=trline.color;
				record.push_back(neli);
				record.push_back(trline);
				FlushBatchDraw();
				down=false;
			break;
			case WM_RBUTTONDOWN:
				reverse(&record,clipframe);
				FlushBatchDraw();
				break;
			case WM_MBUTTONDOWN:
				polygonclip();
				init();
				repaint(record,clipframe);
				outtextxy(60,510, _T("提示：右键为撤销,中键进入多边形裁剪模式"));
				outtextxy(60,530, _T("当前选择为Liang-Barsky算法，双击左键可改变为Cohen-Sutherland算法"));
				FlushBatchDraw();

				break;
			

		}
	}
}
int main(){
	initgraph(1000, 550); 
	init();
	rect clipframe;
    drawframe(&clipframe); 
	FlushBatchDraw();
	drawline(clipframe);
	_getch();   
	EndBatchDraw();
    closegraph();          // 关闭绘图窗口
	while(true) getch();
	return 0;
}
