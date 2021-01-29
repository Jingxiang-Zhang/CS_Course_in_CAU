#include <iostream>
using namespace std;

class Point
{
     int x,y;
public:
    //构造函数，输出;  并完成私有成员的初始化
    Point(int a,int b=0)
    { cout<<"\nPoint is called!";
      x=a;y=b;
	}
    //析构函数，输出    
    ~Point(){cout<<"\n~Point is called!";} 
    //友元输出函数，输出   "("<<p.x<<","<<p.y<<")";
    friend DynamicArray(unsigned length, const Point &content) ;
};



template <typename T>
class DynamicArray {
private:
T* array; 
unsigned int mallocSize; //分配空间的大小。

public:
//Constructors 
DynamicArray(unsigned length, const T &content) 
{
	array=new T[content];
	for(int a=0;a<length;a++) array[a]=content.x;
    cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	mallocSize=length ;// ; 设置每个元素的初始内容是 content；
 } 
DynamicArray(unsigned length) {} 
/*
//Copy Constructor 
// cout<<endl<< "Copy Constructor is called";
DynamicArray(const DynamicArray<T> & anotherDA ) ;

// Destructors
// cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap"; 
~DynamicArray();

//return the this->mallocSize
unsigned int capacity() const;

// for the array[i]=someT.
T& operator[](unsigned int i) ;

//自己定义个operator[]  const 重载

//自己定义个 operator = 重载

// 函数内要输出  cout<<endl<<"operator = is called";

DynamicArray<T> & operator= (const DynamicArray<T> & anotherDA ) ;
*/
};




//StudybarCommentBegin
int main()
{
int length,i;
cin>> length; 
int iarray =length;
DynamicArray<Point> iarray(length,Point(3));
DynamicArray<Point> iarray2(iarray),iarray3(iarray2);
/*
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
