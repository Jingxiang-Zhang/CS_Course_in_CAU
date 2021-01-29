#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Employee
{
	private:char a[20];char b[20];int c;
	public:
		Employee(const char m[20],const char n[20],int k)
		   {strcpy(a,m);strcpy(b,n);c=k;}
		int getMonthlySalary(){return c;}
		char *getFirstName(){return a;}
		char *getLastName(){return b;}
		void setMonthlySalary(int m){c=m;		}
};
//StudybarCommentBegin
// function main begins program execution
int main()
{
    // create two Employee objects
    Employee employee1( "Lisa", "Roberts", 4500 );
    Employee employee2( "Mark", "Stein", 4000 );
    
    // display each Employee's yearly salary
    cout << "Employees' yearly salaries: " << endl;
    
    // retrieve and display employee1's monthly salary multiplied by 12
    int monthlySalary1 = employee1.getMonthlySalary();
    cout << employee1.getFirstName() << " " << employee1.getLastName()
    << ": $" << monthlySalary1 * 12 << endl;
    
    // retrieve and display employee2's monthly salary multiplied by 12
    int monthlySalary2 = employee2.getMonthlySalary();
    cout << employee2.getFirstName() << " " << employee2.getLastName()
    << ": $" << monthlySalary2 * 12 << endl;
    
    // give each Employee a 10% raise
    employee1.setMonthlySalary( monthlySalary1 * 1.1 );
    employee2.setMonthlySalary( monthlySalary2 * 1.1 );
    
    // display each Employee's yearly salary again
    cout << "\nEmployees' yearly salaries after 10% raise: " << endl;
    
    // retrieve and display employee1's monthly salary multiplied by 12
    monthlySalary1 = employee1.getMonthlySalary();
    cout << employee1.getFirstName() << " " << employee1.getLastName()
    << ": $" << monthlySalary1 * 12 << endl;
    
    monthlySalary2 = employee2.getMonthlySalary();
    cout << employee2.getFirstName() << " " << employee2.getLastName()
    << ": $" << monthlySalary2 * 12 << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
