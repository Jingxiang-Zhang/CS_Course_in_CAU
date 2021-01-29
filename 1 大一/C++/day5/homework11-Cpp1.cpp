#include <iostream>

using namespace std;
class Cmycomplex
{
	private: double a,b,c;
	public:
		Cmycomplex(double x,double y){a=x;b=y;}
		Cmycomplex(double x){a=x;b=0;}
		Cmycomplex(){a=0;b=0;}
		Cmycomplex(Cmycomplex &z){a=z.a;b=z.b;}
        void Set(double x,double y){a=x;b=y;}
		
		void Show(){printf("(%.0f+%.0fi)",a,b); }
		friend Cmycomplex operator+ (double i,Cmycomplex &z);
		friend Cmycomplex operator+ (Cmycomplex &z,double i);
		friend Cmycomplex operator+ (Cmycomplex &z,Cmycomplex &t);
};

Cmycomplex operator+(double i,Cmycomplex &z)
{ 
    Cmycomplex m;
    m.a=z.a+i;m.b=z.b;
	return m;   
}
Cmycomplex operator+(Cmycomplex &z,double i)
{ 
	Cmycomplex m;
    m.a=z.a+i;m.b=z.b;
	return m;  
}
Cmycomplex operator+(Cmycomplex &z,Cmycomplex &t)
{
	Cmycomplex m;
    m.a=z.a+t.a;m.b=z.b+t.b;
	return m;
}
//StudybarCommentBegin
int main()
{
Cmycomplex z1(3,4),z2(7),z3,z4(z1);
double x,y;
cin>>x>>y;
z3.Set(x,y);
cout<<endl;
z3=z3+z2;
z3.Show();
z4=2+z4;
cout<<endl;
z4.Show();
z4=z4+2;
cout<<endl;
z4.Show();
return 0;
} 
//StudybarCommentEnd

