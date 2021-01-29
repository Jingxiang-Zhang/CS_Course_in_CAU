/***************************************
实验二 2-4
程序名称：多边形裁剪
功能：两种算法的直线裁剪和金刚石图案的裁剪 
编译环境：Visual C++ 6.0，EasyX_20190219(beta)
作 者：张靖祥<2017304010413><1967527237@qq.com>
最后修改：2019-3-30


			
				****已经处理退化边****
****************************************/



#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <iostream>      
#include <vector>  
#include <math.h>
#include <windows.h>
#include <set>
using namespace std; 
HWND hwnd;
void init(){
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	setbkmode(BLACK);
	setbkcolor(BLACK);
	settextcolor(BLACK);
	fillrectangle(0,0,1200,600);
	line(600,0,600,600);
	line(0,300,1200,300);
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
struct linee{
	int x0;
	int y0;
};
void initline(vector<linee> *li){
	int xx[]={110,160,90,90,70,50,165,175,163,110};
	int yy[]={84,94,169,94,90,189,189,89,54,84};
	int i;
	for(i=0;i<10;i++){
		linee ll;
		ll.x0=xx[i]*1.6+50;
		ll.y0=yy[i]*1.6-30;
		li->push_back(ll);
	}
}
vector<linee> cutleft(int left,int top,int right,int bottom,vector<linee> li){
	vector<linee> templi,lli;
	int maxright=0;
	int i,loc;
	for(i=0;i<li.size();i++)
		if(li[i].x0>maxright){
			maxright=li[i].x0;
			loc=i;
		}	
	lli.push_back(li[loc]);

	for(i=loc;i<li.size();i++)
		lli.push_back(li[i]);
	for(i=0;i<loc;i++)
		lli.push_back(li[i]);
	lli.push_back(li[i]);
	li.clear();
	for(i=0;i<lli.size();i++){
		li.push_back(lli[i]);
	}
	linee se;
	se.x0=li[0].x0;
	se.y0=li[0].y0;
	int beforex=1000,beforey;
	for(i=1;i<li.size();i++){
		if(beforex<left && li[i].x0<left){
			beforex=li[i].x0;
			beforey=li[i].y0;
		} 
		else if(beforex<left && li[i].x0>=left){
			se.y0=beforey-(li[i].y0-beforey)*(beforex-left)/(li[i].x0-beforex);
			se.x0=left;
			templi.push_back(se);
			beforex=1000;
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.x0>=left && li[i].x0>=left){
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.x0>=left && li[i].x0<left){
			se.y0=se.y0-(li[i].y0-se.y0)*(se.x0-left)/(li[i].x0-se.x0);
			se.x0=left;
			beforex=li[i].x0;
			beforey=li[i].y0;
			templi.push_back(se);
		}
	}

	lli.clear();
	int maxleft=1000;
	for(i=0;i<templi.size();i++)
		if(templi[i].x0<=maxleft){
			maxleft=templi[i].x0;
			loc=i;
		}
	if(i==0) return templi;

	li.clear();
	lli.push_back(templi[loc]);
	for(i=loc;i<templi.size();i++)
		lli.push_back(templi[i]);
	for(i=0;i<loc;i++)
		lli.push_back(templi[i]);
	lli.push_back(templi[i]);
	templi.clear();
	for(i=0;i<lli.size();i++)
		li.push_back(lli[i]);
	se.x0=li[0].x0;
	se.y0=li[0].y0;

	beforex=0;
	for(i=1;i<li.size();i++){
		if(beforex>right && li[i].x0>right){
			beforex=li[i].x0;
			beforey=li[i].y0;
		} 
		else if(beforex>right && li[i].x0<=right){
			se.y0=beforey-(li[i].y0-beforey)*(beforex-right)/(li[i].x0-beforex);
			se.x0=right;
			templi.push_back(se);
			beforex=0;
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.x0<=right && li[i].x0<=right){
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.x0<=right && li[i].x0>right){
			se.y0=se.y0-(li[i].y0-se.y0)*(se.x0-right)/(li[i].x0-se.x0);
			se.x0=right;
			beforex=li[i].x0;
			beforey=li[i].y0;
			templi.push_back(se);
		}
	}
	return templi;
}
vector<linee> cuttop(int left,int top,int right,int bottom,vector<linee> li){
	vector<linee> templi,lli;
	int maxbottom=0;
	int i,loc;
	if(li.size()==0) return li;
	for(i=0;i<li.size();i++)
		if(li[i].y0>maxbottom){
			maxbottom=li[i].y0;
			loc=i;
		}
	lli.push_back(li[loc]);

	for(i=loc;i<li.size();i++)
		lli.push_back(li[i]);
	for(i=0;i<loc;i++)
		lli.push_back(li[i]);
	lli.push_back(li[i]);
	li.clear();
	for(i=0;i<lli.size();i++){
		li.push_back(lli[i]);
	}
	linee se;
	se.x0=li[0].x0;
	se.y0=li[0].y0;
	int beforex,beforey=1000;
	for(i=1;i<li.size();i++){
		if(beforey<top && li[i].y0<top){
			beforex=li[i].x0;
			beforey=li[i].y0;
		} 
		else if(beforey<top && li[i].y0>=top){
			se.x0=beforex-(li[i].x0-beforex)*(beforey-top)/(li[i].y0-beforey);
			se.y0=top;
			templi.push_back(se);
			beforey=1000;
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.y0>=top && li[i].y0>=top){
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.y0>=top && li[i].y0<top){
			se.x0=se.x0-(li[i].x0-se.x0)*(se.y0-top)/(li[i].y0-se.y0);
			se.y0=top;
			beforex=li[i].x0;
			beforey=li[i].y0;
			templi.push_back(se);
		}
	}
	if(templi.size()==0) return templi;

	lli.clear();
	int maxtop=1000;
	for(i=0;i<templi.size();i++)
		if(templi[i].y0<=maxtop){
			maxtop=templi[i].y0;
			loc=i;
		}
	if(i==0) return templi;

	li.clear();
	lli.push_back(templi[loc]);
	for(i=loc;i<templi.size();i++)
		lli.push_back(templi[i]);
	for(i=0;i<loc;i++)
		lli.push_back(templi[i]);
	lli.push_back(templi[i]);
	templi.clear();
	for(i=0;i<lli.size();i++)
		li.push_back(lli[i]);
	se.x0=li[0].x0;
	se.y0=li[0].y0;

	beforey=0;
	for(i=1;i<li.size();i++){
		if(beforey>bottom && li[i].y0>bottom){
			beforex=li[i].x0;
			beforey=li[i].y0;
		} 
		else if(beforey>bottom && li[i].y0<=bottom){
			se.x0=beforex-(li[i].x0-beforex)*(beforey-bottom)/(li[i].y0-beforey);
			se.y0=bottom;
			templi.push_back(se);
			beforey=0;
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.y0<=bottom && li[i].y0<=bottom){
			se.x0=li[i].x0;
			se.y0=li[i].y0;
			templi.push_back(se);
		}
		else if(se.y0<=bottom && li[i].y0>bottom){
			se.x0=se.x0-(li[i].x0-se.x0)*(se.y0-bottom)/(li[i].y0-se.y0);
			se.y0=bottom;
			beforex=li[i].x0;
			beforey=li[i].y0;
			templi.push_back(se);
		}
	}
	return templi;
}
void finialpaint(int left,int top,int right,int bottom,vector<linee> li){
	if(li.size()==0) return ;
	vector<int> xpointl,xpointr,ypointt,ypointb,tempp;
	int xb,yb,i,j;
	xb=li[0].x0;
	yb=li[0].y0;

	for(i=1;i<li.size();i++){
		if(xb==left && li[i].x0==left){
			xpointl.push_back(li[i].y0);
			xpointl.push_back(yb);
		}
		else if(xb==right && li[i].x0==right){
			xpointr.push_back(li[i].y0);
			xpointr.push_back(yb);
		}
		else if(yb==top && li[i].y0==top){
			ypointt.push_back(li[i].x0);
			ypointt.push_back(xb);
		}
		else if(yb==bottom && li[i].y0==bottom){
			ypointb.push_back(li[i].x0);
			ypointb.push_back(xb);
		}
		else 
			line(xb+600,yb+300,li[i].x0+600,li[i].y0+300);
		xb=li[i].x0; 
		yb=li[i].y0;
	}
	set<int> tempset;
	set<int>::iterator it;
	for(i=0;i<xpointl.size();i=i++)
		tempset.insert(xpointl[i]);
	if(tempset.size()%2==0)
		for(it=tempset.begin();it!=tempset.end();it++){
		int ttem=*it;
		it++;
		line(left+600,ttem+300,left+600,*it+300);
	}
	else for(it=tempset.begin();it!=tempset.end();it++){
		if(*it==top || *it==bottom) it++;
		if(it==tempset.end()) break;
		int ttem=*it;
		it++;
		if(it==tempset.end()) break;
		if(*it==top || *it==bottom) it++;
		if(it==tempset.end()) break;
		line(left+600,ttem+300,left+600,*it+300);
		}
	tempset.clear();
	for(i=0;i<xpointr.size();i=i++)
		tempset.insert(xpointr[i]);
	if(tempset.size()%2==0)
		for(it=tempset.begin();it!=tempset.end();it++){
		int ttem=*it;
		it++;
		line(right+600,ttem+300,right+600,*it+300);
	}
	else for(it=tempset.begin();it!=tempset.end();it++){
		if(*it==top || *it==bottom) it++;
		if(it==tempset.end()) break;
		int ttem=*it;
		it++;
		if(it==tempset.end()) break;
		if(*it==top || *it==bottom) it++;
		if(it==tempset.end()) break;
		line(right+600,ttem+300,right+600,*it+300);
		}
	tempset.clear();
	for(i=0;i<ypointt.size();i=i++)
		tempset.insert(ypointt[i]);
	if(tempset.size()%2==0)
		for(it=tempset.begin();it!=tempset.end();it++){
		int ttem=*it;
		it++;
		line(ttem+600,top+300,*it+600,top+300);
	}
	else for(it=tempset.begin();it!=tempset.end();it++){
		if(*it==left || *it==right) it++;
		if(it==tempset.end()) break;
		int ttem=*it;
		it++;
		if(it==tempset.end()) break;
		if(*it==left || *it==right) it++;
		if(it==tempset.end()) break;
		line(ttem+600,top+300,*it+600,top+300);
	}
	tempset.clear();
	for(i=0;i<ypointb.size();i=i++)
		tempset.insert(ypointb[i]);
	if(tempset.size()%2==0)
		for(it=tempset.begin();it!=tempset.end();it++){
		int ttem=*it;
		it++;
		line(ttem+600,bottom+300,*it+600,bottom+300 );
	}
	else for(it=tempset.begin();it!=tempset.end();it++){
		if(*it==left || *it==right) it++;
		if(it==tempset.end()) break;
		int ttem=*it;
		it++;
		if(it==tempset.end()) break;
		if(*it==left || *it==right)it++;
		if(it==tempset.end()) break;
		line(ttem+600,bottom+300,*it+600,bottom+300);
	}	
 

}
void repaint(int left,int top,int right,int bottom,vector<linee> li){
	fillrectangle(0,0,1200,600);
	outtextxy(60,30, _T("请在左面出一个矩形，表示裁剪区"));
	outtextxy(660,30, _T("1.左右切割"));
	outtextxy(60,330, _T("2.上下切割"));
	outtextxy(660,330, _T("3.最后结果"));
	line(600,0,600,600);
	line(0,300,1200,300);
	rectangle(left,top,right,bottom);
	rectangle(left+600,top,right+600,bottom);
	rectangle(left,top+300,right,bottom+300);
	rectangle(left+600,top+300,right+600,bottom+300);

	setlinecolor(GREEN);
	int xb,yb,i;
	xb=li[0].x0;
	yb=li[0].y0;
	for(i=1;i<li.size();i++){
		line(xb,yb,li[i].x0,li[i].y0);
		xb=li[i].x0;
		yb=li[i].y0;
	}
	setlinecolor(RED);
	vector<linee> le=cutleft(left,top,right,bottom,li);
	xb=le[0].x0;
	yb=le[0].y0;
	for(i=1;i<le.size();i++){
		line(xb+600,yb,le[i].x0+600,le[i].y0);
		xb=le[i].x0;
		yb=le[i].y0;
	}
	setlinecolor(BLUE);

	le=cuttop(left,top,right,bottom,le);
	xb=le[0].x0;
	yb=le[0].y0;
	for(i=1;i<le.size();i++){
		line(xb,yb+300,le[i].x0,le[i].y0+300);
		xb=le[i].x0;
		yb=le[i].y0;
	}

	setlinecolor(0xCDB38B);
	finialpaint(left,top,right,bottom,le);
	setlinecolor(BLACK);
}
struct rect{
	int left;
	int top;
	int right;
	int bottom;
};
void drawframe(){
	int inx,iny;
	int lastx,lasty;
	bool has_down=false;

	vector<linee> li;
	initline(&li);
	setlinecolor(GREEN);
	int xb,yb;
	vector<linee>::iterator ll;
	ll=li.begin();
	xb=ll->x0;
	yb=ll->y0;
	for(ll++;ll!=li.end();ll++){
		line(xb,yb,ll->x0,ll->y0);
		xb=ll->x0;
		yb=ll->y0;
	}
	FlushBatchDraw();
	while(true){	
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){
			case WM_LBUTTONDOWN:
				if(m.x<600 && m.y<300){
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
					if(right>=600)right=599;
					if(bottom>=300)bottom=299;
					repaint(left,top,right,bottom,li);
					lastx=m.x;
					lasty=m.y;
					FlushBatchDraw();
				}
				break;
			case WM_LBUTTONUP:
				break;

		} 
	}

}


 
int main(){
	hwnd=initgraph(1200, 600);
	init();

    drawframe(); 
	_getch();   
	EndBatchDraw();
    closegraph();         
	return 0;
}
