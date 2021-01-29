#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class st
{
	private:double a,b,c;
	public:
		st(double x=0,double y=0){a=x;b=y;		}
		friend istream &operator >>(istream &s,st &t);
		double getb(){return b;		}
		void show(st &n1,st &m2,st &n2,st &m3,st &n3)   //其中m为x，n为y 
		{
			double j,x,y,z,q=0;   //x为a的解，以此类推 
			j=a*a*m2.a+m3.a*m3.a*a+m2.a*m2.a*m3.a-(m3.a*m3.a*m2.a+m2.a*m2.a*a+a*a*m3.a);
			x=n1.a*m2.a+n3.a*a+n2.a*m3.a-(m2.a*n3.a+n2.a*a+n1.a*m3.a);
			x=x/j;
			y=a*a*n2.a+m3.a*m3.a*n1.a+m2.a*m2.a*n3.a-(m3.a*m3.a*n2.a+m2.a*m2.a*n1.a+a*a*n3.a);
			y=y/j;
			z=n1.a-(a*a*x+a*y);
			printf("%lf %lf\n",x,q);
            printf("%lf %lf\n",y,q);
            printf("%lf %lf\n",z,q);
		}
		void shown(st &n1,st &m2,st &n2,st &m3,st &n3)   //其中m为x，n为y 
		{
			
		}
};

istream &operator >>(istream &s,st &t)
{
	s>>t.a>>t.b;
	return s;
}
int main(int argc, char** argv) {
	st x1,y1,x2,y2,x3,y3;

	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if(x2.getb()==0)  x1.show(y1,x2,y2,x3,y3);
	if(x2.getb()!=0)  x1.shown(y1,x2,y2,x3,y3) ;
	
	   
	return 0;
}
