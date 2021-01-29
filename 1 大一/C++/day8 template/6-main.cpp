#include <iostream>
using namespace std; 
template < class elementType, int numberOfElements >
class Array {
private:
   elementType ptr[ numberOfElements ]; // ptr指向数组的起始位置
   int size; // 数组大小，即为numberOfElements 
   static int arrayCount;  // 生成的类对象的总数
public: 
    	
	Array(){size=numberOfElements;arrayCount=0;}
	friend istream& operator>>(istream &t,Array <elementType,numberOfElements > &z)
	{
	int k=0;
	for(k=0;k<z.size;k++) t>>z.ptr[k];
	return t;
   }
   int getSize(){return   size; }
   friend ostream& operator<<(ostream &t, const Array  <elementType,numberOfElements > &z)
   {
   	    int k;
   	    for(k=0;k<z.size;k++) t<<z.ptr[k];
   	    return t;
   }
   int  static getArrayCount(){return  arrayCount;  }
 
 

}; // end class Array

//StudybarCommentBegin
int main()
{
    // create intArray object
    Array< int, 5 > intArray1;
    
    // initialize intArray with user input values
    cin >> intArray1;
    
  // create intArray object
    Array< int, 5 > intArray2;
     
    // initialize intArray with user input values
    cin >> intArray2;
    
    // create floatArray
    Array< float, 5 > floatArray;
    
    cin >> floatArray;
    
    // output intArray1
    cout << "\nIntArray1 contains " << intArray1.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray1;

    // output intArray2
    cout << "\nIntArray2 contains " << intArray2.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray2;
    
    // output floatArray
    cout << "\nDoubleArray contains " << floatArray.getSize() << " Elements.\n";
    cout << "The values in the doubleArray are:\n";
    cout << floatArray;
    
    cout << "\nThere are " << Array<int,5>::getArrayCount() << " Array<int,5> objects.\n";
    cout << "\nThere are " << Array<float,5>::getArrayCount() << " Array<float,5> objects.\n";

    return 0;
    
} // end main


//StudybarCommentEnd
