#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cmytime
{
	private:
		int a,b,c;
	public:
		void Set(int h,int m,int s)
		{
			a=h;b=m;c=s;
		}
		void Show() {cout<<a<<":"<<b<<":"<<c;		}
}; 

	
//StudybarCommentBegin
int main(void) {
    int h,m,s;
   cin>>h>>m>>s;
  Cmytime t1;
t1.Set(h,m,s);
t1.Show();
    return 0;
}

//StudybarCommentEnd
