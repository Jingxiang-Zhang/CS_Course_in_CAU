//StudybarCommentBegin
#include <iostream>
#include <iomanip>
#include <string>
//StudybarCommentEnd
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class ComplexNumber
{
	private:
		 double a,b,c;
		 char x[20]; 
	public:
		friend ostream& operator <<(ostream &,const ComplexNumber&);
		friend istream& operator >>(istream &, ComplexNumber&);  //定义友元函数 
        ComplexNumber operator+ (ComplexNumber &z)
        { ComplexNumber m;
		  m.a=z.a+a;m.b=z.b+b;
		  return m;
		}

		ComplexNumber operator- (ComplexNumber &z)
		{ ComplexNumber m;
		  m.a=a-z.a;m.b=b-z.b;
		  return m;
		}
		ComplexNumber operator* (ComplexNumber &z)
		{ ComplexNumber m;
		  m.a=a*z.a-b*z.b;
		  m.b=b*z.a+a*z.b;
		  return m;
		}
		ComplexNumber operator/ (ComplexNumber &z)
		{ ComplexNumber m;
		  m.a=(a*z.a+b*z.b)/(z.a*z.a+z.b*z.b) ;
		  m.b=(z.a*b-a*z.b)/(z.a*z.a+z.b*z.b);
		  return m;
		}
};
ostream & operator <<(ostream &t,const ComplexNumber&z)   //重载刘运算符 
{
	if(z.b>0)
	t<<setiosflags(ios::fixed)<<setprecision(2)<<z.a<<"+"<<z.b<<"i";
	else if(z.b<0) t<<setiosflags(ios::fixed)<<setprecision(2)<<z.a<<z.b<<"i";
	else t<<z.a;
	return t;
}
istream & operator >>(istream &t, ComplexNumber&z)
{
	t>>z.x;
	
	return t;
}

//StudybarCommentBegin
void CN() {    //ComplexNumber
	ComplexNumber cn1, cn2;
	std::cin >> cn1 >> cn2;


 	std::cout<<cn1+cn2<< std::endl;    
 	
 	
 	
	std::cout<<cn1 - cn2 << std::endl;
	std::cout<<cn1*cn2 << std::endl;
	std::cout<<cn1 / cn2 << std::endl;
}
int main(void) {
	CN();
	return 0;
}
//StudybarCommentEnd
