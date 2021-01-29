#include <iostream>
#include <iomanip> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Rectangle
{
	private:double a,b,c;
	public:
		Rectangle(){a=1;b=1;	}
		void setLength(double x){if(x>0)a=x;	}
		void setWidth(double x){if(x>0)b=x;	}
		double perimeter(){if(a==1||b==1)return 4;else return 2*(a+b);		}
		double area(){if(a==1||b==1)return 1;return a*b;	}
};
//StudybarCommentBegin
int main()
{
    Rectangle r;
    double length,width;
    
//    cout<<"please input the length of Rectangle:";
    cin>>length;
//    cout<<"please input the width of Rectangle:";
    cin>>width;
    r.setLength(length);
    r.setWidth(width);
    cout<<"the perimeter is:"<<setprecision(2)<<fixed<<r.perimeter()<<endl;
    cout<<"the area is:"<<setprecision(2)<<fixed<<r.area()<<endl;
    return 0;
    
}
//StudybarCommentEnd
