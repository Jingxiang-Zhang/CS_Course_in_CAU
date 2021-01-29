#include <iostream>
#include<string.h> 
using namespace std;

class Invoice
{
	private:
		char s[20],t[20];
		int m,n;
	public:
		Invoice(char a[20],char b[20],int x,int y)
		{ strcpy(s,a);strcpy(t,b);m=x;n=y;}
		char *getPartNumber(){return s;	}
		char *getPartDescription(){return t;}
		int getQuantity(){return m;		}
		int getPricePerItem(){return n;}
		int getInvoiceAmount(){return m*n;		}
		/******************************************/
		void setPartNumber(char *u){strcpy(s,u);		} 
		void setPartDescription(char *u){strcpy(t,u);		}
		void setQuantity(int u){if(u>=0) m=u;else{ m=0;printf("\n");printf("quantity cannot be negative. quantity set to 0.\n");}		}
		void setPricePerItem(int u){if(u>=0) n=u;else n=0;		}
		
		
		
};
//StudybarCommentBegin
int main()
{
    // create an Invoice object
    Invoice invoice( "12345", "Hammer", 100, 5 );
    
    // display the invoice data members and calculate the amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    
    // modify the invoice data members
    invoice.setPartNumber( "123456" );
    invoice.setPartDescription( "Saw" );
    invoice.setQuantity( -5 ); // negative quantity, so quantity set to 0
    invoice.setPricePerItem( 10 );
    cout << "\nInvoice data members modified.\n";
    
    // display the modified invoice data members and calculate new amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
