#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Account 
{
	private:double a;
	public:
	    Account(double x){a=x;	}
	    //double withdrawalAmount(){return a;}
	    void debit(double x){if(a>=x)a-=x;else printf("Debit amount exceeded account balance.\n\n");}
	    double getBalance()
		{if(a>=0)    return a;	
		else 
		{a=0;
		printf("\nError:Initial balance cannot be negative.\n\n");
		return 0;}
		}
	   double credit(double x){a=a+x;  }
};
	//Debit amount exceeded account balance.
//StudybarCommentBegin
int main()
{
    Account account1(50.0);

    double withdrawalAmount;
//    cout<<"\nEnter withdrawal amount for account1:";
    cin>>withdrawalAmount;
    cout<<"\nattempting to subtract "<<withdrawalAmount<<" from account1 balance\n";
    
    account1.debit(withdrawalAmount);
    cout<<"account1 balance:$"<<account1.getBalance()<<endl;
    
    Account account2(-2);
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;
    account2.credit(156.4);
    cout<<"\nattempting to add "<<156.4<<" to account2\n";
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;

    return 0;
}
//StudybarCommentEnd
