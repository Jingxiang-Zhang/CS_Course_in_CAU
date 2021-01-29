#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class  Rectangle
{
	private :double a[4][2],b,c,d,e;
	public:Rectangle(double x[4][2])
	{	int i,j;
	 for(i=0;i<4;i++)
	 for(j=0;j<2;j++)
	   { 
	 if((x[i][j]>=20||x[i][j]<0)&&j==1) printf("第%d个点的纵坐标值无效,被置为0\n",i+1);
	    else if((x[i][j]>=20||x[i][j]<0)&&j==0) printf("第%d个点的纵坐标值无效,被置为0\n",i+1);
	    a[i][j]=x[i][j]; 
		}
				 
	b=a[0][0]-a[1][0];c=a[2][0]-a[3][0];
	if(b!=c) {printf("不能构成长方形！");exit(0);}
    }
				
		
	double length(){b=-a[0][0]+a[1][0];c=-a[2][0]+a[3][0];
	             if(b==c) return b;else printf("不能构成长方形！");exit(0);	}
	double	width() {d=a[0][1]-a[2][1];e=a[1][1]-a[3][1];
	             if(d==e) return d;else printf("不能构成长方形！");exit(0);	}
	double perimeter(){return 2*b+2*d;	}
	double area(){return b*d;	}
	double square(){if(b==d)return 1;else return 0;	}
};
//StudybarCommentBegin
int main()
{
    double rect[4][2];
    int i;
    //        cout<<"请输入第"<<i+1<<"个点的横纵坐标（大于0且小于20）,以空格分隔：";
    for(i=0;i<4;i++)
    {
        cin>>rect[i][0]>>rect[i][1];
    }
    
    Rectangle myRect(rect);
    cout<<"长度为："<<myRect.length()<<endl;
    cout<<"宽度为："<<myRect.width()<<endl;
    cout<<"周长为："<<myRect.perimeter()<<endl;
    cout<<"面积为："<<myRect.area()<<endl;
    
    if(myRect.square())
        cout<<"此长方形是一个正方形"<<endl;
    else
        cout<<"此长方形不是一个正方形"<<endl;
    
    return 0;
}
//StudybarCommentEnd
