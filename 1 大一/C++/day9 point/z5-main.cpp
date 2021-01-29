#include <iostream>
using namespace std;


class Point
{
     int x,y;
public:
	Point(int x,int y=0):x(x),y(y){	cout<<"\nPoint is called!";} 


    //析构函数，输出    cout<<"\n~Point is called!";

    //友元输出函数，输出   "("<<p.x<<","<<p.y<<")";
};


template <typename T>
class DynamicArray {
private:
T* array; //pointer  ，一个T类型的指针
unsigned int mallocSize; //分配空间的大小。

public:
//Constructors 

 DynamicArray(unsigned length, const T &content)  
{
    mallocSize=length;
    array=new T[length];
    for(int a=0;a<length;a++) array[a]=content;
    cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";

 } 
  DynamicArray(unsigned length, const  Point& t)  
  {mallocSize=length;
   array=new Point[length];
    for(int a=0;a<length;a++) array[a]=t.x;
    cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";

  }
//Copy Constructor 
DynamicArray(const DynamicArray<T> & anotherDA ) 
{
	mallocSize=anotherDA.mallocSize ;
	array=new T[mallocSize];
	for(int a=0;a<mallocSize;a++) array[a]=anotherDA.array[a] ;
	cout<<endl<< "Copy Constructor is called";
}
// Destructors
 ~DynamicArray()
{cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap"; 

}
//return the this->mallocSize
//unsigned int capacity() const;

T& operator[](unsigned int i) 
{
	return this->array[i];
}

DynamicArray<T> & operator= (const DynamicArray<T> & anotherDA ) 
{
	cout<<endl<<"operator = is called";
	mallocSize=anotherDA.mallocSize ;
	array=new T[mallocSize];
	for(int a=0;a<mallocSize;a++) array[a]=anotherDA.array[a] ;
	return *this;
	
}

};


//StudybarCommentBegin
int main()
{
int length,i;
cin>> length;

DynamicArray<Point> iarray(length,Point(3));
/*
DynamicArray<Point> iarray2(iarray),iarray3(iarray2);

cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray3[i] <<" ";
	iarray[i] = Point(i,i+1);	
}
iarray3=iarray2=iarray;
cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray3[i] <<" ";	
}
*/
return 0;
}
//StudybarCommentEnd
