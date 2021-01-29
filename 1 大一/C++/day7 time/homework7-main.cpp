//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
 using std::cout;
 using std::endl;
 using std::setfill;
 using std::setw;
//StudybarCommentEnd
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Time
{
	private:int a,b,c;
	public:
		Time(int x=0,int y=0,int z=0){a=x;b=y;c=z;	}
		void setTime(int x=0,int y=0,int z=0){a=x;b=y;c=z;	}
		void printTime()
		{
          cout<<setfill('0')<<setw(2)<<a
         <<":"<<setw(2)<<b<<":"
            <<setw(2)<<c<<endl;
         }
        Time &operator++()
        {
        	c++;
        	if(c>=60){ c-=60;b++;}
        	if(b>=60){ b-=60;a++;}
        	if(a>=24) a=a-24;
        	return *this;
		}
		Time operator++(int)
        {
        	Time m=*this;
        	c++;
        	if(c>=60){ c-=60;b++;}
        	if(b>=60){ b-=60;b++;}
        	if(a>=24) a-=24;
        	return m;
		}
		friend Time operator+(int x,Time &t);
		
};
Time operator+(int x,Time &t)
{
	Time m=t;
	int k=x;
	while(k>0) {k--;++m;} 
	return m;
	
}
//StudybarCommentBegin
int main()
{
	int hour, minute, second;
	int increase;
	Time t1(23, 45, 0), t2, t3(t1);
	cin >> hour >> minute >> second >> increase;
	t1.setTime(hour, minute, second);
	t1.printTime();		
	t2 = ++t1;      //This is  for ++t1
	t2.printTime();
	
	t3 = increase + t1;  //This is  for friend function
	t3.printTime();

	t1 = t2++;     //This is  for t2++
	t1.printTime();
	t2.printTime();
    
    
	t1 = (++t3)++;  // This is for left value (return the reference of  the object )
	t1.printTime();
	t3.printTime();   
	

	return 0;
}
//StudybarCommentEnd
