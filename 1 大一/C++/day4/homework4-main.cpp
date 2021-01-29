#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class  Date
{
	private:int a,b,c;
	public:
		Date(int x,int y,int z){a=x;b=y;c=z;}
		int getMonth(){return a;}
		int getDay(){return b;}
		int getYear(){return c;}
		void setMonth(int k){if(k>12) a=1;else a=k;	}
		void setDay(int k){b=k;}
		void setYear(int k){c=k;}
		void displayDate(){cout<<a<<"/"<<b<<"/"<<c<<endl;		}
};
//StudybarCommentBegin
// function main begins program execution
int main()
{
    Date date( 5, 6, 1981 ); // create a Date object for May 6, 1981
    
    // display the values of the three Date data members
    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;
    
    cout << "\nOriginal date:" << endl;
    date.displayDate(); // output the Date as 5/6/1981
    
    // modify the Date
    date.setMonth( 13 ); // invalid month
    date.setDay( 1 );
    date.setYear( 2005 );
    
    cout << "\nNew date:" << endl;
    date.displayDate(); // output the modified date (1/1/2005)
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
