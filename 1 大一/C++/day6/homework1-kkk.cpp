#include <iostream>
using namespace std;
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
//StudybarCommentBegin
#include <iostream>
using namespace std;

  class Fraction {
        int numerator, denominator;

    public:
        Fraction(int a , int b) ;              

        bool operator==(Fraction const& f) const;	
        bool operator!=(Fraction const& f) const;
        bool operator>(Fraction const& f) const;
        bool operator>=(Fraction const& f) const;
        bool operator<(Fraction const& f) const;
        bool operator<=(Fraction const& f) const;

        Fraction operator+(Fraction const& f) const;
        Fraction operator-(Fraction const& f) const;
        Fraction operator*(Fraction const& f) const;
        Fraction operator/(Fraction const& f) const;        

        friend std::istream& operator>>(std::istream&, Fraction& f);
        friend std::ostream& operator<<(std::ostream&, Fraction const& f);      

    private:
        void simplify();    
    };
//StudybarCommentEnd
Fraction::Fraction(int a=0 , int b=0){numerator=a;denominator=b;}      //构造 
//Fraction::Fraction(double a) {a=a*100;numerator=(int)a;denominator=100;simplify();}
void Fraction::  simplify ()                             
{
	int m;
	for(m=fabs(numerator);m>1;m--) if(numerator%m==0 && denominator%m==0) break;
	numerator=numerator/m;denominator=denominator/m; 
}

std::istream& operator>>(std::istream&t, Fraction& f)     // cin
{
	t>>f.numerator>>f.denominator;
	f.simplify();
	
	return t;
}
std::ostream& operator<<(std::ostream&t, Fraction const& f)  // cout
{   
  
	t<<f.numerator<<"/"<<f.denominator;

}

Fraction Fraction:: operator+(Fraction const& f) const
{
	int m,n;   
	Fraction t;
	m=numerator*f.denominator+f.numerator*denominator;
	n=denominator*f.denominator;
	t.numerator=m;t.denominator=n;
	t.simplify();return t;
}
Fraction Fraction:: operator-(Fraction const& f) const
{
	int m,n;   
	Fraction t;
	m=numerator*f.denominator-f.numerator*denominator;  //m 是分子 
	n=denominator*f.denominator;                           //n是分 母 
	t.numerator=m; 
	t.denominator=n;
   //if(t.denominator<0 ){t.denominator=-t.denominator;t.numerator=-t.numerator;	}
	t.simplify();
	return t;
}
Fraction Fraction:: operator*(Fraction const& f) const
{
	int m,n;   
	Fraction t;
	m=numerator*f.numerator;                      //m 是分子 
	n=denominator*f.denominator;                           //n是分 母 
	t.numerator=m; 
	t.denominator=n;
   //if(t.denominator<0 ){t.denominator=-t.denominator;t.numerator=-t.numerator;	}
	t.simplify();
	return t;
}
Fraction Fraction:: operator/(Fraction const& f) const
{
	int m,n;   
	Fraction t;
	m=numerator*f.denominator;                      //m 是分子 
	n=denominator*f.numerator;                           //n是分 母 
	t.numerator=m; 
	t.denominator=n;
   //if(t.denominator<0 ){t.denominator=-t.denominator;t.numerator=-t.numerator;	}
	t.simplify();
	return t;
}
/*Fraction Fraction:: operator+=(Fraction & f)        
{
	int m,n;   
	Fraction t;
	m=numerator*f.denominator+f.numerator*denominator;
	n=denominator*f.denominator;
	t.numerator=m;t.denominator=n;
	t.simplify();
	numerator=m; denominator=n;
	return t;
}
Fraction Fraction:: operator*=(Fraction & f) 
{	
	int m,n;   
	Fraction t;
	m=numerator*f.numerator;                      //m 是分子 
	n=denominator*f.denominator;                           //n是分 母 
	t.numerator=m; 
	t.denominator=n;
   //if(t.denominator<0 ){t.denominator=-t.denominator;t.numerator=-t.numerator;	}
	t.simplify();
	numerator=m;denominator=n;
	return t;
}*/ 
bool Fraction::operator==(Fraction const& f) const
{
	if(f.numerator==numerator && f.denominator==denominator)  return true;
	else return false;
}
bool Fraction::operator!=(Fraction const& f) const
{
	if(f.numerator==numerator && f.denominator==denominator)  return false;
	else return true;
}
bool Fraction::operator<=(Fraction const& f) const
{
	if((numerator*f.denominator) <=(f.numerator*denominator) )  return true;
	else return false;
}
bool Fraction::operator>=(Fraction const& f) const
{
	if((numerator*f.denominator) >=(f.numerator*denominator) )  return true;
	else return false;
}
bool Fraction::operator>(Fraction const& f) const
{
	if((numerator*f.denominator) >(f.numerator*denominator) )  return true;
	else return false;
}
bool Fraction::operator<(Fraction const& f) const
{
	if((numerator*f.denominator) <(f.numerator*denominator) )  return true;
	else return false;
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

