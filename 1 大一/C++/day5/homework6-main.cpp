#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cmycomplex
{
	private:
		int a,b,c;
	public:
		Cmycomplex(double x,double y){a=x;b=y;	}
		Cmycomplex(double x){a=x;b=0;		}
		Cmycomplex(){;	}
		Cmycomplex operator+ (Cmycomplex &z)
		{
			Cmycomplex t;
			t.a=a+z.a;
			t.b=b+z.b;
			return t;
		}
		void Set(double x,double y){a=x,b=y;		}
		void Show (){cout<<"("<<a<<"+"<<b<<"i)";		}
};

//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
z2=z1+z3;
z2.Show();
double  x,y;
cin>>x>>y;
z2.Set(x,y);
z3=z1+z2;
cout<<"\n";
z3.Show();


}
//StudybarCommentEnd
