
#include <iostream>
#include <iomanip>
using std::cin;
 using std::cout;
 using std::endl;
 using std::setfill;
 using std::setw;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

template<typename t>
void bubbleSort( t a[100],int b)
{
	int x,y;
	t z;
	for(x=0;x<b;x++)
	for(y=0;y<b-1;y++)
	{if(a[y]>a[y+1]) {z=a[y];a[y]=a[y+1];a[y+1]=z;	}
	}
}
//StudybarCommentBegin
int main()
{ 
   const int arraySize = 10;  // size of array
   int a[ arraySize ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, i;

   // display int array in original order
   cout << "Integer data items in original order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << a[ i ];

    bubbleSort( a, arraySize );          // sort the array

   // display int array in sorted order
   cout << "\nInteger data items in ascending order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << a[ i ];

   cout << "\n\n";

   // initialize double array
   double b[ arraySize ] = { 10.1, 9.9, 8.8, 7.7, 6.6, 5.5,
                            4.4, 3.3, 2.2, 1.1 };
   
   // display double array in original order								 
   cout << "double point data items in original order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << b[ i ];

   bubbleSort( b, arraySize );          // sort the array
   
   // display sorted double array
   cout << "\ndouble point data items in ascending order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << b[ i ];

   cout << endl;

   return 0;

} // end main
//StudybarCommentEnd
