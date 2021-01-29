#include <iostream>
using namespace std;
template <typename T>
class DynamicArray {
private:
T* array; 
unsigned int mallocSize; //分配空间的大小。

public:
//Constructors 
//
DynamicArray(unsigned length, const T &content)  // mallocSize=length; 设置每个元素的初始内容是 content；
{   array=new T[length];
mallocSize=length;
   for(int a=0;a<length;a++) array[a]=content;
  cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	
 } 
unsigned int capacity() const
{
	return  this->mallocSize;
 } 
 
// Destructors

~DynamicArray()
{cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap"; 
}


// for the array[i]=someT.
T& operator[](unsigned int i) const
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
DynamicArray<double> darray(length,-2.1);
const DynamicArray<char> carray(length,'c');

cout<<endl<<"capacity:"<<carray.capacity()<<endl;

for(i=0;i<length;i++) {
cout << carray[i] <<" ";
}
cout<<endl;
for(i=0;i<length;i++) {
cout << iarray[i] <<" ";
iarray[i] = i*1.1;
}
cout<<endl;
for(i=0;i<length;i++) {
cout << darray[i] <<" ";
darray[i] = i*1.1;
}
cout<<endl;
for(i=0;i<length;i++) {
cout << iarray[i] <<" ";
iarray[i] = i*1.1;
}
cout<<endl;
for(i=0;i<length;i++) {
cout << darray[i] <<" ";
}  
return 0;
}
//StudybarCommentEnd
