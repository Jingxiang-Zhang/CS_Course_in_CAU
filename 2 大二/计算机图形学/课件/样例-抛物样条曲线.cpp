//////////////////////////
//程序名称：抛物样条曲线 
//功    能：鼠标控制绘制抛物样条曲线，左键单击时绘制红色空心圆，右键双击后绘制抛物线

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void parspl(int p[][2],int n,int k,int e)
{
	int x,y,i,j,m;
	double t1,t2,t3,t,a,b,c,d;
	if(e==1)
	{ 
		m=n;
		p[0][0]=p[1][0];p[0][1]=p[1][1];
		p[n+1][0]=p[n][0];p[n+1][1]=p[n][1]; 
	}
	else
	{
		m=n+1;
		p[0][0]=p[n][0];p[0][1]=p[n][1];
		p[m][0]=p[1][0];p[m][1]=p[1][1];
		p[m+1][0]=p[2][0];p[m+1][1]=p[2][1];  
	}
	t=0.5/k;
	moveto(p[1][0],p[1][1]);
	for(i=0;i<m-1;i++)
	{
		for(j=1;j<k;j++)
		{
			t1=j*t;t2=t1*t1;t3=t2*t1;
			a=-4.0*t3+4.0*t2-t1;
			b=12.0*t3-10.0*t2+1.0;
			c=-12.0*t3+8.0*t2+t1;
			d=4.0*t3-2.0*t2;
			x=a*p[i][0]+b*p[i+1][0]+c*p[i+2][0]+d*p[i+3][0];
			y=a*p[i][1]+b*p[i+1][1]+c*p[i+2][1]+d*p[i+3][1];
			lineto(x,y);    
		}
		lineto(p[i+2][0],p[i+2][1]);   
	}  
}

void main()
{
	int n = 0, e, k = 20;
	e = 1;

	initgraph(640, 480);
	MOUSEMSG msg;
	int p[30][2];
	setcolor(RED);
	while (1)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) //初始点击鼠标左键绘制坐标点
		{
			circle(msg.x, msg.y, 4);
			p[n + 1][0] = msg.x;
			p[n + 1][1] = msg.y;
			n++;
		}
		if (msg.uMsg == WM_RBUTTONDBLCLK)//双击鼠标右键退出循环，绘制抛物线
			break;
	}

	parspl(p, n, k, e);

	getch();
	closegraph();
}