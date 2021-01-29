#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cmycomplex
{
	private: int a,b;
	public:
		Cmycomplex(int x,int y){a=x;b=y;	}
		Cmycomplex(int x){a=x;b=0;		}
		Cmycomplex(){;	}
		Cmycomplex operator+ (Cmycomplex &z)
		{
			Cmycomplex t;
			t.a=a+z.a;
			t.b=b+z.b;
			return t;
		}
		void Show (){cout<<"("<<a<<"+"<<b<<"i)";		}
};
	
//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
z2=z1+z3;
z2.Show();

}
//StudybarCommentEnd
