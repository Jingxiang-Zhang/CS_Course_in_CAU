#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include "sort.h"
using namespace std; 

void random_quque(int n,vote *result,int range=100000){
	//产生一个随机的序列
	/*********
		n表示产生序列的大小
		result表示传回的数组
		range表示取值范围 
	*/ 
	srand((unsigned)time(NULL));
	int i;
	for(i=0;i<n;i++){
		result[i].number=i;
		result[i].point=rand()%range;
	}
}

typedef void(*queue_sort)(vote *result,int first,int end);
ofstream fon("compare_sort_result.txt");
 
double test_time(queue_sort method,bool complax=false,const char* name=""){	
	/***********
		queue_sort：表示需要调用的函数名称，是void(*queue_sort)(vote *result,int first,int end)
		 			类型的指针 
		complax：是，则会把排序数据取到100万，否则只取指到10万
		name：用作函数名称的记录 		
	*/ 
	time_t start,end;
	fon<<endl<<"name:"<<name<<endl;
	if(complax)	
		fon<<"num:"<<5<<endl;
	else
		fon<<"num:"<<4<<endl;
	int number_range[5]={100,1000,10000,100000,1000000};
	int i;
	for(i=0;i<5;i++){
		if(!complax&&i==4) break;
		int number_length=number_range[i];
		vote *number=new vote[number_length];
		random_quque(number_length,number);
		
		start=clock();
		(*method)(number,0,number_length-1);
		end=clock();
		
		cout<<setw(7)<<number_length<<"个样本排序，用时："<<
				double(end-start)/1000<<"s"<<endl;
		fon<<"number:"<<number_length<<";time:"<<double(end-start)/1000<<endl;
	}
	return 0;
}

int main(){
	//这个函数用来调用不同排序算法的时间 
	cout<<"排序方法1：归并排序(merge sort)："<<endl;
	test_time(merge_sort,true,"merge_sort");
	cout<<endl<<"排序方法2：快速排序(quick sort)："<<endl;
	test_time(quickSort,true,"quick_sort");
	cout<<endl<<"排序方法3：希尔排序(shell sort)："<<endl;
	test_time(shell_sort,true,"shell_sort");
	cout<<endl<<"排序方法4：堆排序(heap sort)："<<endl;
	test_time(heap_sort,true,"heap_sort");
	cout<<endl<<"排序方法5：计数排序(counting sort)："<<endl;
	test_time(counting_sort,true,"counting_sort");
	cout<<endl<<"排序方法6：基数排序(base sort)："<<endl;
	test_time(base_sort,true,"base_sort");
	cout<<endl<<"排序方法7：插入排序(insert sort)："<<endl;
	test_time(insert_sort,false,"insert_sort");
	cout<<endl<<"排序方法8：选择排序(select sort)："<<endl;
	test_time(select_sort,false,"select_sort");
	cout<<endl<<"排序方法9：木桶排序(bucket sort)："<<endl;
	test_time(bucket_sort,false,"bucket_sort");
	cout<<endl<<"排序方法10：优化冒泡排序(bubble sort2)："<<endl;
	test_time(bubble_sort2,false,"bubble_sort2");
	cout<<endl<<"排序方法11：冒泡排序(bubble sort)："<<endl;
	test_time(bubble_sort,false,"bubble_sort");
}
