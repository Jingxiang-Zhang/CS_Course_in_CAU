#include <iostream>
using namespace std;
// function template printArray definition
template< typename T >
void printArray( const T *arrayset, int count )
{
   for ( int i = 0; i < count && arrayset[i]!='\0' ; i++ )
      cout << arrayset[ i ] << " ";
   cout << endl;
} 
template< typename T >
int printArray( const T *arrayset, int count,int a,int b )
{
	int k=0;
	if(a<0) return 0;
   for ( int i = a; i < b+1 && arrayset[i]!='\0' ; i++ )
   { cout << arrayset[ i ] << " ";k++;
   }
   cout << endl;
   return k;
} 
//StudybarCommentBegin
int main()
{
    // sizes of arrays
    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;
    
    // declare and initialize arrays
    int a[ aCount ] = { 1, 2, 3, 4, 5 };
    double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    char c[ cCount ] = "HELLO";  // 6th position for null
    int elements;
    
    // display array a using original printArray function
    cout << "\nUsing original printArray function\n";
    printArray( a, aCount );
    
    // display array a using new printArray function
    cout << "\nArray a contains:\n";
    elements = printArray( a, aCount, 0, aCount - 1 );
    cout << elements << " elements were output\n";
    
    // display elements 1-3 of array a
    cout << "Array a from 1 to 3 is:\n";
    elements = printArray( a, aCount, 1, 3 );
    cout << elements << " elements were output\n";
    
    // try to print an invalid element
    cout << "Array a output with invalid subscripts:\n";
    elements = printArray( a, aCount, -1, 10 );
    cout << elements << " elements were output\n\n";
    
    // display array b using original printArray function
    cout << "\nUsing original printArray function\n";
    printArray( a, aCount );
    
    // display array b using new printArray function
    cout << "Array b contains:\n";
    elements = printArray( b, bCount, 0, bCount - 1 );
    cout << elements << " elements were output\n";
    
    // display elements 1-3 of array b
    cout << "Array b from 1 to 3 is:\n";
    elements = printArray( b, bCount, 1, 3 );
    cout << elements << " elements were output\n";
    
    // try to print an invalid element
    cout << "Array b output with invalid subscripts:\n";
    elements = printArray( b, bCount, -1, 10 );
    cout << elements << " elements were output\n\n";
    
    // display array c using original printArray function
    cout << "\nUsing original printArray function\n";
    printArray( a, aCount );
    
    // display array c using new printArray function
    cout << "Array c contains:\n";
    elements = printArray( c, cCount, 0, cCount - 1 );
    cout << elements << " elements were output\n";
    
    // display elements 1-3 of array c
    cout << "Array c from 1 to 3 is:\n";
    elements = printArray( c, cCount, 1, 3 );
    cout << elements << " elements were output\n";
    
    // try to display an invalid element
    cout << "Array c output with invalid subscripts:\n";
    elements = printArray( c, cCount, -1, 10 );
    cout << elements << " elements were output" << endl;
    
    return 0;
    
} // end main

//StudybarCommentEnd
