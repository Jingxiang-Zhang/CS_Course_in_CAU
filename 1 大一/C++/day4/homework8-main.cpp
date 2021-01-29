#include <iostream>
#include <stdio.h> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int zh(int a,int b)//寻找最大公因数 
{
	int c;
	for(c=a;c>1;c--)
	  if(a%c==0&&b%c==0) break;
	return c;     //返回最大公因数 
}
class Rational
{
	private:
		int a,b;
		double c;
	public:
		Rational(int x,int y)
		    {	a=x;b=y;}
		Rational(){;	}   
		printFormal()
		 {int x;
		 x=zh(a,b);     //寻找最大公因数x;
		 a=a/x;b=b/x;
		 printf("%d/%d\n",a,b);} //输出最简形式
		void printBoth()
		{double k,t,z;
		 k=double(a);t=double(b),z=k/t;
		printf("the Formal format of the first rational is : %d/%d\n",a,b);
		 printf("the Fixed format of the first rational is : %.2f",z);
		}
		void add(Rational &x,Rational &y)
		   {int s,t,k;
		     s=x.b*y.b; //s为分母
			 t=x.a*y.b+x.b*y.a; //t为分子 
			 k=zh(s,t);
			 b=s/k;a=t/k;
			 }  
	    void minus(Rational &x,Rational &y)
	        {int s,t,k;
		     s=x.b*y.b; //s为分母
			 t=x.a*y.b-x.b*y.a; //t为分子 
			 k=zh(s,t);
			 b=s/k;a=t/k;
			 } 
		void multi(Rational &x,Rational &y)
		    {int s,t,k;
		      s=x.b*y.b; //s为分母 
		      t=x.a*y.a;//t为分子 
		      k=zh(s,t);
		      b=s/k;a=t/k;
			}
		void divide(Rational &x,Rational &y) 
		    {int s,t,k;
		      s=x.b*y.a;//x为分母 
		      t=x.a*y.b;//y为分子
			  k=zh(s,t);
		      b=s/k;a=t/k;
			}
		
};

//StudybarCommentBegin
int main()
{
    int firstN,firstD,secondN,secondD;
    char op;
    
//    cout<<"Please input the numerator of first Rational: ";
    cin>>firstN;
//    cout<<"Please input the denominator of first Rational: ";
    cin>>firstD;
//    cout<<"Please input the numerator of second Rational: ";
    cin>>secondN;
//    cout<<"Please input the denominator of second Rational: ";
    cin>>secondD;

    
    Rational r1(firstN,firstD),r2(secondN,secondD),r3;

    
    cin>>op;
    
    cout<<"the Formal format of the first rational is : ";
    r1.printFormal();
    cout<<"the Formal format of the second rational is : ";
    r2.printFormal();
    cout<<endl;
    
    switch(op)
    {
        case '+' :
            r3.add(r1,r2);
            r3.printBoth();
            break;
        case '-' :
            r3.minus(r1,r2);
            r3.printBoth();
            break;
        case '*':
            r3.multi(r1,r2);
            r3.printBoth();
            break;
        case '/':
            r3.divide(r1,r2);
            r3.printBoth();
            break;
        default:
            cout<<"Invalid operator!";
    }
    
    return 0;
}
//StudybarCommentEnd
