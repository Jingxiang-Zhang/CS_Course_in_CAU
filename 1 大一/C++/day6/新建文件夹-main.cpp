#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Fraction
{
	private:double a,b,c;
	public:
		Fraction(double x=0,double y=0){a=x;b=y;		}
		friend istream &operator>>(istream &t,Fraction &z);
		friend ostream &operator<<(ostream &t,const Fraction &z);
		Fraction operator +(Fraction &z)   //+++
		{ Fraction t;t.a=a+z.a;t.b=b+t.b;
		       return t;	}
		Fraction operator -(Fraction &z)  //---
		{ Fraction t;t.a=a-z.a;t.b=b-t.b;
		       return t;	}
		Fraction operator *(Fraction &z)   //***
		{ Fraction t;                   
		     t.a=a*z.a-b*z.b;
		     t.b=b*z.a+a*z.b;
		       return t;	}
		Fraction operator /(Fraction &z)   // ///
		{ Fraction m;
		    m.a=(a*z.a+b*z.b)/(z.a*z.a+z.b*z.b) ;
		    m.b=(z.a*b-a*z.b)/(z.a*z.a+z.b*z.b);
		       return m;	}
		Fraction operator ==(Fraction &z)
		{ if(a==z.a&&b==z.b  ) return 1;else return 0;	}
		Fraction operator !=(Fraction &z)
		{ if(a==z.a&&b==z.b  ) return 0;else return 1;	}
		
		Fraction operator >=(Fraction &z)
		{ if((a*a+b*b)>=(z.a*z.a+z.b*z.b)  ) return 1;else return 0;	}
		Fraction operator <=(Fraction &z)
		{ if((a*a+b*b)<=(z.a*z.a+z.b*z.b)  ) return 1;else return 0;	}
		
	    Fraction operator >(Fraction &z)
		{ if((a*a+b*b)>(z.a*z.a+z.b*z.b)  ) return 1;else return 0;	}
		Fraction operator <(Fraction &z)
		{ if((a*a+b*b)<(z.a*z.a+z.b*z.b)  ) return 1;else return 0;	}
		
};
istream &operator>>(istream &t,Fraction &z)
{
	t>>z.a>>z.b;
	return t;
}
ostream &operator<<(ostream &t, const Fraction &z)
{
	t<<z.a<<"/"<<z.b;
	return t;
}
//StudybarCommentBegin
int main(int argc, char *argv[]) {
	
	Fraction a(1),b(1,3);
	
	cin>>a>>b;
	
	cout << "a= " << a << ", b = " << b << endl;
	
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	
	cout << "a == b is " << (a == b) << endl;
	cout << "a != b is " << (a != b) << endl;
	cout << "a <= b is " << (a <= b) << endl;
	cout << "a >= b is " << (a >= b) << endl;
	cout << "a < b is " << (a < b) << endl;
	cout << "a > b is " << (a > b) << endl;
	
    return 1;
}
//StudybarCommentEnd
