#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class SomeClass
{
	private:double a,b;
	public:
		SomeClass(double x=0,double y=0){a=x;b=y;		}
		friend istream &operator>>(istream &t,SomeClass &z);
		friend ostream &operator<<(ostream &t,SomeClass &z);
		bool  operator==(SomeClass &t)
		{
			if(a==t.a&&b==t.b) return true;
			else return false;
		}
};
istream &operator>>(istream &t,SomeClass &z)
{
	t>>z.a>>z.b;
	return t; 
}
ostream &operator<<(ostream &t,SomeClass &z)
{
	t<<"("<<z.a<<","<<z.b<<")";
	return t;
 } 
template <typename t>
bool isEqualTo(t a,t b)
{
	if(a==b) return true;
	else return false;
} 
//StudybarCommentBegin
int main()
{
    int a;   // integers used for
    int b;   // testing equality
    // test if two ints input by user are equal
//    cout << "Enter two integer values: ";

    cin >> a >> b;
    char c;  // chars used for
    char d;  // testing equality
    
    // test if two chars input by user are equal
//    cout << "\nEnter two character values: ";
    cin >> c >> d;
    
    double e;   // double values used for
    double f;   // testing equality
    
    // test if two doubles input by user are equal
//    cout << "\nEnter two double values: ";
    cin >> e >> f;
    
    SomeClass g( 1, 1.1 );  // SomeClass objects used
    SomeClass h;  // for testing equality
    
    cin >> h;
    
   cout << a << " and " << b << " are "
    << ( isEqualTo( a, b ) ? "equal" : "not equal" ) << '\n';
   
    cout << c << " and " << d << " are "
    << ( isEqualTo( c, d ) ? "equal" : "not equal" ) << '\n';
    
    
    cout << e << " and " << f << " are "
    << ( isEqualTo( e, f ) ? "equal" : "not equal") << '\n';
    
    // test if two SomeClass objects are equal
    // uses overloaded << operator
    cout << "The class objects " << g << " and " << h << " are "
    << ( isEqualTo( g, h ) ? "equal" : "not equal" ) << '\n';
    
    return 0; 
} // end main

//StudybarCommentEnd
