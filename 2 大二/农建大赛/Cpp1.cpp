#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <sstream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

double outco2;
double inco2;
double result;

void init(int location) {
	stringstream ss;
	ss<<location;
	char cname[10];
	ss>>cname;
	char tname[100]="data";
	int i,j=4;
	for(i=0;cname[i]!=0;i++){
		tname[j]=cname[i];
		j++;
	}

	tname[j++]='.';
	tname[j++]='j';
	tname[j++]='p';
	tname[j++]='g';
	tname[j++]='\0';
	

	srand((int)time(0));
	IMAGE img;
	loadimage(&img, _T(tname));
	putimage(0, 0, &img);    // 在另一个地方再次显示背景
	settextcolor(BLACK);
	setbkmode(BLACK);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 20;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
/*	BeginBatchDraw();
	FlushBatchDraw();
	EndBatchDraw();*/
	setfillcolor(GREEN);
	setlinecolor(BLACK);
}
void paint(){
	
	IMAGE img;
	fillrectangle(1200,100,1320,150);
	outtextxy(1210,110, _T("开启传感器" ));
	settextcolor(WHITE);
	stringstream ss;
	ss<<outco2;
	char tout[100];
	ss>>tout;
	ss.clear();
	ss<<inco2;
	char tin[100];
	ss>>tin;
	fillrectangle(1025,675,1120,700);
	fillrectangle(1025,615,1120,640);
	outtextxy(1030,680, _T("CO2:"));
	outtextxy(1070,680, _T(tin));
	outtextxy(1030,620, _T("CO2:"));
	outtextxy(1070,620, _T(tout));
	
	int tempdata=inco2/2;
	for(int i=0;i<4;i++){
		ss.clear();
		char temp[100];
		int intt=tempdata*(i+1);
		ss<<intt;
		ss>>temp;
		outtextxy(2,700-i*45, _T(temp));
	}
	
	settextcolor(BLACK);

}
void change(){
	BeginBatchDraw();
	init(0);
	paint();
	int change_data;
	int feifu=-1;
	change_data=outco2;

	fillrectangle(1025,675,1120,700);
	stringstream ss;
	char tin[100];
	ss<<change_data;
	ss>>tin;
	settextcolor(WHITE);
	outtextxy(1030,680, _T("CO2:"));
	outtextxy(1070,680, _T(tin));
	settextcolor(BLACK);

	line(45,666,545,666);
	int i;
	int pixx=45;
	int locationchange=20;

	for(int mm=0;mm<=25;mm++){
				//这里是画图
		init(mm);
		paint();
		line(45,666,545,666);
		double multi=(change_data-inco2)/2.71828;
		double lastresult=666-(change_data-inco2)/(inco2/90);
		moveto(pixx,lastresult);
		double nowvalue=1;
		for(i=0;i<=mm;i++){
			int locationx=pixx+locationchange*i;
			double tempvalue=nowvalue-i*0.16;
			double result=pow(2.71828,tempvalue);
			double tempresult=result;
			result=666-(result*multi)/(inco2/90);
			setlinecolor(WHITE);
			lineto(locationx,result);
				//这里是改变表框中的数据
			int thi=int(tempresult*multi+inco2);
			fillrectangle(1025,675,1120,700);
			char ttin[100];
			ss.clear();
			ss<<thi;
			ss>>ttin;
			settextcolor(WHITE);
			outtextxy(1030,680, _T("CO2:"));
			outtextxy(1070,680, _T(ttin));
			settextcolor(BLACK);
			if(i%5==0){
				char ttin[100];
				stringstream st;
				st<<int(tempresult*multi+inco2);
				st>>ttin;
				outtextxy(locationx-10,result, _T(ttin));
				fillcircle(locationx,result,2);
			}
			setlinecolor(BLACK);
			
		}
		FlushBatchDraw();
		EndBatchDraw();
		Sleep(200);
	}

	
}
void start() {
	paint();
	bool down=false;
	while (true) {
		MOUSEMSG m = GetMouseMsg();
		switch (m.uMsg) {
			case WM_LBUTTONDOWN:
				if (m.x >= 1200 && m.x <= 1300 && m.y >= 100 && m.y<=150) {				 					
					setfillcolor(BLUE);
					fillrectangle(1200,100,1320,150);
					outtextxy(1210,110, _T("开启传感器" ));
					down=true;
				}
				break;
			case WM_MOUSEMOVE:
				break;
			case WM_LBUTTONUP:
				if(down){
					down=false;
					setfillcolor(GREEN);
					fillrectangle(1200,100,1320,150);
					outtextxy(1210,110, _T("开启传感器" ));
					if(m.x >= 1200 && m.x <= 1300 && m.y >= 100 && m.y<=150)
						change();
				}
				break;
		}
	}
}
int main()
	{

	 outco2=430;
	 inco2=1000;
	 initgraph(1500, 790);   // 创建绘图窗口，大小为 640x480 像素
	 init(0);
	 start();
	 int i=_getch();              // 按任意键继续
	 closegraph();          // 关闭绘图窗口
 
	return 0;

}
