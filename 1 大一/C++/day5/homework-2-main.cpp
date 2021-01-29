#include <iostream>
using namespace std;
#include <math.h>
class Cmycomplex
{
	private:double a,b,c,d;
	public:
		Cmycomplex(double x=0,double y=0){a=x;b=y;}	
		Cmycomplex operator*(const Cmycomplex &z)     //重构 * 
		{ Cmycomplex t;
		  t.a=z.a*a-z.b*b;
		  t.b=a*z.b+b*z.a;
		  return t;
		}
		Cmycomplex operator- (const Cmycomplex &z)     //重构 -
		{ Cmycomplex t;
		  t.a=a-z.a;
		  t.b=b-z.b;
		  return t;
		}
		Cmycomplex operator+ (const Cmycomplex &z)     //重构 + 
		{ Cmycomplex t;
		  t.a=a+z.a;
		  t.b=b+z.b;
		  return t;
		}
		friend Cmycomplex operator *(double m,const Cmycomplex &z);
		Cmycomplex sqrt()             //定义开方 
		{   Cmycomplex t;
			double m,n,q;
			m=::sqrt(a*a+b*b);
			n=(m+a)/2;
			q=(m-a)/2;
			n=::sqrt(n);q=::sqrt(q);
			t.a=n;
			if(b>0) t.b=q;else t.b=-q;
			return t;
		}
		Cmycomplex operator/ (const Cmycomplex &z)     //重构 /
		{ Cmycomplex m;
		  m.a=(a*z.a+b*z.b)/(z.a*z.a+z.b*z.b) ;
		  m.b=(z.a*b-a*z.b)/(z.a*z.a+z.b*z.b);
		  return m;
		}
		double gety(){return b;		}
		void Show()
		{if(b>=0)cout<<"("<<a<<"+"<<b<<"i)"<<endl	;
		 else cout<<"("<<a<<b<<"i)"<<endl	;
			}
		//void show(){cout<<          ;}
		
};
Cmycomplex operator *(double m,const Cmycomplex &z)      //定义数字与类相乘 
{
	Cmycomplex t;
	t.a=z.a*m;t.b=z.b*m;
	return t;
}

//StudybarCommentBegin
int main()
{
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	Cmycomplex a(x1, y1), b(x2, y2), c(x3, y3), z, t1, t2,m;
	z=b*b-4*a*c;  z.sqrt();
	t1=((-1)*b+z.sqrt())/(2*a);     //z.sqrt()为求复数z的平方根，这里的2*a涉及操作符重载，且友元重载。
	t2=((-1)*b-z.sqrt())/2.0/a;   //这里涉及到除法的重载
	if(t1.gety()>t2.gety())   //gety()为得到虚部值
	{ 
		t1.Show();
		t2.Show();
	}
	else
	{
		t2.Show();
		t1.Show();
	}
	return 0;
}
//StudybarCommentEnd
