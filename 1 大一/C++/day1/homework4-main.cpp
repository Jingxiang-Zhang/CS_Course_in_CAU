#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class Cmytime
{
	private:
		int a,b,c;
	public:
		int Set(int h,int m,int s)
		{
			if(h>=0&&h<=23&&m>=0&&m<=59&&s>=0&&s<=60)
			{	a=h;b=m;c=s;return 1;}
			else return 0;
		
		}
		void AddOneSecond(){c=c+1;		} 
		void Show() {cout<<a<<":"<<b<<":"<<c;		}
}; 	
//StudybarCommentBegin
int main(void) {
    int h,m,s;
   cin>>h>>m>>s;

   Cmytime t1;
   t1.Set(h,m,s);
   t1.Show();
   cout<<endl<<t1.Set(24,0,0)<<"\n";
   t1.Show();

   t1.AddOneSecond();
   cout<<endl;
   t1.Show();
  
    return 0;
}

//StudybarCommentEnd
