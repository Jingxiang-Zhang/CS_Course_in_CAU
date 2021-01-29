#include<iostream>
using namespace std; 
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
/*
//return the this->mallocSize
unsigned int capacity() const;
*/
// for the array[i]=someT.
T& operator[](unsigned int i) 
{
	return this->array[i];
}


};

//StudybarCommentBegin
int main()
{
int length,i;
cin>> length;

DynamicArray<int> iarray(length,-1);

DynamicArray<int> iarray2(iarray);

cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray[i] <<" ";
	iarray[i] = i*1.1;
}
cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray2[i] <<" ";	
}

return 0;
}
//StudybarCommentEnd

