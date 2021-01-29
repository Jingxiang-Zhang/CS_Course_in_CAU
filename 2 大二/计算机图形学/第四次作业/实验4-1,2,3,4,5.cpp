/***************************************
实验二 4-1,2,3,4,5 
程序名称：三维图形投影和消隐
功能：三维图形的正等测显示、三维图形旋转、三视图的投影、
	  三维图形消隐的正等测显示，消隐的旋转、消隐的投影 
编译环境：Visual C++ 6.0，EasyX_20190219(beta)
作 者：张靖祥<2017304010413><1967527237@qq.com>
最后修改：2019-4-18


			
				
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
	fillrectangle(-10,-10,750,650);
	line(-10,400,750,400);
	line(250,400,250,650);
	line(500,400,500,650);
	LOGFONT f;
	gettextstyle(&f); 
	f.lfHeight = 15;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY; 
	settextstyle(&f); 
	outtextxy(60,30, _T("三维图形的正等轴测投影图,滚轮进行旋转"));
	outtextxy(30,420, _T("正视图"));
	outtextxy(280,420, _T("侧视图"));
	outtextxy(530,420, _T("俯视图"));
	BeginBatchDraw();
	FlushBatchDraw();
}
struct point{
	double x;
	double y;
	double z;
};
struct edge{
	int point1;
	int point2;  
};
 
struct facade{
	int ringbegin;
	int ringend;
};	
void pointset(vector<point> *poin){
	double xx[]={0,150,150,0,0,150,150,0,75};
	double yy[]={0,0,200,200,0,0,200,200,100};
	double zz[]={0,0,0,0,200,200,200,200,100};
	int i=8;
	double offsetx=0;
	double offsety=0;
	double offsetz=0;
	int j;
	point po;
	for(j=0;j<i;j++){
		po.x=xx[j]+offsetx;
		po.y=yy[j]+offsety;
		po.z=zz[j]+offsetz;
		poin->push_back(po);
	}
}
void edgelink(vector<edge> *edg){
	int edge1[]={0,1,2,3, 4,5,6,7, 0,1,2,3};
	int edge2[]={1,2,3,0, 5,6,7,4, 4,5,6,7};
	int i=12,j;
	edge tempedge;
	for(j=0;j<i;j++){
		tempedge.point1=edge1[j];
		tempedge.point2=edge2[j];
		edg->push_back(tempedge);
	}
}  
void createfacades(vector<facade> *facades){
	int facade_begin[]={0,5,10,15,20,25};
	int facade_end[]={4,9,14,19,24,29};
	int i,j=6;
	facade tempfacade;
	for(i=0;i<6;i++){
		tempfacade.ringbegin=facade_begin[i];
		tempfacade.ringend=facade_end[i];
		facades->push_back(tempfacade);
	}
}
void createrings(vector<int> *rings){
	int ring1[6][5]={{1,2,6,5,1},
					{2,3,7,6,2},
					{6,7,4,5,6},
					{0,3,2,1,0},
					{0,1,5,4,0},
					{0,4,7,3,0},
					};
	int j,i;
	for(i=0;i<6;i++)
		for(j=0;j<5;j++)
			rings->push_back(ring1[i][j]);

};
void Isometric_projection(vector<point> *points,vector<edge> edges){
	double offsetx=200;
	double offsety=200;
	vector<point>::iterator it;
	for(it=points->begin();it!=points->end();it++){
		double tempx=it->x*0.707-it->y*0.707-offsetx;
		double tempz=-it->x*0.408-it->y*0.408+it->z*0.8165-offsety;
		it->x=tempx;
		it->z=tempz;
	}
	
}
void paint_Isometric_projection(vector<point> points,vector<edge> edges){
	int i;
	for(i=0;i<edges.size();i++){
		char c=edges[i].point1+48;
		outtextxy(-points[edges[i].point1].x ,-points[edges[i].point1].z, _T(c));
		c=edges[i].point2+48;
		outtextxy(-points[edges[i].point2].x ,-points[edges[i].point2].z, _T(c));

		line(-points[edges[i].point1].x,  -points[edges[i].point1].z,
			 -points[edges[i].point2].x,  -points[edges[i].point2].z);
		
	}


	setlinecolor(RED);
	outtextxy(200,200, _T("0"));

	line(200,200,200,10);
	line(200,10,202,15);
	line(200,10,198,15);
	outtextxy(205,10, _T("z"));

	line(200,200,377,302);
	line(377,302,374,295);
	line(377,302,370,302);
	outtextxy(377,302, _T("y"));

	line(200,200,23,302);
	line(23,302,26,295);
	line(23,302,30,302);
	setlinecolor(BLACK);
	outtextxy(23,302, _T("x"));
}

void paint_front_view(vector<point> points,vector<edge> edges){
	double offsetx=150;
	double offsety=550;
	int i;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2-offsetx;
		double tempz=points[i].z/2-offsety;
		points[i].x=tempx;
		points[i].z=tempz;
	}
	for(i=0;i<edges.size();i++){

		line(-points[edges[i].point1].x,  -points[edges[i].point1].z,
			 -points[edges[i].point2].x,  -points[edges[i].point2].z);
	}


}
void side_view(vector<point> *points,vector<edge> edges){
	double offsetx=200;
	double offsety=200;
	vector<point>::iterator it;
	for(it=points->begin();it!=points->end();it++){
		double tempx=it->y+offsetx;
		double tempy=-it->x+offsety;
		it->x=tempx;
		it->y=tempy;
	}
}
void paint_side_view(vector<point> points,vector<edge> edges){
	double offsetx=250;
	double offsety=550;
	int i;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2+offsetx;
		double tempz=points[i].z/2-offsety;
		points[i].x=tempx;
		points[i].z=tempz;
	}
	for(i=0;i<edges.size();i++){
		line(points[edges[i].point1].x,  -points[edges[i].point1].z,
			 points[edges[i].point2].x,  -points[edges[i].point2].z);
	}
}

void top_view(vector<point> *points,vector<edge> edges){
	double offsetx=200;
	double offsety=200;
	vector<point>::iterator it;
	for(it=points->begin();it!=points->end();it++){
		/**/
		double tempz=-it->y+offsetx;
		double tempy=it->z+offsety;
		it->z=tempz;
		it->y=tempy;
	}
}
void paint_top_view(vector<point> points,vector<edge> edges){
	double offsetx=650;
	double offsety=550;
	int i;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2-offsetx;
		double tempz=points[i].z/2-offsety;
		points[i].x=tempx;
		points[i].z=tempz;
	}
	for(i=0;i<edges.size();i++){
		line(-points[edges[i].point1].x,  -points[edges[i].point1].z,
			 -points[edges[i].point2].x,  -points[edges[i].point2].z);
	}
}
void hidden_side_eliminating(vector<point> points,vector<facade> facades,vector<int> rings,vector<edge> *edges){
	int facade_count;
	set<int> edgeset;
	for(facade_count=0;facade_count<facades.size();facade_count++){	
		int begin=facades[facade_count].ringbegin;
		int end=facades[facade_count].ringend;
		double Za,Zb,Zs,Xa,Xb,Xs;
		Zs=points[rings[begin]].z;
		Za=points[rings[begin+1]].z;
		Zb=points[rings[begin+2]].z;
		Xs=points[rings[begin]].x;
		Xa=points[rings[begin+1]].x;
		Xb=points[rings[begin+2]].x;
		double E;
		E=(Za-Zs)*(Xb-Xa)-(Xa-Xs)*(Zb-Za);
		bool hide;
		if(E>=0) hide=false;
		else hide=true;
		if(!hide){
			int edgenum;
			for(edgenum=begin;edgenum<end;edgenum++){
				int edgebegin=rings[edgenum];
				int edgeend=rings[edgenum+1];
				if(edgeend<edgebegin){
					int temp=edgeend;
					edgeend=edgebegin;
					edgebegin=temp;
				}
				int code=edgeend*100+edgebegin;
				int size1=edgeset.size();
				edgeset.insert(code);
				int size2=edgeset.size();
				if(size1!=size2){
					edge tempedge;
					tempedge.point1=edgebegin;
					tempedge.point2=edgeend;
					edges->push_back(tempedge);
				}

			}
		}


	}
}
void repaint(vector<point> points,vector<facade> facades,vector<int> rings){
	setfillcolor(WHITE);
	fillrectangle(-10,-10,750,650);
	line(-10,400,750,400);
	line(250,400,250,650);
	line(500,400,500,650);
	outtextxy(60,30, _T("三维图形的正等轴测投影图,滚轮进行旋转,左键为x轴透视，右键为xy轴透视，中键为xyz轴透视"));
	outtextxy(30,420, _T("正视图"));
	outtextxy(280,420, _T("侧视图"));	
	outtextxy(530,420, _T("俯视图"));

	vector<edge> edges;
	vector<point> copypoint;
	int i;
	for(i=0;i<points.size();i++){
		copypoint.push_back(points[i]);
	}
		
	edges.clear();
	Isometric_projection(&copypoint,edges);
	hidden_side_eliminating(copypoint,facades,rings,&edges);
	paint_Isometric_projection(copypoint,edges);

	copypoint.clear();
	for(i=0;i<points.size();i++){
		copypoint.push_back(points[i]);
	}
	
	edges.clear();
	hidden_side_eliminating(points,facades,rings,&edges);
	paint_front_view(points,edges);

	edges.clear();
	side_view(&copypoint,edges);
	hidden_side_eliminating(copypoint,facades,rings,&edges);
	paint_side_view(copypoint,edges);
	copypoint.clear();
	for(i=0;i<points.size();i++){
		copypoint.push_back(points[i]);
	}

	edges.clear();
	top_view(&copypoint,edges);
	hidden_side_eliminating(copypoint,facades,rings,&edges);
	paint_top_view(copypoint,edges);
	copypoint.clear();
	for(i=0;i<points.size();i++){
		copypoint.push_back(points[i]);
	}
 
}
void Isometric_projection_nhide(vector<point> points,vector<edge> edges){
	int i;
	double offsetx=200;
	double offsety=200;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x*0.707-points[i].y*0.707-offsetx;
		double tempz=-points[i].x*0.408-points[i].y*0.408+points[i].z*0.8165-offsety;
		points[i].x=tempx;
		points[i].z=tempz;
		cout<<points[i].x<<" "<<points[i].z<<endl;
		char c=i+48;
		outtextxy(-tempx,- tempz, _T(c));
	 

	}
	for(i=0;i<edges.size();i++){
		line(-points[edges[i].point1].x,  -points[edges[i].point1].z,
			 -points[edges[i].point2].x,  -points[edges[i].point2].z);
		
	}
	setlinecolor(RED);
	outtextxy(200,200, _T("0"));

	line(200,200,200,10);
	line(200,10,202,15);
	line(200,10,198,15);
	outtextxy(205,10, _T("z"));

	line(200,200,377,302);
	line(377,302,374,295);
	line(377,302,370,302);
	outtextxy(377,302, _T("y"));

	line(200,200,23,302);
	line(23,302,26,295);
	line(23,302,30,302);
	setlinecolor(BLACK);
	outtextxy(23,302, _T("x"));
	
}
void front_view_nhide(vector<point> points,vector<edge> edges){
	double offsetx=150;
	double offsety=550;
	int i;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2-offsetx;
		double tempz=points[i].z/2-offsety;
		points[i].x=tempx;
		points[i].z=tempz;
	}
	for(i=0;i<edges.size();i++){
		line(-points[edges[i].point1].x,  -points[edges[i].point1].z,
			 -points[edges[i].point2].x,  -points[edges[i].point2].z);
	}
}
void side_view_nhide(vector<point> points,vector<edge> edges){
	double offsetx=350;
	double offsety=550;
	int i;
	for(i=0;i<points.size();i++){
		double tempx=points[i].y/2+offsetx;
		double tempz=points[i].z/2-offsety;
		points[i].x=tempx;
		points[i].z=tempz;
	}
	for(i=0;i<edges.size();i++){
		line(points[edges[i].point1].x,  -points[edges[i].point1].z,
			 points[edges[i].point2].x,  -points[edges[i].point2].z);
	}
}
void top_view_nhide(vector<point> points,vector<edge> edges){
	double offsetx=650;
	double offsety=450;
	int i;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2-offsetx;
		double tempz=points[i].y/2+offsety;
		points[i].x=tempx;
		points[i].z=tempz;
	}
	for(i=0;i<edges.size();i++){
		line(-points[edges[i].point1].x,  points[edges[i].point1].z,
			 -points[edges[i].point2].x,  points[edges[i].point2].z);
	}
}
void repaint_nhide(vector<point> points,vector<edge> edges){
	fillrectangle(-10,-10,750,650);
	line(-10,400,750,400);
	line(250,400,250,650);
	line(500,400,500,650);
	outtextxy(60,30, _T("三维图形的正等轴测投影图,滚轮进行旋转,左键为x轴透视，右键为xy轴透视，中键为xyz轴透视"));
	outtextxy(30,420, _T("正视图"));
	outtextxy(280,420, _T("侧视图"));	
	outtextxy(530,420, _T("俯视图"));
	
	Isometric_projection_nhide(points,edges);
	front_view_nhide(points,edges);
	side_view_nhide(points,edges);
	top_view_nhide(points,edges); 
}



void button(bool hide){
	if(hide){
		setfillcolor(YELLOW);
		fillrectangle(450,100,600,150);
		rectangle(450,100,600,150);
		outtextxy(460,120, _T("点击此处一键解除"));
		setfillcolor(WHITE);
	}
	else{
		setfillcolor(WHITE);
		fillrectangle(450,100,600,150);
		rectangle(450,100,600,150);
		outtextxy(460,120, _T("点击此处一键消隐"));
	}
}
void rotate(double degree,vector<point> *points){
 

	double cosx=cos(degree/3.1415926/2);
	double sinx=sin(degree/3.1415926/2);
 
	vector<point>::iterator it=points->begin();
	double offsetx=-75*cosx-100*sinx+75;
	double offsety=75*sinx-100*cosx+100;

	for(;it!=points->end();it++){
		double tempx=(*it).x*cosx+(*it).y*sinx;
		double tempy=(*it).x*(-sinx)+(*it).y*cosx;
		(*it).x=tempx+offsetx;
		(*it).y=tempy+offsety;
		
	}

 
}
void Xfluoroscopy(vector<point> points,vector<facade> facades,vector<int> rings,bool hide,vector<edge> oldedge){
	double offsetx=0;
	double offsety=0;
	int i;
	double q=0.005;
	double amplify_coefficient=2;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2+offsetx;
		double tempz=points[i].z/2+offsety;
		double tempy=points[i].y/2;
		double temp=(200-points[i].y)*q+1;
		points[i].x=tempx/temp*amplify_coefficient;
		points[i].z=tempz/temp*amplify_coefficient;

	}
	if(hide)
		repaint(points,facades,rings);
	else
		repaint_nhide(points,oldedge);
	button(hide);
}
void XYfluoroscopy(vector<point> points,vector<facade> facades,vector<int> rings,bool hide,vector<edge> oldedge){
	rotate(45,&points);
	double offsetx=0;
	double offsety=0;
	int i;
	double q=0.005;
	double amplify_coefficient=2;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2+offsetx;
		double tempz=points[i].z/2+offsety;
		double tempy=points[i].y/2;
		double temp=(200-points[i].y)*q+1;
		points[i].x=tempx/temp*amplify_coefficient;
		points[i].z=tempz/temp*amplify_coefficient;

	}
	if(hide)
		repaint(points,facades,rings);
	else
		repaint_nhide(points,oldedge);
	button(hide);
}
void XYZfluoroscopy(vector<point> points,vector<facade> facades,vector<int> rings,bool hide,vector<edge> oldedge){
	rotate(45,&points);
	double degree=45;
	double cosx=cos(degree/3.1415926/2);
	double sinx=sin(degree/3.1415926/2);
 
	vector<point>::iterator it=points.begin();
	double offsetx=-75*cosx-100*sinx+75;
	double offsety=75*sinx-100*cosx+100;

	for(;it!=points.end();it++){
		double tempz=(*it).z*cosx+(*it).y*sinx;
		double tempy=(*it).z*(-sinx)+(*it).y*cosx;
		(*it).z=tempz+offsetx;
		(*it).y=tempy+offsety;
		
	}



	int i;
	double q=0.005;
	double amplify_coefficient=2;
	for(i=0;i<points.size();i++){
		double tempx=points[i].x/2;
		double tempz=points[i].z/2;
		double tempy=points[i].y/2;
		double temp=(200-points[i].y)*q+1;
		points[i].x=tempx/temp*amplify_coefficient;
		points[i].z=tempz/temp*amplify_coefficient;

	}
	if(hide)
		repaint(points,facades,rings);
	else
		repaint_nhide(points,oldedge);
	button(hide);
}
void startmotion(){
	/**************************************************/
	vector<point> points;
	pointset(&points);
	vector<edge> edges;
    edgelink(&edges);
	vector<facade> facades;
	createfacades(&facades);
	vector<int> rings;
	createrings(&rings);

	bool hide=false;

	repaint_nhide(points,edges);
	setfillcolor(WHITE);
	rectangle(450,100,600,150);
	outtextxy(460,120, _T("点击此处一键消隐"));


 	FlushBatchDraw();
	bool has_down=false;
	while(true){
		MOUSEMSG m = GetMouseMsg();
		switch(m.uMsg){	
			case WM_MOUSEWHEEL:
				rotate(double(m.wheel)/120,&points);
				if(hide)
					repaint(points,facades,rings);
				else
					repaint_nhide(points,edges);
				
				button(hide);
				FlushBatchDraw();
				break;
			case WM_LBUTTONDOWN:
				if(m.x<600 && m.x>450 &&m.y<150 && m.y>100){
					if(!hide){
						
						repaint(points,facades,rings);
						setfillcolor(YELLOW);
						fillrectangle(450,100,600,150);
						rectangle(450,100,600,150);
						outtextxy(460,120, _T("点击此处一键解除"));
						setfillcolor(WHITE);
						hide=true;
					}
					else{
						repaint_nhide(points,edges);
						setfillcolor(WHITE);
						fillrectangle(450,100,600,150);
						rectangle(450,100,600,150);
						outtextxy(460,120, _T("点击此处一键消隐"));
						hide=false;
					}
				}
				else
					Xfluoroscopy(points,facades,rings,hide,edges);
				FlushBatchDraw();
				break;
			case WM_RBUTTONDOWN:
				XYfluoroscopy(points,facades,rings,hide,edges);
				FlushBatchDraw();
				break;
			case WM_MBUTTONDOWN:
				XYZfluoroscopy(points,facades,rings,hide,edges);
				FlushBatchDraw();
				break;
			case WM_LBUTTONUP:
				break;

		}
	}

}

 
int main(){
	hwnd=initgraph(750,650);
	init();
	startmotion();
	_getch();   

	EndBatchDraw();
    closegraph();         
	return 0;
}
